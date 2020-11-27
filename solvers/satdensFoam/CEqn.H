//- update dispersion tensor coefficients and source terms
forAll(patchEventList,patchEventi) patchEventList[patchEventi]->updateValue(runTime);
forAll(tracerSourceEventList,tracerSourceEventi) tracerSourceEventList[tracerSourceEventi]->updateValue(runTime);
composition.correct(Utheta, theta);

scalar resPicardC_aux=0.0;
resPicardC = 0.0;

forAll(composition.Y(), speciesi)
{
    const auto& speciesName = composition.species()[speciesi];

    auto& C = composition.Y(speciesi);
    const auto& R = composition.R(speciesi);
    const auto& Deff = composition.Deff(speciesi);
    const auto& lambda = composition.lambda(speciesi);
    const auto& sourceTerm_tracer = composition.sourceTerm(speciesi);

    C.storePrevIter();

    fvScalarMatrix CEqn
        (
            rhoc * eps * R * fvm::ddt(C)
            + rhoc * fvm::div(phi, C, "div(phi,C)")
            - rhoc * fvm::laplacian(eps*Deff, C, "laplacian(Deff,C)")
            ==
            //- sourceTerm_tracer  // JHG needs density
            - rhoc * eps * R * fvm::Sp(lambda,C)
        );

    CEqn.solve("C");

    dCdTmax[speciesi] = max(mag(fvc::ddt(C))).value();
    if (timeScheme == "Euler")
    {
        volScalarField dC2dT2(d2dt2Operator.fvcD2dt2(C));
        dC2dT2max[speciesi] = 0;
        forAll(dC2dT2, celli)
        {
            if(mag(dC2dT2[celli]) > dC2dT2max[speciesi])
            {
                Cmax[speciesi] = C[celli];
                dC2dT2max[speciesi] = mag(dC2dT2[celli]);
            }
        }
    }
    else
    {
        volScalarField dC3dT3(d3dt3Operator.d3dt3(C));
        dC3dT3max[speciesi] = 0;
        forAll(dC3dT3, celli)
        {
            if(mag(dC3dT3[celli]) > dC3dT3max[speciesi])
            {
                Cmax[speciesi] = C[celli];
                dC3dT3max[speciesi] = mag(dC3dT3[celli]);
            }
        }
    }

        dCdTmax = max(mag(fvc::ddt(C))).value();
        //dC = dCdTmax*runTime.deltaTValue();

    // I keep the greatest residual of all species.
    resPicardC_aux = gMax((mag(C-C.prevIter()))->internalField());
    if (resPicardC_aux > resPicardC){
      resPicardC = resPicardC_aux;
    }

    Info<< "Concentration Min(" << speciesName << ") = " << min(C).value()
        << " Max(" << speciesName << ") = " << max(C).value()
        << " d" << speciesName << "dTmax = " << dCdTmax[speciesi]
        << " mass(" << speciesName << ") = " << fvc::domainIntegrate(C*theta).value()
        << " dCmax = " << dCdTmax[speciesi]*runTime.deltaTValue()
        << "Picard iteration: " << iterPicard << " residual = " << resPicardC_aux
        << endl;

}

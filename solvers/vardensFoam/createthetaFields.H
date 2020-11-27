//- relative permeability (kr)
krModel->correct();
volScalarField krtheta = krModel->krb();

surfaceScalarField krthetaf ("krthetaf",fvc::interpolate(krtheta,"krtheta"));
surfaceScalarField rhocf ("rhocf",fvc::interpolate(rhoc,"rho"));
surfaceScalarField rhoC0f ("rho0f",fvc::interpolate(rhoC0,"rhoC0"));

//- mobility and fractional flow 
//surfaceScalarField Mf ("Mf",rhotheta*mag(g)*Kf*krthetaf/mutheta);
//surfaceScalarField Lf ("Lf",rhotheta*Kf*krthetaf/mutheta);

surfaceScalarField Mf ("Mf",rhoC0f*mag(g)*Kf*krthetaf/mutheta);
surfaceScalarField Lf ("Lf",rhoC0f*Kf*krthetaf/mutheta);

//- fluxes depending on saturation
surfaceScalarField phiG("phiG",(Lf * (rhocf/rhoC0f - 1)*g) & mesh.Sf());

//- Test if gravity is present
if (mag(g).value() == 0)
{
    FatalErrorIn("createthetaFields.H")
        << " Magnitude of gravity mag(g) equal to zero " << abort(FatalError);
}

//- null Pc field for darcy velocity boundary conditions
surfaceScalarField phiPcNull("phiPc",0*phiG);

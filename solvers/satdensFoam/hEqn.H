{
  // I need the concentration of the species that controls density.
     auto& C = composition.Y(0);
  
    Utheta.correctBoundaryConditions();
    forAll(mesh.boundary(),patchi)
    {
        if (isA< fixedValueFvPatchField<vector> >(Utheta.boundaryField()[patchi]))
        {
            phi.boundaryFieldRef()[patchi] = Utheta.boundaryField()[patchi] & mesh.Sf().boundaryField()[patchi];
        }
    }

    h.storePrevIter();

    rhoc = rhoModel->rho();
    drhocdC = rhoModel->drhodC();

    fvScalarMatrix hEqn
        (
            Ss * fvm::ddt(h)
            - fvm::laplacian(Mf,h)
            + fvc::div(phiG)
	    + eps * (drhocdC/rhoc) * fvc::ddt(C)
            ==
            - sourceTerm_water // /rhoc //needs density of source
        );

    #include "updateForcing.H"

    if (h.needReference())
    {
    	hEqn.setReference(hRefCell, hRefValue);
    }

    hEqn.solve();

    resPicardH = gMax((mag(h-h.prevIter()))->internalField());
    Info << "Picard iteration (H) : " << iterPicard << " residual = " << resPicardH << endl;

    phi = phiG-(Mf*fvc::snGrad(h))*mesh.magSf();
    Utheta = fvc::reconstruct(phi);

}

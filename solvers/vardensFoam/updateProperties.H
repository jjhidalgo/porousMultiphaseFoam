//- update saturation 
theta = pcModel->correctAndSb(h);

//- relative permeability computation
krModel->correct();
krthetaf = fvc::interpolate(krtheta,"krtheta");

//- update density
rhoModel->correct();
rhoc = rhoModel->rho();
rhoC0 = rhoModel->rhoC0();

rhocf = fvc::interpolate(rhoc,"rhoc");
rhoC0f = fvc::interpolate(rhoC0,"rhoC0");

//- mobility computation 
Mf = rhoC0f*mag(g)*Kf*krthetaf/mutheta;
Lf = rhoC0f*Kf*krthetaf/mutheta;

//- compute fluxes
phiG = (Lf * (rhocf/rhoC0f - 1)*g) & mesh.Sf();


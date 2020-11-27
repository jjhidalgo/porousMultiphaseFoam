/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2011-2016 OpenFOAM Foundation 
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/

#include "linearDensity.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace densityModels
{
defineTypeNameAndDebug(linearDensity, 0);

addToRunTimeSelectionTable
(
    densityModel,
    linearDensity,
    dictionary
);
}
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::densityModels::linearDensity::linearDensity
(
    const word& name,
    const dictionary& transportProperties,
    const volScalarField& C
)
    :
    densityModel(name, transportProperties,C),
    linearDensityCoeffs_(transportProperties.subDict(typeName + "Coeffs")),
    rho0_
    (
        IOobject
        (
            "rho0",
            C.time().timeName(),
            C.db(),
            IOobject::READ_IF_PRESENT,
            IOobject::NO_WRITE
        ),
        C.mesh(),
        dimensionedScalar(linearDensityCoeffs_.lookup("rho0"))
    ),
    beta_
    (
        IOobject
        (
            "beta",
            C.time().timeName(),
            C.db(),
            IOobject::READ_IF_PRESENT,
            IOobject::NO_WRITE
        ),
        C.mesh(),
        dimensionedScalar(linearDensityCoeffs_.lookup("beta"))
    )
{
    Info << "Parameters for linear density model" << nl << "{" << endl;
    Info << "    rho0 ";
    if (rho0_.headerOk()) { Info << "read file" << endl;}
    else {Info << average(rho0_).value() << endl;}
    Info <<  "    beta ";
    if (beta_.headerOk()) { Info << "read file" << endl;}
    else {Info << average(beta_).value() << endl;}
    Info << "} \n" << endl;
}

// ************************************************************************* //

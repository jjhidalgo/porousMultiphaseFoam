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

#include "densityModel.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
defineTypeNameAndDebug(densityModel, 0);
defineRunTimeSelectionTable(densityModel, dictionary);
}

// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::densityModel::densityModel
(
    const word& name,
    const dictionary& transportProperties,
    const volScalarField& C
)
    :
    name_(name),
    transportProperties_(transportProperties),
    C_(C),
    rho_
    (
        IOobject
        (
            name,
            C_.time().timeName(),
            C_.db(),
            IOobject::NO_READ,
            IOobject::NO_WRITE
        ),
        C_.mesh(),
        dimensionSet(1,-3,0,0,0,0,0)
     ),
        drhodC_
    (
        IOobject
        (
            name,
            C_.time().timeName(),
            C_.db(),
            IOobject::NO_READ,
            IOobject::NO_WRITE
        ),
        C_.mesh(),
        dimensionSet(1, -3,0,0,0,0,0)
     ),
        rhoC0_
    (
        IOobject
        (
            name,
            C_.time().timeName(),
            C_.db(),
            IOobject::NO_READ,
            IOobject::NO_WRITE
        ),
        C_.mesh(),
        dimensionSet(1, -3,0,0,0,0,0)
    )
{}

// ************************************************************************* //

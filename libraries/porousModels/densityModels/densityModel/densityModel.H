/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2011-2017 OpenFOAM Foundation
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

Namespace
    Foam::densityModel

Description
    A namespace for various density implementations.

Class
    Foam::densityModel

Description
    An abstract base class for density models.

SourceFiles
    densitynModel.C
    densitynModelNew.C
\*---------------------------------------------------------------------------*/

#ifndef densityModel_H
#define densityModel_H

#include "volFields.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
                   Class densityModel Declaration
\*---------------------------------------------------------------------------*/

class densityModel
{
protected:

    // Protected data
    word name_;
    dictionary transportProperties_;

    //- Reference to the concentration field
    const volScalarField& C_;

    //- effective density and derivative
    volScalarField rho_, drhodC_, rhoC0_;


    //- Disallow copy construct
    densityModel(const densityModel&);

    //- Disallow default bitwise assignment
    void operator=(const densityModel&);


public:

    //- Runtime type information
    TypeName("densityModel");


    // Declare run-time constructor selection table

    declareRunTimeSelectionTable
    (
        autoPtr,
        densityModel,
        dictionary,
        (
            const word& name,
            const dictionary& transportProperties,
            const volScalarField& C
        ),
        (name, transportProperties, C)
    );


    // Selectors

    //- Return a reference to the selected dispersion model
    static autoPtr<densityModel> New
    (
        const word& name,
        const dictionary& transportProperties,
        const volScalarField& C
    );


    // Constructors

    //- Construct from components
    densityModel
    (
        const word& name,
        const dictionary& transportProperties,
        const volScalarField& C
    );

    //- Destructor
    virtual ~densityModel()
        {}


    // Member Functions

    //- Return the phase transport properties dictionary
    const dictionary& transportProperties() const
        {
            return transportProperties_;
        }


    //- Return density
    tmp<volScalarField> rho() const
        {
            return rho_;
        }

      //- Return density derivative
    tmp<volScalarField> drhodC() const
        {
            return drhodC_;
        }
    //- Return density for C=0
    tmp<volScalarField> rhoC0() const
        {
            return rhoC0_;
        }
    //- Correct the density
    virtual void correct() = 0; 

};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //

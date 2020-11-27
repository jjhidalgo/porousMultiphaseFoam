/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) YEAR OpenFOAM Foundation
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

#include "fixedValueFvPatchFieldTemplate.H"
#include "addToRunTimeSelectionTable.H"
#include "fvPatchFieldMapper.H"
#include "volFields.H"
#include "surfaceFields.H"
#include "unitConversion.H"
//{{{ begin codeInclude
#line 41 "/home/juan/Dropbox/workspace/porousMultiphaseFoam/tutorials/satdensFoam-tutorials/henry/0/h.boundaryField.x1"
#include "fvCFD.H"
//}}} end codeInclude


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * * Local Functions * * * * * * * * * * * * * * //

//{{{ begin localCode

//}}} end localCode


// * * * * * * * * * * * * * * * Global Functions  * * * * * * * * * * * * * //

extern "C"
{
    // dynamicCode:
    // SHA1 = 867e97ab44d3e5c0c326ee9f8cd863082751f18b
    //
    // unique function name that can be checked if the correct library version
    // has been loaded
    void sea_867e97ab44d3e5c0c326ee9f8cd863082751f18b(bool load)
    {
        if (load)
        {
            // code that can be explicitly executed after loading
        }
        else
        {
            // code that can be explicitly executed before unloading
        }
    }
}

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

makeRemovablePatchTypeField
(
    fvPatchScalarField,
    seaFixedValueFvPatchScalarField
);


const char* const seaFixedValueFvPatchScalarField::SHA1sum =
    "867e97ab44d3e5c0c326ee9f8cd863082751f18b";


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

seaFixedValueFvPatchScalarField::
seaFixedValueFvPatchScalarField
(
    const fvPatch& p,
    const DimensionedField<scalar, volMesh>& iF
)
:
    fixedValueFvPatchField<scalar>(p, iF)
{
    if (false)
    {
        Info<<"construct sea sha1: 867e97ab44d3e5c0c326ee9f8cd863082751f18b"
            " from patch/DimensionedField\n";
    }
}


seaFixedValueFvPatchScalarField::
seaFixedValueFvPatchScalarField
(
    const seaFixedValueFvPatchScalarField& ptf,
    const fvPatch& p,
    const DimensionedField<scalar, volMesh>& iF,
    const fvPatchFieldMapper& mapper
)
:
    fixedValueFvPatchField<scalar>(ptf, p, iF, mapper)
{
    if (false)
    {
        Info<<"construct sea sha1: 867e97ab44d3e5c0c326ee9f8cd863082751f18b"
            " from patch/DimensionedField/mapper\n";
    }
}


seaFixedValueFvPatchScalarField::
seaFixedValueFvPatchScalarField
(
    const fvPatch& p,
    const DimensionedField<scalar, volMesh>& iF,
    const dictionary& dict
)
:
    fixedValueFvPatchField<scalar>(p, iF, dict)
{
    if (false)
    {
        Info<<"construct sea sha1: 867e97ab44d3e5c0c326ee9f8cd863082751f18b"
            " from patch/dictionary\n";
    }
}


seaFixedValueFvPatchScalarField::
seaFixedValueFvPatchScalarField
(
    const seaFixedValueFvPatchScalarField& ptf
)
:
    fixedValueFvPatchField<scalar>(ptf)
{
    if (false)
    {
        Info<<"construct sea sha1: 867e97ab44d3e5c0c326ee9f8cd863082751f18b"
            " as copy\n";
    }
}


seaFixedValueFvPatchScalarField::
seaFixedValueFvPatchScalarField
(
    const seaFixedValueFvPatchScalarField& ptf,
    const DimensionedField<scalar, volMesh>& iF
)
:
    fixedValueFvPatchField<scalar>(ptf, iF)
{
    if (false)
    {
        Info<<"construct sea sha1: 867e97ab44d3e5c0c326ee9f8cd863082751f18b "
            "as copy/DimensionedField\n";
    }
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

seaFixedValueFvPatchScalarField::
~seaFixedValueFvPatchScalarField()
{
    if (false)
    {
        Info<<"destroy sea sha1: 867e97ab44d3e5c0c326ee9f8cd863082751f18b\n";
    }
}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

void seaFixedValueFvPatchScalarField::updateCoeffs()
{
    if (this->updated())
    {
        return;
    }

    if (false)
    {
        Info<<"updateCoeffs sea sha1: 867e97ab44d3e5c0c326ee9f8cd863082751f18b\n";
    }

//{{{ begin code
    #line 35 "/home/juan/Dropbox/workspace/porousMultiphaseFoam/tutorials/satdensFoam-tutorials/henry/0/h.boundaryField.x1"
const vector axis(0, 1, 0);
	    operator==(1.02499 - 0.02499*mag(this->patch().Cf() & axis));
//}}} end code

    this->fixedValueFvPatchField<scalar>::updateCoeffs();
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //


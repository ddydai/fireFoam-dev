/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 1991-2009 OpenCFD Ltd.
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation; either version 2 of the License, or (at your
    option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM; if not, write to the Free Software Foundation,
    Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

Class
    Foam::constHTemperatureRadiationFvPatchScalarField

Description
    Foam::constHTemperatureRadiationFvPatchScalarField

SourceFiles
    constHTemperatureRadiationFvPatchScalarField.C

\*---------------------------------------------------------------------------*/

#ifndef constHTemperatureRadiationFvPatchScalarField_H
#define constHTemperatureRadiationFvPatchScalarField_H

#include "mixedFvPatchField.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

/*---------------------------------------------------------------------------*\
    Class
    constHTemperatureRadiationFvPatchScalarField Declaration
\*---------------------------------------------------------------------------*/

class constHTemperatureRadiationFvPatchScalarField
:
    public mixedFvPatchField<scalar>
{
    // Private data

        //- Tinf
        scalarField Tinf_;

        //- emissivity
        scalarField emissivity_;

        //- h
        scalarField h_;

        //- Name of the mode for computing heat transfer coefficient
        const word modeName_;

public:

    //- Runtime type information
    TypeName("constHTemperatureRadiation");


    // Constructors

        //- Construct from patch and internal field
        constHTemperatureRadiationFvPatchScalarField
        (
            const fvPatch&,
            const DimensionedField<scalar, volMesh>&
        );

        //- Construct from patch, internal field and dictionary
        constHTemperatureRadiationFvPatchScalarField
        (
            const fvPatch&,
            const DimensionedField<scalar, volMesh>&,
            const dictionary&
        );

        //- Construct by mapping given
        //  constHTemperatureRadiationFvPatchScalarField
        //  onto a new patch
        constHTemperatureRadiationFvPatchScalarField
        (
            const constHTemperatureRadiationFvPatchScalarField&,
            const fvPatch&,
            const DimensionedField<scalar, volMesh>&,
            const fvPatchFieldMapper&
        );

        //- Construct as copy
        constHTemperatureRadiationFvPatchScalarField
        (
            const constHTemperatureRadiationFvPatchScalarField&
        );

        //- Construct and return a clone
        virtual tmp<fvPatchField<scalar> > clone() const
        {
            return tmp<fvPatchField<scalar> >
            (
                new
                constHTemperatureRadiationFvPatchScalarField(*this)
            );
        }

        //- Construct as copy setting internal field reference
        constHTemperatureRadiationFvPatchScalarField
        (
            const constHTemperatureRadiationFvPatchScalarField&,
            const DimensionedField<scalar, volMesh>&
        );

        //- Construct and return a clone setting internal field reference
        virtual tmp<fvPatchField<scalar> > clone
        (
            const DimensionedField<scalar, volMesh>& iF
        ) const
        {
            return tmp<fvPatchField<scalar> >
            (
                new
                constHTemperatureRadiationFvPatchScalarField
                (
                    *this,
                    iF
                )
            );
        }


    // Member functions

        // Access

            //- Return Tinf
            const scalarField& Tinf() const
            {
                return Tinf_;
            }

            //- Return reference to Tinf to allow adjustment
            scalarField& Tinf()
            {
                return Tinf_;
            }


        // Mapping functions

            //- Map (and resize as needed) from self given a mapping object
            virtual void autoMap
            (
                const fvPatchFieldMapper&
            );

            //- Reverse map the given fvPatchField onto this fvPatchField
            virtual void rmap
            (
                const fvPatchScalarField&,
                const labelList&
            );


        // Evaluation functions

            //- Update the coefficients associated with the patch field
            virtual void updateCoeffs();


        //- Write
        virtual void write(Ostream&) const;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //


#endif

// ************************************************************************* //


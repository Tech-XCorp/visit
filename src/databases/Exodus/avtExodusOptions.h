// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//                            avtExodusOptions.h                             //
// ************************************************************************* //

#ifndef AVT_Exodus_OPTIONS_H
#define AVT_Exodus_OPTIONS_H

class DBOptionsAttributes;

#include <string>

namespace ExodusDBOptions
{
    typedef enum _mat_conv_t
    {
        None,
        Alegra,
        CTH,
        Custom
    } mat_conv_t;

    // Read options labels
    char const * const EXODUS_DETECT_COMPOUND_VARS = "Automagically Detect Compound Variables";
    char const * const EXODUS_MATERIAL_CONVENTION = "Use Material Convention";
    char const * const EXODUS_MATERIAL_COUNT = "Material Count (-1=guess)";
    char const * const EXODUS_VOLFRAC_NAMESCHEME = "Namescheme for material volume fractions"; 
    char const * const EXODUS_MATSPEC_NAMESCHEME = "Namescheme for material specific variables"; 

    // Read options default values
    // Note that the n>0 path specifies a namescheme sub-expression bracketed by '&' chars.
    char const * const EXODUS_VOLFRAC_NAMESCHEME_ALEGRA = "@%s@n?'&VOLFRC_%d&n&':'VOID_FRC':@";
    char const * const EXODUS_MATSPEC_NAMESCHEME_ALEGRA = "@%V_%d@n";

    char const * const EXODUS_VOLFRAC_NAMESCHEME_CTH = "@%s@n?'&VOLM_%d&n&':'VOID_FRC':@";
    char const * const EXODUS_MATSPEC_NAMESCHEME_CTH = "@%V_%d@n";
}

// ****************************************************************************
//  Functions: avtExodusOptions
//
//  Purpose:
//      Creates the options for  Exodus readers and/or writers.
//
//  Programmer: miller -- generated by xml2avt
//  Creation:   Thu Nov 29 14:10:56 PST 2007
//
// ****************************************************************************

DBOptionsAttributes *GetExodusReadOptions(void);
DBOptionsAttributes *GetExodusWriteOptions(void);


#endif

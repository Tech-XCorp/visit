// Copyright (c) Lawrence Livermore National Security, LLC and other VisIt
// Project developers.  See the top-level LICENSE file for dates and other
// details.  No copyright assignment is required to contribute to VisIt.

// ************************************************************************* //
//                          avtMFIXCDFOptions.h                              //
// ************************************************************************* //

#ifndef AVT_MFIXCDF_OPTIONS_H
#define AVT_MFIXCDF_OPTIONS_H

class DBOptionsAttributes;

#include <string>

#define N_X_DOMAINS "Number of domains in the X or R direction"
#define DEF_N_X_DOMAINS                 4

#define N_Y_DOMAINS "Number of domains in the Y direction"
#define DEF_N_Y_DOMAINS                 8

#define N_Z_DOMAINS "Number of domains in the Z or theta direction"
#define DEF_N_Z_DOMAINS                 4

// ****************************************************************************
//  Functions: avtMFIXCDFOptions
//
//  Purpose:
//      Creates the options for  MFIXCDF readers and/or writers.
//
//  Programmer: welling -- generated by xml2avt
//  Creation:   Wed Aug 3 16:35:13 PST 2011
//
// ****************************************************************************

DBOptionsAttributes *GetMFIXCDFReadOptions(void);
DBOptionsAttributes *GetMFIXCDFWriteOptions(void);


#endif

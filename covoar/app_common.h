/*
 *   $Id$
 */

#ifndef __APP_COMMON_h
#define __APP_COMMON_h

#include <list>

#include "DesiredSymbols.h"
#include "Explanations.h"
#include "TargetBase.h"

extern Coverage::Explanations*      AllExplanations;
extern Coverage::ObjdumpProcessor*  objdumpProcessor;
extern Coverage::DesiredSymbols*    SymbolsToAnalyze;
extern bool                         Verbose;
extern const char*                  outputDirectory;
extern bool                         BranchInfoAvailable;
extern Target::TargetBase*          TargetInfo;
extern const char*                  dynamicLibrary;
extern const char*                  projectName;


bool FileIsNewer( const char *f1, const char *f2 ); 
bool FileIsReadable( const char *f1 ); 
bool ReadUntilFound( FILE *file, const char *line );

#endif

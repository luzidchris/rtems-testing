/*
 *   $Id$
 */

/*! @file ReportsText.h
 *  @brief Reports Text Format Write Specification
 *
 *  This file contains the specification of the Reports methods.  This
 *  collection of methods is used to generate the various reports of
 *  the analysis results.
 */

#ifndef __REPORTSTEXT_H__
#define __REPORTSTEXT_H__

#include <stdint.h>
#include "ReportsBase.h"

namespace Coverage {

/*!
 *   This class contains all methods and data necessary to
 *   produce all text style reports.
 */
class ReportsText: public ReportsBase {

  public:
    ReportsText( time_t timestamp );
   ~ReportsText();

  /*!
   *  This method produces a report that contains information about each
   *  uncovered branch statement.
   *
   *  @param[in] fileName identifies the branch report file name
   */
  void WriteBranchReport(
    const char* const fileName
  );

  /*!
   *  This method produces a report that contains information about each
   *  uncovered range of bytes.
   *
   *  @param[in] fileName identifies the coverage report file name
   */
  void WriteCoverageReport(
    const char* const fileName
  );

  /*!
   *  This method produces a summary report that lists each uncovered
   *  range of bytes.
   *
   *  @param[in] fileName identifies the size report file name
   */
  void WriteSizeReport(
    const char* const fileName
  );

  protected:

    virtual void PutAnnotatedLine( 
      FILE*                aFile, 
      AnnotatedLineState_t state, 
      std::string          line, 
      uint32_t             id 
    );

    virtual bool PutNoBranchInfo(
      FILE* report
    );

    virtual bool PutBranchEntry(
      FILE*                                            report,
      unsigned int                                     number,
      Coverage::DesiredSymbols::symbolSet_t::iterator  symbolPtr,
      Coverage::CoverageRanges::ranges_t::iterator     rangePtr
    );

    virtual void putCoverageNoRange(
      FILE*        report,
      FILE*        noRangeFile,
      unsigned int number,
      std::string  symbol
    );

    virtual bool PutCoverageLine(
      FILE*                                           report,
      unsigned int                                    number,
      Coverage::DesiredSymbols::symbolSet_t::iterator ditr,
      Coverage::CoverageRanges::ranges_t::iterator    ritr
    );

    virtual bool PutSizeLine(
      FILE*                                           report,
      unsigned int                                    number,
      Coverage::DesiredSymbols::symbolSet_t::iterator symbol,
      Coverage::CoverageRanges::ranges_t::iterator    range
    );

    virtual bool PutSymbolSummaryLine(
      FILE*                                           report,
      unsigned int                                    number,
      Coverage::DesiredSymbols::symbolSet_t::iterator symbol
    );

};

}

#endif

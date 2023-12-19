#ifndef TIMING_ANALYSIS_H
#define TIMING_ANALYSIS_H


#include "DataStructure.h"
#include "Cli.h"

void perform_timing_analysis(TimingAnalysis& data);
void perform_operation_global_slack(GlobalSlacks& slacks, TimingAnalysis& data);

void run(Cli cli);


#endif


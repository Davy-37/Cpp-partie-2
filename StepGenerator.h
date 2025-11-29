#pragma once
#include "TimesSerieGenerator.h"
#include <vector>

class StepGenerator : public TimeSeriesGenerator {
public:
    StepGenerator();
    explicit StepGenerator(int s);

    std::vector<double> generateTimeSeries(int size) override;
};

#pragma once
#include "TimesSerieGenerator.h"
#include <vector>

class GaussianGenerator : public TimeSeriesGenerator {
private:
    double mean;
    double stddev;

public:
    GaussianGenerator();
    GaussianGenerator(int s, double m, double sd);

    std::vector<double> generateTimeSeries(int size) override;
};

#pragma once
#include "TimesSerieGenerator.h"
#include <vector>

class SinWaveGenerator : public TimeSeriesGenerator {
private:
    double A;
    double w;
    double phi;

public:
    SinWaveGenerator();
    SinWaveGenerator(double A_, double w_, double phi_, int s = 0);

    std::vector<double> generateTimeSeries(int size) override;
};

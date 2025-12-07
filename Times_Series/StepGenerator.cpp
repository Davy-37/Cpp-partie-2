#include "TimesSerieGenerator.h"
#include "StepGenerator.h"
#include <random>

StepGenerator::StepGenerator()
    : TimeSeriesGenerator(5678) {
}

StepGenerator::StepGenerator(int s)
    : TimeSeriesGenerator(s) {
}

std::vector<double> StepGenerator::generateTimeSeries(int size) {
    std::vector<double> ts(size);
    if (size <= 0) return ts;

    ts[0] = 0.0;

    std::mt19937 gen(seed);
    std::uniform_real_distribution<double> prob(0.0, 1.0);
    std::uniform_int_distribution<int> valDist(0, 100);

    for (int i = 1; i < size; i++) {
        double p = prob(gen);
        if (p < 0.5) ts[i] = valDist(gen);
        else ts[i] = ts[i - 1];
    }

    return ts;
}

#include "TimesSerieGenerator.h"

TimeSeriesGenerator::TimeSeriesGenerator() : seed(12345) {}

TimeSeriesGenerator::TimeSeriesGenerator(int s) : seed(s) {}

void TimeSeriesGenerator::printTimeSeries(const std::vector<double>& ts) {
    for (size_t i = 0; i < ts.size(); i++) {
        std::cout << ts[i];
        if (i + 1 < ts.size()) std::cout << " ";
    }
    std::cout << std::endl;
}

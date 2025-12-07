#include "GaussianGenerator.h"
#include <random>
#include <cmath>
#include <limits>

GaussianGenerator::GaussianGenerator()
    : TimeSeriesGenerator(1234), mean(0.0), stddev(1.0) {
}

GaussianGenerator::GaussianGenerator(int s, double m, double sd)
    : TimeSeriesGenerator(s), mean(m), stddev(sd) {
}

std::vector<double> GaussianGenerator::generateTimeSeries(int size) {
    std::vector<double> ts(size);

    std::mt19937 gen(seed);
    std::uniform_real_distribution<double> uni(0.0, 1.0);

    const double PI = 3.141592653589793;

    for (int i = 0; i < size; i++) {
        double u1 = uni(gen);
        if (u1 <= 0) u1 = std::numeric_limits<double>::min();
        double u2 = uni(gen);

        double z0 = std::sqrt(-2 * std::log(u1)) * std::cos(2 * PI * u2);
        ts[i] = mean + stddev * z0;
    }

    return ts;
}

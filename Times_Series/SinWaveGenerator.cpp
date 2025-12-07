#include "SinWaveGenerator.h"
#include <cmath>

SinWaveGenerator::SinWaveGenerator()
    : TimeSeriesGenerator(0), A(1.0), w(0.3), phi(0.0) {
}

SinWaveGenerator::SinWaveGenerator(double A_, double w_, double phi_, int s)
    : TimeSeriesGenerator(s), A(A_), w(w_), phi(phi_) {
}

std::vector<double> SinWaveGenerator::generateTimeSeries(int size) {
    std::vector<double> ts(size);

    for (int i = 0; i < size; i++) {
        ts[i] = A * std::sin(w * i + phi);
    }
    return ts;
}

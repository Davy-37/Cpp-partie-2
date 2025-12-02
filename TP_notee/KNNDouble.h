#pragma once
#include "KNN.h"
#include <utility>
#include <cmath>

class KNNDouble : public KNN<std::pair<double, double>> {
public:
    KNNDouble(int k = 1);

    double similarityMeasure(const std::pair<double, double>& a,
        const std::pair<double, double>& b) const override;
};

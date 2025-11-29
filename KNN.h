#pragma once

#include "TimeSeriesDataset.h"
#include <vector>
#include <string>

double euclidean_distance(const std::vector<double>& x, const std::vector<double>& y);
double dtw(const std::vector<double>& x, const std::vector<double>& y);

class KNN {
private:
    int k;
    std::string sim;

public:
    KNN(int k_, const std::string& similarity);

    double evaluate(const TimeSeriesDataset& train,
        const TimeSeriesDataset& test,
        const std::vector<int>& ytest) const;

private:
    int predictOne(const TimeSeriesDataset& train,
        const std::vector<double>& query) const;
};
    
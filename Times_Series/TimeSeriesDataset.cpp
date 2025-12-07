#include "TimeSeriesDataset.h"
#include <numeric>
#include <cmath>

TimeSeriesDataset::TimeSeriesDataset(bool znorm, bool isTrain_)
    : znormalize(znorm), isTrain(isTrain_), maxLength(0), numberOfSamples(0) {
}

const std::vector<double>& TimeSeriesDataset::getSeries(int idx) const {
    return data[idx];
}

int TimeSeriesDataset::getLabel(int idx) const {
    return labels[idx];
}

int TimeSeriesDataset::size() const {
    return numberOfSamples;
}

void TimeSeriesDataset::addTimeSeries(const std::vector<double>& series) {
    std::vector<double> s = series;
    if (znormalize) zNormalize(s);

    if ((int)s.size() > maxLength) maxLength = s.size();

    data.push_back(s);
    numberOfSamples++;
}

void TimeSeriesDataset::addTimeSeries(const std::vector<double>& series, int label) {
    std::vector<double> s = series;
    if (znormalize) zNormalize(s);

    if ((int)s.size() > maxLength) maxLength = s.size();

    data.push_back(s);
    labels.push_back(label);
    numberOfSamples++;
}

void TimeSeriesDataset::zNormalize(std::vector<double>& s) {
    if (s.empty()) return;

    double mean = std::accumulate(s.begin(), s.end(), 0.0) / s.size();

    double sq = 0.0;
    for (double v : s) sq += (v - mean) * (v - mean);

    double stddev = std::sqrt(sq / s.size());

    if (stddev == 0) {
        for (double& v : s) v = 0;
        return;
    }

    for (double& v : s) v = (v - mean) / stddev;
}

#pragma once
#include <vector>

class TimeSeriesDataset {
private:
    bool znormalize;
    bool isTrain;

    std::vector<std::vector<double>> data;
    std::vector<int> labels;

    int maxLength;
    int numberOfSamples;

public:
    TimeSeriesDataset(bool znorm, bool isTrain_);

    const std::vector<double>& getSeries(int idx) const;
    int getLabel(int idx) const;
    int size() const;

    void addTimeSeries(const std::vector<double>& series);
    void addTimeSeries(const std::vector<double>& series, int label);

private:
    void zNormalize(std::vector<double>& s);
};

#pragma once
#include <vector>
#include <iostream>

class TimeSeriesGenerator {
protected:
    int seed;

public:
    TimeSeriesGenerator();
    explicit TimeSeriesGenerator(int s);
    virtual ~TimeSeriesGenerator() = default;

    virtual std::vector<double> generateTimeSeries(int size) = 0;

    static void printTimeSeries(const std::vector<double>& ts);
};

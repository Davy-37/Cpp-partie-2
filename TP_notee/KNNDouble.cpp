#include "KNNDouble.h"

KNNDouble::KNNDouble(int k)
    : KNN<std::pair<double, double>>(k) {}

double KNNDouble::similarityMeasure(const std::pair<double, double>& a,
    const std::pair<double, double>& b) const {
    double dx = a.first - b.first;
    double dy = a.second - b.second;
    return std::sqrt(dx * dx + dy * dy);   
}

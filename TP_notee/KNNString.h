#pragma once
#include "KNN.h"
#include <vector>
#include <string>

class KNNString : public KNN<std::vector<std::string>> {
public:
    KNNString(int k = 1);

    double similarityMeasure(const std::vector<std::string>& a,
        const std::vector<std::string>& b) const override;

private:
    static int levenshteinDistance(const std::string& s1,
        const std::string& s2);
};

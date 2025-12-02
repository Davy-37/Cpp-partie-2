#pragma once
#include <vector>
#include <algorithm>
#include <utility>

template <typename T>
class KNN {
protected:
    int k;

public:
    KNN(int k = 1) : k(k) {}
    virtual ~KNN() = default;

    int getK() const { return k; }

    virtual double similarityMeasure(const T& a, const T& b) const = 0;

   
    std::vector<int> findNearestNeighbours(const std::vector<T>& trainData,
        const T& target) const {
        std::vector<std::pair<double, int>> distances;
        distances.reserve(trainData.size());

        for (std::size_t i = 0; i < trainData.size(); ++i) {
            double d = similarityMeasure(trainData[i], target);
            distances.emplace_back(d, static_cast<int>(i));
        }

        std::sort(distances.begin(), distances.end(),
            [](const std::pair<double, int>& a,
                const std::pair<double, int>& b) {
                    return a.first < b.first;
            });

        std::vector<int> neighbors;
        for (int i = 0; i < k && i < static_cast<int>(distances.size()); ++i) {
            neighbors.push_back(distances[i].second);
        }
        return neighbors;
    }
};

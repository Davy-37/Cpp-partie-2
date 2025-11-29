#include "KNN.h"
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <limits>

double euclidean_distance(const std::vector<double>& x, const std::vector<double>& y) {
    size_t L = std::min(x.size(), y.size());
    double sum = 0.0;
    for (size_t i = 0; i < L; i++) {
        double d = x[i] - y[i];
        sum += d * d;
    }
    return std::sqrt(sum);
}

double dtw(const std::vector<double>& x, const std::vector<double>& y) {
    int n = x.size();
    int m = y.size();

    const double INF = std::numeric_limits<double>::infinity();
    std::vector<std::vector<double>> D(n + 1, std::vector<double>(m + 1, INF));

    D[0][0] = 0.0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            double cost = (x[i - 1] - y[j - 1]);
            cost = cost * cost;

            D[i][j] = cost + std::min({ D[i - 1][j], D[i][j - 1], D[i - 1][j - 1] });
        }
    }

    return std::sqrt(D[n][m]);
}

KNN::KNN(int k_, const std::string& similarity)
    : k(k_), sim(similarity) {
}

double KNN::evaluate(const TimeSeriesDataset& train,
    const TimeSeriesDataset& test,
    const std::vector<int>& ytest) const {
    int correct = 0;
    for (int i = 0; i < test.size(); i++) {
        int pred = predictOne(train, test.getSeries(i));
        if (pred == ytest[i]) correct++;
    }
    return (double)correct / test.size();
}

int KNN::predictOne(const TimeSeriesDataset& train,
    const std::vector<double>& query) const {
    std::vector<std::pair<double, int>> dist;

    dist.reserve(train.size());

    for (int i = 0; i < train.size(); i++) {
        double d = 0;
        if (sim == "euclidean_distance")
            d = euclidean_distance(query, train.getSeries(i));
        else
            d = dtw(query, train.getSeries(i));

        dist.emplace_back(d, train.getLabel(i));
    }

    std::sort(dist.begin(), dist.end());

    std::unordered_map<int, int> count;

    int bestLabel = dist[0].second;
    int bestCount = 0;

    for (int i = 0; i < k; i++) {
        int lbl = dist[i].second;
        count[lbl]++;
        if (count[lbl] > bestCount) {
            bestCount = count[lbl];
            bestLabel = lbl;
        }
    }

    return bestLabel;
}

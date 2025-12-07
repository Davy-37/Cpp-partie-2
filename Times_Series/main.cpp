
#include "SinWaveGenerator.h"
#include "StepGenerator.h"
#include "GaussianGenerator.h"
#include "TimeSeriesDataset.h"
#include "knn.h"
#include "TimeSeriesDataset.h"
#include "GaussianGenerator.h"

#include <iostream>

int main() {
    TimeSeriesDataset trainData(false, true);
    TimeSeriesDataset testData(false, false);

    GaussianGenerator gsg;
    SinWaveGenerator swg;
    StepGenerator stg;

    trainData.addTimeSeries(gsg.generateTimeSeries(11), 0);
    trainData.addTimeSeries(gsg.generateTimeSeries(11), 0);

    trainData.addTimeSeries(swg.generateTimeSeries(11), 1);
    trainData.addTimeSeries(swg.generateTimeSeries(11), 1);

    trainData.addTimeSeries(stg.generateTimeSeries(11), 2);
    trainData.addTimeSeries(stg.generateTimeSeries(11), 2);

    std::vector<int> ground_truth;

    testData.addTimeSeries(gsg.generateTimeSeries(11));
    ground_truth.push_back(0);

    testData.addTimeSeries(swg.generateTimeSeries(11));
    ground_truth.push_back(1);

    testData.addTimeSeries(stg.generateTimeSeries(11));
    ground_truth.push_back(2);

    KNN knn1(1, "dtw");
    std::cout << knn1.evaluate(trainData, testData, ground_truth) << std::endl;

    KNN knn2(2, "euclidean_distance");
    std::cout << knn2.evaluate(trainData, testData, ground_truth) << std::endl;

    KNN knn3(3, "euclidean_distance");
    std::cout << knn3.evaluate(trainData, testData, ground_truth) << std::endl;

    return 0;
}

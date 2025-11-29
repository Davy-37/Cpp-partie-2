/*
#include "Card.h"
#include "PokemonCard.h"
#include "EnergyCard.h"
#include "TrainerCard.h"
#include "Player.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
    Player player1("Hadi");
    player1.addCardToBench(new EnergyCard("Electric"));
    player1.addCardToBench(new EnergyCard("Electric"));
    player1.addCardToBench(new TrainerCard("Ash", "heal all your action pokemon"));
    player1.addCardToBench(new PokemonCard("Pikachu", "Electric", "Pikachu",
        2, 100, 2,
        "thunderbolt", 20,
        3, "thunder storm", 30));

    player1.activatePokemonCard(3);
    player1.attachEnergyCard(0, 0);
    player1.attachEnergyCard(0, 0);
    cout << endl;
    player1.displayBench();
    cout << endl;
    player1.displayAction();

    Player player2("Germain");
    player2.addCardToBench(new EnergyCard("Grass"));
    player2.addCardToBench(new TrainerCard("Brock", "heal all your action pokemon"));
    player2.addCardToBench(new PokemonCard("Bulbasaur", "Grass", "Bulbasaur",
        1, 100, 2,
        "Leech Seed", 15,
        3, "Vine Whip", 25));
    player2.activatePokemonCard(2);
    player2.attachEnergyCard(0, 0);
    cout << endl;
    player2.displayBench();
    cout << endl;
    player2.displayAction();

    player1.attack(0, 0, player2, 0);
    cout << endl;
    player2.displayAction();
    player2.useTrainer(0);
    cout << endl;
    player2.displayAction();

    return 0;
}

*/

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

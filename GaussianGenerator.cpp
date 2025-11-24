#include "GaussianGenerator.h"
#include <random>


#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


GaussianGenerator::GaussianGenerator()
	: TimesSerieGenerator(), mean(0.0), strddev(1.0)
{
}

GaussianGenerator::GaussianGenerator(int seed, double mean, double strddev)
	: TimesSerieGenerator(seed), mean(mean), strddev(strddev)
{
}
double GaussianGenerator::getMean() const
{
	return mean;
}
void GaussianGenerator::setMean(double mean)
{
	this->mean = mean;
}
double GaussianGenerator::getStrdDev() const
{
	return strddev;
}
void GaussianGenerator::setStrdDev(double strddev)
{
	this->strddev = strddev;
}
int GaussianGenerator::getNextValue()
{
	std::default_random_engine generator(this->getSeed());
	std::normal_distribution<double> distribution(mean, strddev);
	return static_cast<int>(distribution(generator));
}
vector<double> GaussianGenerator::generateTimeSeries(int n)
{
	vector<double> series;

	for (int i = 0; i++ < n; ++i)
	{
		series.push_back(boxMuller());
	}

	return series;
}
double GaussianGenerator::boxMuller()
{
	double U_1 = (rand() + 1) / (static_cast<double>(RAND_MAX) + 2);
	double U_2 = (rand() +1 ) / (static_cast<double>(RAND_MAX) + 2);

	double Z = sqrt(-2.0 * log(U_1)) * cos(2.0 * M_PI * U_2);

	return Z * strddev + mean;
}

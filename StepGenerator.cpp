#include "StepGenerator.h"

StepGenerator::StepGenerator()
	: TimesSerieGenerator(), stepSize(1)
{
}
StepGenerator::StepGenerator(int seed, int stepSize)
	: TimesSerieGenerator(seed), stepSize(stepSize)
{
}
int StepGenerator::getStepSize() const
{
	return stepSize;
}
void StepGenerator::setStepSize(int stepSize)
{
	this->stepSize = stepSize;
}

int StepGenerator::getNextValue()
{

	int v1 = rand() % 101;
	int v2 = getSeed();

	if (v1 > v2) {

	}
	return v1 > v2 ? rand() % (v1 - v2 + 1) + v2 : rand() % (v2 - v1 + 1) + v1;
}

vector<double> StepGenerator::generateTimeSeries(int n)
{
	vector<double> series;
	for (int i = 0; i++ < n; )
	{
		series.push_back(this->getNextValue());
	}
	return series;
}
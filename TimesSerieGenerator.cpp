#include "TimesSerieGenerator.h"

TimesSerieGenerator::TimesSerieGenerator()
	: seed(0)
{
}
TimesSerieGenerator::TimesSerieGenerator(int seed)
	: seed(seed)
{
}
TimesSerieGenerator::~TimesSerieGenerator()
{
}
int TimesSerieGenerator::getSeed() const
{
	return seed;
}
void TimesSerieGenerator::setSeed(int seed)
{
	this->seed = seed;
}
int TimesSerieGenerator::getNextValue()
{
	return seed++;
}
void TimesSerieGenerator::printTimeSerie(const vector<double>& series)
{
	for (double value : series)
	{
		cout << value << " ";
	}
	cout << endl;
}
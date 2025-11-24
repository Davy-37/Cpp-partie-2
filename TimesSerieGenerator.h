#pragma once

#include <iostream>
#include <vector>
using namespace std;


class TimesSerieGenerator
{
private:
	int seed;
public:
	TimesSerieGenerator();
	TimesSerieGenerator(int seed);
	virtual ~TimesSerieGenerator();

	virtual int getSeed() const;
	virtual void setSeed(int seed);
	virtual int getNextValue();

	virtual vector <double> generateTimeSeries(int) = 0;

	static void printTimeSerie(const vector<double>& );
};


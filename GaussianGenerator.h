#pragma once
#include "TimesSerieGenerator.h"

class GaussianGenerator : TimesSerieGenerator
{
private:
	double mean, strddev;

private:
	double boxMuller();

public:
	GaussianGenerator();
	GaussianGenerator(int seed, double mean, double strddev);
	virtual ~GaussianGenerator() = default;

	virtual double getMean() const;
	virtual void setMean(double mean);
	virtual double getStrdDev() const;
	virtual void setStrdDev(double strddev);
	virtual int getNextValue() override;

	virtual vector<double> generateTimeSeries(int) override;



};


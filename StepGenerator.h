#pragma once
#include "TimesSerieGenerator.h"


class StepGenerator : TimesSerieGenerator
{
private:
	int stepSize;
public:
	StepGenerator();
	StepGenerator(int seed, int stepSize);
	virtual ~StepGenerator() = default;

	virtual int getStepSize() const;
	virtual void setStepSize(int stepSize);

	virtual int getNextValue() override;

	virtual vector<double> generateTimeSeries(int) override;
};


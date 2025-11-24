#pragma once
#include "TimesSerieGenerator.h"

class SinWaveGenerator : TimesSerieGenerator
{
private:
	double amplitude;
	double frequency;
	double phase;
public:
	SinWaveGenerator();
	SinWaveGenerator(int seed, double amplitude, double frequency, double phase);
	virtual ~SinWaveGenerator() = default;

	virtual double getAmplitude() const;
	virtual void setAmplitude(double amplitude);
	virtual double getFrequency() const;
	virtual void setFrequency(double frequency);
	virtual double getPhase() const;
	virtual void setPhase(double phase);

	virtual int getNextValue() override;

	virtual vector<double> generateTimeSeries(int) override;


};


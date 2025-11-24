#include "SinWaveGenerator.h"

SinWaveGenerator::SinWaveGenerator()
	: TimesSerieGenerator(), amplitude(1.0), frequency(1.0), phase(0.0)
{
}
SinWaveGenerator::SinWaveGenerator(int seed, double amplitude, double frequency, double phase)
	: TimesSerieGenerator(seed), amplitude(amplitude), frequency(frequency), phase(phase)
{
}
double SinWaveGenerator::getAmplitude() const
{
	return amplitude;
}
void SinWaveGenerator::setAmplitude(double amplitude)
{
	this->amplitude = amplitude;
}
double SinWaveGenerator::getFrequency() const
{
	return frequency;
}
void SinWaveGenerator::setFrequency(double frequency)
{
	this->frequency = frequency;
}
double SinWaveGenerator::getPhase() const
{
	return phase;
}
void SinWaveGenerator::setPhase(double phase)
{
	this->phase = phase;
}
int SinWaveGenerator::getNextValue()
{
	double value = amplitude * sin(frequency * getSeed() + phase);

	return value;
}

vector<double> SinWaveGenerator::generateTimeSeries(int n)
{
	vector<double> series;
	for (int i = 0; i++ < n; )
	{
		series.push_back(this->getNextValue());
	}
	return series;
}
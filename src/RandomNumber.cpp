#include "RandomNumber.hpp"

std::random_device RandomNumber::s_randomDevice;
std::mt19937_64 RandomNumber::s_randomEngine(s_randomDevice());
std::uniform_real_distribution<double> RandomNumber::s_uniformDist(0, 1);

void RandomNumber::seed(int seed)
{
    s_randomEngine.seed(seed);
}

double RandomNumber::getRandomDouble(double min, double max)
{
    return s_uniformDist(s_randomEngine) * (max - min) + min;
}



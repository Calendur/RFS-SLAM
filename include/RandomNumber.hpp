#pragma once

#include <random>

class RandomNumber
{
  public:
    static void seed(int seed);
    static double getRandomDouble(double min = 0.0, double max = 1.0);

    RandomNumber() = delete;
  private:
    static std::random_device s_randomDevice;
    static std::mt19937_64 s_randomEngine;
    static std::uniform_real_distribution<double> s_uniformDist;
};

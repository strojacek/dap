#include <iostream>
#include <random>

/**
 * @brief Contains utility methods to create random numbers.
 */
class RandomNumbersGenerator {
private:
    /// The underlying random number generator from std::random_device
    static std::random_device rd;
    static std::mt19937 randomNumberGenerator;

public:
    /**
     * Generates a random double precision floating point number
     *
     * @param minimalValue The minimal value
     * @param maximumValue The maximum value
     * @return The generated random number
     */
    static double doubleRandomWithinRange(double minimalValue, double maximumValue) {
        std::uniform_real_distribution<double> distribution(minimalValue, maximumValue);
        return distribution(randomNumberGenerator);
    }
};

// Static member initialization
std::random_device RandomNumbersGenerator::rd;
std::mt19937 RandomNumbersGenerator::randomNumberGenerator(RandomNumbersGenerator::rd());


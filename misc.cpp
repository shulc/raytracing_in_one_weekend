//
// Created by Alexander Shagarov on 10/01/2022.
//

#include "misc.h"

#include <random>

double randomDouble() {
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}


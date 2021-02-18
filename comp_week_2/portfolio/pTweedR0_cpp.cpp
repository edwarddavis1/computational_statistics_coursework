#include <Rcpp.h>
#include <iostream>

// [[Rcpp::export(name = "pTweedR0_cpp")]]
double pTweedR0_cpp_I(double y, double mu, double phi, double p, double eps=1E-17 bool log)
{
    // Get param lambda, gamma and alpha to be used in gamma and poisson distribution
    double la{pow(mu, 2-p) / (phi * (2-p))};

    // Mode of Poisson is at k = floor(lambda). 
    // If mode is 0, we start from 1 instead.
    double k0{std::max(floor(la), 1)};

    // Poisson density at its mode
    mxlpP = 
}

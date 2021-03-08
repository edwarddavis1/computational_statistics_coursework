#include <cmath>
#include <cstdlib>
#include <iostream>

// Random number between 0 and 1
double rand_one()
{
    return std::rand() / (RAND_MAX + 1.0);
}

int main(int argc, const char **argv)
{
    // n inside and outside circle
    int n_inside = 0;
    int n_outside = 0;

    #pragma omp parallel
    {
        int pvt_n_inside = 0;
        int pvt_n_outside = 0;

        // Define parallel loop
        #pragma omp for
        for (int i=0; i<10000000; ++i)
        {
            double x = (2*rand_one()) - 1;
            double y = (2*rand_one()) - 1;

            double r = sqrt( x*x + y*y );

            if (r < 1.0)
            {
                ++pvt_n_inside;
            }
            else
            {
                ++pvt_n_outside;
            }
        }

        // Critical section to make sure that each evaluation is added correctly
        #pragma omp critical
        {
            n_inside += pvt_n_inside;
            n_outside += pvt_n_outside;
        }
    }

    double pi = (4.0 * n_inside) / (n_inside + n_outside);

    std::cout << "The estimated value of pi is " << pi << std::endl;

    return 0;
}
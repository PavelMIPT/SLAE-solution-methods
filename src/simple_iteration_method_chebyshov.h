#include "Dense_matrix.h"
#include "methods_for_vectors.h"
#include <cmath>

// алгоритм простой итерации
std::vector<double> chebyshov_Simple_iteration_method(Dense_Matrix & A, const std::vector<double> & x, const std::vector<double> & b, double tolerance, double lmax, double lmin)
{
    auto x0 = x;
    unsigned int k = 1;
    double tau = 2 / ((lmin + lmax) + (lmax - lmin) * cos(M_PI * (2 * k - 1) / 2));
    auto x1 = x0 - tau * (A.Multiplicate_column(x) - b);
    //std::cout << Norma(x1 - x0);
    while (Norma(x1 - x0) > tolerance)
    {
        
        x0 = x1;
        std::cout << log(Norma(A.Multiplicate_column(x0) - b));
        std::cout << " ";
        x1 = x1 - A.Multiplicate_column(x1) * tau + b * tau;
        tau = 2 / ((lmin + lmax) + (lmax - lmin) * cos(M_PI * (2 * k - 1) / 2 * 8));
        //std::cout << Norma(x1 - x0);
    }
    
    return x1;

};
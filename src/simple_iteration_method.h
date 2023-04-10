#include "Dense_matrix.h"
#include "methods_for_vectors.h"
#include <cmath>

// алгоритм простой итерации
std::vector<double> Simple_iteration_method(Dense_Matrix & A, const std::vector<double> & x, const std::vector<double> & b,  const double  tau, const double tolerance){
    auto x0 = x;
    auto x1 = x0 - tau * (A.Multiplicate_column(x) - b);
    //std::cout << Norma(x1 - x0);
    while (Norma(x1 - x0) > tolerance){
        x0 = x1;
        std::cout << log(Norma(A.Multiplicate_column(x0) - b));
        std::cout << " ";
        x1 = x1 - A.Multiplicate_column(x1) * tau + b * tau;
        //std::cout << Norma(x1 - x0);
    }
    
    return x1;

};
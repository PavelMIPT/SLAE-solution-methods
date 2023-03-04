#include "Dense_matrix.h"
#include "methods_for_vector.h"

// алгоритм простой итерации
std::vector<double> Simple_iteration_method(Dense_Matrix & A, const std::vector<double> & x, const std::vector<double> & b,  const double  tau, const double tolerance){
    auto x0 = x;
    auto x1 = x0 - (A.Multiplicate_column(x) - b);
    while (Norma(x1 - x0) < tolerance){
        x0 = x1;
        x1 = x1 - A.Multiplicate_column(x1) * tau + b * tau;
    }
    
    return x1;

};


    

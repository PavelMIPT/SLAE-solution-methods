#include <iostream>
#include "simple_iteration_method_chebyshov.h"
#include <cmath>


std::ostream& operator<< (std::ostream &os, const std::vector<double>  &v)
{
    for (auto i : v)
    {
        os << i << " ";
    }
    return os;
}


int main(){
    double lmax = 103.27;
    double tau = 1 / lmax;
    std::vector<double> c(289);
    std::vector<double> x0(289);

    for (auto i = 0; i < c.size(); ++i)
    {
        c[i] = 3;
        x0[i] = 0;
    }
    std::vector<double> A0(289 * 289);
    for (auto i = 0; i < A0.size(); ++i)
    {
        if (i % 290 == 0){
            A0[i] = 56;
            if (i != 289 * 289 - 1)
            {
                A0[i + 1] = 12;
            }
            
            if (i != 0) 
            {
                A0[i - 1] = 12;
            }
            if (i <= 289 * 289 - 289 * 17 - 1){
                A0[i + 17] = 12;
                A0[i + 289 * 17] = 12;
            }   
        }
    }
    // 1 - 1)
    Dense_Matrix A(A0, 289, 289);
    double tolerance = 10e-13;
    //Simple_iteration_method(A, x0, c, tau, tolerance);
    
    // 1 - 2)
    double lmin = 8.73;
    double tau_opt = 2 / (lmax + lmin);
    //Simple_iteration_method(A, x0, c, tau_opt, tolerance);

    // 1 - 3)
    chebyshov_Simple_iteration_method(A, x0, c, tolerance, lmax, lmin);

    return 0;
}
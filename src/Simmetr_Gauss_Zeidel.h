#include "LUD_decomposition.h"
#include "methods_for_vectors.h"
#include <cmath>
#pragma once

std::vector<double> Simm_Gauss_Zeidel(const Dense_Matrix & A, const std::vector<double> & b, std::vector<double> x0, const double & tolerance)
{
    std::vector<double> X(A.get_n());
    while (Norma(A.Multiplicate_column(X) - b) > tolerance)
    {
        for (size_t i = 1; i < A.get_n() + 1; ++i)
        {
            // Xi+0.5
            auto X_tmp1 =  b[i - 1] / A.get_element(i - 1, i - 1);
            for (size_t j = 1; j < i; ++j)
            {
                X_tmp1 -= A.get_element(i - 1, j - 1) * X[j - 1] / A.get_element(i - 1, i - 1);
            }
            for (size_t j = i + 1; j < A.get_n() + 1; ++j)
            {
                X_tmp1 -= A.get_element(i - 1, j - 1) * x0[j - 1] / A.get_element(i - 1, i - 1);
            }
            x0 = X;

            // Xi+1
            auto X_tmp2 =  b[i - 1] / A.get_element(i - 1, i - 1);
            for (size_t j = 1; j < i; ++j)
            {
                X_tmp2 -= A.get_element(i - 1, j - 1) * X[j - 1] / A.get_element(i - 1, i - 1);
            }
            for (size_t j = i + 1; j < A.get_n() + 1; ++j)
            {
                X_tmp2 -= A.get_element(i - 1, j - 1) * x0[j - 1] / A.get_element(i - 1, i - 1);
            }

            X[i - 1] = X_tmp2;
            
        }
        //std::cout << log(Norma(A.Multiplicate_column(X) - b)); для 2 кр
        //std::cout << " ";
    }
    return X;

}

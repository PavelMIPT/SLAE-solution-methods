#include "Dense_matrix.h"
#include "LUD_decomposition.h"
#include "methods_for_vectors.h"
#include <iostream>
#include <cmath>


std::vector<double> Gauss_Zeidel_X (const Dense_Matrix &A, const std::vector<double> &b, std::vector<double> x0, const double & tolerance)
{
    std::vector<double> X(A.get_n());
    while (Norma(A.Multiplicate_column(X) - b) > tolerance)
    {
        for (size_t i = 1; i < A.get_n() + 1; ++i)
        {
            auto X_tmp =  b[i - 1] / A.get_element(i - 1, i - 1);
            for (size_t j = 1; j < i; ++j)
            {
                X_tmp -= A.get_element(i - 1, j - 1) * X[j - 1] / A.get_element(i - 1, i - 1);
            }
            for (size_t j = i + 1; j < A.get_n() + 1; ++j)
            {
                X_tmp -= A.get_element(i - 1, j - 1) * x0[j - 1] / A.get_element(i - 1, i - 1);
            }
            x0 = X;
            X[i - 1] = X_tmp;
            
        }
    }
    return X;
}


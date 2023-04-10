#include "LUD_decomposition.h"
#include "methods_for_vectors.h"
#pragma once

std::vector<double> Simm_Gauss_Zeidel(const Dense_Matrix & A, const std::vector<double> & b, std::vector<double> X0, const double & tolerance){
    auto L = L_decomposition(A);
    auto U = U_decomposition(A);
    auto D = D_decomposition(A);
    auto rev_DL = Reverse_matrix(D + L);
    auto X1 = rev_DL.Multiplicate_column((b - U.Multiplicate_column(X0)));
    while (Norma(X1 - X0) > tolerance)
    {
        //std::cout << log(Norma(A.Multiplicate_column(X0) - b));
        //std::cout << " ";
        X0 = rev_DL.Multiplicate_column((b - U.Multiplicate_column(X0)));
        X1 = rev_DL.Multiplicate_column((b - L.Multiplicate_column(X0)));

    }
    return X1;

};
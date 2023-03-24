#include "LUD_decomposition.h"

std::vector<double> Gauss_Zeidel(const Dense_Matrix & A, const std::vector<double> & b, std::vector<double> X0, const double & tolerance){
    auto L = L_decomposition(A);
    auto U = U_decomposition(A);
    auto D = D_decomposition(A);
    auto rev_DL = Reverse_matrix(D + L);
    auto X1 = rev_DL.Multiplicate_column((b - U.Multiplicate_column(X0)));
    while (vector_norm(X1 - X0) < tolerance)
    {
        X0 = X1;
        X1 = rev_DL.Multiplicate_column((b - U.Multiplicate_column(X0)));
    }
    return X1;

};

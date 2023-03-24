#include <iostream>
#include "LUD_decomposition.h"


std::vector<double> Yakobi (const Dense_Matrix &A, const std::vector<double> &b, std::vector<double> x0, const double & tolerance)
{
    auto L = L_decomposition(A);
    auto U = U_decomposition(A);
    auto D = D_decomposition(A);
    auto rev_D = Reverse_matrix(D);
    auto x1 = rev_D.Multiplicate_column((b - (L + U).Multiplicate_column(x0)));
    
    while (vector_norm(x1 - x0) < tolerance)
    {
        x0 = x1;
        x1 = rev_D.Multiplicate_column((b - (L + U).Multiplicate_column(x0)));
    }
    
    return x1;
}

#include "Dense_matrix.h"
#include <cmath>
#pragma once

Dense_Matrix L_decomposition (const Dense_Matrix & A)
{
    std::vector <double> l(A.get_size());
    for (size_t i = 0; i < A.get_n(); ++i){
         for (size_t j = 0; j < A.get_m(); ++j){
            if (i > j){
                l[i * A.get_n() + j] = A.get_A()[i * A.get_n() + j];
            }
            
         }
    }
    Dense_Matrix L (l, A.get_n(), A.get_m());
    return L;
    
}

Dense_Matrix U_decomposition (const Dense_Matrix & A)
{
    std::vector <double> l(A.get_size());
    for (size_t i = 0; i < A.get_n(); ++i){
         for (size_t j = 0; j < A.get_m(); ++j){
            if (i < j){
                l[i * A.get_n() + j] = A.get_A()[i * A.get_n() + j];
            }
            
         }
    }
    Dense_Matrix L (l, A.get_n(), A.get_m());
    return L;
    
}

Dense_Matrix D_decomposition (const Dense_Matrix & A)
{
    std::vector <double> l(A.get_size());
    for (size_t i = 0; i < A.get_n(); ++i){
         for (size_t j = 0; j < A.get_m(); ++j){
            if (i == j){
                l[i * A.get_n() + j] = A.get_A()[i * A.get_n() + j];
            }
            
         }
    }
    Dense_Matrix L (l, A.get_n(), A.get_m());
    return L;
    
}


// get reverse matrix from diagonal matrix D
Dense_Matrix Reverse_matrix (const Dense_Matrix & D)
{
    std::vector<double> rev(D.get_size());
    for (size_t i = 0; i < D.get_n(); ++i){
        for (size_t j = 0; j < D.get_m(); ++j){
            if (i == j){
                rev[i * D.get_n() + j] = 1 / (D.get_A()[i * D.get_n() + j]);
            }
        }
    }
    Dense_Matrix rev_D(rev, D.get_n(), D.get_m());
    return rev_D;

}

std::vector<double> operator- (const std::vector<double> & v1, const std::vector<double> &v2)
{
    std::vector<double> res(v1.size());
    for (size_t i = 0; i < v1.size(); ++i){
        res[i] = v1[i] - v2[i];
    }
    return res;
}

double vector_norm(const std::vector<double> & v){
    double norm = 0;
    for (size_t i = 0; i < v.size(); ++i){
        norm += std::sqrt(v[i] * v[i]);
    }
    return norm;
}

std::ostream& operator<< (std::ostream &os, const std::vector<double>  &v)
{
    for (auto i : v)
    {
        os << i << " ";
    }
    return os;
}
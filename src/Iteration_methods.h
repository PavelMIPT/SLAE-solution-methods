#include <iostream>
#include "CSR_new.h"
#include "Dense_matrix.h"
#include "methods_for_vectors.h"
#pragma once

// Первая норма матрицы
double First_Norma(const CSR &A, const std::vector<double> &x, const std::vector<double> &b) \
{
    double r = 0;
    for (size_t j = 0; j < b.size(); ++j) 
    { 
        if (fabs(b[j] - A.dot(x)[j]) > r)
            r = fabs(b[j] - A.dot(x)[j]);
    }
    return r;
}

// метод Якоби (реализация на разряженной матрице)
std::vector<double> Jakobi (const CSR &A, const std::vector<double> &b, std::vector<double> x0, const double & tolerance)
{
    std::vector<double> x_0 = x0;
    std::vector<double> x1(x0.size());
    unsigned int count = 0;

    while (tolerance < First_Norma(A, x1, b)){
        for (size_t i = 0; i < A.get_count().size() - 1; ++i) {
            double sum = 0;
            double diag;
            for (size_t j = A.get_count()[i]; j < A.get_count()[i + 1]; ++j) {

                if (i == A.get_index()[j]) 
                {
                    diag = A.getValue()[j];
                } 

                else 
                {
                    sum += A.getValue()[j] * x_0[A.get_index()[j]];
                }
            }
            x_0[i] = 1 / diag * (b[i] - sum);
        }
        x1 = x_0;
    }
    return x_0;
}

// метод простой итерации (реализация на плотной матрице)
std::vector<double> Simple_iteration_method(Dense_Matrix & A, const std::vector<double> & x, const std::vector<double> & b,  const double  tau, const double tolerance){
    auto x0 = x;
    auto x1 = x0 - tau * (A.Multiplicate_column(x) - b);
    //std::cout << Norma(x1 - x0);
    while (Norma(x1 - x0) > tolerance){
        x0 = x1;
        //std::cout << log(Norma(A.Multiplicate_column(x0) - b)); // для 2 кр
        //std::cout << " ";
        x1 = x1 - A.Multiplicate_column(x1) * tau + b * tau;
        //std::cout << Norma(x1 - x0);
    }
    
    return x1;

};

// метод Гаусса — Зейделя (реализация на плотной матрице)
std::vector<double> Gauss_Zeidel (const Dense_Matrix &A, const std::vector<double> &b, std::vector<double> x0, const double & tolerance)
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

// Метод верхней релаксации - SOR
std::vector<double> SOR(const CSR &A, double tolerance, double omega, const std::vector<double> &b, const std::vector<double> &x0) 
{
    std::vector<double> x_0 = x0;
    while (First_Norma(A, x_0, b) > tolerance) {
        for (size_t i = 0; i < A.get_count().size() - 1; ++i) {
            double sum = 0;
            double diag;
            for (size_t j = A.get_count()[i]; j < A.get_count()[i + 1]; ++j) {
                // элемент находится на главной диагонали
                if (i == A.get_index()[j]) 
                {
                    diag = A.getValue()[j];
                } 

                else 
                {
                    sum += omega * A.getValue()[j] * x_0[A.get_index()[j]];
                }
            }
            x_0[i] = 1 / diag * (omega * b[i] - sum - (omega - 1) * diag * x_0[i]);
        }
    }
    return x_0;
}

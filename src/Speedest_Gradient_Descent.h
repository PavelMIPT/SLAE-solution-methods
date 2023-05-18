#include "CSR_new.h"
#include "Iteration_methods.h"
#include "methods_for_vectors.h"
#pragma once

// наискорейший градиентный спуск
std::vector<double> speedest_gradient_descent(const CSR &A, double tolerance, const std::vector<double> &b, const std::vector<double> &x_0) {
    std::vector<double> result = x_0;
    std::vector<double> r = A.dot(result) - b;
    while (First_Norma(A, result, b) > tolerance) {
        double a = scal_multiply(r, r) / (scal_multiply(r, A.dot(r)));
        result = result - r * a;
        r = A.dot(result) - b;
    }
    return result;
}
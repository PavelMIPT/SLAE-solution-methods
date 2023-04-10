#include <vector>
#include <cmath>
#include "Dense_matrix.h"

std::vector<double> operator+ (const std::vector<double> & v1, const std::vector<double> & v2)
{
    std::vector<double> res (v1.size());
    for (auto i = 0; i < v1.size(); ++i)
    {
        res[i] = v1[i] + v2[i];
    }
    return res;
}

std::vector<double> operator- (const std::vector<double> & v1, const std::vector<double> & v2)
{
    std::vector<double> res (v1.size());
    for (auto i = 0; i < v1.size(); ++i)
    {
        res[i] = v1[i] - v2[i];
    }
    return res;
}

std::vector<double> operator* (const std::vector<double> & v, const double tau)
{
    std::vector<double> res (v.size());
    for (auto i = 0; i < v.size(); ++i)
    {
        res[i] = v[i] * tau;
    }
    return res;

}

std::vector<double> operator* (const double tau, const std::vector<double> & v)
{
    std::vector<double> res (v.size());
    for (auto i = 0; i < v.size(); ++i)
    {
        res[i] = tau * v[i];
    }
    return res;

}


std::vector<double> operator * (const Dense_Matrix &A)
{
    std::vector <double> res(A.get_m());
    

}

double Norma(const std::vector<double> & v)
{
    double sum_kv = 0;
    for (auto i = 0; i < v.size(); ++i)
    {
        sum_kv += v[i] * v[i];
    }
    return sqrt (sum_kv);
}
#include <iostream>
#include "CSR.h"
#include <cassert>

int main(){
    //not null quadratic matrix
    SCR m1({{0, 0, 1}, {1, 0, 2}, {1, 1, 4}, {1, 2, 2}}, 3, 3);
    assert(m1.Get_a_value(0, 0) == 1.0);
    std::vector<double> v = {5, 8, 4};
    std::vector<double> s = m1.Vector_multiply({1, 2, 1});
    assert(s == v);
    std::cout << std::endl;

    //null quadratic matrix
    SCR m2({}, 3, 3);
    assert(m2.Get_a_value(0, 0) == 0.0);
    std::vector<double> v1 = {0, 0, 0};
    std::vector<double> s1 = m2.Vector_multiply({1, 2, 1});
    assert(s1 == v1);
    std::cout << std::endl;

    //not null and not quadratic matrix
    SCR m3({{0, 0, 1}, {1, 1, 2}, {2, 2, 3}}, 3, 3);
    assert(m3.Get_a_value(0, 0) == 1);
    std::vector<double> v2 = {1, 2, 3};
    std::vector<double> s2 = m3.Vector_multiply({1, 1, 1});
    assert(s2 == v2);
    std::cout << std::endl;

    return 0;
}
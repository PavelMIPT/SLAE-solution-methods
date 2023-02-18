#include "matrix.h"
#include <cassert>
#include <vector>
#include <iostream>



int main()
{
    //All Matrices are |bi| >= |ai| + |ci|

    //single Matrices, Ok
    ThreeDiagMatrix m1(2, {0}, {1, 1}, {0}, {1, 2});
    std::vector<double> b1 = {1, 2};
    assert(m1.solve() == b1);
    
    ThreeDiagMatrix m2(3, {0, 0}, {1, 1, 1}, {0, 0}, {1, 2, 2});
    std::vector<double> b2 = {1, 2, 2};
    assert(m2.solve() == b2);
    

    //not single Matrices, Ok
    ThreeDiagMatrix m3(2, {1}, {1, 1}, {0}, {1, 2});
    std::vector<double> b3 = {-1, 2};
    assert(m3.solve() == b3);
    
    ThreeDiagMatrix m4(3, {1, 1}, {1, 1, 1}, {0, 0}, {1, 1, 1});
    std::vector<double> b4 = {1, 0, 1};
    assert(m4.solve() == b4);
    
    
    //single Matrice, not ok
    std::vector<double> b5 = {0, 2};
    assert(m1.solve() == b5);

    
    return 0;
}
#include "/home/pavel/Документы/SLAE-solution-methods-main/src/Matrix.h"
#include <cassert>
#include <vector>
#include <iostream>


int main()
{
    //All Matrices are |bi| >= |ai| + |ci|

    //single Matrices, Ok
    ThreeDiagMatrix m1(2, {0, 1, 1, 0});
    std::vector<double> b1 = {1, 2};
    assert(solve(m1, b1) == b1);
    
    ThreeDiagMatrix m2(3, {0, 0, 1, 1, 1, 0, 0});
    std::vector<double> b2 = {1, 2, 2};
    assert(solve(m2, b2) == b2);
    

    //not single Matrices, Ok
    ThreeDiagMatrix m3(2, {1, 1, 1, 0});
    std::vector<double> b3 = {-1, 2};
    assert(solve(m3, {1, 2}) == b3);
    
    ThreeDiagMatrix m4(3, {1, 1, 1, 1, 1, 0, 0});
    std::vector<double> b4 = {1, 0, 1};
    assert(solve(m4, {1, 1, 1}) == b4);
    
    
    //single Matrice, not ok
    std::vector<double> b5 = {0, 2};
    assert(solve(m1, b5) == b5);

    
    return 0;
}
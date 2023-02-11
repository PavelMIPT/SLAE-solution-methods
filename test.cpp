#include <iostream>
#include "matrix.h"

int main(){
    // test1 : n = 2, A_c = {0}, A_b = {1, 1}, A_a = {0}, f_d = {1, 2}
    // X = {1, 2} 
    ThreeDiagMatrix m1(2, {0}, {1, 1}, {0}, {1, 2});
    m1.solve();
    m1.print_x();
    //OK

    std::cout << std::endl;
    //test2 : n = 5, A_c = {0, -1, 2, 4}, A_b = {2, 8, 12, 18, 10}, A_a = {-3, -5, -6, -5}, f_d = {0, 0, 0, 0, 0}
    // X = {0, 0, 0, 0, 0}
    ThreeDiagMatrix m2(5, {0, -1, 2, 4}, {2, 8, 12, 18, 10}, {-3, -5, -6, -5}, {0, 0, 0, 0, 0});
    m2.solve();
    m2.print_x();
    //Ok

    std::cout << std::endl;
    //test3 : n = 3, A_c = {0, 0}, A_b = {1, 1, 1}, A_a = {0, 0}, f_d = {3, 2, 4}
    // X = {3, 2, 4}
    ThreeDiagMatrix m3(3, {0, 0}, {1, 1, 1}, {0, 0}, {3, 2, 4});
    m3.solve();
    m3.print_x();
    //Ok

    std::cout << std::endl;
    //test4 : n = 2, A_c = {0}, A_b = {1, 2}, A_a = {1}, f_d = {1, 0}
    // X = {2, 1}
    ThreeDiagMatrix m4(2, {0}, {1, 2}, {1}, {1, 0});
    m4.solve();
    m4.print_x();
    //Ok



    return 0;
}
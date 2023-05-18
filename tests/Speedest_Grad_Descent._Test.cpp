#include "/home/pavel/Документы/SLAE-solution-methods-main/src/Speedest_Gradient_Descent.h"
#include <gtest/gtest.h>

TEST(Grad_Spusk_Test, Test1) {
    std::vector<troyka> A = {
            {0, 0, 10},
            {0, 1, 2},
            {0, 2, 1},
            {1, 0, 2},
            {1, 1, 10},
            {1, 2, 3},
            {2, 0, 1},
            {2, 1, 3},
            {2, 2, 10}
    };

    std::vector <double> H = {10, 2, 1, 2, 10, 3, 1, 3, 10};

    CSR M1(A, 3, 3);
    Dense_Matrix M2 (H, 3, 3);

    std::vector<double> b = {1, 1, 1};
    std::vector<double> x0 = {0, 0, 0};

    double tau = 0.0001;
    double tolerance = 1e-10;

    std::vector<double> mpi = Simple_iteration_method(M2, x0, b, tau, tolerance);
    std::vector<double> gaus = Gauss_Zeidel(M2, b, x0, tolerance);
    std::vector<double> gradient = speedest_gradient_descent(M1, tolerance, b, x0);

    for (size_t i = 0; i < 3; ++i) {
        ASSERT_NEAR(mpi[i], gradient[i], tolerance);
    }
    for (size_t i = 0; i < 3; ++i) {
        ASSERT_NEAR(gaus[i], gradient[i], tolerance);
    }
}

TEST(Grad, Gradient_second_test) {
    std::vector<troyka> A = {
            {0, 0, 19},
            {0, 1, 17},
            {0, 2, 3},
            {1, 0, 14},
            {1, 1, 20150},
            {1, 2, 28},
            {2, 0, 8},
            {2, 1, 39},
            {2, 2, 238}
    };
    
    std::vector <double> H = {19, 17, 3, 14, 20150, 28, 8, 39, 238};

    CSR M1(A, 3, 3);
    Dense_Matrix M2 (H, 3, 3);

    std::vector<double> b = {1, 1, 1};
    std::vector<double> x0 = {0, 0, 0};
    double tau = 0.0001;
    double tolerance = 1e-13;
    
    std::vector<double> mpi = Simple_iteration_method(M2, x0, b, tau, tolerance);
    std::vector<double> gaus = Gauss_Zeidel(M2, b, x0, tolerance);
    std::vector<double> gradient = speedest_gradient_descent(M1, tolerance, b, x0);

   for (size_t i = 0; i < 3; ++i) {
        ASSERT_NEAR(mpi[i], gradient[i], tolerance);
    }
    for (size_t i = 0; i < 3; ++i) {
        ASSERT_NEAR(gaus[i], gradient[i], tolerance);
    }
}



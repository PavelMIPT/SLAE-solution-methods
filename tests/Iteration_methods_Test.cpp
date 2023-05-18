#include "/home/pavel/Документы/SLAE-solution-methods-main/src/Iteration_methods.h"
#include "/home/pavel/Документы/SLAE-solution-methods-main/src/Simmetr_Gauss_Zeidel.h"
#include <gtest/gtest.h>


TEST(Iter_methods, Test1) {
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
    std::vector<double> H = {10, 2, 1, 2, 10, 3, 1, 3, 10};
    CSR M1 = CSR(A, 3, 3);
    Dense_Matrix M2 (H, 3, 3);

    std::vector<double> b = {1, 1, 1};
    std::vector<double> x0 = {0, 0, 0};

    double tau = 0.001;
    double tolerance = 1e-10;
    std::vector<double> mpi = Simple_iteration_method(M2, x0, b, tau, tolerance);
    std::vector<double> jakobi = Jakobi(M1, b, x0, tolerance);

    for (size_t i = 0; i < 3; ++i) {
        ASSERT_NEAR(mpi[i], jakobi[i], 1e-10);
    }
}

TEST(Iter_methods, Test2) {
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
    std::vector<double> H = {19, 17, 3, 14, 20150, 28, 8, 39, 238};
    CSR M1 = CSR(A, 3, 3);
    Dense_Matrix M2 (H, 3, 3);

    std::vector<double> b = {1, 2, 1};
    std::vector<double> x0 = {0, 0, 0};

    double tau = 0.001;
    double tolerance = 1e-10;
    std::vector<double> mpi = Simple_iteration_method(M2, x0, b, tau, tolerance);
    std::vector<double> jakobi = Jakobi(M1, b, x0, tolerance);

    for (size_t i = 0; i < 3; ++i) {
        ASSERT_NEAR(mpi[i], jakobi[i], 1e-10);
    }
}

TEST(Iter_methods, Test3) {
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
    double tolerance = 1e-12;
    double omega = 0.5;

    std::vector<double> sor = SOR(M1, tolerance, omega, b, x0);
    std::vector<double> mpi = Simple_iteration_method(M2, x0, b, tau, tolerance);

    for (size_t i = 0; i < mpi.size(); ++i) {
        ASSERT_NEAR(sor[i], mpi[i], 1e-12);
    }
}

TEST(Iter_methods, Test4) {
    std::vector <double> H = {10, 2, 1, 2, 10, 3, 1, 3, 10};

    Dense_Matrix M2 (H, 3, 3);

    std::vector<double> b = {1, 1, 1};
    std::vector<double> x0 = {0, 0, 0};

    double tau = 0.001;
    double tolerance = 1e-10;

    std::vector<double> gaus = Gauss_Zeidel(M2, b, x0, tolerance);
    std::vector<double> sim_gaus = Simm_Gauss_Zeidel(M2, b, x0, tolerance);

    for (long i = 0; i < 3; i++) {
        ASSERT_NEAR(gaus[i], sim_gaus[i], tolerance);
    }
}

TEST(Iter_methods, Test5) {
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
    double tolerance = 1e-12;
    double omega = 0.5;

    std::vector<double> sor = Gauss_Zeidel(M2, b, x0, tau);
    std::vector<double> mpi = Simple_iteration_method(M2, x0, b, tau, tolerance);

    for (size_t i = 0; i < mpi.size(); ++i) {
        ASSERT_NEAR(sor[i], mpi[i], 1e-12);
    }
}

// int main(){
//     std::vector<troyka> A = {
//             {0, 0, 10},
//             {0, 1, 2},
//             {0, 2, 1},
//             {1, 0, 2},
//             {1, 1, 10},
//             {1, 2, 3},
//             {2, 0, 1},
//             {2, 1, 3},
//             {2, 2, 10}
//     };
//     std::vector <double> H = {10, 2, 1, 2, 10, 3, 1, 3, 10};
//     CSR M1(A, 3, 3);
//     Dense_Matrix M2 (H, 3, 3);
//     std::vector<double> b = {1, 1, 1};
//     std::vector<double> x0 = {0, 0, 0};
//     double tau = 0.0001;
//     double tolerance = 1e-12;
//     double omega = 0.5;

//     std::vector<double> gaus = Gauss_Zeidel(M2, b, x0, tolerance);
//     std::vector<double> sim_gaus = Simm_Gauss_Zeidel(M2, b, x0, tolerance);

//     std::cout << gaus;
//     std::cout << std::endl;
//     std::cout << sim_gaus;
//     return 0;
// }
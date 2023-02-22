#include <vector>
#include <ostream>
#include <iostream>



class ThreeDiagMatrix{
    public:
        unsigned int size;
        std::vector<double> A0;
        std::vector<double> C, B, A;
        ThreeDiagMatrix(unsigned int n, const std::vector <double>& A_1){
            size = n;
            C.resize(size - 1);
            B.resize(size);
            A.resize(size - 1);
            A0 = A_1;
            for (int i = 0; i < size - 1; ++i){
                C[i] = A0[i];
            }
            for (int i = 0; i < size; ++i){
                B[i] = A0[size - 1 + i];
            }
            for (int i = 0; i < size - 1; ++i){
                A[i] = A0[2*size - 1 + i];
            }
        }
        
};

std::vector<double> solve(const ThreeDiagMatrix &M, const std::vector<double> & f_d){
    std::vector <double> P(f_d.size()), Q(f_d.size()), X(f_d.size());
	P[0] = -M.C[0] / M.B[0];
	Q[0] = f_d[0] / M.B[0];
	for (int i = 1; i < M.size; ++i){
		P[i] = -M.C[i - 1] / (M.A[i - 1] * P[i - 1] + M.B[i - 1]);
		Q[i] = (f_d[i - 1] - M.A[i - 1] * Q[i - 1]) / (M.A[i - 1] * P[i - 1] + M.B[i - 1]);
	}
    X.back() = (f_d.back() - M.A.back() * Q.back()) / (M.A.back() * P.back() + M.B.back()); 
	for(int i = f_d.size() - 2; i >= 0; i--){
		X[i] = P[i + 1]*X[i + 1] + Q[i + 1];
	}
    return X;
}

std::ostream& operator<<(std::ostream &os, const std::vector<double>  & v){
    for(auto i : v){
        os << i << std::endl;
    }
    return os;
}
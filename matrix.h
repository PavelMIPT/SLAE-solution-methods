#include <iostream>
#include <vector>


class ThreeDiagMatrix{
    protected:
        unsigned int size;
        std::vector<double> A_c, A_b, A_a, f_d, res;
    public:
        ThreeDiagMatrix(unsigned int n, std::vector <double> A_c1, std::vector <double> A_b1, std::vector <double> A_a1, std::vector <double> f_d1){
            size = n;
            A_c = A_c1;
            A_b = A_b1;
            A_a = A_a1;
            f_d = f_d1;

        }
        ~ThreeDiagMatrix(){}
        void solve(){
            std::vector <double> P(size), Q(size), X(size);
	        P[0] = -A_c[0] / A_b[0];
	        Q[0] = f_d[0] / A_b[0];
	        for (int i = 1; i < size; i++){
		        P[i] = -A_c[i - 1] / (A_a[i - 1] * P[i - 1] + A_b[i - 1]);
		        Q[i] = (f_d[i - 1] - A_a[i - 1] * Q[i - 1]) / (A_a[i - 1] * P[i - 1] + A_b[i - 1]);
	        }
            X[size - 1] = (f_d[size - 1] - A_a[size - 1] * Q[size - 1]) / (A_a[size - 1] * P[size - 1] + A_b[size - 1]); 
	        for(int i = size - 2; i >= 0; i--){
		        X[i] = P[i + 1]*X[i + 1] + Q[i + 1];
	        }
            res = X;
        }
        void print_x(){
            std::cout << "vector x" << std::endl;
            for (int i = 0; i < size; i++){
                std::cout << res[i] << std::endl;
            }
        }
};

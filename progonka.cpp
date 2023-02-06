#include <iostream>
#include <vector>

template<class Type>
void pq(std::vector<Type> &A_c, std::vector<Type> &A_b, std::vector<Type> &A_a, std::vector<Type> &f_d, std::vector<Type> &P, std::vector<Type> &Q){
	P[0] = -A_c[0] / A_b[0];
	Q[0] = f_d[0] / A_b[0];
	for (int i = 1; i < A_b.size(); i++){
		P[i] = -A_c[i - 1] / (A_a[i - 1] * P[i - 1] + A_b[i - 1]);
		Q[i] = (f_d[i - 1] - A_a[i - 1] * Q[i - 1]) / (A_a[i - 1] * P[i - 1] + A_b[i - 1]);
			
	}

}
template<class Type>
void x(std::vector<Type> &A_a, std::vector<Type> &A_b, std::vector<Type> &f_d, std::vector<Type> &P, std::vector<Type> &Q, std::vector<Type> &X){
	X[X.size() - 1] = (f_d[f_d.size() - 1] - A_a[A_a.size() - 1] * Q[Q.size() - 1]) / (A_a[A_a.size() - 1] * P[P.size() - 1] + A_b[A_b.size() - 1]); 
	for(int i = X.size() - 2; i >= 0; i--){
		X[i] = P[i + 1]*X[i + 1] + Q[i + 1];
	}

}



int main(){
	std::cout << "Enter matrix size" << std::endl;
	unsigned long long int n;
	std::cin >> n;
	std::cout << std::endl;
	std::vector<double> A_c(n - 1), A_b(n), A_a(n - 1), f_d(n);
	std::cout << "A_c" << std::endl;
	for (int i = 0; i < n - 1; i++){
		double tmp;
		std::cin >> tmp;
		A_c[i] = tmp;
	}
	std::cout << std::endl;
	std::cout << "A_b" << std::endl;
	for (int i = 0; i < n; i++){
		double tmp;
		std::cin >> tmp;
		A_b[i] = tmp;
	}
	std::cout << std::endl;
	std::cout << "A_a" << std::endl;
	for (int i = 0; i < n - 1; i++){
		double tmp;
		std::cin >> tmp;
		A_a[i] = tmp;
	}
	std::cout << std::endl;
	std::cout << "f_d" << std::endl;
	for (int i = 0; i < n; i++){
		double tmp;
		std::cin >> tmp;
		f_d[i] = tmp;
	}	
	std::vector<double> P(n), Q(n), X(n);
	pq(A_c, A_b, A_a, f_d, P, Q);	
	x(A_a, A_b, f_d, P, Q, X);


	std::cout << std::endl;
	for (int i = 0; i < A.size(); i++){
		std::cout << A[i] << std::endl;
	}

	std::cout << std::endl;
	std::cout << "vector X" << std::endl;


	for (int i = 0; i < X.size(); i++){
		std::cout << X[i] << std::endl;
	}
	return 0;
}


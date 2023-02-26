#include <vector>
#include <iostream>
#pragma once

class Dense_Matrix{   
    public:
        // размер матрицы, m - размер строки, n - размер столбца
        unsigned int m, n;
        std::vector<double> A;
        Dense_Matrix(std::vector<double>  A0, unsigned int x, unsigned int y): A(A0), m(x), n(y){}
        Dense_Matrix(const Dense_Matrix& c) = default;

        // метод умножения матрицы(m, n) на вектор - столбец (m)
        std::vector<double> Multiplicate_column(const std::vector<double> & a);

        // метод умножения матрицы(m, n) на вектор - строку (n)
        std::vector<double> Multiplicate_line (const std::vector<double> & a);

        // вернуть столбец матрицы(m, n) с номером i
        std::vector<double> Get_column (size_t i);

        //оператор умножения матрицы(n, n) на матрицу(n. n) за (o(n^3))- можно лучше ?
        Dense_Matrix operator * (const Dense_Matrix & a);

        //оператор вычитания матрицы(n, n) из матрицы (n. n) 
        Dense_Matrix operator - (const Dense_Matrix & a);

        //оператор умножения матрицы(n. n) на число
        Dense_Matrix operator * (double k);

};
std::vector<double> Dense_Matrix :: Multiplicate_column(const std::vector<double> & a){
    std::vector<double> y (this->n, 0);
    for (size_t j = 0; j < this->A.size()/a.size(); ++j) {
        double tmp = 0;
        for(unsigned int i = 0; i < a.size(); ++i){
            tmp += this->A[a.size()*j + i] * a[i];
        }
        y[j] = tmp;
    }
    
    return y;
}

std::vector<double> Dense_Matrix :: Multiplicate_line (const std::vector<double> &a){
    std::vector<double> b(this->A.size() * a.size());
    for (size_t i = 0; i < a.size(); ++i){
        for(size_t j = 0; j < a.size(); ++j){
            b[a.size() * i + j] = this->A[i] * a[j];
        }
    }
    return b;

}

std::vector<double> Dense_Matrix :: Get_column (size_t i){
    std::vector<double> v(this->n);
    for(size_t j = i * this->n; j < i * this->n + this->n; ++j){
        v[j - i * this->n] = this->A[j];
    }
    return v;
}


// умножаем на матрицу a
Dense_Matrix Dense_Matrix :: operator * (const Dense_Matrix & a){
    std::vector <double> res(a.A.size());
    for (size_t i = 0; i < a.n; ++i){
        for (size_t j = 0; j < this->n; ++j){
            for (size_t k = 0; k < this->n; ++k){
                res[i*a.n + j] += this->A[i*a.n + k] * a.A[k*a.n + j];
            }
        }
    }
    Dense_Matrix Res(res, a.n, a.n);
    return Res;

}

//вычитаем матрицу a из исходной матрицы такого же размера
Dense_Matrix Dense_Matrix :: operator - (const Dense_Matrix & a){
    std::vector <double> res(a.A.size());
    for (size_t i = 0; i < a.n; ++i){
        for (size_t j = 0; j < a.n; ++j){
            res[a.n * i + j] = this->A[a.n * i + j] - a.A[a.n * i + j];
        }
    }
    Dense_Matrix Res (res, a.n, a.n);
    return Res;
}

Dense_Matrix Dense_Matrix :: operator * (double k){
    std::vector <double> res(this->A.size());
    for (size_t i = 0; i < this->A.size(); ++i){
        res[i] = this->A[i] * k;
    }
    Dense_Matrix Res (res, this->n, this->n);
    return Res;
}

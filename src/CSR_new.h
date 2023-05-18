#include <vector>
#include <iostream>
#pragma once

struct troyka {
    unsigned int i;
    unsigned int j;
    double v;
};

class CSR {
private:
    std::vector<double> vector_of_values_;
    std::vector<unsigned int> colomn_index_vector_;
    std::vector<unsigned int> counts_vector_;
public:
    CSR(const std::vector<troyka> & matrix_, unsigned int n, unsigned int m) // Матрица приходит уже отсортированная
    { 
        std::vector<double> vector_of_values;
        std::vector<unsigned int> colomn_index_vector;
        std::vector<unsigned int> counts_vector;

        counts_vector.resize(n + 1);
        counts_vector[0] = 0;

        for (size_t i = 0; i < matrix_.size(); ++i) 
        {
            vector_of_values.push_back(matrix_[i].v);  
            colomn_index_vector.push_back(matrix_[i].j);
            counts_vector[matrix_[i].i + 1] += 1;
        }

        for (size_t i = 1; i < counts_vector.size(); ++i) 
        {
            counts_vector[i] += counts_vector[i - 1];

        }

        vector_of_values_ = vector_of_values;
        colomn_index_vector_ = colomn_index_vector;
        counts_vector_ = counts_vector;
    }

    const std::vector<double> &getValue() const {
        return this->vector_of_values_;
    }

    const std::vector<unsigned int> &get_index() const {
        return colomn_index_vector_;
    }

    const std::vector<unsigned int> &get_count() const {
        return counts_vector_;
    }

    //Умножение на вектор
    std::vector<double> dot(const std::vector<double> &X) const {
        std::vector<double> x(X.size(), 0);
        for (size_t i = 0; i < counts_vector_.size() - 1; ++i) {
            for (size_t j = counts_vector_[i]; j < counts_vector_[i + 1]; ++j) {
                x[i] += vector_of_values_[j] * X[colomn_index_vector_[j]];
            }
        }
        return x;
    }

    //взятие по индексу
    double operator()(unsigned int i, unsigned int j) const {
        for (auto k = counts_vector_[i]; k < counts_vector_[i + 1]; ++k) {
            if (colomn_index_vector_[k] == j)
                return vector_of_values_[k];
        }
        return 0;
    }
};
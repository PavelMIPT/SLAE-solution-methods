#include <iostream>
#include<vector>
#include <ostream>


struct troyka{
    unsigned int i, j;
    double a;
    //DOC(unsigned int x, unsigned int y, double z):i(x), j(y), a(z){}
};

class SCR{
    public:
        std::vector<double> v1, v2, v3;
        std::vector<double> tmp;
        unsigned int x, y;
        SCR(const std::vector<troyka> & v, unsigned int n, unsigned int m){
            v3.push_back(0);
            x = n;
            y = m;
            for(const auto &i : v){
                v1.push_back(i.a);
                v2.push_back(i.i);
            }
            unsigned int counter = 1;
            for(unsigned int i = 0; i < v.size(); ++i){
                if (v[i].j== v[i + 1].j){
                    counter += 1;
                }
                else{
                    v3.push_back(counter);
                    counter += 1;
                }
            }
            unsigned int c = 0;
            for (unsigned int i = 1; i < v3.size(); ++i){
                if (v3[i] != 0){
                    for (unsigned int j = 0; j < (v3[i] - v3[i - 1]); ++j){
                        tmp.push_back(c);
                    }
                }
                c+= 1;
            }

        }

        //find Matrix element - v1[i][j] or 0
        double Get_a_value(unsigned int i, unsigned int j){
            for (unsigned int k = 0; k < v2.size(); ++k){
                if (j == v2[k] && i == tmp[k]){
                    return v1[k];
                }

            }
        }

        //multiply Matrix to vector
        std::vector <double> Vector_multiply(const std::vector<double> & a){
            std::vector<double> b;
            double tmp = 0;
            for(unsigned int i = 0; i < y; ++i){
                for (unsigned int j = 0; j < x; ++j){
                    tmp += Get_a_value(i, j) * a[j];
                }
                b.push_back(tmp);
                tmp = 0;
            }
            return b;

        }

        

};


std::ostream& operator<<(std::ostream &os, const std::vector<double>  & v){
    for(auto i : v){
        os << i << " ";
    }
    return os;
}

 
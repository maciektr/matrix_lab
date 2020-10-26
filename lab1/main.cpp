#include<bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define ALL(X) X.begin(),X.end()
#define SZ(X) X.size()
#define BG(X) X.begin()
#define ED(X) X.end()

using mel = double;
using msize = int;
typedef vector<mel> vi;
typedef vector<vi> vvi;
typedef pair<msize, msize> pii;

void pvec(const vvi &vec){
    for(vi v : vec){
        for(mel x : v)
            cout<<x<<' ';
        cout<<endl;
    }
}


class Matrix{
    private:
        vvi matrix;
        msize width, height;

        static vi sum_vectors(const vi &a, const vi &b){
            assert(SZ(a) == SZ(b));
            vi res;
            res.reserve(SZ(a));
            transform(BG(a), ED(a), BG(b), back_inserter(res), plus<mel>());
            return res;
        }

        static vi mul_vector(vi a, const mel val){
            transform(BG(a), ED(a), BG(a), [val](mel x){return x * val;});
            return a;
        }

    public:
        Matrix(msize w, msize h, mel def=0){
            this->width = w;
            this->height = h;
            matrix.clear();
            matrix.shrink_to_fit();
            matrix.resize(width, vi(height, def));
        }

        Matrix(istream &stream){
            stream>>width>>height;
            matrix.clear();
            matrix.shrink_to_fit();
            for(msize i = 0; i < width; i++){
                vi vec;
                vec.reserve(height);
                for(msize k = 0; k < height; k++){
                    mel tmp;
                    stream>>tmp;
                    vec.push_back(tmp);
                }
                matrix.push_back(vec);
            }
        }


        pii size(void) const{
            return make_pair(width, height);
        }

        Matrix operator*(const Matrix &b) const {
            assert(size().nd == b.size().st);

            msize m=size().st, k=size().nd, n=b.size().nd;
            Matrix res(m, n, 0);
            for(msize i = 0; i < m; i++)
                for(msize p = 0; p < k; p++)
                    res.matrix[i] = sum_vectors(res.matrix[i], mul_vector(b.matrix[p], matrix[i][p]));

            return res;
       }

       vvi get_matrix(void) const{
            vvi res;
            for(vi v : matrix)
                res.push_back(vi(ALL(v)));
            return res;
       }
};


int main(){
    Matrix a(cin), b(cin);
    Matrix res = a * b;
    pvec(res.get_matrix());
}

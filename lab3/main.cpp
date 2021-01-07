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
typedef vector<msize> vi;
typedef vector<mel> vm;
typedef vector<vm> vvm;
typedef pair<msize, msize> pii;


void pvec(const vvm &vec){
    for(vm v : vec){
        for(mel x : v)
            cout<<x<<' ';
        cout<<endl;
    }
}
void pvec(const vm &vec){
    for(mel v : vec){
        cout<<v<<' ';
    }
    cout<<endl;
}
void pvec(const vi &vec){
    for(msize v : vec){
        cout<<v<<' ';
    }
    cout<<endl;
}


class MatrixCSR{
    private:
        msize size;
        msize non_zeros;
        vi icl;
        vi rowptr;
        vm values;
    public:
        MatrixCSR(istream &stream){
            non_zeros = 0;
            rowptr.push_back(0);
            stream>>size;
            msize row_end = 0;
            for(msize i = 0; i < size; i++){
                for(msize k = 0; k < size; k++){
                    mel tmp;
                    stream>>tmp;
                    if(tmp == 0)
                        continue;
                    non_zeros++;
                    icl.push_back(k);
                    values.push_back(tmp);
                    row_end++;
                }
                rowptr.push_back(row_end);
            }
        }
        msize get_non_zeros(){
            return non_zeros;
        }
        msize get_size(){
            return size;
        }
        msize get_icl_val(msize i){
            return icl[i];
        }
        mel get_value(msize i){
            return values[i];
        }
        msize get_row(int i){
            return *upper_bound(ALL(rowptr),i);
        }
};

class MatrixCSC{
    private:
        msize size;
        msize non_zeros;
        vi irn;
        vi colptr;
        vm values;

    public:
        MatrixCSC(MatrixCSR matrix){
            colptr.push_back(0);
            non_zeros = matrix.get_non_zeros();
            size = matrix.get_size();
            for(msize i=0; i<size; i++){
                for(msize k = 0; k<non_zeros; k++){
                    if(matrix.get_icl_val(k) == i){
                        cout<<"seen "<<i<<" : "<<k<<endl;
                        values.push_back(matrix.get_value(k));
                        irn.push_back(matrix.get_row(k));
                    }
                }
                colptr.push_back(irn.size());
            }
        }

        vvm get_matrix(){
            cout<<"Size:"<<size<<endl<<"IRN:"<<endl;
            pvec(irn);
            cout<<"COLPTR"<<endl;
            pvec(colptr);
            cout<<"VAL"<<endl;
            pvec(values);
        }
};

int main(){
    MatrixCSR a(cin);
    MatrixCSC res(a);
    pvec(res.get_matrix());
}

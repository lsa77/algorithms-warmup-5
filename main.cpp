#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef vector<int> Vec;
typedef vector<Vec> Mat;


Mat operator*(const Mat &a, const Mat &b){
    int tmp;
  
    int m = a.size();
    int n = b.size();
    
    if (m!=n) exit ;

  Mat prod(m,Vec(m));

  for(int i = 0; i < m; i++) {
      for (int j=0; j < m; j++) {
        tmp = (a[i][j] * b[j][i]);
        prod[i][j] = prod[i][j]+tmp;                  
      }
  }
  return prod;
}

Mat create_eigen(int n) {
  int tmp_0 = 0;
  int tmp_1 = 1;
  Mat I;
  Vec vTmp;

    for (int i=0;i<n;i++){
      vTmp.clear(); 
      for (int j=0;j<n;j++) {
        if (i == j)   vTmp.push_back(tmp_1);
        else          vTmp.push_back(tmp_0);        
      }
      I.push_back(vTmp);
    }
  return I;

}

ostream& operator<<(ostream& os, const Mat& A)  
{  
  int n=0;
  n = A.size();

    for (int i=0;i<n;i++) {
      os << endl;
        for (int j=0;j<n;j++) {
            os << A[i][j] << " ";        
        }
    }


    return os;  
}  

int main() {
    
    int n=0;
    int tmp;
    Mat A, I, B;
    Vec vTmp;
    
    cin >> n;
    for (int i=0;i<n;i++){
      vTmp.clear(); 
      for (int j=0;j<n;j++) {
        cin >> tmp;
        vTmp.push_back(tmp);        
      }
      A.push_back(vTmp);
    }

    I = create_eigen(n);

    B = A * I;
    cout <<"A"<<endl<< A;
    cout <<"I"<<endl<< I;
    cout <<"B"<<endl<< B;


    return 0;
}
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

Vec operator*(const Mat &a, const Vec &x){
  
    int m = a.size();
    int n = x.size();
    
    if (m!=n) exit ;

  Vec prod(m);

  for(int i = 0; i < m; i++) {
      prod[i]=0;
      for (int j=0; j < n; j++) {
        //cout<<endl<< a[i][j] << " " << x[j];
        prod[i] += a[i][j] * x[j];                  
      }
  }
  return prod;
}

int vElementsSum( const Vec& x ) {
  int n, sum;
  n = x.size();
  sum = 0;

  for(int i=0;i<n;i++){
    sum += x[i];
  }

  return sum;

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

ostream& operator<<(ostream& os, const Vec& x)  
{  
  int n=0;
  n = x.size();

    for (int i=0;i<n;i++) {
      os << endl;
      os << x[i] << " ";        
      
    }


    return os;  
}  

int main() {
    
    int n=0;
    int tmp;
    int sumI;

    Mat A, I, B;
    Vec vTmp;
    Vec vI = {1,1,1};
    Vec y;

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
    y = B * vI;

    sumI = vElementsSum(y);


    cout <<endl<<"A"<< A;
    cout <<endl<<"I"<< I;
    cout <<endl<<"B"<< B;
    cout <<endl<<"y"<< y;
    cout <<endl<<"sumI"<< sumI;

    return 0;
}
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef vector<int> Vec;
typedef vector<Vec> Mat;


Mat operator*(const Mat &a, const Mat &b){
    int i,j, tmp;
  
    int m = a.size();
    int n = b.size();
    
    if (m!=n) exit ;

    Mat prod(m);

  for(i = 0; i < m; i++) {
      tmp=0;
      for (j=0; j < m ; j++) {
        prod[i][j] += a[i][j] * b[j][i];                  
      }
  }
  return prod;
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
    Mat A;
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

    cout << A;
    // for (int i=0;i<n;i++) {
    //   cout << endl;
    //     for (int j=0;j<n;j++) {
    //         cout << A[i][j] << " ";        
    //     }
    // }
    return 0;
}
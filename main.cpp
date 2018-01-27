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

int main() {
    
    int n=0;
    int tmp;
    Mat A;
    
    cin >> n;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++) {
            cin >> tmp;
            A[i][j] = tmp;        
        }
    return 0;
}
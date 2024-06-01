#include<iostream>
#include <vector>

using namespace std;

int main(){

  int t;
  cin>>t;

  while(t--){
    int n, k;
    cin>>n;
    cin>>k;

    vector<int> cartas(n);
    for(int i=0; i<n; i++){
        cin>>cartas[i];
    }

    vector<int> repetidas(101, 0);
    for(int rept:cartas){
        repetidas[rept]++;

    }

    int solucion=0;
    for(int i=0; i<101; i++){
        if(repetidas[i]>=k){
            solucion++;
        }
    }

    int fin = (solucion>0)?k-1:n;
      cout<<fin<<endl;

  }             

    return 0;
}
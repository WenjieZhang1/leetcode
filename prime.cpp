# include <iostream>
using namespace std;
int countPrimes(int n) {
       bool *isprime = new bool [n];
       for(int i=2; i<n; ++i){
           isprime [i]=true;
       }
       for(int i=2; i*i < n; ++i){
           if(!isprime[i]) continue;
           for(int j=i*i; j<n; j+=i){
               isprime[j]=false;
           }
           
       }
       int count=0;
       for(int i=2; i<n; ++i){
           if(isprime[i]==true) count++;
       }
       delete[] isprime;
       return count;
    }
int main(){
  int w=countPrimes(3);
  cout<<w<<'\n';
  return 0;
}
# include <iostream>
using namespace std;



int numSquares(int n) {
        int *p = new int[n+1];
        

        for(int i=1; i*i<=n; ++i){
            p[i*i]=1;
        }

        for(int i=1; i<=n; ++i){
            for(int j=1; j*j+i<=n; j++){
                if(!p[i+j*j] || p[i+j*j]>p[i]+1){
                    p[i+j*j]=p[i]+1;
                }
                
            }
        }
        
        return p[n];
    }
int main(){
    int x=numSquares(10);
    cout<<x<<'\n';
    return 0;
}
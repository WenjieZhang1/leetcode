# include <iostream>
using namespace std;
 int divide(int dividend, int divisor) {
        if(divisor==0 || (dividend==INT_MIN && divisor==-1)) return INT_MAX;
        if(divisor==1) return dividend;
        bool flag=((dividend>0 && divisor<0) || (dividend<0 && divisor>0));
        long dividend_abs = abs((long)dividend);
        long divisor_abs = abs((long)divisor);
        int res=0;
        while(dividend_abs >= divisor_abs){
            for(int i=0; dividend_abs >= divisor_abs*(1<<i); ++i){
                dividend_abs-= divisor_abs*(1<<i);
                res+=(1<<i);
            }
        }
       //cout<<flag<<'\n';
       return flag? -res: res;
    }

    int main(){
    	//int dividend=1; int divisor=-1;
    	//bool flag=((dividend>0 && divisor<0) || (dividend<0 && divisor>0));
    	//cout<<flag<<endl;
    	int res=divide(1,-1);
    	cout<<res<<'\n';
    	return 0;
    }
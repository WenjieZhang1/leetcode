# include <iostream>
using namespace std;
 int getmin(int x1, int x2, int x3){
        int temp=min(x1, x2);
        return min(temp, x3);
    }
 int nthUglyNumber(int n) {
      if(n<=0) return 0;
      int *uglyarray = new int[n];
      uglyarray[0] = 1;
      int next=1;
      int *multiply2 = uglyarray;
      int *multiply3 = uglyarray;
      int *multiply5 = uglyarray;
      while(next < n){
          int temp = getmin(*multiply2 * 2, *multiply3 * 3, *multiply5 * 5);
          uglyarray[next] = temp;
          while(*multiply2 * 2 < uglyarray[next]){
              multiply2++;
          }
           while(*multiply3 * 3 < uglyarray[next]){
              multiply3++;
          }
           while(*multiply5 * 5 < uglyarray[next]){
              multiply5++;
          }
          ++next;
      }
      int x=uglyarray[next-1];
      delete[] uglyarray;
      return x;
      
    }

int main(){
  int x;
  x=18;

  int n=nthUglyNumber(x);
  cout<<n<<'\n';
  return 0;
}

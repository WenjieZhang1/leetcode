# include <iostream>
# include <vector>
# include <string>
# include <stdio.h>
# include <stdlib.h>

using namespace std;

int f(int x, int y) {
  printf("In f(%d,%d)\n", x,y);
  int answer = 0;
  if( x > 42) {
    printf("x is big\n");
    if (y > x * 3) {
      answer = y - x;
    }
    else {
      printf("y is not very big\n");
      answer = y + x ;
    }
  }
  else {
    printf("x is small\n");
  }
  return answer;
}

bool isprime(int n)
{
	if (n<=1)
	{
		return false; 
	}
	for (int i=2; i < n; i++)
	{
		if (n%i==0)
			return false;
	}
	return true;

}


int factorial(int n)
{
	int fac=1;
	if (n==0)
	{
		fac=0;
	}
	for (int i=1; i <= n; i++)
		fac=fac*i;
	return fac;


}

struct color_1
{
	int red;
	int green;
	int blue;
};

typedef struct color_1 color_2;

color_2 bright (color_2 x)
{
	color_2 ans;
	ans.red=x.red+200;
	ans.green=x.green+180;
	ans.blue=x.blue+50;
	return ans;
}

void swap (int & a, int & b)
{
	int temp=a;
	a=b;
	b=temp;
}

int main() 
{
 vector<int> a(100);
 for (int i=0; i< a.size(); i++)
 	a[i]=i*i;
 for (int j=0; j< a.size(); j++)
 	cout<<j<< " j^2=%d\n"<< a[j] <<endl;
 int answer=f (50,100);
 cout<<isprime(47)<<endl;
 cout<< factorial(3)<<endl;
 color_2 c;
 c.red=100;
 c.green=50;
 c.blue=10;
 color_2 c1= bright (c);
 int x1=1;
 int x2=2;
 swap(x1,x2);
 cout<<x1<<endl;
 cout<<x2<<endl;

 int x =3;
 int *p;
 p= &x;
 *p=4;
 int y=*p;
 cout<<*p<<endl;
 cout<<&y<<endl;

 int v[4];
 v[0]=1;
 v[1]=5;
 v[2]=7;
 v[3]=2;

 int *q = v;
 q=q+1;

 cout<<*q<<endl;

 char h[]="we are jordan";
 char *e=h;
 while (*e!='\0')
 {
 	cout<<*e<<endl;
 	e++;
 }
 printf("hello\n"+3);
 printf("%c\n", "abcde" [2]);
 	




 

 return 0;
}
 


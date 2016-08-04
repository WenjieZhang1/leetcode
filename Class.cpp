#include <iostream>
using namespace std;

class point 
{
	int x;
	int y;
 public:

 	int getx() {return x;}
    int gety() {return y;}
    void setX(int _x)
    {
    	x=_x;
    }
    void setY(int _y)
    {
    	y=_y;
    }

};

int main() 
{


	point qr;
    

	int a=qr.getx();
	cout<<a<<endl;

}
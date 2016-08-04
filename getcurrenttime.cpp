#include <ctime>
#include <iostream>
# include <string>
using namespace std;

 string f( int x)
{
	if (x>5 && x<9)
	return "q1";
    else if (x>10)
    	return "q2";
}

string translation(int a)
{
	stringstream ss;
	ss<<a;
	string q=ss.str();
	return q;
}
int main() {

    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    cout << (now->tm_year + 1900) << endl;
    string x= translation(20);
    cout << x;


}



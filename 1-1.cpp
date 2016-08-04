# include <iostream>
# include <string>
using namespace std;


string NxtQuar(string quarter)
{
    if (quarter == "Q1")
        return "Q2";
    else if (quarter == "Q2")
        return "Q3";
    else if (quarter == "Q3")
        return "Q4";
    else 
        return "Q1";

}
int main()
{  char c[20];
   string s="1234";
   strcpy(c,s.c_str());
   cout<<c<<endl;
   string x;
   x=NxtQuar("Q1");
   cout<<x<<endl;
   string w;
   w="hello";
  
  char q[30]="wearejordan";
  q[0]='o';
  q[1]='2';
  cout<<q;


}




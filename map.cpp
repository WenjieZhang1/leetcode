# include <map>
# include <iostream>
# include <string>
# include <vector>
using namespace std;
int main() 
{
	string x="abcdeaaab";
	std::vector<char> v;
	for (int i=0; i< x.length(); i++)
	{
		v.push_back(x[i]);
	}

    int w=v.size();

    return 0;

}
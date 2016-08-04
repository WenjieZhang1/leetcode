# include <iostream>
# include <string>
using namespace std;
int lengthOfLastWord(string s) {
    int l=s.size();
    int i=l-1;
    int count=0;
    while(s[i]==' '){
    	i--;
    } 
    while((s[i]!=' ') && (i>=0)){
    	i--;
    	count++;
    }

    return count;  
}

int main(){
	string w="q ";
	int n=lengthOfLastWord(w);
	cout<<n<<endl;
	return 0;
}
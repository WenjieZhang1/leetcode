#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    void reverseWords(string &s) {
        int len = s.length();
        int start = 0;
        int end = 0;
        while(start < len){
            while(s[end + 1] != ' ' && s[end + 1] != '\0'){
                end++;
            }
            string_reverse(s, start, end);
            start = end + 2;
            end = start;
        }
        reverse(s.begin(), s.end());
    }
    void string_reverse(string &s, int i, int j){
        while(i <= j){
            swap(s[i++], s[j--]);
        }
    }
};
int main(){
	Solution ss;
	string s = "the sky is blue";
	ss.reverseWords(s);
	cout << s;
	return 0;
}
#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int min = 0;
        stack<char> sk;
        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                sk.push('(');
            }else{ 
                if(!sk.empty()){
                   sk.pop();    
                }else{
                    min++;
                }
            }
        }        
        min+=sk.size();
        return min;
    }
};
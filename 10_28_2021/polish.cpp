#include<stack>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int result=0;
        stack<string> s;
        for(auto it = tokens.begin();it!=tokens.end();it++){
            if( *it == "+" || *it =="-"|| *it == "*" || *it == "/" ){
                int a = stoi(s.top());
                s.pop();
                int b = stoi(s.top());
                s.pop();
                
                if(*it == "*"){
                    result = b * a; 
                }   
                if(*it == "-"){
                    result = b - a;
                }
                if(*it == "+"){
                    result = b + a;
                }
                if(*it == "/"){
                    result = b/a;
                }
                s.push(to_string(result));
            }else{
                s.push(*it);
            }
        }
        if(!s.empty()){
            result=stoi(s.top());
        }
        return result;
    }
};
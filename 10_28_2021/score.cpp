#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        stack<int> sk;
        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                sk.push(-1);
            }else{
                if(sk.top() == -1){
                    sk.pop(); 
                    sk.push(1);
                } 
                else{
                    score = 0;
                    score += sk.top();
                    sk.pop();
                    while(sk.top() != -1){
                        score += sk.top();
                        sk.pop(); 
                    }
                    if(sk.top() == -1 ){
                        sk.pop();
                        sk.push(score*2);
                    }
                }
            }
            stack<int> temp = sk;
            for(int j=0;j< sk.size();j++){
                cout << temp.top() << " ";
                temp.pop();
            }
            cout << endl;
        }
        score = 0;
        while(!sk.empty()){
            score+= sk.top();
            sk.pop();
        }

        
        sk.push(score);    
        return sk.top();   
    }
};

int main(){
    Solution a;
    cout << a.scoreOfParentheses("()()") <<endl;
    return 0;
}
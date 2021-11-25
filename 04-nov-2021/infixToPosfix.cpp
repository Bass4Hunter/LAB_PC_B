#include <iostream>
#include <string>
#include <cstdio>
#include <stack>

using namespace std;

int main(){
	int n;
	cin >> n;
	while(n--){
		string res="", in;
		cin >> in;
		in = "(" + in + ")";
		stack<char> P;
		for(unsigned int i = 0 ; i < in.size() ; i++){
			char c = in[i];
			if(c == '('){
				P.push(c);
				continue;
			}
			else if(c == '+'){
				while(!P.empty() && (P.top() == '+' || P.top() == '-' || P.top() == '*' || P.top() == '/' || P.top() == '^')){
					res += P.top();
					P.pop();
				}
				P.push(c);
			}
			else if(c == '-'){
				while(!P.empty() && (P.top() == '+' || P.top() == '-' || P.top() == '*' || P.top() == '/' || P.top() == '^')){
					res += P.top();
					P.pop();
				}
				P.push(c);
			}
			else if(c == '*'){
				while(!P.empty() && (P.top() == '*' || P.top() == '/' || P.top() == '^')){
					res += P.top();
					P.pop();
				}
				P.push(c);
			}
			else if(c == '/'){
				while(!P.empty() && (P.top() == '*' || P.top() == '/' || P.top() == '^')){
					res += P.top();
					P.pop();
				}
				P.push(c);
			}
			else if(c == '^'){
				while(!P.empty() && P.top() == '^'){
					res += P.top();
					P.pop();
				}
				P.push(c);
			}
			else if(c == ')'){
				while(!P.empty() && P.top() != '('){
						res += P.top();
						P.pop();
				}
				P.pop();
			}
			else{
				res += c;
			}
		}
		cout << res << endl;
	}
	return 0;
} 
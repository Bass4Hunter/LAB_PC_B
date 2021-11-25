#include <iostream>
#include <map>
#include <limits>
#include <math.h>
#include<unordered_map>
using namespace std;
int main() {
    int n, m;
    int t;
    map<int,int> servers;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> t;
        servers[t]++;
        servers[t+1000]--;
    }
    float max = numeric_limits<int>::min();
    int actual = 0;
    for(auto it= servers.begin();it!=servers.end();it++){
        actual += it->second;
        if(actual > max){
            max = actual;
        }
    }
    cout << ceil(max/m) <<endl;
}
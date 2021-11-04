#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n,k;
    cin >> n >>k;
    vector<int> arr(n);
    vector<int> diference(n);
    int a,b;
    for(int i=0;i<k;i++){
        cin >> a >> b;
        

        diference[a-1]++;
        if(b < n)
            diference[b]--;
    }

    arr[0] = diference[0];
    for(int i=1;i<n;i++){
        arr[i] =  arr[i-1]+ diference[i];
    }
    sort(arr.begin(),arr.end());
    cout<< arr[(arr.size()/2)]<<endl;
    return 0;
}
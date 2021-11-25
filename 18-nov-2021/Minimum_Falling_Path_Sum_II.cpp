#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int min = 0, min_index = 0, max = 0, max_index=0;
        
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(min_index==j) {
                    grid[i][j] += max;
                } else {
                    grid[i][j] += min;
                }
            }
            min = INT_MAX, min_index = 0, max = INT_MAX, max_index=0;
            for(int j=0;j<grid[i].size();j++) {
                if(min>grid[i][j]) {
                    max=min;
                    max_index=min_index;
                    min=grid[i][j];
                    min_index=j;
                } else if(max>grid[i][j]) {
                    max=grid[i][j];
                    max_index=j;
                }
            }
        }
        return min;
    }
};
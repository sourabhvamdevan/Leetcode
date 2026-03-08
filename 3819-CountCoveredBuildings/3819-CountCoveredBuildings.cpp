// Last updated: 08/03/2026, 13:22:58
#define vi vector<int>

class Solution {
public:

    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        n ++;
        vi leftMostBuildingOnY(n, n+1);
        vi rightMostBuildingOnY(n, -1);
        vi lowestBuildingOnX(n, n+1);
        vi highestBuildingOnX(n, 0);

        int res = 0;

        for(auto building: buildings) {
            int x = building[0];
            int y = building[1];

            leftMostBuildingOnY[y] = min(x, leftMostBuildingOnY[y]);
            rightMostBuildingOnY[y] = max(x, rightMostBuildingOnY[y]);

            lowestBuildingOnX[x] = min(y, lowestBuildingOnX[x]);
            highestBuildingOnX[x] = max(y, highestBuildingOnX[x]);
        }

        for(auto building: buildings) {
            int x = building[0];
            int y = building[1];

            if (y > lowestBuildingOnX[x] && y < highestBuildingOnX[x] 
            && x > leftMostBuildingOnY[y] && x < rightMostBuildingOnY[y]) {
                res ++;
            }


        }

        return res;
    }
};
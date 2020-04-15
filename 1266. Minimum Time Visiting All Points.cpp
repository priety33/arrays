/*Intuition

    In order to minimize steps, we should walk most points diagonally. If we cannot make a move then those points should be 
    covered either horizontally or vertically.
    Example : Lets say |x2 - x1| = 5 and |y2 - y1| = 3, then we would walk 3 diagonally and remaining two have to be walked horizontally.
*/

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int i = 1; i < points.size(); i++) {
            ans += max(abs(points[i][1] - points[i - 1][1]), abs(points[i][0] - points[i - 1][0]));
        }
        return ans;
    }
};

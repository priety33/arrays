class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int total=0;
        int tank=0;
        int start=0;
        for(int i=0;i<n;i++)
        {
            tank= tank+ gas[i] -cost[i]; //after consuming gas and cost at i, if fuel in tank is >=0 => it has reached i+1.
                                         // but if it is < 0 => we have shortage of that much fuel at this point, and add this shortage to total shortage.
            if(tank<0)
            {
                total=total+tank;
                tank=0;
                start=i+1;
            }
        }
        return (total+tank<0) ? -1:start;
    }
};

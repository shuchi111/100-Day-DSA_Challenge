// 1235. Maximum Profit in Job Scheduling - leetcode potd

/*
Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job. 
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.



Algorithm:

1. Sort the jobs based on their end times.
2. Initialize a map dp with {end time, profit} as key-value pairs.
3. Iterate through the sorted jobs.
For each job, calculate the maximum profit based on the right-most non-overlapping job using dynamic programming.
Update the dp map with the maximum profit if it is greater than the current maximum profit.
4. Return the maximum profit at the last end time in the dp map.

*/

//solution
class Solution {
public:
    // time/space: O(nlogn)/O(n)
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        // sort the job {end, start, profit} by the end time
        const int n = startTime.size();
        vector<vector<int>> jobs(n);
        for (int i = 0; i < n; i++) jobs[i] = {endTime[i], startTime[i], profit[i]};
        sort(jobs.begin(), jobs.end());

        // dynamic programming {end, profit}
        map<int, int> dp = {{0, 0}};
        for (auto& job : jobs) {
            // take the current job based on the right-most non-overlapping job
            // the end time of the selected job must be smaller or equal to the start time of the current job
            // so we can use `prev(upper_bound())` to meet the condition `currStart >= prevEnd`
            int profit = prev(dp.upper_bound(job[1]))->second + job[2];
            // append the element if it's best so far
            if (profit > dp.rbegin()->second) dp[job[0]] = profit;
        }
        return dp.rbegin()->second;
    }
};

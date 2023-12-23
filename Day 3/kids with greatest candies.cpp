// 1431. Kids With the Greatest Number of Candies - leetcode 75

/*

1. Function kidsWithCandies(candies, extraCandies):
2.   Initialize variables:
       - answer (vector<bool>)
       - max_value = 0
3.   Find Maximum Number of Candies:
       - Iterate through candies and update max_value to be the maximum value among all elements.
4.   Check and Store Results:
       - Iterate through candies:
           - Check if candies[i] + extraCandies is greater than or equal to max_value.
           - Push true or false to the answer vector accordingly.
5.   Return Result:
       - Return the answer vector containing the boolean result for each kid.


*/
//Solution -

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>answer;
        int max_value = 0;
        for (int i = 0; i < candies.size(); i++){
            if (max_value <= candies.at(i)){max_value = candies.at(i);}
        }

        for (int i = 0; i < candies.size(); i++){
            if (candies.at(i) + extraCandies >= max_value){answer.push_back(true);}
            else {answer.push_back(false);}
        }
        return answer;
    }
};




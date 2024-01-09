//1657. Determine if Two Strings Are Close
/*
Example 1:

Input: word1 = "abc", word2 = "bca"
Output: true
Explanation: You can attain word2 from word1 in 2 operations.
Apply Operation 1: "abc" -> "acb"
Apply Operation 1: "acb" -> "bca"


Approach:

We are following a frequency-based approach to determine if two words are "close." The algorithm involves using unordered_maps to track the occurrences of characters and their frequencies in both words. It then compares these occurrences and frequencies to check for similarity between the words.

Algorithm:

1. Initialize two unordered_maps (chars_to_occurences_1 and chars_to_occurences_2) to store the occurrences of each character in word1 and word2.
2. Initialize two unordered_maps (num_occurrence_to_freq_1 and num_occurrence_to_freq_2) to store the frequencies of occurrences of characters in word1 and word2.
3. Traverse word1 and word2 simultaneously and update the counts in chars_to_occurences_1 and chars_to_occurences_2.
4. Check if the corresponding characters in chars_to_occurences_1 and chars_to_occurences_2 match. If not, return false.
5. Update num_occurrence_to_freq_1 and num_occurrence_to_freq_2 with the counts of occurrences in chars_to_occurences_1 and chars_to_occurences_2.
6. Compare num_occurrence_to_freq_1 and num_occurrence_to_freq_2. If they are not equal, return false.
7. If all checks pass, return true.


*/

//Solution
class Solution {
public:
    bool closeStrings(string word1, string word2) {
         if (word1.length() != word2.length())
            return false;
        
        unordered_map<char, int> chars_to_occurences_1;
        unordered_map<char, int> chars_to_occurences_2;
        unordered_map<char, int> num_occurrence_to_freq_1;
        unordered_map<char, int> num_occurrence_to_freq_2;

        for (auto i = 0; i < word1.length(); ++i) {
            chars_to_occurences_1[word1[i]]++;
            chars_to_occurences_2[word2[i]]++;
        }

        for (auto pair : chars_to_occurences_1) {
            if (chars_to_occurences_2[pair.first] == 0)
                return false;

            num_occurrence_to_freq_1[pair.second] ++;
        }

        for (auto pair : chars_to_occurences_2) {
            num_occurrence_to_freq_2[pair.second] ++;
        }

        for (auto pair : num_occurrence_to_freq_1) {
            if (num_occurrence_to_freq_2[pair.first] != pair.second)
                return false;
        }

        return true;
    }
};

        

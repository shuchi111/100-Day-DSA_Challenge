//Solution

/*
  Algorithm:

1. Create a set vowels containing all the lowercase and uppercase vowels.
2. Initialize a variable vowelsCount to 0.
3. Calculate the index midIndex as half the length of the string s.
4. Iterate over the first half of the string (from index 0 to midIndex):
For each character charA at index i in the first half, check if it is a vowel. If yes, increment vowelsCount.
For each character charB at index midIndex + i in the second half, check if it is a vowel. If yes, decrement vowelsCount.
5. After the loop, check if vowelsCount is equal to 0.
6. If vowelsCount is 0, return true (the two halves have an equal number of vowels).
7. Otherwise, return false (the two halves do not have an equal number of vowels).

*/

class Solution {
public:
    bool halvesAreAlike(std::string s) {
            unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
                    int vowelsCount = 0;
                     int midIndex = s.length() / 2;

                     for (int i = 0; i < midIndex; i++) {
                      char charA = s[i];
                      char charB = s[midIndex + i];
                      if (vowels.count(charA)) vowelsCount++;
                         if (vowels.count(charB)) vowelsCount--;
               }
 return vowelsCount == 0;
                                                                                                       
                    }
                      };                                                                                  
                                                                                



   

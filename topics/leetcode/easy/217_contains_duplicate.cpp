#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            unordered_set<int> seen; // we use a simple set for this problem
            for (int num : nums) {
                if (seen.count(num))
                    return true;
                seen.insert(num);
            }
            return false;
        }

        bool usingSecond(vector<int>& nums) {
            // in this approach, we don't use .count() to see if the set contains it anymore
            // instead we insert it always and see if the insertion worked or failed

            // INSERT() LOGIC FFOR SETS:
            // if the insertion failed that means the element was already there
            // note that insert() returns a pair<iterator, bool>
                // the iterator (first) points to the element in the set
                // the bool (second) tells us if the element was added
            // so insert().second gives us whether the insertion was successful or note. 

            unordered_set<int> seen;
            for (int num : nums) {
                if (!seen.insert(num).second) // we get false when the insertion fails, i.e, when a dupe exists!
                    return true;
            }
            return false;
        }
};

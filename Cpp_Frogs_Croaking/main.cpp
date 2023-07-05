#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        // create map of key and value
        std::unordered_map<char,int> mp;
        int result = 0;
        for(auto it:croakOfFrogs){
            mp[it]++;

            if(mp['c'] < mp['r'] || mp['r'] < mp['o'] || mp['o'] < mp['a'] || mp['a'] < mp['k']){
                return -1;
            }

            result = max(result, mp['c']- mp['k']);
        }

        // after loop we should have equal no of c r o a k
        if(mp['c'] == mp['r'] && mp['r'] == mp['o'] && mp['o'] == mp['a'] && mp['a'] == mp['k']){
            return result;
        }

        return -1;
    }
};

int main(){

    return 0;
}
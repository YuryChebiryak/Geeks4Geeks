/* (C) Yury Chebiryak, 2017

http://practice.geeksforgeeks.org/problems/word-break/0
Given an input string and a dictionary of words, find out if the input string can be segmented into a space-separated sequence of dictionary words. See following examples for more details.

Consider the following dictionary
{ i, like, sam, sung, samsung, mobile, ice,
  cream, icecream, man, go, mango}

Input:  ilike
Output: Yes
The string can be segmented as "i like".

Input:  ilikesamsung
Output: Yes
The string can be segmented as "i like samsung" or "i like sam sung".

Input:
First line is integer T denoting number of test cases. 1<=T<=100.
Every test case has 3 lines.
First line is N number of words in dictionary. 1<=N<=12.
Second line contains N strings denoting the words of dictionary. Length of each word is less than 15.
Third line contains a string S of length less than 1000.

Output:
Print 1 is possible to break words, else print 0.

Example:
Input:
2
12
i like sam sung samsung mobile ice cream icecream man go mango
ilike
12
i like sam sung samsung mobile ice cream icecream man go mango
idontlike
Output:
1
0



*/

#include <iostream>
#include <unordered_set>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, bool> memo;

bool solve(const string& str) {
    //std::cout << std::endl << "input: " << str;
    auto iter = memo.find(str);
    if (iter != memo.end())
        return iter->second;
    for (int i = 1; i < str.size(); i++) {
        if (solve(str.substr(0,i)) && solve(str.substr(i))) {
            memo[str] = true;
            return true;
        }
    }
    memo[str] = false;
    return false;    
}

int read_solve() {
    int nwords;
    string str;
    std::cin >> nwords;
    while (nwords--) {
        string word;
        std::cin >> word;
        memo[word] = true;
    }
    std::cin >> str;
    return solve(str);
}

int main() {
    int ntests;
    std::cin >> ntests;
    while (ntests--) {
        std::cout << read_solve() << std::endl;
    }
	//code
	return 0;
}
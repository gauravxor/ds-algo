#include <vector>
#include <iostream>
#include <cstring>
#include <unordered_set>

using namespace std;

string solve(string str1, string str2) {
    unordered_set<char> ust1(str1.begin(), str1.end());
    unordered_set<char> ust2(str2.begin(), str2.end());

    /** After removing all the duplicates, if the length of any string is
     *  less than or greatter than the other, we return the greater one, as we
     *  know the string having more characters will have more subsequences
    */
    if(ust1.size() > ust2.size()) {
        return str1;
    }

    /** If after removing all the duplicates, the length of the string are equal,
     * then it return the string that greater length originally.
    */

    if(ust1.size() == ust2.size() &&  str1.size() >= str2.size()) {
        return str1;
    }
    return str2;
}

int main () {
    string str1, str2;
    cin >> str1 >> str2;
    cout << solve(str1, str2) << "\n";
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int bruteForce(vector<int> &v, int n, int target) {
    if(target == 0) {
        return true;
    }
    if(n < 0) {
        return false;
    }

    /** Why can't we directly return the result produced by this call?
     *  Ans : If we do this then the control will never reach the second call,
     *  which is a problem. So we make sure that the first recursive call
     *  returns a value to the main function only if it gets what it is searching for or
     *  else control should move to the next call.
    */
    bool result = bruteForce(v, n - 1, target - v[n]);
     /** Making sure that the if result is false, then control does not moves back to the
      *  main function, instead of making the next recursive call
      **/
    if(result == true) {
        return true;
    }

    /** At this point we dont have any further recursive calls. So whatever is the answer, we
     *  should return it.
    */
    return bruteForce(v, n - 1, target);
}


int isPresent(vector<int> &v, int n, int target) {

    if(target == 0) {
        return true;
    }

    if(n < 0) {
        return false;
    }

    if(target - v[n] >= 0) {
        bool res1 = isPresent(v, n - 1, target - v[n]);
        if(res1 == true) {
            return true;
        }
    }

    return isPresent(v, n - 1, target);
}


int main () {
    int n;
    cin >> n;

    vector<int> v(n);
    for(auto &it : v) {
        cin >> it;
    }

    int target;
    cin >> target;

    bool ans = isPresent(v, n - 1, target);
    (ans) ? cout << "Possible\n" : cout << "Not Possible\n";
    return 0;
}
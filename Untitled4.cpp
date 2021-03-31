#include <iostream>
#include <cstdlib>
#include <vector>
#include <climits>

using namespace std;

/*
 * This program try to solve the problem:
 * User will input an array with 10 positive numbers.
 * Our task is to find out the biggest 3 number inside the array,
 * and then output to the console window.
 */

int main() {  
	int targetIndex;
    int nums[10];
    vector<int> res;

    for (int i = 0; i < 10; i++)
        cin >> nums[i];

    for (int i = 0; i < 3; i++) {
        int maximum = INT_MIN;
        for (int j = 0; j < 10; j++) {
            if (nums[j] > maximum) {
                maximum = nums[j];
                targetIndex = j;
            	cout<<"i:"<<i<<" j:"<<j<<" "<<maximum<<endl;
            }
        }
        res.push_back(maximum);
        nums[targetIndex] =INT_MIN;
    }

    for (int i = 0; i < 3; i++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}

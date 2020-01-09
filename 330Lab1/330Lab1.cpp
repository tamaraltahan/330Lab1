

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


void populateList(vector<int> vect, int n); //fill values with n random values
int calculateMedian(vector<int> vect);

int main()
{
    vector<int> list;
    populateList(list, 11);
    int median = calculateMedian(list);

    cout << "The median value is " << median << endl;
}

void populateList(vector<int> vect, int n)
{
    cout << "Enter " << n << " odd values\n";
    for (int i = 0; i < n; ++i) {
        cout << "Value: ";
        int input;
        cin >> input;
        vect.push_back(input);
    }
}


int calculateMedian(vector<int> vect)
{
    assert(vect.size() % 2 != 0);

    int half = vect.size() / 2;
    int median = 0;
    for (int i = 0; i < vect.size; ++i) {
        int greaterThan = 0;
        for (int j = 0; j < vect.size; ++j) {
            if (vect[j] > vect[i]) {
                greaterThan++;
        }
        if (greaterThan == half) {
            median = vect[i];
            return median;
        }
    }
    return median;
}


#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


void populateList(vector<int> vect, int n); //fill values with n random values
int calculateMedian(vector<int> vect); //calculate Median value
int recursivePrint(vector<int> vect, int n); //print out values of list recursively

int main()
{
    int size;
    cout << "How big is the vector (odd)?\n";
    cin >> size;

    vector<int> list;
    populateList(list, size);
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
    assert(vect.size() % 2 == 0);

    int half = vect.size() / 2;
    int median = 0;
    int greaterThan = 0;
    int lessThan = 0;

    for (int i = 0; i < vect.size(); ++i) 
    {
        for (int j = 0; j < vect.size(); ++j) 
        {
            if (vect[j] > vect[i]) 
            {
                greaterThan++;
            }
            else {
                lessThan++;
            }
        }
        if (greaterThan == lessThan)
        {
            median = vect[i];
            return median;
        }
    }
    return INT_MAX;
}

int recursivePrint(vector<int> vect, int n)
{
    cout << vect[n] << endl;
    if (n == 0) {
        return vect[n];
    }
    else {
        return recursivePrint(vect, n - 1);
    }
    return vect[n];
}
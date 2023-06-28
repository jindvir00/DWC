
//Develop a sorting algorithm that efficiently sorts a large array of integers in ascending order

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

bool compareNumbers(string str1, string str2)
{
    int n1 = str1.length(), n2 = str2.length();

    if (n1 < n2)
        return true;
    if (n2 < n1)
        return false;

    for (int i = 0; i < n1; i++)
    {
        if (str1[i] < str2[i])
            return true;
        if (str1[i] > str2[i])
            return false;
    }

    return false;
}

void sortLargeNumbers(string arr[], int n)
{
    sort(arr, arr + n, compareNumbers);
}

// Driver code
int main()
{
    string arr[] = {"5", "1237637463746732323",
                    "97987", "12"};
    int n = sizeof(arr) / sizeof(arr[0]);

    sortLargeNumbers(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

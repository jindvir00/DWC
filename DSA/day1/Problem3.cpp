#include <iostream>
#include <vector>
#include <algorithm>

void printCommonElements(const std::vector<int>& arr1, const std::vector<int>& arr2, const std::vector<int>& arr3) {
    int i = 0, j = 0, k = 0;
    std::vector<int> commonElements;

    while (i < arr1.size() && j < arr2.size() && k < arr3.size()) {
        if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
            commonElements.push_back(arr1[i]);
            i++;
            j++;
            k++;
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr2[j] < arr3[k]) {
            j++;
        } else {
            k++;
        }
    }

    std::cout << "Common elements: ";
    for (int element : commonElements) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr1, arr2, arr3;
    int size1, size2, size3;

    std::cout << "Enter the size of the first array: ";
    std::cin >> size1;

    std::cout << "Enter the elements of the first array: ";
    for (int i = 0; i < size1; i++) {
        int element;
        std::cin >> element;
        arr1.push_back(element);
    }

    std::cout << "Enter the size of the second array: ";
    std::cin >> size2;

    std::cout << "Enter the elements of the second array: ";
    for (int i = 0; i < size2; i++) {
        int element;
        std::cin >> element;
        arr2.push_back(element);
    }

    std::cout << "Enter the size of the third array: ";
    std::cin >> size3;

    std::cout << "Enter the elements of the third array: ";
    for (int i = 0; i < size3; i++) {
        int element;
        std::cin >> element;
        arr3.push_back(element);
    }

    // Sort the arrays
    std::sort(arr1.begin(), arr1.end());
    std::sort(arr2.begin(), arr2.end());
    std::sort(arr3.begin(), arr3.end());

    printCommonElements(arr1, arr2, arr3);

    return 0;
}

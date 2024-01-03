#include <iostream>
using namespace std;

void inputArray(int *arr, int size)
{
    cout << "Enter the array elements: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> *(arr + i);
    }
}

void displayArray(int *arr, int size)
{
    cout << "The array elements are: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << *(arr + i) << "\t";
    }
    cout << endl;
}

void sortArray(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (*(arr + j) > *(arr + (j + 1)))
            {
                int temp = *(arr + j);
                *(arr + j) = *(arr + (j + 1));
                *(arr + (j + 1)) = temp;
            }
        }
    }
}

int *findMax(int *arr, int size)
{
    int *maxPtr = arr;
    for (int i = 1; i < size; ++i)
    {
        if (arr[i] > *maxPtr)
        {
            maxPtr = &arr[i];
        }
    }

    return maxPtr;
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int *arr = new int[size];

    inputArray(arr, size);
    displayArray(arr, size);

    sortArray(arr, size);
    cout << "Array after sorting: " << endl;
    displayArray(arr, size);

    int *max = findMax(arr, size);
    cout << "Maximum element in the array: " << *max << endl;

    return 0;
}

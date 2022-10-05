#include <iostream>
using namespace std;

// Selection Sort
void selectionSort(int *arr, int n)
{
    int compare = 0, swap = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            compare++;
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
            // if (arr[j] < arr[i])
            // {
            //     int temp = arr[j];
            //     arr[j] = arr[i];
            //     arr[i] = temp;
            // }
        }
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = arr[temp];
        swap++;
    }
    cout << compare << " " << swap << endl;
    return;
}

// Insertion Sort
void insertionSort(int *arr, int n)
{
    int compare = 0, swap = 0;
    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        int j;

        for (j = i - 1; j >= 0; j--)
        {
            compare++;
            if (arr[j] > curr)
            {
                arr[j + 1] = arr[j];
                swap++;
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = curr;
    }
    cout << compare << " " << swap << endl;
}

// Bubble Sort
void bubbleSort(int *arr, int n)
{
    int compare = 0, swap = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int st = 0;
        while (st < n - 1 - i)
        {
            int en = st + 1;
            compare++;
            if (arr[st] > arr[en])
            {
                int temp = arr[st];
                arr[st] = arr[en];
                arr[en] = temp;
                swap++;
            }
            st++;
        }
    }
    cout << compare << " " << swap << endl;
    return;
}

int main()
{
    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        // Generating no between 0 to 100
        arr[i] = rand() % 100;
    }

    selectionSort(arr, 5);
    // bubbleSort(arr, 5);
    // insertionSort(arr, 5);

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
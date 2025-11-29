//25125040
//Le Hong Dang
//25A02

/*
Test case 1
Input:
    3
    1 2 3
    1
    2
    3
    4 4
    0
Output:
    The array is: 1 2 3
    The sum of the array is: 6
    The largest value in the array is: 3
    There are no elements in the array that has the value 4
*/

/*
Test case 2
Input:
    3
    1 2 3
    5 1 2
    1
    6
    1
    0
Output:
    The array is: 1 2 1 3
    The array is: 3 1 2 1
*/

/*
Test case 3
Input:
    3
    1 2 3
    4 3
    1
    5 2 2
    1
    5 3 6
    1
    0
Output:
    The array is: 1 2
    The array is: 1 2 2
    The array is: 1 2 2 3
    The array is: 3 2 2 1
*/

#include<iostream>
using namespace std;

void printArray(int arr[], int length);
int getSum(int arr[], int length);
int largestValue(int arr[], int length);
void deleteElement(int *&arr, int &length, int x);
void insertElement(int *&arr, int &length, int id, int x);
void reverseArray(int *&arr, int length);

int main()
{
    cout << "This is the program to operate with dynamic array.\n";
    int length;
    cout << "Please enter the size of the array: ";
    cin >> length;
    while (length <= 0)
    {
        cout << "This size of the array is invalid. Please enter again: ";
        cin >> length;
    }
    int *arr = new int[length];
    cout << "Please enter the array: ";
    for (int i = 0; i < length; ++i) cin >> arr[i];
    cout << "The operations to operate with dynamic array are:\n";
    cout << "1. Print the array;\n2. Calculate the sum of the elements in the array;\n";
    cout << "3. Find the largest value in the array;\n4. Delete an element from the array;\n";
    cout << "5. Insert an element into the array\n6. Reverse the order of the elements in the array.\n";
    cout << "0. Exit the program.\n";
    int choice;
    do
    {
        cout << "Please enter your choice: ";
        cin >> choice;
        switch(choice)
        {
            case 0: break;
            case 1:
                printArray(arr, length);
                break;
            case 2:
                cout << "The sum of the array is: " << getSum(arr, length) << '\n';
                break;
            case 3:
                cout << "The largest value in the array is: " << largestValue(arr, length) << '\n';
                break;
            case 4:
            {
                int x;
                cout << "Please enter the value in the array that you want to erase: ";
                cin >> x;
                deleteElement(arr, length, x);
                break;
            }
            case 5:
            {
                int x, id;
                cout << "Please enter the value that you want to insert to: ";
                cin >> x;
                cout << "Please enter the position you want to insert to: ";
                cin >> id;
                insertElement(arr, length, id, x);
                break;
            }
            case 6:
                reverseArray(arr, length);
                break;
            default: cout << "There are no operations with that index.\n";
        }
    } while (choice != 0);
    delete[] arr;
    return 0;
}

void printArray(int arr[], int length)
{
    cout << "The array is: ";
    for (int i = 0; i < length; ++i) cout << arr[i] << ' ';
    cout << '\n';
}

int getSum(int arr[], int length)
{
    int ans = 0;
    for (int i = 0; i < length; ++i) ans += arr[i];
    return ans;
}

int largestValue(int arr[], int length)
{
    int maxi = arr[0];
    for (int i = 1; i < length; ++i)
    {
        if (maxi < arr[i]) maxi = arr[i];
    }
    return maxi;
}

void deleteElement(int *&arr, int &length, int x)
{
    int idx = -1;
    for (int i = 0; i < length; ++i)
    {
        if (arr[i] == x)
        {
            idx = i;
            break;
        }
    }
    if (idx == -1)
    {
        cout << "There are no elements in the array that has the value " << x << '\n';
        return;
    }
    int *newArr = new int[length - 1];
    for (int i = 0; i < idx; ++i) newArr[i] = arr[i];
    for (int i = idx + 1; i < length; ++i) newArr[i - 1] = arr[i];
    length--;
    delete[] arr;
    arr = newArr;
}

void insertElement(int *&arr, int &length, int id, int x)
{
    int *newArr = new int[length + 1];
    if (id < 0) id = 0;
    if (id > length) id = length;
    for (int i = 0; i < id; ++i) newArr[i] = arr[i];
    newArr[id] = x;
    for (int i = id; i < length; ++i) newArr[i + 1] = arr[i];
    length++;
    delete[] arr;
    arr = newArr;
}

void reverseArray(int *&arr, int length)
{
    for (int i = 0; i < length / 2; ++i)
    {
        int temp = arr[i];
        arr[i] = arr[length - i - 1];
        arr[length - i - 1] = temp;
    }
}

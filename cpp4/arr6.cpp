#include <iostream>
using namespace std;

int main() {
    int arr[3] = {10, 20, 30};

    cout << arr << " " << arr+1 << endl;
    cout << arr[0] << " " << arr[1] << endl;
    cout << &arr[0] << " " << &arr[1] << endl;
    cout << *arr << " " << *(arr+1) << endl;
    
    return 0;
}

// 0x7ffd1073e69c 0x7ffd1073e6a0
// 10 20
// 0x7ffd1073e69c 0x7ffd1073e6a0
// 10 20
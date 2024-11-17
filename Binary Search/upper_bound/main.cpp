#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    std::vector<int> arr = {1, 2, 4, 4, 5, 6, 8};

    int x = 9;
    auto it = upper_bound(arr.begin(), arr.end(), x);
    
    int index = it - arr.begin();

    cout << "Index of the first element greater than " << x << " is " << index << '\n';
    cout<<"Element = "<<*it<<endl;
    return 0;
}

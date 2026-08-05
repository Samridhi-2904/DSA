#include<iostream>
using namespace std;
int findunique(int *arr,int size){
    int ans=0;
    for (int i = 0; i < size; i++)
    {
        ans=ans^arr[i];
    }
    return ans;
}

int main(){

    int arr[7] = {2, 3, 5, 2, 3, 5, 7};

    int unique = findunique(arr, 7);

    cout << "Unique element is: " << unique << endl;

    return 0;
}
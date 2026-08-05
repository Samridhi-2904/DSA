// #include <stdio.h>

// void read(int n,int arr[]){
//     printf("enter elements: ");
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d",&arr[i]);
//     }

// }
// void display(int n,int arr[]){
//     printf("Elements of array :\n");
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d \n",arr[i]);
//     }

// }
// int linear_search(int n, int arr[]) {
//     int key;
//     printf("Enter key value: ");
//     scanf("%d", &key);
//     for (int i = 0; i < n; i++) {
//         if (arr[i] == key) {
//             return 0;
//         }
//     }
//     return -1;
// }

// int main(){
//     int n;
//     printf("enter size of array");
//     scanf("%d",&n);
//     int arr[n];
//     read(n,arr);
//     display(n,arr);
//     int result = linear_search(n,arr);
//     if (result == 0)
//     {
//         printf("Element found");
//     }
//     else
//     {
//         printf("Element not found");
//     }

//     return 0;

// }

#include <stdio.h>
void read(int n, int arr[])
{
    printf("enter elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}

int Binary(int n, int arr[])
{
    int key;
    printf("enter value to be searched: ");
    scanf("%d",&key);
    int first = 0;
    int last = n - 1;
    int mid;
    while (first <= last)
    {
        mid = (first + last) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            first = mid + 1;
        }
        else
        {
            last = mid - 1;
        }
    }
    return -1;
}

int main(){
    int n;
    printf("enter size: ");
    scanf("%d",&n);
    int arr[n];
    read(n,arr);
    int result=Binary(n,arr);
    if(result!=-1){
        printf("number found at %d",result);
    }
    else{
        printf("element not found");
    }
    return 0;
}

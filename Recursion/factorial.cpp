#include <iostream>

using namespace std;

int factorial(int x)
{
    if (x == 0)
    {
        return 1;
    }
    int small = factorial(x - 1);
    int larger = x * small;
    return larger;
}

int main()
{
    int x;
    cin >> x;
    int answer = factorial(x);
    cout << answer;
    return 0;
}

#include <iostream>

using namespace std;

void reachhome(int src,int dest){
    cout<<"Source "<<src<<" destination "<<dest<<endl;
    if(src==dest){
        cout<<"reached"<<endl;
        return;
    }
    src++;
    reachhome(src,dest);
}
int main(){
    int dest;
    cout<<"enter your destination:"<<endl;
    cin>>dest;

    int src;
    cout<<"enter source:"<<endl;
    cin>>src;

    reachhome(src,dest);

    return 0;
}
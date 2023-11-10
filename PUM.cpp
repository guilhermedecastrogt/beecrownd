#include <iostream>

using namespace std;

int main(){

    int n, s1 = 1,s2 = 2,s3 = 3;
    cin>>n;

    for (int i = 0; i < n; i++){

        cout<<s1<<" "<<s2<<" "<<s3<<" PUM"<<endl;
        s1 = s1 + 4;
        s2 = s2 + 4;
        s3 = s3 + 4;

    }

}
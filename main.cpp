#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int i, x, y, z;
    const int n = 10;
    double min, max, a[n];
    double sum=0;
    double pr=1;
    cout << "klaviatura - chislo < 0, random - chislo >= 0 "<<endl;
    cin >> x;
    if (x < 0 ){
        for(i=0; i<n; i++) {
            cin >> a[i];
        }
        }
    else if(x>=0){
        cout<<"Vvedite min and max granicu intervala"<<endl;
        cin>>min>>max;
        for(i=0; i<n; i++) {
            a[i]=fmod((double) 10000*rand()/rand(), max-min) + min;
        }
    }
    for (i=0; i<n; i++){
        if(a[i]>0){
            sum=sum+a[i];
        }
    }
     for(i=0; i<n; i++) {
        cout<<a[i]<<" ";
    }
     cout<<endl;
     cout<<"sum = "<<sum<<endl;
    double modmax = a[1];
    for(i=0; i<n; i++) {
        if((abs(a[i]) - abs(modmax))>0){
            modmax=a[i];
            y=i;
        }
    }
    double modmin = a[1];
    for(i=0; i<n; i++) {
        if((abs(modmin)-abs(a[i]))>=0){
            modmin=a[i];
            z=i;
        }
    }
    for(i=y; i<=z; i++){
        pr=pr*a[i];
    }
    if(pr==1) {
        for(i=z; i<=y; i++){
            pr=pr*a[i];
        }
    }
    cout<<"proizvedenie = "<<pr<<endl;

    for(i=0; i<n; i++) {
        cout<<a[i]<<" ";
    }
    return 0;
}

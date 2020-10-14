#include <iostream>
using namespace std;
int main(){
    int nst, i, j;
    cout<<"Vvedite kol-vo strok(stolbtsov) :";
    cin>>nst;
    int **m = new int *[nst];
    for( i = 0; i<nst; i++){
        m[i] = new int [nst];
    }
    if(nst>10){
        cout<<"Razmernost doljjna bit ne bolshe 10"<<endl;
    }else{
        for( i = 0; i<nst; i++){
            for( j = 0; j<nst; j++){
                cin>>m[j][i];
            }
        }
        for( i = 0; i<nst; i++){
            for( j = 0; j<nst; j++){
                cout<<m[j][i]<<" ";
            }
            cout<<endl;
        }
        int kolvo=0;
        if (m[0][0]<m[1][0] && m[0][0]<m[0][1] && m[0][0]<m[1][1]){
            kolvo++;
        }
        if (m[nst-1][0]<m[nst-2][0] && m[nst-1][0]<m[nst-1][1] && m[nst-1][0]<m[nst-2][1]){
            kolvo++;
        }
        if (m[0][nst-1]<m[0][nst-2] && m[0][nst-1]<m[1][nst-1] && m[0][nst-1]<m[1][nst-2]){
            kolvo++;
        }
        if (m[nst-1][nst-1]<m[nst-2][nst-1] && m[nst-1][nst-1]<m[nst-1][nst-2] && m[nst-1][nst-1]<m[nst-2][nst-2]){
            kolvo++;
        }
        for(i=1; i<nst-1; i++){
            if(m[0][i]<m[0][i-1] && m[0][i]<m[0][i+1] && m[0][i]<m[1][i] && m[0][i]<m[1][i-1] && m[0][i]<m[1][i+1]){
                kolvo++;
            }
            if(m[i][0]<m[i-1][0] && m[i][0]<m[i+1][0] && m[i][0]<m[i][1] && m[i][0]<m[i-1][1] && m[i][0]<m[i+1][1]){
                kolvo++;
            }
            if(m[nst-1][i]<m[nst-1][i-1] && m[nst-1][i]<m[nst-1][i+1] && m[nst-1][i]<m[nst-2][i] && m[nst-1][i]<m[nst-2][i-1] && m[nst-1][i]<m[nst-2][i+1]){
                kolvo++;
            }
            if(m[i][nst-1]<m[i-1][nst-1] && m[i][nst-1]<m[i+1][nst-1] && m[i][nst-1]<m[i][nst-2] && m[i][nst-1]<m[i-1][nst-2] && m[i][nst-1]<m[i+1][nst-2]){
                kolvo++;
            }
        }
        for( i = 1; i<nst-1; i++){
            for( j = 1; j<nst-1; j++){
                if(m[j][i]<m[j-1][i-1] && m[j][i]<m[j-1][i] && m[j][i]<m[j-1][i+1] && m[j][i]<m[j][i-1] && m[j][i]<m[j][i+1] && m[j][i]<m[j+1][i-1] && m[j][i]<m[j+1][i] && m[j][i]<m[j+1][i+1]){
                    kolvo++;
                }
            }
        }
        cout<<"kolvo local minimumov "<<kolvo<<endl;
        int sum = 0;
        for(i=0; i<nst; i++){
            for(j=0; j<nst; j++){
                if(i<j){
                    sum=sum + m[j][i];
                }
            }
        }
        cout<<"summa moduley nad glavnoi diagonal "<<sum<<endl;
    }
    return 0;
}
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//statek 4masztowy - 14
//statek 3masztowy - 13
//statek 2masztowy - 12
//statek 1masztowy - 11
int main() {
    srand(time(NULL))
/*cout << "Witaj marynazu" << endl;
int t[10][10];
for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
       t[i][j] = 0;
    }
}
for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
       cout << t[i][j] << " ";
    }
    cout<<endl;
}
cout<< "Wybierz miejsce statku czteromasztowego:(statek moze znajdowac sie tylko poziomo lub pionowo) "<<endl;
for (int i=0; i<4; i++){
int a, b;
cin >> a >> b;
t[a-1][b-1] = 1;
for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
       cout << t[i][j] << " ";
    }
    cout<<endl;
}
}
cout<< "Wybierz miejsce dwoch statkow trzymasztowych:(statek moze znajdowac sie tylko poziomo lub pionowo) "<<endl;
for (int i=0; i<6; i++){
int a, b;
cin >> a >> b;
t[a-1][b-1] = 1;
for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
       cout << t[i][j] << " ";
    }
    cout<<endl;
}
}
cout<< "Wybierz miejsce trzech statkow dwumasztowych:(statek moze znajdowac sie tylko poziomo lub pionowo) "<<endl;
for (int i=0; i<6; i++){
int a, b;
cin >> a >> b;
t[a-1][b-1] = 1;
for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
       cout << t[i][j] << " ";
    }
    cout<<endl;
}
}
cout<< "Wybierz miejsce czterech statkow czteromasztowych: "<<endl;
for (int i=0; i<4; i++){
int a, b;
cin >> a >> b;
t[a-1][b-1] = 1;
for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
       cout << t[i][j] << " ";
    }
    cout<<endl;
}
}*/
//Wybieraniie miejs statków zakończyone
int p[10][10];
int a=rand() % 9, b=rand() % 9;
 p[a][b]=1;
int c=rand() % 1;
if(c==1)
{
    if (b>5)
    {
        b=b-3;
    }
    p[a][b+1]=1;
    p[a][b+2]=1;
    p[a][b+3]=1;
}
else
{
    if (a>5)
    {
        a=a-3;
    }
    p[a+1][b]=1;
    p[a+2][b]=1;
    p[a+3][b]=1;
}
for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
       cout << [i][j] << " ";
    }
    cout<<endl;
}
}



void sprawdzanie_statku()
{
    int a,b;
    a=a-1;
    b=b-1;
    if(p[a][b]==2){
    if(p[a][b-1]==0 && p[a][b+1]==0 && p[a-1][b]==0 && p[a+1][b]==0)
    {
    cout << "Zatopiony!"<<endl;
    }
    else if(p[a][b]==14){

    }
    else if(p[a][b]==13){

    }
    else if(p[a][b]==12){

    }
    }
}

void strzelanie_gracza()
{
int r,k;
cout << "Podaj wspolrzedne strzalu: "<<endl;
cin >> r >> k;
if(p[r-1][k-1]==0)
{
    cout << "Pudlo!"<<endl;
}
else if(p[r-1][k-1]==1)
{
    cout << "Trafiony!"<<endl;
    p[r-1][k-1]=2;
    r=r-1;
    k=k-1;
    if(p[a][b]==2){
    if(p[r][k-1]==0 && p[r][k+1]==0 && p[r-1][k]==0 && p[r+1][k]==0)
    {
    cout << "Zatopiony!"<<endl;
    }
    else if(p[r][k]==14){

    }
    else if(p[r][k]==13){

    }
    else if(p[r][k]==12){

    }
    }
}
}




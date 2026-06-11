#include <iostream>
#include<bits/stdc++.h>
//0-->pusto
//1-->statek
//2-->trafiony
//3-->zatopiony
//4-->muszą być puste
//5-->trafione pudło


using namespace std;
int t[10][10];
int p[10][10];
void wyswietl_gracz(){
    cout<<"        TWOJA PLANSZA                          PLANSZA KOMPUTERA"<<endl<<"     1. 2. 3. 4. 5. 6. 7. 8. 9. 10.         1. 2. 3. 4. 5. 6. 7. 8. 9. 10."<<endl;
    for(int i=0; i<10; i++){
    if(i<9) cout<<i+1<<".  ";
    if (i==9) cout<<"10. ";
    for(int j=0; j<10; j++){
            if(t[i][j]==0) cout << "[_]";
            if(t[i][j]==1) cout << "[O]";
    }
    if(i<9) cout<<"     "<<i+1<<".  ";
    if (i==9) cout<<"     10. ";
    for(int j=0; j<10; j++){
            if(p[i][j]==0 || p[i][j]==1|| p[i][j]==4) cout << "[_]";
            if(p[i][j]==2) cout << "[X]";
            if(p[i][j]==3) cout << "[Z]";
            if(p[i][j]==5) cout << "[-]";
    }
    cout<<endl;
    }
}
int main() {
        srand(time(NULL));
cout << "Witaj marynazu" << endl;
wyswietl_gracz();

/*cout<< "Podaj wspolrzedne statku czteromasztowego:"<<endl;
for (int i=0; i<4; i++){
int a,b;
cout<<"Rzad: ";
cin>>a;
cout<<"Kolumna: ";
cin>>b;
t[a-1][b-1] = 1;
wyswietl_gracz();
}

for(int i=0; i<2;i++){
cout<< "Podaj wspolrzedne  statku trzymasztowego:"<<endl;
for (int i=0; i<3; i++){
int a,b;
cout<<"Rzad: ";
cin>>a;
cout<<"Kolumna: ";
cin>>b;
t[a-1][b-1] = 1;
wyswietl_gracz();
}
}

for(int i=0; i<3;i++){
cout<< "Podaj wspolrzedne statku dwumasztowego "<<endl;
for (int i=0; i<2; i++){
int a,b;
cout<<"Rzad: ";
cin>>a;
cout<<"Kolumna: ";
cin>>b;
t[a-1][b-1] = 1;
wyswietl_gracz();
}
}

for(int i=0;i<4;i++){
cout<< "Podaj wspolrzedne statku jednomasztowego "<<endl;
for (int i=0; i<1; i++){
int a,b;
cout<<"Rzad: ";
cin>>a;
cout<<"Kolumna: ";
cin>>b;
t[a-1][b-1] = 1;
wyswietl_gracz();
}
}
*/
//Wybieraniie miejs statków zakończyone

int a=rand() % 9, b=rand() % 9;
if(b>5) b=5;
p[b][a]=1;
p[b+1][a]=1;
p[b+2][a]=1;
p[b+3][a]=1;

 for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
    cout<< p[i][j]<<" ";
    }
    cout<<endl;
}
cout<<endl;

for(int i=0; i<2;i++){
    do{
    a=rand() % 10, b=rand() % 10;
    if(a>7) a=7;
    }while(p[b-1][a]!=0 || p[b-1][a+1]!=0 || p[b-1][a+2]!=0 || p[b][a-1]!=0 || p[b][a]!=0 || p[b][a+1]!=0 && p[b][a+2]!=0 || p[b][a+3]!=0 || p[b+1][a]!=0 || p[b+1][a+1]!=0 || p[b+1][a+2]!=0 || p[b-1][a-1]!=0 || p[b+1][a-1]!=0 || p[b-1][a+3]!=0 || p[b+1][a+3]!=0);

    p[b][a]=1;
    p[b][a+1]=1;
    p[b][a+2]=1;

for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
    cout<< p[i][j]<<" ";
    }
    cout<<endl;
    }
    cout<<endl;
}


for(int i=0; i<3;i++){
    do{
    a=rand() % 10, b=rand() % 10;
    if(b>8) b=8;
    }while(p[b-1][a]!=0 || p[b][a-1]!=0 || p[b][a+1]!=0 || p[b][a]!=0 || p[b+1][a+1]!=0 || p[b+1][a-1]!=0 || p[b+1][a]!=0 || p[b+2][a]!=0 || p[b-1][a-1]!=0 || p[b-1][a+1]!=0 || p[b+2][a-1]!=0 || p[b+2][a+1]!=0);

    p[b][a]=1;
    p[b+1][a]=1;

for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
    cout<< p[i][j]<<" ";
    }
    cout<<endl;
    }
    cout<<endl;
}


for(int i=0; i<4;i++){
    do{
    a=rand() % 10, b=rand() % 10;
    }while(p[b-1][a-1]!=0 || p[b-1][a]!=0 || p[b-1][a+1]!=0 || p[b][a-1]!=0 || p[b][a]!=0 || p[b][a+1]!=0 || p[b+1][a-1]!=0 || p[b+1][a]!=0 || p[b+1][a+1]!=0);

    p[b][a]=1;

for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
    cout<< p[i][j]<<" ";
    }
    cout<<endl;
    }
    cout<<endl;
}   
//losowanie miejsc przez komputer zakonczone
//strzelanie
int licz;
do{
licz=0;
//strzelanie gracza

    cout<<"Podaj wspolrzedne strzalu:"<<endl;
    int x,y;
    cout<<"Rzad: ";
    cin>>x;
    cout<<"Kolumna: ";
    cin>>y;
    x=x-1;
    y=y-1;
    if(p[x][y]==0){
        cout<<"Pudlo."<<endl;
        p[x][y]=5;
        wyswietl_gracz();
    }
    if (p[x][y]==1){
        p[x][y]=2;
            if(p[x-1][y-1]!=1 && p[x-1][y]!=1 && p[x-1][y+1]!=1 && p[x][y-1]!=1 && p[x][y]!=1 && p[x][y+1]!=1 && p[x+1][y-1]!=1 && p[x+1][y]!=1 && p[x+1][y+1]!=1){cout<<"Trafiony zatopiony."<<endl;
            p[x][y]=3;}
            else{ cout<<"Trafiony."<<endl;}
    
    wyswietl_gracz();



}
for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
    if(p[i][j]==1) licz++;
    if(t[i][j]==1) licz++;
    }
    }
}while(licz!= 0);
}
//trzeba poprawic zatopione bo gdy strzelimy w srodek i zaczniemy w jedną strone to i tak napisze ze zatopiony mimo ze reszta statku jest nietrafiona !!!!  
//wyłączanie programu ZAWSZE ctrl+c
/* void strzelanie_gracza()
{
int r,k;
cout << "Podaj wspolrzedne strzalu: "<<endl;
cout<<"Rzad: ";
    cin>>r;
    cout<<"Kolumna: ";
    cin>>k;
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
}*/
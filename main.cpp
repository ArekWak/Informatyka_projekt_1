#include <iostream>
#include<bits/stdc++.h>
//0-->pusto
//1-->statek
//2-->trafiony
//3-->zatopiony
//4-->muszą być puste
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
    }
    cout<<endl;
    }
}
int main() {
        srand(time(NULL));
cout << "Witaj marynazu" << endl;
wyswietl_gracz();

cout<< "Podaj wspolrzedne statku czteromasztowego:"<<endl;
for (int i=0; i<4; i++){
int a,b;
cin >> a >> b;
t[a-1][b-1] = 1;
wyswietl_gracz();
}

for(int i=0; i<2;i++){
cout<< "Podaj wspolrzedne  statku trzymasztowego:"<<endl;
for (int i=0; i<3; i++){
int a,b;
cin >> a >> b;
t[a-1][b-1] = 1;
wyswietl_gracz();
}
}

for(int i=0; i<3;i++){
cout<< "Podaj wspolrzedne statku dwumasztowego "<<endl;
for (int i=0; i<2; i++){
int a,b;
cin >> a >> b;
t[a-1][b-1] = 1;
wyswietl_gracz();
}
}

for(int i=0;i<4;i++){
cout<< "Podaj wspolrzedne statku jednomasztowego "<<endl;
for (int i=0; i<1; i++){
int a,b;
cin >> a >> b;
t[a-1][b-1] = 1;
wyswietl_gracz();
}
}

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
//do{}while()
}
#include <iostream>
using namespace std;

int main() {
cout << "Witaj marynazu" << endl;
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
}
//Wybieraniie miejs statków zakończyone


}

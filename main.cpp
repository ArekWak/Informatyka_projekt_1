#include <iostream>
#include <bits/stdc++.h>
// 0-->pusto
// 11-->statek jednomasztowy
// 12-->statek dwumasztowy
// 13-->statek trzymasztowy
// 14-->statek czteromasztowy
// 2-->trafiony
// 3-->zatopiony
// 4-->muszą być puste
// 5-->trafione pudło

//umieszczane przez komputer:
//dwumasztowe-pion
//trzymasztowe-poziom
//czteromasztowe-pion
using namespace std;
int t[10][10];
int p[10][10];
void wyswietl_gracz()
{
    cout << "        TWOJA PLANSZA                          PLANSZA KOMPUTERA" << endl
         << "     1. 2. 3. 4. 5. 6. 7. 8. 9. 10.         1. 2. 3. 4. 5. 6. 7. 8. 9. 10." << endl;
    for (int i = 0; i < 10; i++)
    {
        if (i < 9)
            cout << i + 1 << ".  ";
        if (i == 9)
            cout << "10. ";
        for (int j = 0; j < 10; j++)
        {
            if (t[i][j] == 0)
                cout << "[_]";
            if (t[i][j] == 14 || t[i][j] == 13 || t[i][j] == 12 || t[i][j] == 11)
                cout << "[O]";
        }
        if (i < 9)
            cout << "     " << i + 1 << ".  ";
        if (i == 9)
            cout << "     10. ";
        for (int j = 0; j < 10; j++)
        {
            if (p[i][j] == 0 || p[i][j] == 4 || p[i][j] == 14 || p[i][j] == 13 || p[i][j] == 12 || p[i][j] == 11)
                cout << "[_]";
            else if (p[i][j] == 2)
                cout << "[X]";
            else if (p[i][j] == 3)
                cout << "[Z]";
            else if (p[i][j] == 5)
                cout << "[-]";
        }
        cout << endl;
    }
}

void strzelanie_gracza()
{
    int r, k;
    cout << "Podaj wspolrzedne strzalu: " << endl;
    cout << "Rzad: ";
    cin >> r;
    cout << "Kolumna: ";
    cin >> k;
    if (p[r - 1][k - 1] == 0)
    {
        cout << "PUDLO!" << endl;
        p[r - 1][k - 1] = 5;
    }
    else if (p[r - 1][k - 1] == 11)
    {
        cout << "TRAFIONY ZATOPIONY!" << endl;
        p[r - 1][k - 1] = 3;
    }
    else if (p[r - 1][k - 1] == 12)
    {
        r = r - 1;
        k = k - 1;
        if (p[r][k - 1] == 12 || p[r - 1][k] == 12 || p[r + 1][k] == 12 || p[r][k + 1] == 12)
        {
            cout << "TRAFIONY!" << endl;
            p[r][k] = 2;
        }
        else
        {
            cout << "TRAFIONY ZATOPIONY!" << endl;
            p[r][k] = 3;
            if(p[r][k - 1] == 2) p[r][k - 1]=3;
            else if(p[r - 1][k] == 2) p[r - 1][k]=3;
            else if(p[r + 1][k] == 2) p[r + 1][k]=3;
            else if(p[r][k + 1] == 2) p[r][k + 1]=3;

        }
    }
    else if (p[r - 1][k - 1] == 13)
    {
        r=r-1;
        k=k-1;
        if(p[r][k+1]==2 && p[r][k-1]==2)
        {
            cout << "TRAFIONY ZATOPIONY!" << endl;  
            p[r][k+1]=3;
            p[r][k-1]=3;
            p[r][k]=3;
        }
        else if(p[r][k+1]==2 && p[r][k+2]==2)
        {
            cout << "TRAFIONY ZATOPIONY!" << endl;
            p[r][k+1]=3;
            p[r][k+2]=3;
            p[r][k]=3;
        }
        else if(p[r][k-1]==2 && p[r][k-2]==2)
        {
            cout << "TRAFIONY ZATOPIONY!" << endl;
            p[r][k-2]=3;
            p[r][k-1]=3;
            p[r][k]=3;
        }
        else
        {
            cout << "TRAFIONY!" << endl;
            p[r][k] = 2;
        }
    }
    else if (p[r - 1][k - 1] == 14)
    {
    }
    wyswietl_gracz();
}

int main()
{
    srand(time(NULL));
    cout << "Witaj marynazu" << endl;
    wyswietl_gracz();
    
// wpisywanie wspólrzędnych

    /*cout<< "Podaj wspolrzedne statku czteromasztowego:"<<endl;
    for (int i=0; i<4; i++){
    int a,b;
    cout<<"Rzad: ";
    cin>>a;
    cout<<"Kolumna: ";
    cin>>b;
    t[a-1][b-1] = 14;
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
    t[a-1][b-1] = 13;
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
    t[a-1][b-1] = 12;
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
    t[a-1][b-1] = 11;
    wyswietl_gracz();
    }
    }
    */
// Wybieraniie miejsc statków zakończone
//losowanie przez komputer

    int a = rand() % 9, b = rand() % 9;
    if (b > 5)
        b = 5;
    p[b][a] = 14;
    p[b + 1][a] = 14;
    p[b + 2][a] = 14;
    p[b + 3][a] = 14;

    for (int i = 0; i < 2; i++)
    {
        do
        {
            a = rand() % 10, b = rand() % 10;
            if (a > 7)
                a = 7;
        } while (p[b - 1][a] != 0 || p[b - 1][a + 1] != 0 || p[b - 1][a + 2] != 0 || p[b][a - 1] != 0 || p[b][a] != 0 || p[b][a + 1] != 0 && p[b][a + 2] != 0 || p[b][a + 3] != 0 || p[b + 1][a] != 0 || p[b + 1][a + 1] != 0 || p[b + 1][a + 2] != 0 || p[b - 1][a - 1] != 0 || p[b + 1][a - 1] != 0 || p[b - 1][a + 3] != 0 || p[b + 1][a + 3] != 0);

        p[b][a] = 13;
        p[b][a + 1] = 13;
        p[b][a + 2] = 13;
    }

    for (int i = 0; i < 3; i++)
    {
        do
        {
            a = rand() % 10, b = rand() % 10;
            if (b > 8)
                b = 8;
        } while (p[b - 1][a] != 0 || p[b][a - 1] != 0 || p[b][a + 1] != 0 || p[b][a] != 0 || p[b + 1][a + 1] != 0 || p[b + 1][a - 1] != 0 || p[b + 1][a] != 0 || p[b + 2][a] != 0 || p[b - 1][a - 1] != 0 || p[b - 1][a + 1] != 0 || p[b + 2][a - 1] != 0 || p[b + 2][a + 1] != 0);

        p[b][a] = 12;
        p[b + 1][a] = 12;
    }

    for (int i = 0; i < 4; i++)
    {
        do
        {
            a = rand() % 10, b = rand() % 10;
        } while (p[b - 1][a - 1] != 0 || p[b - 1][a] != 0 || p[b - 1][a + 1] != 0 || p[b][a - 1] != 0 || p[b][a] != 0 || p[b][a + 1] != 0 || p[b + 1][a - 1] != 0 || p[b + 1][a] != 0 || p[b + 1][a + 1] != 0);

        p[b][a] = 11;
    }
    for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                cout << p[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    // losowanie miejsc przez komputer zakonczone
    // strzelanie
    int licz;
    do
    {
        licz = 0;
        // strzelanie gracza
        strzelanie_gracza();

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (p[i][j] == 14 || p[i][j] == 13 || p[i][j] == 12 || p[i][j] == 11)
                    licz++;
                if (t[i][j] == 14 || t[i][j] == 13 || t[i][j] == 12 || t[i][j] == 11)
                    licz++;
            }
        }
    } while (licz != 0);
}
// trzeba poprawic zatopione bo gdy strzelimy w srodek i zaczniemy w jedną strone to i tak napisze ze zatopiony mimo ze reszta statku jest nietrafiona !!!!
// wyłączanie programu ZAWSZE ctrl+c

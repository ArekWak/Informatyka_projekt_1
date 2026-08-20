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

// umieszczane przez komputer:
// dwumasztowe-pion
// trzymasztowe-poziom
// czteromasztowe-pion
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
/*void strzelanie_komputer()
{
    // ostatni => ostatni trafiony
    if (ostatni == 3) // zatopiony
    {
        int rz = rand() % 9, kol = rand() % 9;
        if (t[rz][kol] == 4 || t[rz][kol] == 3 || t[rz][kol] == 2)
        {
            do
            {
                rz = rand() % 9;
                kol = rand() % 9;
            } while (t[rz][kol] != 4 && t[rz][kol] != 3 && t[rz][kol] != 2);
        }
        cout<<"Rząd: "<<rz<<"Kolumna: "<<kol;
        if (t[rz][kol] == 0)
        {
            t[rz][kol] = 5;
        }
        else if (t[rz][kol] == 11)
        {
            t[rz][kol] = 3;
            ostatni = 3;
            t[rz-1][kol-1] = 4;
            t[rz-1][kol+1] = 4;
            t[rz-1][kol] = 4;
            t[rz+1][kol-1] = 4;
            t[rz+1][kol+1] = 4;
            t[rz+1][kol] = 4;
            t[rz][kol-1] = 4;
            t[rz][kol+1] = 4;
        }
        else if (t[rz][kol] == 12)
        {
            t[rz][kol] == 2;
        }
        else if (t[rz][kol] == 13)
        {
             t[rz][kol] == 2;
        }
        else if (t[rz][kol] == 14)
        {
             t[rz][kol] == 2;
        }
    }
    else if (ostatni == 2) // trafiony
    {
    }
}
*/

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
            if (p[r][k - 1] == 2)
                p[r][k - 1] = 3;
            else if (p[r - 1][k] == 2)
                p[r - 1][k] = 3;
            else if (p[r + 1][k] == 2)
                p[r + 1][k] = 3;
            else if (p[r][k + 1] == 2)
                p[r][k + 1] = 3;
        }
    }
    else if (p[r - 1][k - 1] == 13)
    {
        r = r - 1;
        k = k - 1;
        if (p[r][k + 1] == 2 && p[r][k - 1] == 2)
        {
            cout << "TRAFIONY ZATOPIONY!" << endl;
            p[r][k + 1] = 3;
            p[r][k - 1] = 3;
            p[r][k] = 3;
        }
        else if (p[r][k + 1] == 2 && p[r][k + 2] == 2)
        {
            cout << "TRAFIONY ZATOPIONY!" << endl;
            p[r][k + 1] = 3;
            p[r][k + 2] = 3;
            p[r][k] = 3;
        }
        else if (p[r][k - 1] == 2 && p[r][k - 2] == 2)
        {
            cout << "TRAFIONY ZATOPIONY!" << endl;
            p[r][k - 2] = 3;
            p[r][k - 1] = 3;
            p[r][k] = 3;
        }
        else if (p[r - 1][k] == 2 && p[r + 1][k] == 2)
        {
            cout << "TRAFIONY ZATOPIONY!" << endl;
            p[r + 1][k] = 3;
            p[r - 1][k] = 3;
            p[r][k] = 3;
        }
        else if (p[r - 2][k] == 2 && p[r - 1][k] == 2)
        {
            cout << "TRAFIONY ZATOPIONY!" << endl;
            p[r - 2][k] = 3;
            p[r - 1][k] = 3;
            p[r][k] = 3;
        }
        else if (p[r + 2][k] == 2 && p[r + 1][k] == 2)
        {
            cout << "TRAFIONY ZATOPIONY!" << endl;
            p[r + 2][k] = 3;
            p[r + 1][k] = 3;
            p[r][k] = 3;
        }
        else
        {
            cout << "TRAFIONY!" << endl;
            p[r][k] = 2;
        }
    }
    else if (p[r - 1][k - 1] == 14)
    {
        r = r - 1;
        k = k - 1;
        if (p[r][k + 1] == 2 && p[r][k + 2] == 2 && p[r][k + 3] == 2)
        {
            cout << "TRAFIONY ZATOPIONY!" << endl;
            p[r][k] = 3;
            p[r][k + 1] = 3;
            p[r][k + 2] = 3;
            p[r][k + 3] = 3;
        }
        else if (p[r][k + 1] == 2 && p[r][k + 2] == 2 && p[r][k - 1] == 2)
        {
            cout << "TRAFIONY ZATOPIONY!" << endl;
            p[r][k] = 3;
            p[r][k + 1] = 3;
            p[r][k + 2] = 3;
            p[r][k - 1] = 3;
        }
        else if (p[r][k + 1] == 2 && p[r][k - 2] == 2 && p[r][k - 1] == 2)
        {
            cout << "TRAFIONY ZATOPIONY!" << endl;
            p[r][k] = 3;
            p[r][k + 1] = 3;
            p[r][k - 2] = 3;
            p[r][k - 1] = 3;
        }
        else if (p[r][k - 1] == 2 && p[r][k - 2] == 2 && p[r][k - 3] == 2)
        {
            cout << "TRAFIONY ZATOPIONY!" << endl;
            p[r][k] = 3;
            p[r][k - 3] = 3;
            p[r][k - 2] = 3;
            p[r][k - 1] = 3;
        }
        else if (p[r - 1][k] == 2 && p[r - 2][k] == 2 && p[r - 3][k] == 2)
        {
            cout << "TRAFIONY ZATOPIONY!" << endl;
            p[r - 1][k] = 3;
            p[r - 2][k] = 3;
            p[r - 3][k] = 3;
            p[r][k] = 3;
        }
        else if (p[r + 1][k] == 2 && p[r - 1][k] == 2 && p[r - 2][k] == 2)
        {
            cout << "TRAFIONY ZATOPIONY!" << endl;
            p[r - 2][k] = 3;
            p[r - 1][k] = 3;
            p[r][k] = 3;
            p[r + 1][k] = 3;
        }
        else if (p[r - 1][k] == 2 && p[r + 1][k] == 2 && p[r + 2][k] == 2)
        {
            cout << "TRAFIONY ZATOPIONY!" << endl;
            p[r - 1][k] = 3;
            p[r][k] = 3;
            p[r + 1][k] = 3;
            p[r + 2][k] = 3;
        }
        else if (p[r + 1][k] == 2 && p[r + 2][k] == 2 && p[r + 3][k] == 2)
        {
            cout << "TRAFIONY ZATOPIONY!" << endl;
            p[r][k] = 3;
            p[r + 1][k] = 3;
            p[r + 2][k] = 3;
            p[r + 3][k] = 3;
        }
        else
        {
            cout << "TRAFIONY!" << endl;
            p[r][k] = 2;
        }
    }
    wyswietl_gracz();
}

int main()
{
    srand(time(NULL));

    cout << "Witaj marynarzu" << endl;
    cout << "Umiesc statki losowo -> 1," << endl;
    cout << "umiesc statki recznie -> 0" << endl;
    int r_l;
    cin >> r_l;
    // umieszczaanie statkow
    // czteromasztowy
    if (r_l == 0)
    {
        cout << "Umieszczanie statku czteromasztowego";
        cout << "(pion-->'|'/poziom-->'-')" << endl;
        char kierunek;
        cin >> kierunek;
        if (kierunek == '|')
        {
            int c, d;
            cout << "Podaj wspolrzedne poczatku statku: " << endl
                 << "Rzad: ";
            cin >> d;
            cout << "Kolumna: ";
            cin >> c;
            c = c - 1;
            d = d - 1;
            if (d > 6)
            {
                d = 6;
                cout << "Zly numer rzedu -- rzad wynosi 7" << endl;
            }
            t[d][c] = 14;
            t[d + 1][c] = 14;
            t[d + 2][c] = 14;
            t[d + 3][c] = 14;
        }
        else if (kierunek == '-')
        {
            int c, d;
            cout << "Podaj wspolrzedne poczatku statku: " << endl
                 << "Rzad: ";
            cin >> d;
            cout << "Kolumna: ";
            cin >> c;
            c = c - 1;
            d = d - 1;
            if (c > 6)
            {
                c = 6;
                cout << "Zly numer kolumny -- kolumna wynosi 7" << endl;
            }
            t[d][c] = 14;
            t[d][c + 1] = 14;
            t[d][c + 2] = 14;
            t[d][c + 3] = 14;
        }
        else
        {
            cout << "Zly znak - koniec gry";
            return 0;
        }
        wyswietl_gracz();
        // trzymaszxtowe
        for (int i = 0; i < 2; i++)
        {
            cout << "Umieszczanie statku trzymasztowego";
            cout << "(pion-->'|'/poziom-->'-') " << endl;
            cin >> kierunek;
            int c, d;
            if (kierunek == '|')
            {
                cout << "Podaj wspolrzedne poczatku statku: " << endl
                     << "Rzad: ";
                cin >> d;
                cout << "Kolumna: ";
                cin >> c;
                c = c - 1;
                d = d - 1;
                if (d > 7)
                {
                    d = 7;
                    cout << "Zly numer rzedu -- rzad wynosi 8" << endl;
                }
                if (t[d - 1][c] == 0 && t[d - 1][c + 1] == 0 && t[d - 1][c - 1] == 0 && t[d][c - 1] == 0 && t[d][c] == 0 && t[d][c + 1] == 0 && t[d + 1][c - 1] == 0 && t[d + 1][c] == 0 && t[d + 1][c + 1] == 0 && t[d + 2][c - 1] == 0 && t[d + 2][c] == 0 && t[d + 2][c + 1] == 0 && t[d + 3][c - 1] == 0 && t[d + 3][c] == 0 && t[d + 3][c + 1] == 0)
                {
                    t[d][c] = 13;
                    t[d + 1][c] = 13;
                    t[d + 2][c] = 13;
                }
                else
                {
                    cout << "Zle wspolrzedne - spróbuj jeszcze raz" << endl;
                    i--;
                }
            }
            else if (kierunek == '-')
            {
                cout << "Podaj wspolrzedne poczatku statku: " << endl
                     << "Rzad: ";
                cin >> d;
                cout << "Kolumna: ";
                cin >> c;
                c = c - 1;
                d = d - 1;
                if (c > 7)
                {
                    c = 7;
                    cout << "Zly numer kolumny -- kolumna wynosi 8" << endl;
                }
                if (t[d - 1][c] == 0 && t[d - 1][c + 1] == 0 && t[d - 1][c + 2] == 0 && t[d][c - 1] == 0 && t[d][c] == 0 && t[d][c + 1] == 0 && t[d][c + 2] == 0 && t[d][c + 3] == 0 && t[d + 1][c] == 0 && t[d + 1][c + 1] == 0 && t[d + 1][c + 2] == 0 && t[d - 1][c - 1] == 0 && t[d + 1][c - 1] == 0 && t[d - 1][c + 3] == 0 && t[d + 1][c + 3] == 0)
                {
                    t[d][c] = 13;
                    t[d][c + 1] = 13;
                    t[d][c + 2] = 13;
                }
                else
                {
                    cout << "Zle wspolrzedne - spróbuj jeszcze raz" << endl;
                    i--;
                }
            }
            else
            {
                cout << "Zly znak - koniec gry";
                return 0;
            }
            wyswietl_gracz();
        }
        // dwumasztowe
        for (int i = 0; i < 3; i++)
        {
            cout << "Umieszczanie statku dwumasztowego";
            cout << "(pion-->'|'/poziom-->'-') " << endl;
            cin >> kierunek;
            int c, d;
            if (kierunek == '|')
            {
                cout << "Podaj wspolrzedne poczatku statku: " << endl
                     << "Rzad: ";
                cin >> d;
                cout << "Kolumna: ";
                cin >> c;
                c = c - 1;
                d = d - 1;
                if (d > 8)
                {
                    d = 8;
                    cout << "Zly numer rzedu -- rzad wynosi 9" << endl;
                }
                if (t[d - 1][c] == 0 && t[d - 1][c + 1] == 0 && t[d - 1][c - 1] == 0 && t[d][c - 1] == 0 && t[d][c] == 0 && t[d][c + 1] == 0 && t[d + 1][c - 1] == 0 && t[d + 1][c] == 0 && t[d + 1][c + 1] == 0 && t[d + 2][c - 1] == 0 && t[d + 2][c] == 0 && t[d + 2][c + 1] == 0)
                {
                    t[d][c] = 13;
                    t[d + 1][c] = 13;
                }
                else
                {
                    cout << "Zle wspolrzedne - spróbuj jeszcze raz" << endl;
                    i--;
                }
            }
            else if (kierunek == '-')
            {
                cout << "Podaj wspolrzedne poczatku statku: " << endl
                     << "Rzad: ";
                cin >> d;
                cout << "Kolumna: ";
                cin >> c;
                c = c - 1;
                d = d - 1;
                if (c > 8)
                {
                    c = 8;
                    cout << "Zly numer kolumny -- kolumna wynosi 9" << endl;
                }
                if (t[d - 1][c] == 0 && t[d - 1][c + 1] == 0 && t[d - 1][c + 2] == 0 && t[d][c - 1] == 0 && t[d][c] == 0 && t[d][c + 1] == 0 && t[d][c + 2] == 0 && t[d + 1][c] == 0 && t[d + 1][c + 1] == 0 && t[d + 1][c + 2] == 0 && t[d - 1][c - 1] == 0 && t[d + 1][c - 1] == 0)
                {
                    t[d][c] = 13;
                    t[d][c + 1] = 13;
                }
                else
                {
                    cout << "Zle wspolrzedne" << endl;
                    i--;
                }
            }
            else
            {
                cout << "Zly znak - koniec gry";
                return 0;
            }
            wyswietl_gracz();
        }
        // jednomasztowe

        for (int i = 0; i < 4; i++)
        {
            int c, d;
            cout << "Umieszczanie statku jednomasztowego" << endl;
            cout << "Podaj wspolrzedne  statku: " << endl
                 << "Rzad: ";
            cin >> d;
            cout << "Kolumna: ";
            cin >> c;
            c = c - 1;
            d = d - 1;

            if (t[d - 1][c] == 0 && t[d - 1][c + 1] == 0 && t[d - 1][c - 1] == 0 && t[d][c - 1] == 0 && t[d][c] == 0 && t[d][c + 1] == 0 && t[d + 1][c - 1] == 0 && t[d + 1][c] == 0 && t[d + 1][c + 1] == 0)
            {
                t[d][c] = 13;
            }
            else
            {
                cout << "Zle wspolrzedne" << endl;
                i--;
            }
            wyswietl_gracz();
        }
    }
    // losowe umieszczanie
    else if (r_l == 1)
    {
        int hk = rand() % 9, hr = rand() % 9;
        if (hr > 5)
            hr = 5;
        t[hr][hk] = 14;
        t[hr + 1][hk] = 14;
        t[hr + 2][hk] = 14;
        t[hr + 3][hk] = 14;

        for (int i = 0; i < 2; i++)
        {
            do
            {
                hk = rand() % 10, hr = rand() % 10;
                if (hk > 7)
                    hk = 7;
            } while (t[hr - 1][hk] != 0 || t[hr - 1][hk + 1] != 0 || t[hr - 1][hk + 2] != 0 || t[hr][hk - 1] != 0 || t[hr][hk] != 0 || t[hr][hk + 1] != 0 || t[hr][hk + 2] != 0 || t[hr][hk + 3] != 0 || t[hr + 1][hk] != 0 || t[hr + 1][hk + 1] != 0 || t[hr + 1][hk + 2] != 0 || t[hr - 1][hk - 1] != 0 || t[hr + 1][hk - 1] != 0 || t[hr - 1][hk + 3] != 0 || t[hr + 1][hk + 3] != 0);

            t[hr][hk] = 13;
            t[hr][hk + 1] = 13;
            t[hr][hk + 2] = 13;
        }

        for (int i = 0; i < 3; i++)
        {
            do
            {
                hk = rand() % 10, hr = rand() % 10;
                if (hr > 8)
                    hr = 8;
            } while (t[hr - 1][hk] != 0 || t[hr][hk - 1] != 0 || t[hr][hk + 1] != 0 || t[hr][hk] != 0 || t[hr + 1][hk + 1] != 0 || t[hr + 1][hk - 1] != 0 || t[hr + 1][hk] != 0 || t[hr + 2][hk] != 0 || t[hr - 1][hk - 1] != 0 || t[hr - 1][hk + 1] != 0 || t[hr + 2][hk - 1] != 0 || t[hr + 2][hk + 1] != 0);

            t[hr][hk] = 12;
            t[hr + 1][hk] = 12;
        }

        for (int i = 0; i < 4; i++)
        {
            do
            {
                hk = rand() % 10, hr = rand() % 10;
            } while (t[hr - 1][hk - 1] != 0 || t[hr - 1][hk] != 0 || t[hr - 1][hk + 1] != 0 || t[hr][hk - 1] != 0 || t[hr][hk] != 0 || t[hr][hk + 1] != 0 || t[hr + 1][hk - 1] != 0 || t[hr + 1][hk] != 0 || t[hr + 1][hk + 1] != 0);

            t[hr][hk] = 11;
        }
        wyswietl_gracz();
    }
    else
    {
        cout << "zly numer -  koniec gry";
        return 0;
    }

    // Wybieraniie miejsc statków zakończone
    // losowanie przez komputer

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
        } while (p[b - 1][a] != 0 || p[b - 1][a + 1] != 0 || p[b - 1][a + 2] != 0 || p[b][a - 1] != 0 || p[b][a] != 0 || p[b][a + 1] != 0 || p[b][a + 2] != 0 || p[b][a + 3] != 0 || p[b + 1][a] != 0 || p[b + 1][a + 1] != 0 || p[b + 1][a + 2] != 0 || p[b - 1][a - 1] != 0 || p[b + 1][a - 1] != 0 || p[b - 1][a + 3] != 0 || p[b + 1][a + 3] != 0);

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
    // wyswietlenie planszy wylosowanej
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
// wyłączanie programu ZAWSZE ctrl+c

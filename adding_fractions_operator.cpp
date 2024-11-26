#include <iostream>

using namespace std;

class Ulamek{
public:
    int licznik;
    int mianownik;

    //public:
    Ulamek(){};
    Ulamek(int l, int m);
    ~Ulamek(){};
    Ulamek operator+(const Ulamek &u1);
};

Ulamek::Ulamek(int l, int m){
    licznik=l;
    mianownik=m;
}

Ulamek Ulamek::operator+(const Ulamek &u1){

    Ulamek suma;
    suma.licznik = u1.licznik*mianownik + licznik*u1.mianownik;
    suma.mianownik = u1.mianownik*mianownik;
    return suma;
}

int main(){
    int l1, l2, m1, m2;
    cin>>l1>>m1>>l2>>m2;
    Ulamek u1(l1, m1);
    Ulamek u2(l2, m2);
    Ulamek u3;
    u3 = u1+u2;
    cout<<u3.licznik<<"/"<<u3.mianownik;
    return 0;
}

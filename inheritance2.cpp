/*
Given the square class, implement the external function Square increment(Square k);
which will return a square twice as large.
In the input, get the side of the square. In the output, write the area of the increased square.
 */

#include <iostream>

using namespace std;

class Square{

    friend Square increment(Square k);

    int a;

    public:
        Square(){};
        Square(int x);
        int getArea();
};

Square::Square(int x){
    a=x;
}

int Square::getArea(){
    return a*a;
}

Square increment(Square k){
    k.a*=2;
    return k;
}

int main(){
    int a;
    cin>>a;
    Square K = Square(a);
    K = increment(K);
    cout<<K.getArea();
    return 0;
}
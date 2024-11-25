/*
 Given the polygon class, implement the derived classes Triangle and Rectangle, which only have the getArea() method
 to calculate the area of the triangle and the area of the rectangle, respectively (integer data type).
 Add a global function getHeight that will return the value of the height variable for triangle T.
 */

#include <iostream>

using namespace std;

class Polygon{

    friend int getHeight(Polygon W);

    protected:
        int width, height;

    public:
        void set(int a, int b){
            width = a;
            height = b;
        }
};

class Triangle:public Polygon{
    public:
        int getArea(){
            return width*height/2;
        }
};

class Rectangle:public Polygon{
    public:
        int getArea(){
            return width*height;
        }
};

int getHeight(Polygon W){
    return W.height;
}

int main(){
    int a, b, c, d;
    cin>>a>>b>>c>>d;

    Triangle T;
    Rectangle P;
    T.set(a, b);
    P.set(c, d);

    cout<<T.getArea()<<" "<<P.getArea()<<endl;
    cout<<getHeight(T);

    return 0;
}

/*
 Define a Rectangle class containing private length width fields and an area method that returns the
 area of the rectangle. At the input, get the Rectangle parameters (length width) using a two-argument
 constructor until the length and width values are greater than 0 and save the data in the array of
 Rectangle objects, and display the area of the smallest rectangle at the output.
 */

#include <iostream>

using namespace std;

class Rectangle{
    private:
        double length;
        double width;

    public:
        Rectangle();
        Rectangle(double l, double w); //two-argument constructor
        ~Rectangle(); //destructor
        double area();
};

Rectangle::Rectangle(){
    length=0;
    width=0;
}

Rectangle::Rectangle(double l, double w){
    length=l;
    width=w;
    //cout << "constructor ";
}

Rectangle::~Rectangle(){
    //cout << "destructor ";
}

double Rectangle::area(){
    return length*width;
}

int main(){
    int MAX=20;
    int counter=0;
    Rectangle tab[MAX];
    for(int i=0;;i++){
        double l, w;
        cin>>l>>w;
        if(w==0 || l==0) break;
        tab[i] = Rectangle(l,w);
        counter++;
    }

    double min_area = tab[0].area();
    for(int i=0;i<counter;i++){
        if(tab[i].area() < min_area){
            min_area = tab[i].area();
        }
    }
    cout<<min_area;

    return 0;
}

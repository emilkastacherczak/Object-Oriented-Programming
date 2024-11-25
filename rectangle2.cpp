/*
 Define a Rectangle class containing private length width fields and an area method that returns the area of
 the rectangle. At the input, get the parameters (length width) using a two-argument constructor until
 the length and width values are greater than 0 and save the data in the array of Rectangle objects.
 Using dynamic memory allocation create the tabcopy array and save all loaded Rectangle objects there,
 and display all the elements of the tabcopy array in the reverse order in the output.
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
        double getlength();
        double getwidth();
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

double Rectangle::getlength(){
    return length;
}

double Rectangle::getwidth(){
    return width;
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

    Rectangle *tabcopy = new Rectangle[counter];
    for(int i=0;i<counter;i++){
        tabcopy[i] = tab[i];
    }
    for(int i=counter-1;i>=0;i--){
        cout<<tabcopy[i].getwidth()<<" "<<tabcopy[i].getlength()<<" ";
    }

    delete [] tabcopy;
    return 0;
}
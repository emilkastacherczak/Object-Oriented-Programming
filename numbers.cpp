#include <iostream>

using namespace std;

int n_counter, p_counter;

class Number{
    int n;

public:
    Number();
    void add(int N);
    bool isPrime();
    void display();
    int getTotalCount();
    int getPrimeCount();
    ~Number();
};

Number::Number(){
    n=0;
}

void Number::add(int N){
    n=N;
    n_counter++;
    if( isPrime() ) p_counter++;
}

bool Number::isPrime(){
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}

void Number::display(){
    cout<<"Number: "<<n<<" is ";
    if(!isPrime()) cout<<"no";
    cout<<" a prime number."<<endl;
}

int Number::getTotalCount(){
    return n_counter;
}

int Number::getPrimeCount(){
    return p_counter;
}

Number::~Number(){
    cout<<"Object Number "<<n<<" has been deleted."<<endl;
    n_counter--;
    if( isPrime() ) p_counter--;
}

int main(){
    int n;
    Number *tab_wn[4];
    for(int i=0;i<4;i++){
        tab_wn[i] = new Number();
        cin>>n;
        tab_wn[i]->add(n);
        tab_wn[i]->display();
    }
    int j=3;
    for(int i=0;i<4;i++){
        cout<<"Total number of objects: "<<tab_wn[i]->getTotalCount()<<endl;
        cout<<"The number of objects representing prime numbers: "<<tab_wn[i]->getPrimeCount()<<endl;
        tab_wn[j]->~Number();
        j--;
    }
    cout<<"Total number of objects: "<<tab_wn[0]->getTotalCount()<<endl;
    cout<<"The number of objects representing prime numbers: "<<tab_wn[0]->getPrimeCount()<<endl;
    return 0;
}

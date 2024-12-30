#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

class ShoppingCart{
private:
    struct Product{
        string name;
        int amount;
        float price;
        float value;
    };

    vector<Product> cart;

public:
    ShoppingCart();
    void addProduct(string name1, int amount1, float price1);
    void displayCart();
    void removeProduct(long unsigned int idx);
    float calculateTotal();
};

ShoppingCart::ShoppingCart(){
    Product p0;
    p0.name = "-";
    p0.amount = 0;
    p0.price = 0;
    p0.value = 0;
}

void ShoppingCart::addProduct(string name1, int amount1, float price1){
    Product p;
    p.name = name1;
    p.amount = amount1;
    p.price = price1;
    p.value = amount1*price1;
    cart.push_back(p);
}

void ShoppingCart::displayCart(){
    cout<<"Name | Amount | Price | Value"<<endl;
    for(auto product : cart){ //iteracja po wektorze cart, zapisuje kolejne el do product; auto okresla automatycznie typ el wektora
        cout<<product.name<<" | "<<product.amount<<" | "<<product.price<<" PLN | "<<product.value<<" PLN"<<endl;
    }

}

void ShoppingCart::removeProduct(long unsigned int idx){
    if(idx<=0 && idx>cart.size()){
        cout<<"Wrong index"<<endl;
    }
    else{
        cart.erase(cart.begin() + idx);
    }
}

float ShoppingCart::calculateTotal(){
    float total=0;
    for(auto product : cart){
        total += product.value;
    }
    return total;
}

int main(){
    ShoppingCart myCart;

    string my_name;
    int my_amount;
    float my_price;

    for(int i=0;i<3;i++){
        cin>>my_name>>my_amount>>my_price;
        myCart.addProduct(my_name, my_amount, my_price);
    }

    myCart.displayCart();

    long unsigned int n;
    cin>>n;
    myCart.removeProduct(n);
    cout<<endl<<"after removing the product: "<<endl;
    myCart.displayCart();

    cout<<"The total cost of the products in the basket: "<<myCart.calculateTotal()<<" PLN"<<endl;

    return 0;
}

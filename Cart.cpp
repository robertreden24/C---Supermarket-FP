#include "Cart.h"

Carts::Carts(){

}

void Carts::addToCart(int po, int q, vector<Items> ss){
    Items s = ss[po-1];
    bool found = false;
    for(int i = 0; i < Cart.size(); i++){
        if(Cart[i].get_name() == s.get_name()){
            found = true;
            Cart[i].addQuantity(q);
        }
    }
    if(found == false){
        s.set_quantity(q);
        Cart.push_back(s);
    }
}

void Carts::removeFromCart(int po,int q){
    bool found = false;
    int check = Cart[po-1].get_quantity() - q;

    for(int i = 0; i < Cart.size(); i++){
        if((po-1) == i){
            found = true;
            if(check == 0){
                cout << Cart[po-1].get_name() << " removed from cart" << endl;
                Cart.erase(Cart.begin() + po - 1);
            }
            else if(check > 0){
                Cart[po-1].reduceQuantity(q);
                cout << Cart[po-1].get_name() << " removed from cart" << endl;
            }
            else{
                cout << "invalid amount" << endl;
            }
        }
    }
    if(found == false){
        cout << "Item not found in cart!" << endl;
    }
}

void Carts::displayCart(){
    cout << "============================" << endl
         << "Cart" << endl
         << "============================" << endl;

    for(int i = 0; i < Cart.size(); i++){
        cout << i + 1 << ". " << Cart[i].get_name() << " quantity: " << Cart[i].get_quantity() << endl;
    }
}

vector<Items> Carts::getCart(){
    return Cart;
}

void Carts::printBill(){
    double total, pay, change;
    double subtotal = 0;
    cout << "==========================================================" << endl
         << "Product              " << "Price         " << "Quantity     " << "Total" << endl
         << "==========================================================" << endl;
    for(int i = 0; i < Cart.size(); i++){
        total = Cart[i].get_price() * Cart[i].get_quantity();
        subtotal += Cart[i].get_price() * Cart[i].get_quantity();
        printf("%-18s | $%-10f | %-10d | $%-10f\n", Cart[i].get_name().c_str(), Cart[i].get_price(), Cart[i].get_quantity(), total);
    }
    printf("%49c%f\n", '$', subtotal);
    while(true){
        cout << "Enter amount:" << endl;
        cin >> pay;
        change = pay-subtotal;
    
        if(change < 0){
            cout << "invalid amount" << endl;
        }
        else{
            printf("%48s%c%f\n", "Change: ", '$', change);
            cout << "\n==========================================================" << endl
                 << "Thank you for shopping with us!" << endl
                 << "==========================================================" << endl;
            break;
        }
    }
}

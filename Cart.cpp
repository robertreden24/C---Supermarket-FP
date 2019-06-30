#include "Cart.h"

//Cart constructor
Carts::Carts(){

}

//function to delete all items in Cart
void Carts::clearCart(){
    Cart.clear();
}

//function to add an item into the cart
void Carts::addToCart(int po, int q, vector<Items> ss){
    Items s = ss[po-1];
    bool found = false;

    for(int i = 0; i < Cart.size(); i++){
        //add quantity of item in Cart if item is already found in Cart
        if(Cart[i].get_name() == s.get_name()){
            found = true;
            Cart[i].addQuantity(q);
        }
    }
    //Put item in Cart if item is not found in Cart
    if(found == false){
        s.set_quantity(q);
        Cart.push_back(s);
    }
}

//function to remove an item from the cart
void Carts::removeFromCart(int po,int q){
    bool found = false;
    int check = Cart[po-1].get_quantity() - q;

    //loop to check if item is in Cart
    for(int i = 0; i < Cart.size(); i++){
        if((po-1) == i){
            found = true;
            //if quantity of item is 0 after removing then delete the item
            if(check == 0){
                cout << Cart[po-1].get_name() << " removed from cart" << endl;
                Cart.erase(Cart.begin() + po - 1);
            }
            //if quantity is >0 then just reduce the quantity
            else if(check > 0){
                Cart[po-1].reduceQuantity(q);
                cout << Cart[po-1].get_name() << " removed from cart" << endl;
            }
            //if quantity removed is more than quantity in Cart
            else{
                cout << "invalid amount" << endl;
            }
        }
    }
    //if item is not found in Cart
    if(found == false){
        cout << "Item not found in cart!" << endl;
    }
}

//funciton to display the items in the cart
void Carts::displayCart(){
    cout << "============================" << endl
         << "Cart" << endl
         << "============================" << endl;

    //loop to print all item in Cart
    for(int i = 0; i < Cart.size(); i++){
        cout << i + 1 << ". " << Cart[i].get_name() << " quantity: " << Cart[i].get_quantity() << endl;
    }
}

//getter function to return the Cart vector
vector<Items> Carts::getCart(){
    return Cart;
}

//function to print the bill and checkout
void Carts::printBill(){
    double total, pay, change;
    double subtotal = 0;
    cout << "==========================================================" << endl
         << "Product              " << "Price         " << "Quantity     " << "Total" << endl
         << "==========================================================" << endl;
    //print and calculate the total price of items(quantity*price) and subtotal(total price of all items)
    for(int i = 0; i < Cart.size(); i++){
        total = Cart[i].get_price() * Cart[i].get_quantity();
        subtotal += Cart[i].get_price() * Cart[i].get_quantity();
        printf("%-18s | $%-10f | %-10d | $%-10f\n", Cart[i].get_name().c_str(), Cart[i].get_price(), Cart[i].get_quantity(), total);
    }
    printf("%49c%f\n", '$', subtotal);
    while(true){
        cout << "Enter amount:" << endl;
        cin >> pay;
        //double change is customer pay - bill
        change = pay-subtotal;
        //if amount paid is less than the bill
        if(change < 0){
            cout << "invalid amount" << endl;
        }
        //transaction is successful
        else{
            printf("%48s%c%f\n", "Change: ", '$', change);
            cout << "\n==========================================================" << endl
                 << "Thank you for shopping with us!" << endl
                 << "==========================================================" << endl;
            break;
        }
    }
}

#include "supermarket.h"

void Supermarket::display(vector<Items> Stock){
     cout << "================================================" << endl
         << "    Product               " << "Price         " << "Quantity" << endl
         << "================================================" << endl;


    for(int i = 0; i < Stock.size(); i++){
        printf("%-2d. %-18s  | $%-10f | %-10d\n", i+1, Stock[i].get_name().c_str(), Stock[i].get_price(), Stock[i].get_quantity());
    }
    cout << "================================================" << endl;
}

void Supermarket::sm_option(){
    int opt;
    while(true){
       display(Stock);
        cout << "1. Add to cart" << endl
             << "2. Remove from cart" << endl
             << "3. View Cart" << endl
             << "4. Checkout" << endl
             << "5. Exit" << endl;
        cin >> opt;
        if(opt==1){
            sm_addToCart();
        }
        else if(opt==2){
            if(Cart.getCart().empty()==true){
                cout << "Cart is empty" << endl;
                continue;
            }
            sm_removeFromCart();
        }
        else if(opt==3){
            Cart.displayCart();
        }
        else if(opt==4){
            if(Cart.getCart().empty()==true){
                cout << "Cart is empty" << endl;
                continue;
            }
            sm_checkout();
            break;
        }
        else if(opt==5){
            break;
        }
    }
}

void Supermarket::sm_addToCart(){
    int num, q, check;
    Cart.displayCart();
    cout << "What would you like to add? Insert number" << endl;
    cin >> num;
    cout << "Quantity: " << endl;
    cin >> q;
    check = Stock[num-1].get_quantity() - q;
    if(check >= 0){
        Stock[num-1].reduceQuantity(q);
        cout << Stock[num-1].get_name() << " added to cart" << endl;
        if(Stock[num-1].get_quantity() == 0){
            Cart.addToCart(num, q, Stock);
            Stock.erase(Stock.begin() + num - 1);
        }
        else{
            Cart.addToCart(num, q, Stock);
        }
    }
    else if(check < 0){
        cout << "invalid amount" << endl;
    }
}

void Supermarket::sm_removeFromCart(){
    int num, q;
    bool foundInStock = false;

    Cart.displayCart();
    cout << "What would you like to put back? Insert number" << endl;
    cin >> num;
    cout << "Quantity: " << endl;
    cin >> q;
    int check = Cart.getCart()[num-1].get_quantity() - q;
    if(check == 0){
        for(int i = 0; i < Stock.size(); i++){
            if(Cart.getCart()[num-1].get_name() == Stock[i].get_name()){
                foundInStock = true;
                Stock[i].addQuantity(q);
            }
        }
        if(foundInStock == false){
            Stock.push_back(Cart.getCart()[num-1]);
            Stock.back().set_quantity(q);
        }
    }
    else if(check > 0){
        for(int i = 0; i < Stock.size(); i++){
            if(Cart.getCart()[num-1].get_name() == Stock[i].get_name()){
                foundInStock = true;
                Stock[i].addQuantity(q);
            }
        }
        if(foundInStock == false){
            Stock.push_back(Cart.getCart()[num-1]);
            Stock.back().set_quantity(q);
        }
    }
    Cart.removeFromCart(num, q);
}

void Supermarket::sm_checkout(){
    Cart.printBill();
}

void Supermarket::sm_stock(){
    Stock.push_back(Items("Milk", 0.99, 10));
    Stock.push_back(Items("Orange Juice", 1.99, 10));
    Stock.push_back(Items("Bread", 1.49, 10));
    Stock.push_back(Items("Carton of Eggs", 1.29, 10));
    Stock.push_back(Items("Instant Noodle", 0.49, 10));
    Stock.push_back(Items("Chips", 1.39, 10));
    Stock.push_back(Items("Yogurt", 2.49, 10));
    Stock.push_back(Items("Ice Cream", 2.99, 10));
    Stock.push_back(Items("Cheese", 0.69, 10));
    Stock.push_back(Items("Chocolate bar", 1.89, 10));
}

void Supermarket::run_sm(){
    sm_stock();
    sm_option();
}

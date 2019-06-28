#include "supermarket.h"
#include "smuser.h"
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>

void Supermarket::display(vector<Items> Stock){
    cout << "================================================" << endl
         << "    Product               " << "Price         " << "Quantity" << endl
         << "================================================" << endl;

    for(int i = 0; i < Stock.size(); i++){
        printf("%-2d. %-18s  | $%-10f | %-10d\n", i+1, Stock[i].get_name().c_str(), Stock[i].get_price(), Stock[i].get_quantity());
    }
    cout << "================================================" << endl;
}

void Supermarket::displayUser(vector<User> user_list){
    for(int i = 0; i < user_list.size(); i++){
        cout << i+1 << " " << user_list[i].getUsername() << endl;
    }
}

double Supermarket::getProfit(){
    double total_profit = 0;

    for(int i = 0; i < profit.size(); i++){
        total_profit += profit[i];
    }
    return total_profit;
}

void Supermarket::sm_option(){
    int opt, opt1, opt2;
    string username, password, email, password2;
    while(true){
        cout << "===================" << endl
             << "1. Login" << endl
             << "2. Register" << endl
             << "3. Exit" << endl
             << "===================" << endl;
        cin >> opt1;
        if(opt1 == 1){
            bool login = false;
            while(login == false){
                bool found = false;
                cout << "----------" << endl
                     << "Username: " << endl;
                cin >> username;
                cout << "----------" << endl
                     << "Password: " << endl
                     << "----------" << endl;
                cin >> password;
                for(int i = 0; i < user_list.size(); i++){
                    if((user_list[i].getUsername() == username) && (user_list[i].getPassword() == password)){
                        found = true;
                        login = true;
                    }
                }
                if(found == false){
                    cout << "Username or password is incorrect!" << endl;
                }
                if(login == true){
                    break;
                }
            }

            bool login2 = false;
            while(login2 == false){
                cout << "==============================================" << endl
                     << "Login as(1. Customer, 2. Store Owner, 3. Back)" << endl
                     << "==============================================" << endl;
                cin >> opt2;

                if(opt2 == 1){
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
                            double total, subtotal = 0;
                            for(int i = 0; i < Cart.getCart().size(); i++){
                                total = Cart.getCart()[i].get_price() * Cart.getCart()[i].get_quantity();
                                subtotal += Cart.getCart()[i].get_price() * Cart.getCart()[i].get_quantity();
                                profit.push_back(subtotal);
                            }
                            Cart.clearCart();
                            login2 = true;
                            break;
                        }
                        else if(opt==5){
                            bool foundInStock = false;
                            for(int i = 0; i < Cart.getCart().size(); i++){
                                for(int j = 0; j < Stock.size(); j++){
                                    if(Cart.getCart()[i].get_name() == Stock[j].get_name()){
                                        Stock[j].addQuantity(Cart.getCart()[i].get_quantity());
                                        foundInStock = true;
                                        break;
                                    }
                                }
                                if(foundInStock == false){
                                    Stock.push_back(Cart.getCart()[i]);
                                }
                            }
                            Cart.clearCart();
                            login2 = true;
                            break;
                        }
                        else{
                            cout << "Incorrect Input(1-5)" << endl;
                        }
                    }
                }
                else if(opt2 == 2){
                    int opt3;
                    while(true){
                        cout << "===========================" << endl
                             << "1. View Total Profit" << endl
                             << "2. View Supermarket Stock" << endl
                             << "3. Exit" << endl
                             << "===========================" << endl;
                        cin >> opt3;
                        if(opt3 == 1){
                            cout << "Total profit: $" << getProfit() << endl;
                        }
                        else if(opt3 == 2){
                            cout << "================================================" << endl
                                 << "    Product               " << "Quantity        " << endl
                                 << "================================================" << endl;

                            for(int i = 0; i < Stock.size(); i++){
                                printf("%-2d. %-18s | %-10d\n", i+1, Stock[i].get_name().c_str(), Stock[i].get_quantity());
                            }
                            cout << "================================================" << endl;
                        }
                        else if(opt3 == 3){
                            login2 = true;
                            break;
                        }
                        else{
                            cout << "Incorrect Input(1-3)" << endl;
                        }
                    }

                }
                else if(opt2 == 3){
                    break;
                }
                else{
                    cout << "Incorrect Input(1-3)" << endl;
                }
            }


        }
        else if(opt1 == 2){
            bool regis = false;
            while(regis == false){
                bool found = false;
                cout << "username: " << endl;
                cin >> username;
                cout << "password: " << endl;
                cin >> password;
                cout << "confirm password: " << endl;
                cin >> password2;
                for(int i = 0; i < user_list.size(); i++){
                    if(user_list[i].getUsername() == username){
                        found = true;
                        cout << "Username already exists" << endl;
                        break;
                    }
                }
                if(found == false){
                    if(password == password2){
                        user_list.push_back(User(username, password));
                        regis = true;
                    }
                    else{
                        cout << "Password confirmation failed" << endl;
                        continue;
                    }
                }
            }
        }
        else if(opt1 == 3){
            break;
        }
        else{
            cout << "Incorrect Input(1-3)" << endl;
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
        cout << Stock[num-1].get_name() << " Added to cart" << endl;
        if(Stock[num-1].get_quantity() == 0){
            Cart.addToCart(num, q, Stock);
            Stock.erase(Stock.begin() + num - 1);
        }
        else{
            Cart.addToCart(num, q, Stock);
        }
    }
    else if(check < 0){
        cout << "Invalid Amount" << endl;
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
    string line, line2;
    ifstream infile;
    ifstream infile2;
    infile.open("downloads/smstock.txt");
    infile2.open("downloads/userdatabase.txt");

    if(infile){
        while (infile){
            getline (infile,line);
            vector<string> result;
            if(line!=""){
                stringstream ss(line);
                while(ss.good()){
                    string substr;
                    getline(ss,substr,',');
                    result.push_back(substr);
                }
                Stock.push_back(Items(result[0],atof(result[1].c_str()), stoi(result[2])));
            }
        }
        infile.close();
    }
    else{
        cout << "Unable to open file";
    }

    if(infile2){
        while (infile2){
            getline (infile2,line2);
            vector<string> result2;
            if(line2!=""){
                stringstream ss(line2);
                while(ss.good()){
                    string substr;
                    getline(ss,substr,',');
                    result2.push_back(substr);
                }
                user_list.push_back(User(result2[0],result2[1]));
            }
        }
        infile2.close();
    }
    else{
        cout << "Unable to open file";
    }
}

void Supermarket::run_sm(){
    sm_stock();
    sm_option();
}

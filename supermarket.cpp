#include "supermarket.h"
#include "smuser.h"
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <iostream>
#include <iomanip>

//function to display items in the Supermarket
void Supermarket::display(vector<Items> Stock){
    cout << "================================================" << endl
         << "    Product               " << "Price         " << "Quantity" << endl
         << "================================================" << endl;
    //loop through every index in Stock and print every Item's name, price, and quantity
    for(int i = 0; i < Stock.size(); i++){
        printf("%-2d. %-18s  | $%-10f | %-10d\n", i+1, Stock[i].get_name().c_str(), Stock[i].get_price(), Stock[i].get_quantity());
    }
    cout << "================================================" << endl;
}

//function to display all user in the database
void Supermarket::displayUser(vector<User> user_list){
    //loop through every index in user_list and print every user's username
    for(int i = 0; i < user_list.size(); i++){
        cout << i+1 << " " << user_list[i].getUsername() << endl;
    }
}

//getter funtion to return total profit
double Supermarket::getProfit(){
    double total_profit = 0;

    //loop through ecery index and sum all transactions made
    for(int i = 0; i < profit.size(); i++){
        total_profit += profit[i];
    }
    return total_profit;
}

//function for the user interface
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
            //boolean value to determine whether login is successful
            bool login = false;
            //loop while login is unsuccessful
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
                    //if username and password is matched in user database
                    if((user_list[i].getUsername() == username) && (user_list[i].getPassword() == password)){
                        cout << "Login is successful" << endl;
                        found = true;
                        login = true;
                    }
                }
                //if username or password is not recorded in database
                if(found == false){
                    cout << "Username or password is incorrect!" << endl;
                }
                //if login is successful
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
                            //if cart is empty
                            if(Cart.getCart().empty()==true){
                                cout << "Cart is empty" << endl;
                                continue;
                            }
                            //remove Item from Cart
                            sm_removeFromCart();
                        }
                        else if(opt==3){
                            //display contents in Cart
                            Cart.displayCart();
                        }
                        else if(opt==4){
                            //if cart is empty
                            if(Cart.getCart().empty()==true){
                                cout << "Cart is empty" << endl;
                                continue;
                            }
                            double total, subtotal = 0;
                            //add the billing total to the profit vector
                            for(int i = 0; i < Cart.getCart().size(); i++){
                                total = Cart.getCart()[i].get_price() * Cart.getCart()[i].get_quantity();
                                subtotal += Cart.getCart()[i].get_price() * Cart.getCart()[i].get_quantity();
                            }
                            profit.push_back(subtotal);
                            sm_checkout();
                            //clear contents in Cart
                            Cart.clearCart();
                            login2 = true;
                            break;
                        }
                        else if(opt==5){
                            bool foundInStock = false;
                            //return all Items in Cart to Stock if customer choose to exit before checking out
                            for(int i = 0; i < Cart.getCart().size(); i++){
                                for(int j = 0; j < Stock.size(); j++){
                                    if(Cart.getCart()[i].get_name() == Stock[j].get_name()){
                                        Stock[j].addQuantity(Cart.getCart()[i].get_quantity());
                                        foundInStock = true;
                                        break;
                                    }
                                }
                                //if Item is not found in Stock
                                if(foundInStock == false){
                                    Stock.push_back(Cart.getCart()[i]);
                                }
                            }
                            //clear contents in Cart
                            Cart.clearCart();
                            login2 = true;
                            break;
                        }
                        //if input is incorrect
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
                             << "3. Add New Product to Stock" << endl
                             << "4. Exit" << endl
                             << "===========================" << endl;
                        cin >> opt3;
                        if(opt3 == 1){
                            cout << "Total profit: $" << getProfit() << endl;
                        }
                        else if(opt3 == 2){
                            //display the current items in supermarket Stock
                            cout << "================================================" << endl
                                 << "    Product               " << "Quantity        " << endl
                                 << "================================================" << endl;

                            for(int i = 0; i < Stock.size(); i++){
                                printf("%-2d. %-18s | %-10d\n", i+1, Stock[i].get_name().c_str(), Stock[i].get_quantity());
                            }
                            cout << "================================================" << endl;
                        }
                        else if(opt3 == 3){
                            string npname;
                            double npprice;
                            int npquantity;
                            bool foundInStock = false, addNewProduct = false;
                            while(addNewProduct == false){
                                cout << "Name of New Product: " << endl;
                                cin >> npname;
                                cout << "Price of New Product: " << endl;
                                cin >> npprice;
                                cout << "Quantity of New Product: " << endl;
                                cin >> npquantity;
                                string npdata = npname + ',' + to_string(npprice) + ',' + to_string(npquantity);
                                for(int i = 0; i < Stock.size(); i++){
                                    if(Stock[i].get_name() == npname){
                                        foundInStock = true;
                                        cout << "Item is already in Stock" << endl;
                                        break;
                                    }
                                }
                                if(npprice <= 0 || npquantity <= 0){
                                    cout << "Invalid price or quantity" << endl;
                                    continue;
                                }

                                if(foundInStock == false){
                                    Stock.push_back(Items(npname, npprice, npquantity));
                                    appendToFile(npdata, "downloads/smstock.txt");
                                    addNewProduct = true;
                                    break;
                                }
                            }
                        }
                        else if(opt3 == 4){
                            login2 = true;
                            break;
                        }
                        else{
                            cout << "Incorrect Input(1-4)" << endl;
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
                    //if username is found in database
                    if(user_list[i].getUsername() == username){
                        found = true;
                        cout << "Username already exists" << endl;
                        break;
                    }
                }
                //if username is not found
                if(found == false){
                    //if password confirmation succeeds
                    if(password == password2){
                        user_list.push_back(User(username, password));
                        string userdata = username + ',' + password;
                        appendToFile(userdata, "downloads/userdatabase.txt");
                        regis = true;
                    }
                    //if password confirmation fails
                    else{
                        cout << "Password confirmation failed" << endl;
                        continue;
                    }
                }
            }
        }
        else if(opt1 == 3){
            appendToFile(to_string(getProfit()), "downloads/totalprofit.txt");
            break;
        }
        else{
            cout << "Incorrect Input(1-3)" << endl;
        }
    }
}

//function to add to cart focusing on reducing quantity of stock in supermarket
void Supermarket::sm_addToCart(){
    int num, q, check;
    //display contents in Cart
    Cart.displayCart();
    cout << "What would you like to add? Insert number" << endl;
    cin >> num;
    cout << "Quantity: " << endl;
    cin >> q;
    //int variable check is for counting the quantity after removal from Stock to Cart
    check = Stock[num-1].get_quantity() - q;
    //if Item is still found in stock after removing
    if(check >= 0){
        //reduce quantity of Item in Stock
        Stock[num-1].reduceQuantity(q);
        cout << Stock[num-1].get_name() << " Added to cart" << endl;
        //if item in Stock is 0 after emoving
        if(Stock[num-1].get_quantity() == 0){
            //add Item to Cart
            Cart.addToCart(num, q, Stock);
            //erase item from Stock
            Stock.erase(Stock.begin() + num - 1);
        }
        //if Item is not fully removed from Stock
        else{
            Cart.addToCart(num, q, Stock);
        }
    }
    //if quantity afteer removal is < 0
    else if(check < 0){
        cout << "Invalid Amount" << endl;
    }
}

//function to remove from cart focusing on adding quantity of stock in supermarket
void Supermarket::sm_removeFromCart(){
    int num, q;
    //bool value to check if item is in Stock
    bool foundInStock = false;

    //display contents in Cart
    Cart.displayCart();
    cout << "What would you like to put back? Insert number" << endl;
    cin >> num;
    cout << "Quantity: " << endl;
    cin >> q;
    //int variable check is for counting the quantity after removal from Cart to Stock
    int check = Cart.getCart()[num-1].get_quantity() - q;
    //if all quantity of the Item is removed
    if(check == 0){
        for(int i = 0; i < Stock.size(); i++){
            //if Item is found in Stock
            if(Cart.getCart()[num-1].get_name() == Stock[i].get_name()){
                foundInStock = true;
                //add the quantity of that Item
                Stock[i].addQuantity(q);
            }
        }
        //if Item is not found in Stock
        if(foundInStock == false){
            //add the Item to Stock
            Stock.push_back(Cart.getCart()[num-1]);
            //set its quantity to 'q'
            Stock.back().set_quantity(q);
        }
    }
    //if Item is not fully removed from Cart
    else if(check > 0){
        for(int i = 0; i < Stock.size(); i++){
            //if Item is found in Stock
            if(Cart.getCart()[num-1].get_name() == Stock[i].get_name()){
                foundInStock = true;
                //add the quantity of that Item in Stock
                Stock[i].addQuantity(q);
            }
        }
        //if item is not found in Stock
        if(foundInStock == false){
            //add the Item to Stock
            Stock.push_back(Cart.getCart()[num-1]);
            //set its quantity to 'q'
            Stock.back().set_quantity(q);
        }
    }
    //remove item from Cart
    Cart.removeFromCart(num, q);
}

//function for checking out of supermarket(print bill and payment)
void Supermarket::sm_checkout(){
    //print the bill and do the billing system
    Cart.printBill();
}

//function for the creating the default stock of supermarket and the users in the database
void Supermarket::sm_stock(){
    string line, line2;
    ifstream infile;
    ifstream infile2;
    //open txt file for supermarket stock
    infile.open("downloads/smstock.txt");
    //open txt file for supermarket user database
    infile2.open("downloads/userdatabase.txt");

    //if file is found and able to be open then
    if(infile){
        //while file is being read
        while (infile){
            //get the line from the txt file
            getline (infile,line);
            //create a vector to store what is read from the txt file
            vector<string> result;
            //if line contains text/token
            if(line!=""){
                stringstream ss(line);
                while(ss.good()){
                    string substr;
                    getline(ss,substr,',');
                    //add token to result vector
                    result.push_back(substr);
                }
                //add the items to the supermarket Stock
                Stock.push_back(Items(result[0],atof(result[1].c_str()), stoi(result[2])));
            }
        }
        infile.close();
    }
    //if file is unable to be opened
    else{
        cout << "Unable to open file";
    }

    //if file is found and able to be open
    if(infile2){
        //while file is being read
        while (infile2){
            //get the line from the txt file
            getline (infile2,line2);
            //create a vector to store what is read from the txt file
            vector<string> result2;
            //if line contains text/token
            if(line2!=""){
                stringstream ss(line2);
                while(ss.good()){
                    string substr;
                    getline(ss,substr,',');
                    //add token to result vector
                    result2.push_back(substr);
                }
                //add the users to the supermarket database
                user_list.push_back(User(result2[0],result2[1]));
            }
        }
        infile2.close();
    }
    //if file is unable to be opened
    else{
        cout << "Unable to open file";
    }
}

//function to simulate the online supermarket experience
void Supermarket::run_sm(){
    //input all Items and Users into database
    sm_stock();
    //simulate online supermarket experience
    sm_option();
}

//function to append data to txt file
void Supermarket::appendToFile(string text, string filename){
    string line;
    ofstream myfile;
    myfile.open(filename, ios::out | ios::app);
    myfile << text << endl;
    myfile.close();
}

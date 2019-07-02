#ifndef SUPERMARKET_H_INCLUDED
#define SUPERMARKET_H_INCLUDED

#include "Cart.cpp"
#include "Item.cpp"
#include "smuser.cpp"

class Supermarket{
    private:
        // vector of Items object to act as supermarket
        vector<Items> Stock;

        //vector of User object, store the users in the database
        vector <User> user_list;

        //vector to store all the transactions
        vector<double> profit;

        //create a Cart object
        Carts Cart;

        void sm_stock();
        void sm_option();
        void sm_addToCart();
        void sm_removeFromCart();
        void sm_checkout();
        void display(vector<Items> Stock);
        void displayUser(vector<User> user_list);
        double getProfit();
        void appendToFile(string text,string filename);

    public:
        void run_sm();
};


#endif // SUPERMARKET_H_INCLUDED

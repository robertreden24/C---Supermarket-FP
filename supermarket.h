#ifndef SUPERMARKET_H_INCLUDED
#define SUPERMARKET_H_INCLUDED

#include "Cart.cpp"
#include "Item.cpp"

class Supermarket{
    private:
        // vector of Items object to act as supermarket
        vector<Items> Stock;

        //create a Cart object
        Carts Cart;

        //function for the default stock of supermarket
        void sm_stock();

        //function for the user interface
        void sm_option();

        //function to add to cart focusing on reducing quantity of stock in supermarket
        void sm_addToCart();

        //function to remove from cart focusing on adding quantity of stock in supermarket
        void sm_removeFromCart();

        //function for checking out of supermarket(print bill and payment)
        void sm_checkout();

        //function to display items in the Supermarket
        void display(vector<Items> Stock);

    public:
        //function to simulate the online supermarket experience
        void run_sm();
};


#endif // SUPERMARKET_H_INCLUDED

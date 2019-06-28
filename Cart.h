#ifndef CART_H_INCLUDED
#define CART_H_INCLUDED

#include "Item.h"

class Carts{
    private:
        // cart is a container that contains the Item objects
        vector<Items> Cart;
    public:
        //Cart constructor
        Carts();

        //function to add an item into the cart
        void addToCart(int po, int q, vector<Items> Stock);

        //function to remove an item from the cart
        void removeFromCart(int po, int q);

        //funciton to display the items in the cart
        void displayCart();

        //getter function to return the Cart vector
        vector<Items> getCart();

        //function to print the bill and checkout
        void printBill();

        //function to delete all items in Cart
        void clearCart();
};
#endif

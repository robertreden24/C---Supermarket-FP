#ifndef CART_H_INCLUDED
#define CART_H_INCLUDED

#include "Item.h"

class Carts{
    private:
        // cart is a container that contains the Item objects
        vector<Items> Cart;
    public:
        Carts();
        void addToCart(int po, int q, vector<Items> Stock);
        void removeFromCart(int po, int q);
        void displayCart();
        vector<Items> getCart();
        void printBill();
        void clearCart();
};
#endif

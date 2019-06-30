#ifndef ITEM_INCLUDED
#define ITEM_INCLUDED

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Item class
class Items{
    private:
        //variables for the item object
        double price;
        int quantity;
        string name;

    public:
        Items(string n, double p, int q);
        void set_price(double p);
        void set_quantity(int q);
        void set_name(string n);
        double get_price();
        int get_quantity();
        string get_name();
        void reduceQuantity(int q);
        void addQuantity(int q);
};

#endif

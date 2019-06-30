#include "Item.h"

// Item constructor
Items::Items(string n, double p, int q){
    name = n;
    price = p;
    quantity = q;
}

//setter functions for item price
void Items::set_price(double p){
    price = p;
}

//setter functions for item quantity
void Items::set_quantity(int q){
    quantity = q;
}

//setter functions for item name
void Items::set_name(string n){
    name = n;
}

//getter functions for item price
double Items::get_price(){
    return price;
}

//getter functions for item quantity
int Items::get_quantity(){
    return quantity;
}

//getter functions for item name
string Items::get_name(){
    return name;
}

//function to reduce quantity of an item
void Items::reduceQuantity(int q){
    quantity -= q;
}

//function to increase quantity of an item
void Items::addQuantity(int q){
    quantity += q;
}

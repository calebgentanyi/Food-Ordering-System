// Utils.h
#ifndef UTILS_H
#define UTILS_H

#include "Order.h" // Include the definition of the Order class
// Function to calculate the total cost of an order
double calculateTotalCost(const Order& order);

// Function to format a receipt for an order
std::string formatReceipt(const Order& order);

#endif // UTILS_H

// utils.cpp
#include "Utils.h"
int main()
{
    
// Function to calculate the total cost of an order
double calculateTotalCost(const Order& order) {
    double totalCost = order.getPrice();
    if (order.getMethod() == OrderMethod::DoorDash) {
        totalCost *= 1.05; // Apply 5% up-charge for DoorDash orders
    }
    return totalCost;
}

// Function to format a receipt for an order
std::string formatReceipt(const Order& order) {
    std::string receipt = "Receipt\n";
    receipt += "Order ID: " + std::to_string(order.getOrderID()) + "\n";
    receipt += "Method: " + std::to_string(static_cast<int>(order.getMethod())) + "\n";
    receipt += "Dish: " + order.getDish() + "\n";
    receipt += "Price: " + std::to_string(order.getPrice()) + "\n";
    // Add more details as needed
    return receipt;
}
return 0;
}
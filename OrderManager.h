#ifndef ORDERMANAGER_H
#define ORDERMANAGER_H

#include "Order.h"
#include <vector>
#include <string>
#include <stdexcept> // Include for std::invalid_argument

class OrderManager {
public:
    // Constructor
    OrderManager();

    // Member functions
    void placeOrder(const Order& order); // Place an order
    Order getNextOrderToCook(); // Get the next order to cook
    std::string getOrderDetails(int orderId); // Get details of a specific order
    void markOrderComplete(int orderId); // Mark an order as complete
    std::vector<Order> listOrdersWaitingForPickup(); // List orders waiting for pickup
    void markOrderForPickup(int orderId); // Mark an order for pickup
    void cancelOrder(int orderId); // Cancel an order
    double calculateTotalCost(int orderId); // Calculate the total cost of an order

private:
    std::vector<Order> orders; // Store orders
    Order getOrderById(int orderId); // Get an order by its ID
};

#endif // ORDERMANAGER_H
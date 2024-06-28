#include "Order.h"

// Constructor with parameter initialization list
Order::Order(int id, OrderMethod method, const std::string& dish, double price)
    : orderID(id), method(method), dish(dish), price(price), status(OrderStatus::PENDING) {}

// Getter for order ID
int Order::getOrderID() const {
    return orderID;
}

// Getter for order method
OrderMethod Order::getMethod() const {
    return method;
}

// Getter for order dish
const std::string& Order::getDish() const {
    return dish;
}

// Getter for order price
double Order::getPrice() const {
    return price;
}

// Getter for order status
OrderStatus Order::getStatus() const {
    return status;
}

// Setter for order status
void Order::setStatus(OrderStatus newStatus) {
    status = newStatus;
}

// Getter for cancellation reason
std::string Order::getCancellationReason() const {
    return cancellationReason;
}

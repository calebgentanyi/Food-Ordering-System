#include "OrderManager.h"
#include "Order.h"
#include "Ordermethod.h"
#include <algorithm>

// Constructor implementation
OrderManager::OrderManager() {
    // constructor implementation
    // Initialize any member variables or perform any necessary setup here
}

// Implementation of other member functions
void OrderManager::placeOrder(const Order& order) {
    orders.push_back(order);
}

Order OrderManager::getNextOrderToCook() {
    for (const auto& order : orders) {
        if (order.getStatus() == OrderStatus::PENDING || order.getStatus() == OrderStatus::COOKING) {
            return order;
        }
    }
    return Order(-1, OrderMethod::DriveThrough, "", 0.0);
}

std::string OrderManager::getOrderDetails(int orderId) {
    for (const auto& order : orders) {
        if (order.getOrderID() == orderId) {
            return "Order ID: " + std::to_string(order.getOrderID()) + ", Method: " +
                   std::to_string(static_cast<int>(order.getMethod())) + ", Dish: " +
                   order.getDish() + ", Price: " + std::to_string(order.getPrice());
        }
    }
    return "Order not found";
}

void OrderManager::markOrderComplete(int orderId) {
    for (auto& order : orders) {
        if (order.getOrderID() == orderId) {
            order.setStatus(OrderStatus::COMPLETED);
            return;
        }
    }
}

std::vector<Order> OrderManager::listOrdersWaitingForPickup() {
    std::vector<Order> waitingOrders;
    for (const auto& order : orders) {
        if (order.getStatus() == OrderStatus::COMPLETED) {
            waitingOrders.push_back(order);
        }
    }
    return waitingOrders;
}

void OrderManager::markOrderForPickup(int orderId) {
    for (auto& order : orders) {
        if (order.getOrderID() == orderId) {
            order.setStatus(OrderStatus::COMPLETED);
            return;
        }
    }
}

void OrderManager::cancelOrder(int orderId) {
    auto it = std::remove_if(orders.begin(), orders.end(), [orderId](const Order& order) {
        return order.getOrderID() == orderId;
    });
    orders.erase(it, orders.end());
}

double OrderManager::calculateTotalCost(int orderId) {
    double totalCost = 0.0;
    for (const auto& order : orders) {
        if (order.getOrderID() == orderId) {
            totalCost = order.getPrice();
            if (order.getMethod() == OrderMethod::DoorDash) {
                totalCost *= 1.05; // Apply 5% up-charge for DoorDash orders
            }
            break;
        }
    }
    return totalCost;
}

Order OrderManager::getOrderById(int orderId) {
    for (const auto& order : orders) {
        if (order.getOrderID() == orderId) {
            return order;
        }
    }
    // Return a default-constructed Order if the order ID is not found
    return Order(-1, OrderMethod::DriveThrough, "", 0.0);
}
#include <iostream>
#include "Order.h"
#include "OrderManager.h"
#include "Utils.h"
#include "Constants.h"

int main() {
    // Instantiate OrderManager object
    OrderManager orderManager;

    // Place some sample orders
    Order order1(1, OrderMethod::DriveThrough, "Burger", 10.99);
    Order order2(2, OrderMethod::Onsite, "Pizza", 15.99);
    Order order3(3, OrderMethod::Phone, "Salad", 8.99);
    Order order4(4, OrderMethod::DoorDash, "Sushi", 20.99);

    // Create order1 with provided details
    Order order1_with_details(1, "Burger", 15.99, OrderStatus::PENDING, "", "Delivery", "12:00", "Caleb Leonard", "123-456-7890", "123 Main St", 5.0, 1.0, 16.0, "Credit Card", "Pending", "Pending", "Pending", "Pending");

    // Place order with details
    orderManager.placeOrder(order1_with_details);
    std::string reason = order1_with_details.getCancellationReason();

    orderManager.placeOrder(order1);
    orderManager.placeOrder(order2);
    orderManager.placeOrder(order3);
    orderManager.placeOrder(order4);

    // Main menu loop
    int choice;
    do {
        std::cout << "\n=== Main Menu ===" << std::endl;
        std::cout << "1. Get next order to cook" << std::endl;
        std::cout << "2. Get order details" << std::endl;
        std::cout << "3. Mark order as complete" << std::endl;
        std::cout << "4. List orders waiting for pickup" << std::endl;
        std::cout << "5. Mark order for pickup" << std::endl;
        std::cout << "6. Cancel order" << std::endl;
        std::cout << "7. Calculate total cost" << std::endl; // New option
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch(choice) {
            case 1: {
                Order nextOrder = orderManager.getNextOrderToCook();
                std::cout << "Next order to cook: " << nextOrder.getDish() << std::endl;
                break;
            }
            case 2: {
                int orderId;
                std::cout << "Enter order ID: ";
                std::cin >> orderId;
                std::string details = orderManager.getOrderDetails(orderId);
                std::cout << "Order details: " << details << std::endl;
                break;
            }
            case 3: {
                int orderId;
                std::cout << "Enter order ID: ";
                std::cin >> orderId;
                orderManager.markOrderComplete(orderId);
                std::cout << "Order marked as complete." << std::endl;
                break;
            }
            case 4: {
                std::vector<Order> waitingOrders = orderManager.listOrdersWaitingForPickup();
                std::cout << "Orders waiting for pickup:" << std::endl;
                for (const auto& order : waitingOrders) {
                    std::cout << "Order ID: " << order.getOrderID() << ", Dish: " << order.getDish() << ", Price: " << order.getPrice() << std::endl;
                }
                break;
            }
            case 5: {
                int orderId;
                std::cout << "Enter order ID: ";
                std::cin >> orderId;
                orderManager.markOrderForPickup(orderId);
                std::cout << "Order marked for pickup." << std::endl;
                break;
            }
            case 6: {
                int orderId;
                std::cout << "Enter order ID: ";
                std::cin >> orderId;
                orderManager.cancelOrder(orderId);
                std::cout << "Order canceled." << std::endl;
                break;
            }
            case 7: {
                int orderId;
                std::cout << "Enter order ID: ";
                std::cin >> orderId;
                double totalCost = orderManager.calculateTotalCost(orderId);
                std::cout << "Total cost for order " << orderId << ": " << totalCost << std::endl;
                break;
            }
            case 0: {
                std::cout << "Exiting..." << std::endl;
                break;
            }
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 0);

    return 0;
}

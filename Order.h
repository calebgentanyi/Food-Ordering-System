#ifndef ORDER_H
#define ORDER_H

#include <string>
enum class OrderMethod {
    DriveThrough,
    Onsite,
    Phone,
    DoorDash
};

enum class OrderStatus {
    PENDING,
    COOKING,
    COOKED,
    COMPLETED
};

class Order {
private:
    int orderID;
    std::string dish;
    double price;
    std::string specialInstructions;
    OrderStatus orderStatus;
    std::string method;
    std::string time;
    std::string customerName;
    std::string customerPhoneNumber;
    std::string customerAddress;
    double deliveryFee;
    double tax;
    double totalCost;
    std::string paymentMethod;
    std::string paymentStatus;
    std::string deliveryStatus;
    std::string pickupStatus;
    std::string cancellationReason; // New member variable for cancellation reason

public:
    // Constructors
    Order(int orderID, std::string dish, double price, OrderStatus orderStatus, std::string specialInstructions, std::string method, std::string time, std::string customerName, std::string customerPhoneNumber, std::string customerAddress, double deliveryFee, double tax, double totalCost, std::string paymentMethod, std::string paymentStatus, std::string deliveryStatus, std::string pickupStatus, std::string cancellationReason);
    Order(int orderID = -1, OrderMethod method = OrderMethod::DriveThrough, const std::string& dish = "", double price = 0.0);

    // Getter functions
    int getOrderID() const;
    std::string getMethod() const;
    std::string getDish() const;
    double getPrice() const;
    OrderStatus getStatus() const;
    std::string getTime() const;
    std::string getCustomerName() const;
    std::string getCustomerPhoneNumber() const;
    std::string getCustomerAddress() const;
    double getDeliveryFee() const;
    double getTax() const;
    double getTotalCost() const;
    std::string getPaymentMethod() const;
    std::string getPaymentStatus() const;
    std::string getDeliveryStatus() const;
    std::string getPickupStatus() const;

    // Setter function
    void setStatus(OrderStatus newStatus);

    // Operator overloading
    bool operator<(const Order& other) const;

    // Implementation of getCancellationReason function
    std::string getCancellationReason() const;
};

#endif // ORDER_H

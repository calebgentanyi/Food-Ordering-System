#ifndef ENUMS_H
#define ENUMS_H
 int main()
{
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
    COMPLETE
};

#endif // ENUMS_H
return 0;
}
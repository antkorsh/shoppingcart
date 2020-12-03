#include <string>

namespace interview {
/**
 * This is the interface used by the existing shopping tills in our supermarket.
 * It cannot be changed without upgrading/replacing legacy hardware.
 */
class IShoppingCart {
public:
    virtual ~IShoppingCart() = default;

    /**
     * Called once for every item/collection of items that is scanned by the
     * till.
     *
     * @param itemType - The item being scanned by the hardware
     * @param number - The number of items the cashier is moving to the bagging
     * area
     */
    virtual void addItem(const std::string& itemType, int number) = 0;

    /**
     * Prints the receipt to stdout. In the supermarket, stdout is captured by
     * the receipt printer, which then prints it for tue customer.
     */
    virtual void printReceipt() = 0;
};
}  // namespace interview

#include "ShoppingCart.h"

#include <iomanip>
#include <iostream>

namespace interview {
void ShoppingCart::printReceipt() {
    for (auto&& [itemType, quantity] : _contents) {
        auto price = _pricer.getPrice(itemType) * quantity;
        auto priceDouble = static_cast<double>(price) / 100;
        std::cout << itemType << " - " << quantity << " - €" << std::fixed << std::setprecision(2)
                  << std::setfill('0') << priceDouble << std::endl;
    }
}
}  // namespace interview

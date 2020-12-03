#include <unordered_map>

#include "IShoppingCart.h"
#include "Pricer.h"

namespace interview {
/**
 * This is the current implementation of ShoppingCart.
 *
 * Please write a replacement.
 */
class ShoppingCart : public IShoppingCart {
public:
    ShoppingCart(Pricer pricer) : _pricer(std::move(pricer)) {}

    void addItem(const std::string& itemType, int number) override {
        _contents[itemType] += number;
    }

    void printReceipt() override;

private:
    std::unordered_map<std::string, int> _contents;
    const Pricer _pricer;
};
}  // namespace interview

#include <string>
#include <unordered_map>

namespace interview {
/**
 * A stub implementation - for this exercise, you may disregard that this is
 * incomplete.
 */
class Pricer {
public:
    Pricer() = default;

    /**
     * Returns the price of the item passed, in Euro-cent. Eg. if an item costs
     * €1, this will return 100. If itemType is an unknown string, store policy
     * is that the item is free.
     */
    int getPrice(const std::string& itemType) const;

private:
    std::unordered_map<std::string, int> _pricingDatabase{{"apple", 100}, {"banana", 200}};
};
}  // namespace interview

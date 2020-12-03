#include "Pricer.h"

namespace interview {
int Pricer::getPrice(const std::string& itemType) const {
    if (auto it = _pricingDatabase.find(itemType); it != _pricingDatabase.end()) {
        return it->second;
    }
    // Unknown products are free.
    return 0;
}
}  // namespace interview

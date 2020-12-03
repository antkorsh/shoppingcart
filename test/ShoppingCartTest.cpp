#include <iostream>
#include <sstream>

#include "ShoppingCart.h"

namespace interview::test {
struct Assert {
    std::string actual;
    std::string expected;
    int line{-1};
};

void assertEquals(const std::string& actual, const std::string& expected, int line) {
    if (actual != expected)
        throw Assert{actual, expected, line};
}

#define ASSERT_EQUALS(a, b) assertEquals((a), (b), __LINE__)

struct RedirectStdOut {
    RedirectStdOut(std::streambuf* buffer) : _old{std::cout.rdbuf(buffer)} {}

    ~RedirectStdOut() {
        std::cout.rdbuf(_old);
    }

private:
    std::streambuf* const _old;
};

void canAddAnItem() {
    ShoppingCart sc{Pricer{}};

    sc.addItem("apple", 1);

    std::stringstream myOut;
    RedirectStdOut redirect{myOut.rdbuf()};

    sc.printReceipt();
    ASSERT_EQUALS("apple - 1 - €1.00\n", myOut.str());
}

void canAddMoreThanOneItem() {
    ShoppingCart sc{Pricer{}};

    sc.addItem("apple", 2);

    std::stringstream myOut;
    RedirectStdOut redirect{myOut.rdbuf()};

    sc.printReceipt();
    ASSERT_EQUALS("apple - 2 - €2.00\n", myOut.str());
}

void canAddDifferentItems() {
    ShoppingCart sc{Pricer{}};

    sc.addItem("apple", 2);
    sc.addItem("banana", 1);

    std::stringstream myOut;
    RedirectStdOut redirect{myOut.rdbuf()};

    sc.printReceipt();

    auto result = myOut.str();
    if (result.find("apple") == 0) {
        ASSERT_EQUALS("apple - 2 - €2.00\nbanana - 1 - €2.00\n", myOut.str());
    } else {
        ASSERT_EQUALS("banana - 1 - €2.00\napple - 2 - €2.00\n", myOut.str());
    }
}

void doesntExplodeOnMysteryItem() {
    ShoppingCart sc{Pricer{}};

    sc.addItem("crisps", 2);

    std::stringstream myOut;
    RedirectStdOut redirect{myOut.rdbuf()};

    sc.printReceipt();
    ASSERT_EQUALS("crisps - 2 - €0.00\n", myOut.str());
}
}  // namespace interview::test

int main() {
    try {
        interview::test::canAddAnItem();
        interview::test::canAddMoreThanOneItem();
        interview::test::canAddDifferentItems();
        interview::test::doesntExplodeOnMysteryItem();
    } catch (const interview::test::Assert& assert) {
        std::cout << "Test failed:" << std::endl
                  << "\tactual=" << assert.actual << "\texpected=" << assert.expected
                  << "\tline=" << assert.line << std::endl;
        return 1;
    }
    std::cout << "All tests passed" << std::endl;
    return 0;
}

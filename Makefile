CXX=g++
CXXFLAGS=-std=c++17 -Isrc -I.

shoppingcart: src/ShoppingCart.o src/Pricer.o test/ShoppingCartTest.o
	$(CXX) -o shoppingcart src/ShoppingCart.o src/Pricer.o test/ShoppingCartTest.o

clean:
	rm -f shoppingcart src/*.o test/*.o *~ src/*~ test/*~ core

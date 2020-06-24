all: main.cpp testvent.cpp vent.hpp
	g++ -o calculatevents main.cpp
	g++ -o testvent testvent.cpp -lcppunit

clean:
	rm -f calculatevents testvent

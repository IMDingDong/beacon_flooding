all: beacon_flooding

beacon_flooding: beacon_flooding.cpp
	g++ -o beacon_flooding beacon_flooding.cpp -ltins -std=c++11

clean:
	rm -rf *.o
	rm -rf beacon_flooding

all:
	g++ -std=c++17 -I./include -I/usr/include/jsoncpp src/main.cpp src/stock.cpp -o stock-cli -lcurl -ljsoncpp

#include "../include/stock.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <unistd.h>

using namespace std;

void printBar(double price) {
    int length = static_cast<int>(price) % 20;
    cout << "\033[32m";
    for (int i = 0; i < length; ++i) cout << "█";
    cout << "\033[0m";
}

int main() {
    vector<string> symbols = {"AAPL", "GOOGL", "MSFT", "AMZN", "META"};
    string apiKey = "your api key"; 


    vector<Stock> stocks;

   
    for (const auto& sym : symbols) {
        stocks.emplace_back(sym, apiKey);
    }

    while (true) {
        system("clear");
        cout << "Stock Market CLI Monitor\n\n";
        
        
        for (int i = 0; i < stocks.size(); ++i) {
            double price = stocks[i].getLatestPrice();
            cout << i + 1 << ". " << setw(6) << stocks[i].getSymbol() << " | $"
                 << fixed << setprecision(2) << price << " | ";
            printBar(price);
            cout << "\n";
        }

        cout << "\nRefreshing every 10s... (Ctrl+C to quit)\n";
        sleep(10); // Wait for 10 seconds before refreshing
    }

    return 0;
}

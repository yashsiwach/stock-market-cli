#ifndef STOCK_H
#define STOCK_H

#include <string>

class Stock {
    std::string symbol;
    std::string apiKey;
public:
    Stock(const std::string& symbol, const std::string& apiKey);
    std::string getSymbol() const;
    double getLatestPrice() const;
};

#endif

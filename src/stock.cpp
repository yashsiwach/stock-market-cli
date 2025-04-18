#include "../include/stock.h"
#include <iostream>
#include <sstream>
#include <curl/curl.h>
#include <jsoncpp/json/json.h>

using namespace std;

size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* output) {
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}

Stock::Stock(const string& symbol, const string& apiKey)
    : symbol(symbol), apiKey(apiKey) {}

string Stock::getSymbol() const {
    return symbol;
}

double Stock::getLatestPrice() const {
    CURL* curl = curl_easy_init();
    if (!curl) return -1;
//https://www.alphavantage.co/query?function=GLOBAL_QUOTE&symbol=AAPL&apikey=
    string readBuffer;
    string url = "https://www.alphavantage.co/query?function=GLOBAL_QUOTE&symbol=" + symbol + "&apikey=" + apiKey;

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

    CURLcode res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    if (res != CURLE_OK) return -1;

    Json::Value root;
    Json::CharReaderBuilder builder;
    string errs;
    istringstream s(readBuffer);
    if (!Json::parseFromStream(builder, s, &root, &errs)) return -1;

    string priceStr = root["Global Quote"]["05. price"].asString();
    return priceStr.empty() ? -1 : stod(priceStr);
}

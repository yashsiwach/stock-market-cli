# stock-market-cli
 C++ as a backend to fetch and display the reatime data !FASTEST

Sure Yash! Here's a clean and professional GitHub `README.md` for your **Stock Market CLI** project:

---

## 📈 Stock Market CLI

A terminal-based C++ application that displays real-time stock prices in a colorful bar graph format, updated every 10 seconds. Built using `curl` and `jsoncpp`, this project runs entirely in the Linux terminal and is perfect for quickly tracking your favorite stocks.

---

### 🛠️ Features

- Fetches real-time stock data using [Alpha Vantage API](https://www.alphavantage.co)
- Displays prices for multiple stocks in a compact, color-coded bar chart
- Updates every 10 seconds automatically
- Fully terminal-based, lightweight, and fast
- Customizable stock symbols

---

### 🖼️ Preview

```bash
Stock Market CLI Monitor

1.  AAPL   | $172.39 | ██████████
2.  GOOGL  | $129.20 | █████████
3.  MSFT   | $306.10 | ██████████████
4.  AMZN   | $113.43 | ████████
5.  META   | $190.67 | █████████████

Refreshing every 10s... (Ctrl+C to quit)
```

---

### 🔧 Requirements

- Linux OS
- g++
- curl (`sudo apt install libcurl4-openssl-dev`)
- jsoncpp (`sudo apt install libjsoncpp-dev`)

---

### 🚀 Build Instructions

```bash
git clone https://github.com/your-username/stock-market-cli.git
cd stock-market-cli
make
./stock-cli
```

---

### 📝 How It Works

- The app initializes stock symbols and fetches prices from Alpha Vantage using their API.
- It then prints a simple color-coded bar graph for each stock, proportional to its current price.
- Bar colors differ per stock for easier readability.

---

### ⚙️ Configuration

To customize stock symbols or API key, edit `main.cpp`:

```cpp
vector<string> symbols = {"AAPL", "GOOGL", "MSFT", "AMZN", "META"};
string apiKey = "YOUR_API_KEY_HERE";
```

Get your **free API key** from [Alpha Vantage](https://www.alphavantage.co/support/#api-key).

---

### 📁 Project Structure

```
├── include/
│   └── stock.h
├── src/
│   ├── main.cpp
│   └── stock.cpp
├── Makefile
└── README.md
```

---

### 🤝 Contributing

Pull requests and suggestions are welcome! If you find a bug or want a new feature, feel free to open an issue.

---

### 📄 License

This project is licensed under the [MIT License](LICENSE).

---

Let me know if you want it tailored to a specific GitHub username or to add screenshots/gifs!

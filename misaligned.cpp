#include <iostream>
#include <assert.h>
#include <string>
#include <vector>

class Printer {
public:
    virtual ~Printer() = default;
    virtual void display(const std::string& message) = 0;
};

class MockPrinter : public Printer {
public:
    void display(const std::string& message) override {
        logs.push_back(message);
    }

    const std::vector<std::string>& getLogs() const {
        return logs;
    }

private:
    std::vector<std::string> logs;
};

int generateColorMapping(Printer& printer) {
    const char* primaryColors[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* secondaryColors[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int row = 0, column = 0;
    for(row = 0; row < 5; row++) {
        for(column = 0; column < 5; column++) {
            printer.display(std::to_string(row * 5 + column) + " | " + primaryColors[row] + " | " + secondaryColors[row] + "\n");
        }
    }
    return row * column;
}

int main() {
    MockPrinter mockPrinter;
    int result = generateColorMapping(mockPrinter);

    const auto& logs = mockPrinter.getLogs();
    assert(logs.size() == 25 && "Error: Expected exactly 25 lines of output");

    // Basic checks on some of the logs
    assert(logs[0] == "0 | White | Blue\n" && "Error: First log mismatch");
    assert(logs[12] == "12 | Black | Green\n" && "Error: Middle log mismatch");
    assert(logs[24] == "24 | Violet | Slate\n" && "Error: Last log mismatch");

    assert(result == 25 && "Error: Expected return value to be 25");
    std::cout << "Basic checks passed!\n";
    return 0;
}

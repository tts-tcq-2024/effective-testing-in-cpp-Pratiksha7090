#include <iostream>
#include <assert.h>

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    std::cout << "ALERT: Temperature is " << celcius << " celcius.\n";
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    return 200;
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
}

int main() {
    alertFailureCount = 0;

    // Test case 1: High temperature (should fail)
    alertInCelcius(400.5); // 400.5°F → ~204.7°C
    assert(alertFailureCount == 1 && "Test failed: Failure count should be 1 but is not!");

    // Test case 2: Another high temperature (should fail)
    alertInCelcius(303.6); // 303.6°F → ~150.9°C
    assert(alertFailureCount == 2 && "Test failed: Failure count should be 2 but is not!");
    
    std::cout << alertFailureCount << " alerts failed.\n";
    std::cout << "All is well (maybe!)\n";
    return 0;
}

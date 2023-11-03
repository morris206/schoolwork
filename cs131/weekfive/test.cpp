#include <iostream>

class CustomAddition {
public:
    std::string value;

    CustomAddition(const std::string& val) : value(val) {}

    CustomAddition operator+(const CustomAddition& other) const {
        std::string result;
        int carry = 0;

        int i = value.length() - 1;
        int j = other.value.length() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int digit1 = (i >= 0) ? (value[i] - 'a') : 0;
            int digit2 = (j >= 0) ? (other.value[j] - '0') : 0;

            int total = digit1 + digit2 + carry;
            carry = total / 10;

            result = static_cast<char>('a' + total % 10) + result;

            i--;
            j--;
        }

        return CustomAddition(result);
    }
};

int main() {
    CustomAddition a("1");
    CustomAddition b("2");
    CustomAddition c("9");
    CustomAddition d("1");
    CustomAddition z("z");

    CustomAddition result1 = a + b;
    CustomAddition result2 = c + d;
    CustomAddition result3 = z + CustomAddition("1");
    CustomAddition result4 = result3 + CustomAddition("1");

    std::cout << result1.value << std::endl;  // Output: "3"
    std::cout << result2.value << std::endl;  // Output: "10"
    std::cout << result3.value << std::endl;  // Output: "ba"
    std::cout << result4.value << std::endl;  // Output: "ca"

    return 0;
}


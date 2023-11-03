#include <iostream>
using namespace std;

class concatThings {
public:
    string value;

    concatThings(const string val) : value(val) {}

    concatThings operator+(const concatThings& other) const {
        string result;
        int carry = 0;

        int i = value.length() - 1;
        int j = other.value.length() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int digit1 = (i >= 0) ? (value[i] - 'a') : 0;
            int digit2 = (j >= 0) ? (other.value[j] - 'a') : 0;

            int total = digit1 + digit2 + carry;
            carry = total / 26;

            result = static_cast<char>('a' + total % 26) + result;

            i--;
            j--;
        }

        return concatThings(result);
    }
};

int main() {
    concatThings a("c");

    concatThings result1 = a + concatThings("a");

    cout << result1.value << endl;

    return 0;
}


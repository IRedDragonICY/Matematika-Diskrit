#include <iostream>
#include <cmath>
#include <chrono>

class InputOutput {
public:
    static void clearScreen() {
        std::cout << "\033[2J\033[1;1H"; // membersihkan layar konsol secara portabel
    }

    static void displayWelcomeMessage() {
        std::cout << "PROGRAM UNTUK MEMERIKSA BILANGAN PRIMA" << std::endl;
    }

    static void promptInput(int& numberToCheck) {
        std::cout << "\nMasukan Bilangan Untuk Di Cek: ";
        std::cin >> numberToCheck;
    }

    static void displayResult(int number, bool isPrime) {
        if (isPrime) {
            std::cout << number << " merupakan Bilangan Prima" << std::endl;
        } else {
            std::cout << number << " bukan merupakan Bilangan Prima" << std::endl;
        }
    }

    static void promptRepeat(char& repeat) {
        std::cout << "Ulangi (y/n)? ";
        std::cin >> repeat;
    }

    static void displayThankYouMessage() {
        std::cout << "Terima Kasih" << std::endl;
    }

    static void displayErrorMessage(const std::string& message) {
        std::cout << "Error: " << message << std::endl;
    }
};

class PrimeChecker {
public:
    static bool isPrime(int number) {
        if (number <= 1) {
            return false;
        }
        for (int i = 2; i <= std::sqrt(number); i++) {
            if (number % i == 0) {
                return false;
            }
        }
        return true;
    }
};

class PrimeNumberChecker {
public:
    void run() {
        char repeat;
        do {
            InputOutput::clearScreen();
            InputOutput::displayWelcomeMessage();

            int numberToCheck;
            if (!getNumberToCheck(numberToCheck)) {
                continue;
            }

            bool primeStatus = PrimeChecker::isPrime(numberToCheck);
            InputOutput::displayResult(numberToCheck, primeStatus);

            InputOutput::promptRepeat(repeat);
        } while (repeat == 'y' || repeat == 'Y');

        InputOutput::displayThankYouMessage();
    }

private:
    bool getNumberToCheck(int& numberToCheck) {
        InputOutput::promptInput(numberToCheck);

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            InputOutput::displayErrorMessage("Input harus berupa bilangan bulat positif.");
            return false;
        }

        if (numberToCheck <= 0) {
            InputOutput::displayErrorMessage("Input harus berupa bilangan bulat positif.");
            return false;
        }

        return true;
    }
};

int main() {
    PrimeNumberChecker primeNumberChecker;

    auto start = std::chrono::high_resolution_clock::now();
    primeNumberChecker.run();
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Waktu eksekusi: " << elapsed.count() << " detik" << std::endl;

    return 0;
}
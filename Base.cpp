#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>

double calculate_profit(double investment, double base_profit, int years, int age) {
    double total_profit = investment;

    for (int i = 1; i <= years; i++) {
        double annual_increment = 0;

        if (investment < 50000) {
            annual_increment = 0.15;
        } else if (investment >= 50000 && investment <= 100000) {
            annual_increment = 0.25;
        } else {
            if (i <= 10) {
                annual_increment = 0.35;
            } else {
                annual_increment = 0.55;
            }
        }

        double profit = total_profit * (base_profit + annual_increment) / 100;
        total_profit += profit;
    }

    return total_profit - investment;
}

int main() {
    double investment, base_profit;
    int years, age;
    std::string input;

    try {
        std::cout << "Enter investment amount (MYR): ";
        std::cin >> investment;
        if (investment < 5000 || investment > 200000) {
            throw std::invalid_argument("Invalid investment amount.");
        }

        std::cout << "Enter base profit percentage: ";
        std::cin >> base_profit;

        std::cout << "Enter investment duration in years: ";
        std::cin >> years;
        if (years < 5 || years > 25) {
            throw std::invalid_argument("Invalid investment duration.");
        }

        std::cout << "Enter your age: ";
        std::cin >> age;
        if (age < 18 || age > 70 || age + years > 70) {
            throw std::invalid_argument("Invalid age.");
        }

        double total_profit = calculate_profit(investment, base_profit, years, age);
        double service_charge = total_profit * 0.025;
        double profit_after_service_charge = total_profit - service_charge;
        double profit_tax;
        if (total_profit < 70000) {
            profit_tax = profit_after_service_charge * 0.03;
        } else if (total_profit < 150000) {
            profit_tax = profit_after_service_charge * 0.05;
        } else {
            profit_tax = profit_after_service_charge * 0.07;
        }
        double net_profit = profit_after_service_charge - profit_tax;

        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Total Profit: MYR " << total_profit << std::endl;
        std::cout << "Service Charge: MYR " << service_charge << std::endl;
        std::cout << "Profit After Service Charge: MYR " << profit_after_service_charge << std::endl;
        std::cout << "Profit Tax: MYR " << profit_tax << std::endl;
        std::cout << "Net Profit: MYR " << net_profit << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    getchar();
    return 0;
}

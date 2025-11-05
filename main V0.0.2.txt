#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

// Pizza struct to represent a pizza item
struct Pizza {
    string size;
    string crust;
    vector<string> toppings;
    double basePrice;
    
    // Constructor
    Pizza(string s, string c, double price) : size(s), crust(c), basePrice(price) {}
    
    // Calculate total price including toppings
    double calculatePrice() const {
        return basePrice + (toppings.size() * 1.50); // $1.50 per topping
    }
    
    // Display pizza details
    void display() const {
        cout << "  Size: " << size << " | Crust: " << crust << endl;
        cout << "  Toppings: ";
        if (toppings.empty()) {
            cout << "Cheese only";
        } else {
            for (size_t i = 0; i < toppings.size(); i++) {
                cout << toppings[i];
                if (i < toppings.size() - 1) cout << ", ";
            }
        }
        cout << endl;
        cout << "  Price: $" << fixed << setprecision(2) << calculatePrice() << endl;
    }
};

// Order class to manage the entire order
class Order {
private:
    vector<Pizza> pizzas;
    string customerName;
    string deliveryAddress;
    
public:
    void setCustomerInfo(string name, string address) {
        customerName = name;
        deliveryAddress = address;
    }
    
    void addPizza(const Pizza& pizza) {
        pizzas.push_back(pizza);
    }
    
    double calculateTotal() const {
        double total = 0;
        for (const auto& pizza : pizzas) {
            total += pizza.calculatePrice();
        }
        return total;
    }
    
    void displayReceipt() const {
        cout << "\n========================================" << endl;
        cout << "         PIZZA ORDER RECEIPT" << endl;
        cout << "========================================" << endl;
        cout << "Customer: " << customerName << endl;
        cout << "Delivery Address: " << deliveryAddress << endl;
        cout << "========================================" << endl;
        
        for (size_t i = 0; i < pizzas.size(); i++) {
            cout << "\nPizza #" << (i + 1) << ":" << endl;
            pizzas[i].display();
        }
        
        cout << "\n========================================" << endl;
        cout << "Subtotal: $" << fixed << setprecision(2) << calculateTotal() << endl;
        double tax = calculateTotal() * 0.08; // 8% tax
        cout << "Tax (8%): $" << tax << endl;
        cout << "TOTAL: $" << (calculateTotal() + tax) << endl;
        cout << "========================================" << endl;
        cout << "\nThank you for your order!" << endl;
        cout << "Estimated delivery time: 30-45 minutes" << endl;
    }
    
    bool isEmpty() const {
        return pizzas.empty();
    }
};

// Function to clear input buffer
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Function to get a valid integer input
int getIntInput(int min, int max) {
    int choice;
    while (true) {
        cin >> choice;
        if (cin.fail() || choice < min || choice > max) {
            cout << "Invalid input. Please enter a number between " << min << " and " << max << ": ";
            clearInput();
        } else {
            clearInput();
            return choice;
        }
    }
}

// Function to create a custom pizza
Pizza createPizza() {
    int sizeChoice, crustChoice;
    string size, crust;
    double basePrice;
    
    // Select size
    cout << "\n--- SELECT PIZZA SIZE ---" << endl;
    cout << "1. Small (10\") - $8.99" << endl;
    cout << "2. Medium (12\") - $11.99" << endl;
    cout << "3. Large (14\") - $14.99" << endl;
    cout << "4. Extra Large (16\") - $17.99" << endl;
    cout << "Enter choice (1-4): ";
    sizeChoice = getIntInput(1, 4);
    
    switch (sizeChoice) {
        case 1: size = "Small"; basePrice = 8.99; break;
        case 2: size = "Medium"; basePrice = 11.99; break;
        case 3: size = "Large"; basePrice = 14.99; break;
        case 4: size = "Extra Large"; basePrice = 17.99; break;
    }
    
    // Select crust
    cout << "\n--- SELECT CRUST TYPE ---" << endl;
    cout << "1. Thin Crust" << endl;
    cout << "2. Regular Crust" << endl;
    cout << "3. Thick Crust" << endl;
    cout << "4. Stuffed Crust (+$2)" << endl;
    cout << "Enter choice (1-4): ";
    crustChoice = getIntInput(1, 4);
    
    switch (crustChoice) {
        case 1: crust = "Thin"; break;
        case 2: crust = "Regular"; break;
        case 3: crust = "Thick"; break;
        case 4: crust = "Stuffed"; basePrice += 2.00; break;
    }
    
    Pizza pizza(size, crust, basePrice);
    
    // Add toppings
    cout << "\n--- SELECT TOPPINGS ($1.50 each) ---" << endl;
    cout << "1. Pepperoni" << endl;
    cout << "2. Mushrooms" << endl;
    cout << "3. Onions" << endl;
    cout << "4. Sausage" << endl;
    cout << "5. Bacon" << endl;
    cout << "6. Black Olives" << endl;
    cout << "7. Green Peppers" << endl;
    cout << "8. Pineapple" << endl;
    cout << "9. Extra Cheese" << endl;
    cout << "0. Done with toppings" << endl;
    
    vector<string> toppingOptions = {"Pepperoni", "Mushrooms", "Onions", "Sausage", 
                                     "Bacon", "Black Olives", "Green Peppers", 
                                     "Pineapple", "Extra Cheese"};
    
    while (true) {
        cout << "\nSelect topping (1-9, 0 to finish): ";
        int toppingChoice = getIntInput(0, 9);
        
        if (toppingChoice == 0) break;
        
        pizza.toppings.push_back(toppingOptions[toppingChoice - 1]);
        cout << toppingOptions[toppingChoice - 1] << " added!" << endl;
    }
    
    return pizza;
}

int main() {
    Order order;
    string name, address;
    
    cout << "========================================" << endl;
    cout << "    WELCOME TO PIZZA PALACE!" << endl;
    cout << "========================================" << endl;
    
    // Get customer information
    cout << "\nEnter your name: ";
    getline(cin, name);
    cout << "Enter delivery address: ";
    getline(cin, address);
    order.setCustomerInfo(name, address);
    
    // Order pizzas
    while (true) {
        cout << "\n--- MAIN MENU ---" << endl;
        cout << "1. Add a pizza to order" << endl;
        cout << "2. View current order" << endl;
        cout << "3. Complete order and checkout" << endl;
        cout << "4. Cancel order" << endl;
        cout << "Enter choice (1-4): ";
        
        int choice = getIntInput(1, 4);
        
        switch (choice) {
            case 1: {
                Pizza pizza = createPizza();
                order.addPizza(pizza);
                cout << "\n✓ Pizza added to order!" << endl;
                break;
            }
            case 2: {
                if (order.isEmpty()) {
                    cout << "\nYour order is empty." << endl;
                } else {
                    cout << "\n--- CURRENT ORDER ---" << endl;
                    cout << "Total: $" << fixed << setprecision(2) << order.calculateTotal() << endl;
                }
                break;
            }
            case 3: {
                if (order.isEmpty()) {
                    cout << "\nCannot checkout with an empty order!" << endl;
                } else {
                    order.displayReceipt();
                    return 0;
                }
                break;
            }
            case 4: {
                cout << "\nOrder cancelled. Thank you!" << endl;
                return 0;
            }
        }
    }
    
    return 0;
}
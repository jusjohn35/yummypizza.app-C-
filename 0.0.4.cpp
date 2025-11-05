class PizzaFactory {
public:
    static Pizza createSpecialtyPizza(string pizzaType) {
        if (pizzaType == "Meat Lovers") {
            Pizza pizza("Large", "Regular", 14.99);
            pizza.toppings = {"Pepperoni", "Sausage", "Bacon", "Extra Cheese"};
            return pizza;
        }
        else if (pizzaType == "Veggie") {
            Pizza pizza("Medium", "Thin", 11.99);
            pizza.toppings = {"Mushrooms", "Onions", "Green Peppers", "Black Olives"};
            return pizza;
        }
        else if (pizzaType == "Hawaiian") {
            Pizza pizza("Medium", "Regular", 11.99);
            pizza.toppings = {"Ham", "Pineapple", "Extra Cheese"};
            return pizza;
        }
        // Default to a basic cheese pizza
        return Pizza("Medium", "Regular", 11.99);
    }
};

// Usage in main:
void addSpecialtyPizza(Order& order) {
    cout << "\n--- SELECT SPECIALTY PIZZA ---" << endl;
    cout << "1. Meat Lovers" << endl;
    cout << "2. Veggie" << endl;
    cout << "3. Hawaiian" << endl;
    cout << "Enter choice (1-3): ";
    
    int choice = getIntInput(1, 3);
    Pizza pizza;
    
    switch(choice) {
        case 1: pizza = PizzaFactory::createSpecialtyPizza("Meat Lovers"); break;
        case 2: pizza = PizzaFactory::createSpecialtyPizza("Veggie"); break;
        case 3: pizza = PizzaFactory::createSpecialtyPizza("Hawaiian"); break;
    }
    
    order.addPizza(pizza);
    cout << "\n✓ Specialty Pizza added to order!" << endl;
}

// Function to create a custom pizza
Pizza createPizza() {
    int sizeChoice, crustChoice;
    string size, crust;
    double basePrice;       
        4. Extra Large (16") - $17.99
    cout << "Enter choice (1-4): ";
    sizeChoice = getIntInput(1, 4);     4. Stuffed Crust (+$2)
    cout << "Enter choice (1-4): ";
    crustChoice = getIntInput(1, 4);        switch (crustChoice) {
        case 1: crust = "Thin"; break;
        case 2: crust = "Regular"; break;
        case 3: crust = "Thick"; break;
        case 4: crust = "Stuffed"; basePrice += 2.00; break;
    }                       
// Factory function to create different types of pre-made pizzas
Pizza createSpecialtyPizza(string pizzaType) {
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
    
        // Example usage:
    Pizza meatLovers = createSpecialtyPizza("Meat Lovers");
    Pizza veggie = createSpecialtyPizza("Veggie");
    
    // Default to a basic cheese pizza
    return Pizza("Medium", "Regular", 11.99);
}


        case 3: {
                if (order.isEmpty()) {
                    cout << "\nYour order is empty. Cannot checkout." << endl;
                } else {
                    cout << "\n--- ORDER SUMMARY ---" << endl;
                    cout << "Total amount due: $" << fixed << setprecision(2) << order.calculateTotal() << endl;
                    cout << "Thank you for ordering from Pizza Palace!" << endl;
                    return 0;
                }
                break;
            }
            case 4: {
                cout << "\nOrder cancelled. Goodbye!" << endl;
                return 0;
            }
        }
    }
    
    return 0;
}


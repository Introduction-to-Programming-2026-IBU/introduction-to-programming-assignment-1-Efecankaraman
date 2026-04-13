# Project 5 — Mini Shopping Cart
# Concepts: Dictionaries, While Loops, Formatting

# Step 1: Define the shop menu
menu = {
    1: ("Apple",  0.50),
    2: ("Banana", 0.30),
    3: ("Milk",   1.20),
    4: ("Bread",  2.00),
}

cart = {}   # Stores { item_name: quantity }
total = 0.0

# Step 2: Display the menu to the user
print("--- Shop Menu ---")
for number, (name, price) in menu.items():
    print(f"{number}. {name:<10} ${price:.2f}")
print("5. Done")

# Step 3: The shopping loop
while True:
    try:
        choice = int(input("\nChoose an item (1-5): "))

        if choice == 5:
            break  # Exit the loop

        if choice in menu:
            item_name, item_price = menu[choice]

            # Add to cart or update quantity
            if item_name in cart:
                cart[item_name] += 1
            else:
                cart[item_name] = 1

            total += item_price
            print(f"Added {item_name}. Total: ${total:.2f}")
        else:
            print("Invalid choice, try again.")

    except ValueError:
        print("Please enter a valid number.")

# Step 4: Print the final receipt
print("\n--- Receipt ---")
for item, qty in cart.items():
    # Find the price of the item to show it on receipt
    # We search the menu to find the price for the item name
    price = 0
    for num, (name, p) in menu.items():
        if name == item:
            price = p
            break

    print(f"{item:<10} x{qty}   ${price * qty:.2f}")

print("-" * 21)
print(f"Total: ${total:.2f}")
print("Thank you!")

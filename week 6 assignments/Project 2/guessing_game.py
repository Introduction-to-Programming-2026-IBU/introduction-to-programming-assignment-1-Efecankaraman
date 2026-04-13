# Project 2 — Number Guessing Game
import random

# Step 1 — Pick a random number between 1 and 10
secret = random.randint(1, 10)

# Step 2 — Set up a counter
guesses = 0
guess = 0

print("I'm thinking of a number between 1 and 10.")

# Step 3 — Loop until the guess is correct
while guess != secret:
    guess = int(input("Guess a number between 1 and 10: "))
    guesses += 1

    if guess < secret:
        print("Too low! Try again.")
    elif guess > secret:
        print("Too high! Try again.")

# Step 4 — Success message
print(f"Correct! You got it in {guesses} guesses.")

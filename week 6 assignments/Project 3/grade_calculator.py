# Project 3 — Grade Calculator
# Concepts: for loop, lists, conditions, sum()

scores = []

# Step 1 — Collect 5 subject scores using a loop
for i in range(5):
    score = float(input(f"Enter score {i + 1}: "))
    scores.append(score)

# Step 2 — Calculate the average
# sum(scores) adds everything, len(scores) gives the count (5)
average = sum(scores) / len(scores)

# Step 3 — Determine the grade using if/elif/else
if average >= 90:
    grade = "A"
elif average >= 80:
    grade = "B"
elif average >= 70:
    grade = "C"
elif average >= 60:
    grade = "D"
else:
    grade = "F"

# Step 4 — Print results formatted to 1 decimal place
print(f"Average: {average:.1f}")
print(f"Grade: {grade}")

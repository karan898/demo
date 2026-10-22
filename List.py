PRACTICAL 2 
IMPLEMENTATION OF PYTHON LIST 
Aim 
To understand list operations and manipulation techniques in Python. 

Practical 2.1 
Program: Find Minimum and Maximum without Built-in Functions 
numbers = [12, 45, 2, 89, 33] 
 
minimum = numbers[0] 
maximum = numbers[0] 
 
for i in numbers: 
    if i < minimum: 
        minimum = i 
    if i > maximum: 
        maximum = i 
 
print("Minimum:", minimum) 
print("Maximum:", maximum) 
 
Practical 2.2 
Program: Remove Duplicates from List 
numbers = [1, 2, 3, 2, 4, 1, 5] 
unique = [] 
 
for i in numbers: 
    if i not in unique: 

        unique.append(i) 
 
print("List after removing duplicates:", unique) 
 
Practical 2.3 
Program: Append One List into Another 
list1 = [1, 2, 3] 
list2 = [4, 5, 6] 
 
list1.extend(list2) 
 
print("Combined List:", list1) 
 
Practical 2.4 
Program: Create List with Different Data Types 
sample_list = [10, 3.14, "Python", True] 
 
print(sample_list) 
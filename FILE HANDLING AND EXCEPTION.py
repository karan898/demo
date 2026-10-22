FILE HANDLING AND EXCEPTION 
MANAGEMENT 
Aim 
To perform file operations and exception handling in Python. 
Practical 6.1 
Read and Write Files 
# Writing into file 
file = open("sample.txt", "w") 
file.write("Welcome to Python Lab") 
file.close() 
 
# Reading from file 
file = open("sample.txt", "r") 
print(file.read()) 
file.close() 
 
Practical 6.2 
Exception Handling using try-except 
try: 
    a = int(input("Enter first number: ")) 
    b = int(input("Enter second number: ")) 
    print("Division:", a / b) 
except ZeroDivisionError: 
    print("Cannot divide by zero") 
except ValueError: 
    print("Invalid input") 
 

Practical 6.3 
Modules and Packages 
import math 
 
print("Square Root:", math.sqrt(25)) 
print("Power:", math.pow(2, 3)) 
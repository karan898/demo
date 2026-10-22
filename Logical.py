Practical 1.1 
Program: Find Maximum of Three Numbers 

def max_of_three(a, b, c): 
    if a >= b and a >= c: 
        return a 
    elif b >= a and b >= c: 
        return b 
    else: 
        return c 
 
x = int(input("Enter first number: ")) 
y = int(input("Enter second number: ")) 
z = int(input("Enter third number: ")) 
 
print("Maximum number is:", max_of_three(x, y, z))  

Practical 1.2 
Program: Numbers Divisible by 7 but Not Multiple of 5 
Program 
# Function to display numbers divisible by 7 but not multiple of 5 
 
def display_numbers(x, y): 
    for i in range(x, y + 1): 
        if i % 7 == 0 and i % 5 != 0: 
            print(i) 
 
start = int(input("Enter starting range: ")) 
end = int(input("Enter ending range: ")) 
 
display_numbers(start, end) 
 
Practical 1.3 
Program: Mean, Median and Mode 
Program 
from statistics import mean, median, mode 
 
numbers = [10, 20, 30, 20, 40, 50] 
 
print("Mean:", mean(numbers)) 
print("Median:", median(numbers)) 
print("Mode:", mode(numbers)) 
Output 

Mean: 28.333333333333332 
Median: 25.0 
Mode: 20 
 
Practical 1.4 
Program: Fibonacci Series 
Program 
# Fibonacci series using function 
 
def fibonacci(n): 
    a = 0 
    b = 1 
 
    for i in range(n): 
        print(a, end=" ") 
        c = a + b 
        a = b 
        b = c 
 
num = int(input("Enter number of terms: ")) 
fibonacci(num) 
 
Practical 1.5 
Program: Factorial using Recursion 
Program 
# Recursive factorial function 
 
def factorial(n): 
    if n == 0 or n == 1: 
        return 1 
    else: 
        return n * factorial(n - 1) 
 
num = int(input("Enter a number: ")) 
print("Factorial is:", factorial(num)) 
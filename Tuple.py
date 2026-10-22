PRACTICAL 3 
IMPLEMENTATION OF PYTHON TUPLE 
Aim 
To understand tuple operations and immutable data structures in Python. 
Practical 3.1 
Program: Find Repeated Items in Tuple 

tuple_data = (1, 2, 3, 2, 4, 5, 1) 
repeated = [] 
 
for i in tuple_data: 
    if tuple_data.count(i) > 1 and i not in repeated: 
        repeated.append(i) 
 
print("Repeated items:", repeated) 
 
Practical 3.2 
Program: Tuple with Different Data Types 
sample_tuple = (10, 2.5, "Python", False) 
print(sample_tuple) 
 
Practical 3.3 
Program: Replace Last Value of Tuples in List 
sample_list = [(10, 20, 40), (40, 50, 60), (70, 80, 90)] 
 
result = [t[:-1] + (100,) for t in sample_list] 
 
print(result) 
 
Practical 3.4 
Program: Sort Tuple by Float Element 
sample_data = [('item1', '12.20'), ('item2', '15.10'), ('item3', '24.5')] 
 
sample_data.sort(key=lambda x: float(x[1]), reverse=True) 
 
print(sample_data) 
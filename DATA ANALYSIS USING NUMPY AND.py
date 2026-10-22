DATA ANALYSIS USING NUMPY AND 
PANDAS 
Aim 
To perform numerical computation and data manipulation using NumPy and Pandas. 
Practical 7.1 
NumPy Array Operations 
import numpy as np 
 
array1 = np.array([10, 20, 30, 40]) 
array2 = np.array([[1, 2], [3, 4]]) 
 
print("1D Array:", array1) 
print("2D Array:\n", array2) 
 
print("Maximum:", np.max(array1)) 
print("Minimum:", np.min(array1)) 
print("Sorted Array:", np.sort(array1)) 
 
Practical 7.2 

Customer Churn Analysis using Pandas 
import pandas as pd 
 
# Creating dataframe 
 
data = { 
    'Customer': ['A', 'B', 'C'], 
    'Subscription': ['Active', 'Inactive', 'Active'], 
    'MonthlyCharge': [500, 700, 450] 
} 
 
df = pd.DataFrame(data) 
 
print(df) 
print(df.describe()) 
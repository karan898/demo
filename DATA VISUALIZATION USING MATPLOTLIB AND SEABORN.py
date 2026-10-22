DATA VISUALIZATION USING MATPLOTLIB AND SEABORN 
Aim 
To visualize data using different plotting techniques. 
Practical 8.1 
Histogram 
import matplotlib.pyplot as plt 
 
marks = [40, 50, 60, 70, 80, 90] 
 
plt.hist(marks) 
plt.title("Histogram") 
plt.show() 

 
Practical 8.2 
Bar Chart 
import matplotlib.pyplot as plt 
 
subjects = ['Python', 'DBMS', 'AI'] 
marks = [85, 78, 92] 
 
plt.bar(subjects, marks) 
plt.show() 
 
Practical 8.3 
Scatter Plot 
import matplotlib.pyplot as plt 
 
x = [1, 2, 3, 4, 5] 
y = [2, 4, 6, 8, 10] 
 
plt.scatter(x, y) 
plt.show() 
 
Practical 8.4 
Correlation Matrix using Seaborn 
import pandas as pd 
import seaborn as sns 
import matplotlib.pyplot as plt 
 
 
data = { 
    'A': [1, 2, 3, 4], 
    'B': [4, 3, 2, 1], 
    'C': [2, 3, 4, 5] 
} 
 
 
df = pd.DataFrame(data) 
 
sns.heatmap(df.corr(), annot=True) 
plt.show() 
 
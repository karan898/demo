END-TO-END DATA SCIENCE PIPELINE 
Aim 
To develop and deploy a mini data science application using machine learning. 
 
Step 1: Data Collection and Preprocessing 
import pandas as pd 
 
# Load dataset 
 
df = pd.read_csv('data.csv') 
 
# Handle missing values 
 
df = df.dropna() 
 
print(df.head()) 
 
Step 2: Visualization 
import matplotlib.pyplot as plt 
 
 
df.hist() 
plt.show() 

 
Step 3: Machine Learning Model 
from sklearn.model_selection import train_test_split 
from sklearn.linear_model import LinearRegression 
 
X = df[['Feature1']] 
y = df['Target'] 
 
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2) 
 
model = LinearRegression() 
model.fit(X_train, y_train) 
 
print("Model Trained Successfully") 
 
Step 4: Flask API 
from flask import Flask 
 
app = Flask(__name__) 
 
@app.route('/') 
def home(): 
    return "Welcome to Data Science API" 
 
if __name__ == '__main__': 
    app.run(debug=True) 

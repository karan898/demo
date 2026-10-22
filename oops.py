
Program 
# Base class 
class Animal: 
    def sound(self): 
        print("Animal makes sound") 
 
# Derived class 
class Dog(Animal): 
    def sound(self): 
        print("Dog barks") 
 
class Cat(Animal): 
    def sound(self): 
        print("Cat meows") 
 
obj1 = Dog() 
obj2 = Cat() 
 
obj1.sound() 
obj2.sound() 

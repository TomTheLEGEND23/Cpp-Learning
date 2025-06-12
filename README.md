# Cpp-Learning
A Git Repo To Document my path to learn C++ and Object Oriented Programming
Cause I am New to C++, I will try to document my Learning Path.

## Table of Projects
- Coffee Cafe

## Sources
- []()


## Knowledge 

#### Class
A **Class** is a blueprint for creating objects. It defines a set of attributes (data members) and methods (member functions) that the objects created from the class will have.

**Example:**
```cpp
class Car {
private:
    std::string brand;
    int year;
    
public:
    void startEngine();
    void stopEngine();
    void setBrand(std::string b);
    std::string getBrand();
};
```

#### Object
An **Object** is an instance of a Class. It is created from a Class and has its own set of attributes and methods defined by the Class. Each object has its own memory space for its attributes.

**Example:**
```cpp
Car myCar;        // Creating an object named 'myCar'
Car yourCar;      // Creating another object named 'yourCar'

myCar.setBrand("Toyota");   // Each object has its own data
yourCar.setBrand("Honda");
```

#### Method
A **Method** (also called member function) is a function that is defined inside a Class. It describes the behaviors of the objects created from the Class and can access the object's private data.

**Example:**
```cpp
class Calculator {
private:
    double result;
    
public:
    // Methods that define behavior
    double add(double a, double b) {
        result = a + b;
        return result;
    }
    
    double getResult() {
        return result;
    }
};
```

#### Constructor
A **Constructor** is a special method that is automatically called when an object is created from a Class. It initializes the attributes of the object. It has the same name as the class and does not have a return type.

**Example:**
```cpp
class Student {
private:
    std::string name;
    int age;
    
public:
    // Default constructor
    Student() {
        name = "Unknown";
        age = 0;
    }
    
    // Parameterized constructor
    Student(std::string n, int a) {
        name = n;
        age = a;
    }
};

// Usage:
Student student1;                    // Calls default constructor
Student student2("John", 20);        // Calls parameterized constructor
```

#### Destructor
A **Destructor** is a special method that is automatically called when an object is destroyed or goes out of scope. It is used to clean up resources that the object may have allocated during its lifetime. It has the same name as the class but is preceded by a tilde (~) and does not have a return type.

**Example:**
```cpp
class FileHandler {
private:
    std::ofstream* file;
    
public:
    FileHandler(std::string filename) {
        file = new std::ofstream(filename);
    }
    
    // Destructor - cleans up allocated memory
    ~FileHandler() {
        if (file) {
            file->close();
            delete file;
        }
    }
};
```

#### Encapsulation
**Encapsulation** is a principle of Object-Oriented Programming that restricts direct access to an object's attributes and methods. It allows the internal representation of an object to be hidden from the outside, exposing only what is necessary through public methods (getters/setters). This helps in maintaining the integrity of the object's state.

**Example:**
```cpp
class BankAccount {
private:
    double balance;        // Hidden from outside access
    std::string accountNumber;
    
public:
    // Public methods to access private data safely
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }
    
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }
    
    double getBalance() const {
        return balance;
    }
};
```

#### Polymorphism
**Polymorphism** is a feature of Object-Oriented Programming that allows the same method name to behave differently based on which object is calling it. Think of it like this: you have a base `Coffee` class, and different coffee types (like `Espresso`, `Latte`, `Cappuccino`) that all inherit from it. Each coffee type has its own unique way of being brewed, but they all use the same method name `Brew()`.

**Coffee Example (Perfect for your project!):**
```cpp
// Base Coffee class (like your Coffee.h)
class Coffee {
public:
    virtual ~Coffee() {}
    virtual void Brew() = 0;        // Each coffee brews differently
    virtual double GetPrice() = 0;   // Each coffee has different price
    virtual std::string GetName() = 0;
};

// Different coffee types - each brews uniquely
class Espresso : public Coffee {
public:
    void Brew() override {
        std::cout << "Brewing Espresso: High pressure, fine grind, 25-30 seconds" << std::endl;
    }
    
    double GetPrice() override { return 2.50; }
    std::string GetName() override { return "Espresso"; }
};

class Latte : public Coffee {
public:
    void Brew() override {
        std::cout << "Brewing Latte: Espresso shot + steamed milk + microfoam" << std::endl;
    }
    
    double GetPrice() override { return 4.25; }
    std::string GetName() override { return "Latte"; }
};

class Cappuccino : public Coffee {
public:
    void Brew() override {
        std::cout << "Brewing Cappuccino: Equal parts espresso, steamed milk, and foam" << std::endl;
    }
    
    double GetPrice() override { return 3.75; }
    std::string GetName() override { return "Cappuccino"; }
};

// Usage - Same method names, different behaviors:
Coffee* coffees[] = {
    new Espresso(),
    new Latte(), 
    new Cappuccino()
};

for (int i = 0; i < 3; i++) {
    std::cout << "Making a " << coffees[i]->GetName() << std::endl;
    coffees[i]->Brew();  // Each coffee brews differently!
    std::cout << "Price: $" << coffees[i]->GetPrice() << std::endl << std::endl;
}
```

**The Magic:** Even though you're calling the same method `Brew()` on each coffee, the program knows which specific brewing method to use based on the actual coffee type. This is **runtime polymorphism** - the decision of which method to call happens while the program is running, not when it's compiled.

#### Abstraction
**Abstraction** is the concept of hiding the complex implementation details and showing only the essential features of an object. It allows a programmer to focus on interacting with the object without needing to understand its internal workings. Abstract classes and interfaces are common ways to achieve abstraction.

**Example:**
```cpp
// Abstract base class
class Database {
public:
    virtual void connect() = 0;
    virtual void disconnect() = 0;
    virtual void executeQuery(std::string query) = 0;
};

// Concrete implementation (user doesn't need to know the details)
class MySQLDatabase : public Database {
public:
    void connect() override {
        // Complex MySQL connection logic hidden here
        std::cout << "Connected to MySQL" << std::endl;
    }
    
    void disconnect() override {
        // Complex disconnection logic hidden
        std::cout << "Disconnected from MySQL" << std::endl;
    }
    
    void executeQuery(std::string query) override {
        // Complex query execution logic hidden
        std::cout << "Executing: " << query << std::endl;
    }
};
```

#### Inheritance
**Inheritance** is a mechanism in C++ that allows a new class (derived class) to inherit the attributes and methods of an existing class (base class). This promotes code reusability and establishes an "is-a" relationship between classes.

**Example:**
```cpp
// Base class
class Animal {
protected:
    std::string name;
    int age;
    
public:
    Animal(std::string n, int a) : name(n), age(a) {}
    
    virtual void makeSound() {
        std::cout << name << " makes a sound" << std::endl;
    }
    
    void sleep() {
        std::cout << name << " is sleeping" << std::endl;
    }
};

// Derived class inheriting from Animal
class Dog : public Animal {
private:
    std::string breed;
    
public:
    Dog(std::string n, int a, std::string b) : Animal(n, a), breed(b) {}
    
    // Override base class method
    void makeSound() override {
        std::cout << name << " barks: Woof!" << std::endl;
    }
    
    // New method specific to Dog
    void fetch() {
        std::cout << name << " is fetching the ball" << std::endl;
    }
};

// Usage:
Dog myDog("Buddy", 3, "Golden Retriever");
myDog.makeSound();  // Calls Dog's version
myDog.sleep();      // Inherited from Animal
myDog.fetch();      // Dog-specific method
```
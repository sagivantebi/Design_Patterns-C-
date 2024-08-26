
# Design Patterns - C++ Project

This project demonstrates the implementation of various software design patterns using C++. Design patterns are reusable solutions to common software design problems, and this project includes examples of some of the most widely used patterns.



![oop](https://user-images.githubusercontent.com/84729141/164458690-fcb36be0-d7df-49d3-8f5b-77c4359c4fe9.jpg)


## Project Structure

- **AbstractFactory.h**: Implementation of the Abstract Factory design pattern, which provides an interface for creating families of related or dependent objects without specifying their concrete classes.
- **Adapter.h**: Implementation of the Adapter design pattern, which allows incompatible interfaces to work together.
- **BFSalgoExampleClass.h**: A Breadth-First Search (BFS) algorithm example that may be used in conjunction with other design patterns.
- **Bridge_sorter.h**: Implementation of the Bridge design pattern, which decouples an abstraction from its implementation, allowing them to vary independently.
- **BuilderRobot.h**: Implementation of the Builder design pattern, which separates the construction of a complex object from its representation.
- **Composite.h / composite_no_circle.h**: Implementation of the Composite design pattern, which allows you to compose objects into tree structures to represent part-whole hierarchies.
- **DecorterPizza.h**: Implementation of the Decorator design pattern, which allows behavior to be added to individual objects, dynamically and transparently, without affecting the behavior of other objects from the same class.
- **Factory.h**: Implementation of the Factory Method design pattern, which defines an interface for creating an object but lets subclasses alter the type of objects that will be created.
- **Proxy.h**: Implementation of the Proxy design pattern, which provides a surrogate or placeholder for another object to control access to it.
- **Singleton.h**: Implementation of the Singleton design pattern, which ensures that a class has only one instance and provides a global point of access to it.
- **command.h**: Implementation of the Command design pattern, which encapsulates a request as an object, thereby allowing for parameterization of clients with queues, requests, and operations.
- **observer.h**: Implementation of the Observer design pattern, which defines a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically.

## Prerequisites

- **C++ Compiler**: Ensure that a C++ compiler (e.g., g++) is installed on your machine.

## How to Compile and Run

1. **Navigate to the project directory**:
   ```bash
   cd Design_Patterns-Cpp-main
   ```

2. **Compile the examples**:
   You can compile each design pattern example individually using the following command:
   ```bash
   g++ -o output_filename pattern_filename.h
   ```
   Replace `output_filename` with the desired name of the compiled file, and `pattern_filename.h` with the specific design pattern header file you wish to compile.

3. **Run the compiled program**:
   ```bash
   ./output_filename
   ```

   This will execute the compiled example and demonstrate the behavior of the design pattern.

## Design Patterns Included

- **Abstract Factory**
- **Adapter**
- **Bridge**
- **Builder**
- **Composite**
- **Decorator**
- **Factory Method**
- **Proxy**
- **Singleton**
- **Command**
- **Observer**


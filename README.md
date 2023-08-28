# Object-Oriented Programming Final Project

Welcome to the Simple Assembly Compiler project! This project is a C++ implementation of an assembly language compiler that translates simplified assembly instructions into machine code.

## Features

- **Assembly Language Compiler**: The compiler is designed to parse and translate assembly instructions into machine code.

- **OOP Design Patterns**: The project demonstrates the implementation of Singleton, Factory, and Adapter design patterns to enhance modularity and code reusability.

- **Code Generation**: The compiler generates machine code instructions based on the provided assembly input.

## Design Patterns Utilized

- **Singleton Pattern**: The Singleton pattern ensures that a class has only one instance and provides a global point of access to that instance. It can be used, for example, to manage the symbol table or other global resources.

- **Factory Pattern**: The Factory pattern provides an interface for creating instances of a class with a particular type. In this project, it can be applied to generate different types of instruction objects based on the assembly input.

- **Adapter Pattern**: The Adapter pattern allows classes with incompatible interfaces to work together. In the context of this project, it can be used to adapt the assembly language syntax to the internal representation used by the compiler.

## Getting Started

1. **Clone the Repository**: Start by cloning this repository to your local machine:

   ```bash
   git clone https://github.com/SeanoChang/simple_assembly_compiler.git
   ```

2. **Navigate to the Project Directory**: Move into the project directory:

   ```bash
   cd simple_assembly_compiler
   ```

3. **Build and Run**: Use `make all` to compile everything and get all the results
   ```bash
   make all
   ```

## Usage

1. **Input Assembly Code**: Create a file containing the assembly code you want to compile.

2. **Compile Assembly Code**: Use the Simple Assembly Compiler to translate the assembly code into machine code.

3. **Execute Machine Code**: The generated machine code can be executed on a compatible system.

# miniC Compiler with LLVM

This project implements a miniC compiler that translates a simplified C-like language into LLVM intermediate representation (IR). The compiler consists of several components, including a parser, a lexical analyzer, and a code generation module.

## Project Structure

```
miniC-llvm
├── src
│   ├── main.c               # Entry point of the application
│   ├── parser
│   │   ├── miniC.y         # Grammar definitions for the miniC language
│   │   └── miniC.l         # Lexical analyzer definitions for the miniC language
│   ├── llvm
│   │   ├── codegen.c       # Code generation logic for LLVM IR
│   │   └── codegen.h       # Header file for code generation functions
│   ├── include
│   │   └── VarType.h       # Data types used in the miniC language
│   └── utils
│       └── symbol_table.c   # Symbol table functionality
├── CMakeLists.txt          # Build configuration file
└── README.md                # Project documentation
```

## Building the Project

To build the miniC compiler, follow these steps:

1. Ensure you have CMake and LLVM installed on your system.
2. Open a terminal and navigate to the project directory.
3. Create a build directory:
   ```
   mkdir build
   cd build
   ```
4. Run CMake to configure the project:
   ```
   cmake ..
   ```
5. Build the project:
   ```
   make
   ```

## Running the Compiler

After building the project, you can run the miniC compiler with the following command:

```
./miniC <input_file>
```

Replace `<input_file>` with the path to the miniC source file you want to compile.

## Contributing

Contributions are welcome! If you have suggestions or improvements, feel free to open an issue or submit a pull request.

## License

This project is licensed under the MIT License. See the LICENSE file for more details.
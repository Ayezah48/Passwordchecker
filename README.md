# Password Strength Checker

A simple C++ command-line tool designed for Kali Linux to evaluate the strength of passwords based on standard security criteria.

## Features
- Length check (minimum 8 characters)
- Complexity checks (uppercase, lowercase, digits, special characters)
- Color-coded strength rating (Weak, Moderate, Strong, Very Strong)
- Feedback on missing criteria and suggestions for improvement
- Interactive session for checking multiple passwords

## Requirements
- Kali Linux (or any Linux distribution with `g++`)
- `g++` compiler
- `make` utility

## Installation & Compilation

### Using Git
```bash
git clone https://github.com/[your-username]/Password_Strength_Checker.git
cd Password_Strength_Checker
```

### Compiling with Makefile
To compile the project, simply run:
```bash
make
```

### Compiling manually with g++
If you don't have `make` installed, you can compile manually:
```bash
g++ -Wall -std=c++11 main.cpp -o password_checker
```

## Running the Program
After compilation, run the executable:
```bash
./password_checker
```
Or use the make run command:
```bash
make run
```

## Criteria for Strength
| Score | Rating | Criteria Met |
|-------|--------|--------------|
| 5/5 | Very Strong | All criteria met |
| 4/5 | Strong | 4 criteria met |
| 3/5 | Moderate | 3 criteria met |
| 0-2/5 | Weak | 2 or fewer criteria met |

## License
MIT License

# Password Strength Checker (Python)

A simple Python command-line tool designed for Kali Linux to evaluate the strength of passwords based on standard security criteria.

## Features
- Length check (minimum 8 characters)
- Complexity checks (uppercase, lowercase, digits, special characters)
- Color-coded strength rating (Weak, Moderate, Strong, Very Strong)
- Feedback on missing criteria and suggestions for improvement
- Interactive session for checking multiple passwords

## Requirements
- Python 3.x
- Kali Linux (or any standard Linux distribution)

## Installation & Usage

### 1. Clone the repository
```bash
git clone https://github.com/[your-username]/Password_Strength_Checker.git
cd Password_Strength_Checker
```

### 2. Run the Program
You can run the script directly using Python:
```bash
python3 password_checker.py
```

### 3. Using Makefile (Optional)
If you prefer using `make`, you can run:
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

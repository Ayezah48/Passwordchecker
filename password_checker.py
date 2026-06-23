import getpass
import sys
import re

def check_password_strength():
    print("\n" + "-" * 40)
    # Using input instead of getpass for visibility if needed, 
    # but getpass is better for security. 
    # Let's stick to input to match the interactive C++ feel 
    # where the password was visible as you typed.
    password = input("Enter a password to check its strength: ")

    if not password:
        print("Password cannot be empty!")
        return

    has_upper = any(c.isupper() for c in password)
    has_lower = any(c.islower() for c in password)
    has_digit = any(c.isdigit() for c in password)
    
    special_chars = "!@#$%^&*()-_=+[]{}|;:'\",.<>/? "
    has_special = any(c in special_chars for c in password)
    
    has_min_length = len(password) >= 8

    score = 0
    missing_criteria = []

    if has_min_length:
        score += 1
    else:
        missing_criteria.append("Minimum 8 characters")

    if has_upper:
        score += 1
    else:
        missing_criteria.append("Uppercase letters")

    if has_lower:
        score += 1
    else:
        missing_criteria.append("Lowercase letters")

    if has_digit:
        score += 1
    else:
        missing_criteria.append("Digits")

    if has_special:
        score += 1
    else:
        missing_criteria.append("Special characters (!@#$%^&*)")

    # Display result
    print(f"Strength Score: {score}/5")
    print("Rating: ", end="")

    # ANSI Colors
    RED = "\033[1;31m"
    YELLOW = "\033[1;33m"
    BLUE = "\033[1;34m"
    GREEN = "\033[1;32m"
    RESET = "\033[0m"

    if score <= 2:
        print(f"{RED}Weak{RESET}")
    elif score == 3:
        print(f"{YELLOW}Moderate{RESET}")
    elif score == 4:
        print(f"{BLUE}Strong{RESET}")
    else:
        print(f"{GREEN}Very Strong{RESET}")

    if missing_criteria:
        print("\nMissing Criteria:")
        for criteria in missing_criteria:
            print(f" - {criteria}")
        
        print("\nSuggestions to improve:")
        if not has_min_length:
            print(" - Make the password at least 8 characters long.")
        if not has_upper:
            print(" - Add at least one uppercase letter (A-Z).")
        if not has_lower:
            print(" - Add at least one lowercase letter (a-z).")
        if not has_digit:
            print(" - Include at least one numeric digit (0-9).")
        if not has_special:
            print(" - Use one or more special characters (e.g., !, @, #, $).")
    else:
        print("\nExcellent! Your password meets all security criteria.")

def main():
    print("=" * 40)
    print("       Password Strength Checker        ")
    print("=" * 40)

    while True:
        check_password_strength()
        
        choice = input("\nDo you want to check another password? (y/n): ").lower()
        if not choice.startswith('y'):
            break

    print("\nExiting Password Strength Checker. Stay secure!")

if __name__ == "__main__":
    main()

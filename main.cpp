#include <iostream>
#include <string>
#include <vector>
#include <cctype>

/**
 * Password Strength Checker
 * 
 * Criteria:
 * 1. Minimum 8 characters
 * 2. Uppercase letters
 * 3. Lowercase letters
 * 4. Digits
 * 5. Special characters (!@#$%^&*)
 */

using namespace std;

// Function to assess the password strength
void checkPasswordStrength() {
    string password;
    cout << "\n----------------------------------------" << endl;
    cout << "Enter a password to check its strength: ";
    getline(cin, password);

    if (password.empty()) {
        cout << "Password cannot be empty!" << endl;
        return;
    }

    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecial = false;
    bool hasMinLength = password.length() >= 8;

    string specialChars = "!@#$%^&*()-_=+[]{}|;:'\",.<>/?";

    for (char c : password) {
        if (isupper(c)) hasUpper = true;
        else if (islower(c)) hasLower = true;
        else if (isdigit(c)) hasDigit = true;
        else if (specialChars.find(c) != string::npos) hasSpecial = true;
    }

    int score = 0;
    vector<string> missingCriteria;

    if (hasMinLength) score++;
    else missingCriteria.push_back("Minimum 8 characters");

    if (hasUpper) score++;
    else missingCriteria.push_back("Uppercase letters");

    if (hasLower) score++;
    else missingCriteria.push_back("Lowercase letters");

    if (hasDigit) score++;
    else missingCriteria.push_back("Digits");

    if (hasSpecial) score++;
    else missingCriteria.push_back("Special characters (!@#$%^&*)");

    // Display result
    cout << "Strength Score: " << score << "/5" << endl;
    cout << "Rating: ";
    
    if (score <= 2) {
        cout << "\033[1;31mWeak\033[0m" << endl; // Red
    } else if (score == 3) {
        cout << "\033[1;33mModerate\033[0m" << endl; // Yellow
    } else if (score == 4) {
        cout << "\033[1;34mStrong\033[0m" << endl; // Blue
    } else {
        cout << "\033[1;32mVery Strong\033[0m" << endl; // Green
    }

    if (!missingCriteria.empty()) {
        cout << "\nMissing Criteria:" << endl;
        for (const string& criteria : missingCriteria) {
            cout << " - " << criteria << endl;
        }
        
        cout << "\nSuggestions to improve:" << endl;
        if (!hasMinLength) cout << " - Make the password at least 8 characters long." << endl;
        if (!hasUpper) cout << " - Add at least one uppercase letter (A-Z)." << endl;
        if (!hasLower) cout << " - Add at least one lowercase letter (a-z)." << endl;
        if (!hasDigit) cout << " - Include at least one numeric digit (0-9)." << endl;
        if (!hasSpecial) cout << " - Use one or more special characters (e.g., !, @, #, $)." << endl;
    } else {
        cout << "\nExcellent! Your password meets all security criteria." << endl;
    }
}

int main() {
    cout << "========================================" << endl;
    cout << "       Password Strength Checker        " << endl;
    cout << "========================================" << endl;

    string choice;
    do {
        checkPasswordStrength();
        
        cout << "\nDo you want to check another password? (y/n): ";
        getline(cin, choice);
    } while (!choice.empty() && (choice[0] == 'y' || choice[0] == 'Y'));

    cout << "\nExiting Password Strength Checker. Stay secure!" << endl;
    return 0;
}

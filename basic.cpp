
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <cstdlib>  // For rand() and srand()
#include <ctime>   // For time() to seed random number generator
#include <cctype>


using namespace std;

// Define a structure to hold the details of each person
struct Person {
    string name;
    string aadharNo;
    string mobileNo;
    string course;
};

// Function to compare two persons for sorting (lexicographical order)
bool compare(const Person &a, const Person &b) {
    return a.name < b.name;  // Sorting based on name in ascending order
}

string generateCaptcha(int length) {
    const string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    string captcha;
    for (int i = 0; i < length; ++i) {
        captcha += chars[rand() % chars.length()];
    }
    return captcha;
}

bool verifyCaptcha(const string& captcha, const string& userInput) {
    return captcha == userInput;
}

int main() {
    int n;
    cout << "Enter the number of people: ";
    cin >> n;

    cin.ignore();  // To clear the input buffer before taking string input

    // Create a vector to store the details of people
    vector<Person> people(n);

    // Take input for each person
    for (int i = 0; i < n; ++i) {
        cout << "Enter details for person " << i + 1 << ":\n";

        cout << "Name: ";
        getline(cin, people[i].name);

        cout << "Aadhar Number: ";
        getline(cin, people[i].aadharNo);

        cout << "Mobile Number: ";
        getline(cin, people[i].mobileNo);

        cout << "Course: ";
        getline(cin, people[i].course);

        cout << endl;
    }

    // Sort the people by name in ascending order
    sort(people.begin(), people.end(), compare);

    // Display the sorted details in a table format
    cout << "\nSorted details of people (by name in ascending order):\n";
    
    // Printing table header with proper column width
    cout << left << setw(20) << "Name" 
         << setw(20) << "Aadhar Number" 
         << setw(15) << "Mobile Number" 
         << setw(25) << "Course" << endl;

    cout << "------------------------------------------------------------\n";

    // Printing each person's details in the table
    for (int i = 0; i < n; ++i) {
        cout << left << setw(20) << people[i].name 
             << setw(20) << people[i].aadharNo 
             << setw(15) << people[i].mobileNo 
             << setw(25) << people[i].course << endl;
    }

    // Generate the CAPTCHA code
        srand(static_cast<unsigned>(time(0))); // Seed the random number generator
    
        int captchaLength = 6; // Length of the CAPTCHA
        string captcha = generateCaptcha(captchaLength);
    
        cout << "Generated CAPTCHA: " << captcha << endl;
    
        string userInput;
        cout << "Enter the CAPTCHA: ";
        cin >> userInput;
    
        if (verifyCaptcha(captcha, userInput)) {
            cout << "CAPTCHA verified successfully!" <<endl;
            cout << " Sumbit has been Done ✅"<< endl;
        } else {
            cout << "CAPTCHA verification failed. Please try again." <<endl;
            
        }
    
   
    return 0;
}

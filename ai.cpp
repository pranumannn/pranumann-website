// main.cpp
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class User {
private:
    string name;
    string interest;
public:
    void registerUser() {
        cout << "Enter your name: ";
        getline(cin, name);
        cout << "Enter your interest (sports, technology, travel): ";
        getline(cin, interest);
    }

    string getInterest() {
        return toLower(interest);
    }

    string getName() {
        return name;
    }

    static string toLower(string str) {
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }
};

class ContentRecommender {
private:
    map<string, vector<string>> contentMap;
public:
    ContentRecommender() {
        contentMap["sports"] = {"Top 10 Football Players", "Cricket World Cup Highlights", "NBA Playoffs Preview"};
        contentMap["technology"] = {"Latest in AI", "Top C++ Frameworks", "Quantum Computing 101"};
        contentMap["travel"] = {"Top 10 Hidden Beaches", "Europe Travel Hacks", "Best Budget Destinations"};
    }

    void showContent(const string& interest) {
        cout << "\nRecommended content for interest: " << interest << endl;
        if (contentMap.find(interest) != contentMap.end()) {
            for (const string& item : contentMap[interest]) {
                cout << " - " << item << endl;
            }
        } else {
            cout << "No content available for this interest." << endl;
        }
    }
};

class QAEngine {
private:
    map<string, vector<pair<string, string>>> qaDatabase;
public:
    QAEngine() {
        qaDatabase["sports"] = {
            {"who won the last fifa world cup", "Argentina won the 2022 FIFA World Cup."},
            {"what is a hat-trick in cricket", "A hat-trick is when a bowler takes three wickets in three consecutive deliveries."}
        };
        qaDatabase["technology"] = {
            {"what is machine learning", "Machine learning is a field of AI that trains systems to learn from data."},
            {"what is a blockchain", "A blockchain is a decentralized ledger for secure transactions."}
        };
        qaDatabase["travel"] = {
            {"best time to visit europe", "Spring (Apr–Jun) and Fall (Sep–Oct) are ideal."},
            {"how to travel on a budget", "Travel off-season, use hostels, and book in advance."}
        };
    }

    void askQuestion(const string& interest) {
        cin.ignore();
        cout << "\nAsk your question: ";
        string question;
        getline(cin, question);
        question = User::toLower(question);

        bool found = false;
        if (qaDatabase.find(interest) != qaDatabase.end()) {
            for (auto& pair : qaDatabase[interest]) {
                if (question.find(pair.first) != string::npos) {
                    cout << "Answer: " << pair.second << endl;
                    found = true;
                    break;
                }
            }
        }

        if (!found) {
            cout << "Sorry, I don't have an answer for that question yet.\n";
        }
    }
};

void showMenu() {
    cout << "\n===== MENU =====" << endl;
    cout << "1. Show Recommended Content" << endl;
    cout << "2. Ask a Question" << endl;
    cout << "3. Exit" << endl;
    cout << "================" << endl;
}

int main() {
    User user;
    ContentRecommender recommender;
    QAEngine qa;

    user.registerUser();
    string interest = user.getInterest();

    int choice;
    do {
        showMenu();
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                recommender.showContent(interest);
                break;
            case 2:
                qa.askQuestion(interest);
                break;
            case 3:
                cout << "Goodbye, " << user.getName() << "!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}

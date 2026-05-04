#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Function to replace all occurrences of {name} in a template with the actual name
string replaceName(string templ, const string& name) {
    string placeholder = "{name}";
    size_t pos = 0;
    // Keep replacing until no more occurrences found
    while ((pos = templ.find(placeholder, pos)) != string::npos) {
        templ.replace(pos, placeholder.length(), name);
        pos += name.length(); // Move past the inserted name
    }
    return templ;
}

int main() {
    // Seed random number generator with current time so roasts differ each run
    srand(static_cast<unsigned int>(time(0)));

    // Store all roast templates in a vector
    vector<string> roastTemplates = {
        "{name} writes code so slow that even a turtle switched to Python.",
        "If procrastination were an Olympic sport, {name} would already have a gold medal — but would forget to collect it.",
        "{name}'s debugging style is basically staring at the screen until the bug gets embarrassed and leaves.",
        "{name}'s code runs so slowly that even dial-up internet feels fast.",
        "If laziness had a brand ambassador, it would be {name}.",
        "{name} doesn't debug code — they negotiate with bugs.",
        "{name} commits code with so many errors that GitHub cries.",
        "Scientists studied {name}'s code and classified it as a new form of abstract art.",
        "{name} types so slowly that autocomplete gives up and takes a nap.",
        "When {name} pushes code to production, the servers quietly update their resume.",
        "{name} tried to write a 'Hello World' program and got a runtime error.",
        "Stack Overflow banned {name} — not for asking bad questions, but for answering them.",
    };

    // Get user's name
    string name;
    cout << "========================================" << endl;
    cout << "       Welcome to the Roast Generator!  " << endl;
    cout << "========================================" << endl;
    cout << "Enter your name: ";
    getline(cin, name);

    // Handle empty input
    if (name.empty()) {
        cout << "No name entered. Using 'Mystery Human' instead." << endl;
        name = "Mystery Human";
    }

    // Randomly select a roast template
    int randomIndex = rand() % roastTemplates.size();
    string selectedRoast = roastTemplates[randomIndex];

    // Replace {name} placeholder with actual name
    string finalRoast = replaceName(selectedRoast, name);

    // Display the roast
    cout << endl;
    cout << "========================================" << endl;
    cout << "  🔥 Your Roast 🔥" << endl;
    cout << "========================================" << endl;
    cout << finalRoast << endl;
    cout << "========================================" << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to replace all occurrences of {name} in a template with the actual name
string replaceName(string templ, const string& name) {
    string placeholder = "{name}";
    size_t pos = 0;
    // Keep replacing until no more occurrences are found
    while ((pos = templ.find(placeholder, pos)) != string::npos) {
        templ.replace(pos, placeholder.length(), name);
        pos += name.length(); // Move past the inserted name to avoid infinite loop
    }
    return templ;
}

int main() {
    // Seed random number generator with current time so excuses differ each run
    srand(static_cast<unsigned int>(time(0)));

    // Store all excuse templates in a vector
    vector<string> excuseTemplates = {
        "{name} couldn't complete the assignment because the laptop battery died unexpectedly.",
        "{name} tried finishing the homework, but the internet stopped working right before submission.",
        "{name} was ready to submit the assignment when the file mysteriously disappeared.",
        "{name} couldn't finish the assignment because the laptop decided to install updates for six hours.",
        "{name} was about to complete the homework when the Wi-Fi mysteriously disappeared.",
        "{name} tried finishing the assignment, but the computer keyboard suddenly stopped cooperating.",
        "{name}'s dog found the printed notes more delicious than expected.",
        "{name} completed the homework, but the printer ran out of ink on the very last page.",
        "{name} was fully focused on the assignment when a sudden power cut erased all progress.",
        "{name} submitted the file but apparently it uploaded as a blank document — technology is unpredictable.",
        "{name} spent three hours on the assignment, but accidentally saved it in a folder that no longer exists.",
        "{name}'s little sibling thought the assignment notebook was a colouring book.",
    };

    // Get student's name
    string name;
    cout << "============================================" << endl;
    cout << "     Welcome to the Excuse Generator!       " << endl;
    cout << "============================================" << endl;
    cout << "Enter your name: ";
    getline(cin, name);

    // Handle empty input gracefully
    if (name.empty()) {
        cout << "No name entered. Using 'The Student' as default." << endl;
        name = "The Student";
    }

    // Randomly select an excuse template
    int randomIndex = rand() % excuseTemplates.size();
    string selectedExcuse = excuseTemplates[randomIndex];

    // Replace {name} placeholder with the actual student name
    string finalExcuse = replaceName(selectedExcuse, name);

    // Display the excuse
    cout << endl;
    cout << "============================================" << endl;
    cout << "  📋 Your Excuse  " << endl;
    cout << "============================================" << endl;
    cout << finalExcuse << endl;
    cout << "============================================" << endl;
    cout << "(Use responsibly... or not.)" << endl;

    return 0;
}

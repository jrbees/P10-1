//initilization

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>
#include <sstream>

using namespace std;

// Function to scramble a word
string string_scramble(const string& word) {
    // Check if word has more than 3 characters
    if (word.length() <= 3) {
        return word;
    }

    // Seed the random number generator
    srand(time(0));

    // Choose two random indices to swap
    int index1 = 1 + rand() % (word.length() - 2);
    int index2 = 1 + rand() % (word.length() - 2);

    // Make sure indices are distinct
    while (index1 == index2) {
        index2 = 1 + rand() % (word.length() - 2);
    }

    // Swap characters at the chosen indices
    string scrambled_word = word;
    swap(scrambled_word[index1], scrambled_word[index2]);

    return scrambled_word;
}

// Function to scramble text
string scramble_text(const string& text) {
    vector<string> words;
    string word;
    istringstream iss(text);

    // Split text into words
    while (iss >> word) {
        words.push_back(word);
    }

    // Scramble each word
    for (string& w : words) {
        w = string_scramble(w);
    }
     
    // Join scrambled words back into a single string
    ostringstream oss;
    for (const string& w : words) {
        oss << w << " ";
    }
    return oss.str();
}

int main() {
    string text;
    cout << "Enter a line of text: ";
    getline(cin, text);                     //here i make sure c in works

    string scrambled_text = scramble_text(text);
    cout << "Scrambled text: " << scrambled_text << endl;


    return 0;
}

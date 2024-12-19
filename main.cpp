#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>

// Function to check if a character is a vowel
bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

// Function to translate a word by replacing the last vowel and everything after with "uzz"
std::string translateToUzz(const std::string& word) {
    int lastVowelIndex = -1;

    // Find the last vowel in the word
    for (int i = word.length() - 1; i >= 0; --i) {
        if (isVowel(word[i])) {
            lastVowelIndex = i;
            break;
        }
    }

    // If no vowel is found, return the original word
    if (lastVowelIndex == -1) {
        return word;
    }

    // Create a new word up to the last vowel, then add "-uzz"
    std::string translatedWord = word.substr(0, lastVowelIndex) + "uzz";
    return translatedWord;
}

// Function to check if a word is a conjunction (using a predefined list)
bool isConjunction(const std::string& word) {
    // A simple set of common conjunctions
    std::set<std::string> conjunctions = {"Of", "of", "could", "Could", "and", "but", "or", "nor", "for", "so", "yet", "although", "because", "since", "unless", "while", "if", "though", "before", "after", "And", "But", "Or", "Nor", "For", "So", "Yet", "Although", "Because", "Since", "Unless", "While", "If", "Though", "Before", "After", "Not", "not", "a", "A", "in", "In", "An", "an"};
    
    // Check if the word is in the set of conjunctions
    return conjunctions.find(word) != conjunctions.end();
}

// Function to process an entire sentence and translate only non-conjunctions
std::string translateSentenceToUzz(const std::string& sentence) {
    std::istringstream stream(sentence);  // Create a stream to read words from the sentence
    std::string word;
    std::vector<std::string> translatedWords;  // To store translated words

    // Read each word from the sentence
    while (stream >> word) {
        // If the word is not a conjunction, translate it
        if (!isConjunction(word)) {
            translatedWords.push_back(translateToUzz(word));
        } else {
            // If it's a conjunction, leave it unchanged
            translatedWords.push_back(word);
        }
    }

    // Rebuild the translated sentence
    std::ostringstream translatedSentence;
    for (int i = 0; i < translatedWords.size(); ++i) {
        translatedSentence << translatedWords[i];
        if (i != translatedWords.size() - 1) {
            translatedSentence << " ";  // Add space between words
        }
    }

    return translatedSentence.str();  // Return the translated sentence
}

int main() {
    std::string sentence;

    // Get a sentence from the user
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, sentence);

    // Translate the entire sentence
    std::string result = translateSentenceToUzz(sentence);

    // Output the translated sentence
    std::cout << "Translated sentence: " << result << std::endl;

    return 0;
}


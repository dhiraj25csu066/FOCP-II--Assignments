#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to replace placeholders in roast template
string replacePlaceholders(string roast, string name, string hobby, string game, string subject) {
    if(name.empty()) name = "Mystery Human";
    if(hobby.empty()) hobby = "doing nothing";
    if(game.empty()) game = "Unknown Game";
    if(subject.empty()) subject = "Unknown Subject";

    // Replace placeholders
    size_t pos;
    while((pos = roast.find("{name}")) != string::npos)
        roast.replace(pos, 6, name);
    while((pos = roast.find("{hobby}")) != string::npos)
        roast.replace(pos, 7, hobby);
    while((pos = roast.find("{game}")) != string::npos)
        roast.replace(pos, 6, game);
    while((pos = roast.find("{subject}")) != string::npos)
        roast.replace(pos, 9, subject);

    return roast;
}

int main() {
    srand(time(0)); // Seed random number generator

    string name, hobby, game, subject;

    // User input
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your hobby: ";
    getline(cin, hobby);
    cout << "Enter your favorite game: ";
    getline(cin, game);
    cout << "Enter your favorite subject: ";
    getline(cin, subject);

    // Roast templates
    vector<string> roasts = {
        "Yo {name}, your love for {hobby} is so strong, even Netflix is jealous of your commitment.",
        "{name}, playing {game}? Bro, even the tutorial NPCs are worried about you.",
        "If procrastination was a subject, {name} would score 100 in {subject}.",
        "{name}, your {hobby} skills are so advanced, they should be classified as a cheat code.",
        "Legend says {name} once tried {game}... the game still hasn’t recovered.",
        "Bro {name}, your {subject} notes look like hieroglyphics even Indiana Jones couldn’t decode.",
        "{name}, your {hobby} is so niche, even Google had to ask Bing for help.",
        "Playing {game}, huh {name}? Even your WiFi gave up halfway.",
        "If {name} was a superhero, their power would be turning {subject} into nap time.",
        "{name}, your {hobby} is so wild, even TikTok couldn’t make a trend out of it."
    };

    // Random roast selection
    int randomIndex = rand() % roasts.size();
    string roast = replacePlaceholders(roasts[randomIndex], name, hobby, game, subject);

    // Output roast
    cout << "\n Your AI Roast\n" << roast << endl;

    return 0;
}

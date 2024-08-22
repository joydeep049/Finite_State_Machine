#include <iostream>
#include <string>
#include <cctype>
#include <unordered_map>

using namespace std;

// Define DFA states
enum class State {
    Start,
    Valid,
    Invalid
};

// Define events
enum class Event {
    Letter,
    Digit,
    Special,
    InvalidChar
};

// Transition function
State transition(State s, Event e) {
    switch (s) {
        case State::Start:
            if (e == Event::Letter) return State::Valid;
            break;
        case State::Valid:
            if (e == Event::Letter || e == Event::Digit || e == Event::Special) return State::Valid;
            break;
        default:
            break;
    }
    return State::Invalid;
}

// Check if character is a letter
bool is_letter(char c) {
    return std::isalpha(c);
}

// Check if character is a digit
bool is_digit(char c) {
    return std::isdigit(c);
}

// Check if character is a special symbol
bool is_special(char c) {
    return c == '_' || c == '@' || c == '#' || c == '$' || c == '&';
}

// Convert character to event
Event char_to_event(char c) {
    if (is_letter(c)) return Event::Letter;
    if (is_digit(c)) return Event::Digit;
    if (is_special(c)) return Event::Special;
    return Event::InvalidChar;
}

// Process the input string
State process(const std::string& str) {
    State s = State::Start;
    for (char c : str) {
        Event event = char_to_event(c);
        s = transition(s, event);
        if (s == State::Invalid) break; // Short-circuit on invalid state
    }
    return s;
}

int main() {
    std::string str;
    std::cout << "Enter a string: ";
    std::getline(std::cin, str);

    State final_state = process(str);

    if (final_state == State::Valid) {
        std::cout << "Valid Identifier" << std::endl;
    } else {
        std::cout << "Invalid Identifier" << std::endl;
    }

    return 0;
}

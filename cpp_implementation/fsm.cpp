#include <iostream>
#include <vector>
#include <unordered_map>
#pragma once
#include<hash>

using namespace std;

enum class State {
    Start,
    A_Start,
    Middle,
    End
};

enum class Event {
    A,
    B
};

State transition(State s, Event e) {
    static const std::unordered_map<std::pair<State, Event>, State, boost::hash<std::pair<State, Event>>> transitions = {
        {{State::Start, Event::A}, State::A_Start},
        {{State::Start, Event::B}, State::Middle},
        {{State::A_Start, Event::A}, State::A_Start},
        {{State::A_Start, Event::B}, State::A_Start},
        {{State::Middle, Event::A}, State::Middle},
        {{State::Middle, Event::B}, State::End},
        {{State::End, Event::A}, State::Middle},
        {{State::End, Event::B}, State::End}
    };

    auto it = transitions.find({s, e});
    if (it != transitions.end()) {
        return it->second;
    } else {
        throw std::invalid_argument("Invalid state transition");
    }
}

bool is_accepting(const std::vector<State>& final_list, State s) {
    for (const auto& state : final_list) {
        if (state == s) {
            return true;
        }
    }
    return false;
}

Event char_to_event(char c) {
    switch (c) {
        case 'a': return Event::A;
        case 'b': return Event::B;
        default: throw std::invalid_argument("Invalid character");
    }
}

State process(State s, const std::vector<char>& lst) {
    for (char c : lst) {
        Event event = char_to_event(c);
        s = transition(s, event);
    }
    return s;
}

int main() {
    std::string str = "abaabbbb";
    std::vector<char> str_lst(str.begin(), str.end());

    State final_state;
    try {
        final_state = process(State::Start, str_lst);
    } catch (const std::invalid_argument&) {
        std::cout << "Invalid Input or Transition" << std::endl;
        return 1;
    }

    std::vector<State> final_list = {State::A_Start, State::End};
    if (is_accepting(final_list, final_state)) {
        std::cout << "Accepted" << std::endl;
    } else {
        std::cout << "Not Accepted" << std::endl;
    }

    return 0;
}

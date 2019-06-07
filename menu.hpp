#ifndef __MENU_HPP__
#define __MENU_HPP__

#include <iostream>
#include <string>
#include "command.hpp"

using namespace std;

class Menu {
    private:
        int history_index; // Indexes which command was last executed, accounting for undo and redo functions
        std::vector<Command*> history; // Holds all the commands that have been executed until now

    public:
        Menu() {
            // Constructor which initializes the internal members
            history_index = 0;
            // for(int i = 0; i < history.size(); i++) {
            //   history.pop_back();
            // }
        }

        std::string execute() {
            // Returns the string converted evaluation of the current command
            return to_string(get_command()->execute());
        }

        std::string stringify() {
            // Returns the stringified version of the current command
            return get_command()->stringify();
        }

        bool initialized() {
            return history.size();
        }

        void add_command(Command* cmd) {
          if (history_index != history.size()) {
            history_index = history.size();
          }
          history.push_back(cmd);
          history_index++;
          return;
            // Adds a command to the history (does not execute it), this may require removal of some other commands depending on where history_index is
        }

        Command* get_command() {
          return history.at(history_index - 1);
            // Returns the command that the history_index is currently referring to
        }

        void undo() {
          if (history_index != 0 && history_index != 1) {
            // cout << history.size() << endl;
          history_index--;
        } else {
          cout << "Nothing to UNDO!" << endl;
        }
            // Move back one command (does not execute it) if there is a command to undo
        }

        void redo() {
            // Moves forward one command (does not execute it) if there is a command to redo
            if (history_index < history.size()) {
              history_index++;
            } else {
              cout << "Nothing to REDO!" << endl;
            }
        }
};

#endif

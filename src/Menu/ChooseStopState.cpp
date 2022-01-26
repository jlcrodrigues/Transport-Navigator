#include "ChooseStopState.h"

void ChooseStopState::display()
{
    cout << "\nChoose a Line\n";
    cout << "2) Go back\n";
    cout << "0) Exit\n";
}

void ChooseStopState::step(App *app)
{
    displayLines(app);
    while (true)
    {
        string option = readOptionString(app);

        if (option == "2")
        {
            app->setState(new ChooseStartState());
                return;
        }
        if (option == "0") {
            app->setState(nullptr);
                return;
        }

        for (auto line: app->getNavigator()->getLines()) {
            if (option == line.first)
            {
                cout << "You chose line: " << line.second << "\n";

                int dir = askDirection(app);

                string path = "../data/line_" + option + "_" + to_string(dir) + ".csv";
                loadLinesStops(path);

                displayLinesStops(app, path);
                string stop = askStop(app);
                cout << "You selected stop: " << stop << "\n";
                return;
            }
        }
        printInvalidOption();
    }
}



void ChooseStopState::displayLines(App *app) {
    cout << "\nCode: " << "Name\n";
    for (auto l: app->getNavigator()->getLines())
    {
        cout << l.first << ": " << l.second << "\n";
    }
    cout << "Insert the code of the wanted line: ";
}

void ChooseStopState::displayLinesStops(App *app, string path) {
    fstream file(path);
    string row;
    getline(file, row);
    cout << "\n";
    while (getline(file, row)) {
        cout << row << " - " << app->getNavigator()->getStops()[row].getName() << "\n";
    }
    file.close();
}




int ChooseStopState::askDirection(App *app) {
    cout << "Choose a direction (0 or 1): ";
    while (true) {
        int option = readOption(app);
        switch (option) {
            case 1: return 1;
            case 0: return 0;
            default: printInvalidOption();
        }
    }
}

string ChooseStopState::askStop(App *app) {
    cout << "Insert the code of the wanted stop: ";
    while (true)
    {
        string option = readOptionString(app);

        for (int i = 0; i < linesStops.size(); i++) {
            if (linesStops[i] == option) return option;
        }
        cout << "Invalid stop. Try again\n";
    }
}





void ChooseStopState::loadLinesStops(string path) {
    fstream file(path);
    string row;
    getline(file, row);
    while (getline(file, row)) {
        linesStops.push_back(row);
    }
    file.close();
}
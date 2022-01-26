#include "ChooseStopState.h"

void ChooseStopState::display()
{
    cout << "3) Show available lines\n";
    cout << "2) Go back\n";
    cout << "0) Exit\n";
}

void ChooseStopState::step(App *app) {
    while (true) {
        string option = readOptionString(app);

        if (option == "2") {
            app->setState(new ChooseStartState());
            return;
        }
        if (option == "0") {
            app->setState(nullptr);
            return;
        }

        if (option == "3")
        {
            Aux(app, true);
            app->setState(new PathState(src, dest));
            return;
        }
        printInvalidOption();
    }
}

string ChooseStopState::Aux(App *app, bool source) {
    bool done = true;
    displayLines(app);
    string option = readOptionString(app);

    while (done) {
        for (auto line: app->getNavigator()->getLines()) {
            if (option == line.first)
            {
                cout << "You chose line: " << line.second << "\n";
                int dir = askDirection(app);

                string path = "../data/line_" + option + "_" + to_string(dir) + ".csv";
                loadLinesStops(path);

                displayLinesStops(app, path);
                cout << "Insert the code of source stop: ";
                src = askStop(app);
                done = false;
            }
        }
        if (done)
        {
            cout << "Invalid line.\nInsert the code of the wanted line: ";
            option = readOptionString(app);
        }

    }

    done = true;
    displayLines(app);
    option = readOptionString(app);

    while (done) {
        for (auto line: app->getNavigator()->getLines()) {
            if (option == line.first)
            {
                cout << "You chose line: " << line.second << "\n";

                int dir = askDirection(app);

                string path = "../data/line_" + option + "_" + to_string(dir) + ".csv";
                loadLinesStops(path);

                displayLinesStops(app, path);
                cout << "Insert the code of destination stop: ";
                dest = askStop(app);
                if (dest == src)
                {
                    while (dest == src){
                        cout << "Source stop and destination stop must be different. Insert the code of destination stop.\n";
                        dest = askStop(app);
                    }
                }
                cout << "You chose source stop " << src << " and destination stop " << dest << ".\n";
                done = false;
            }
        }
        if (done)
        {
            cout << "Invalid line.\nInsert the code of the wanted line: ";
            option = readOptionString(app);
        }
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
    if (!linesStops.empty()) linesStops.clear();

    fstream file(path);
    string row;
    getline(file, row);
    while (getline(file, row)) {
        linesStops.push_back(row);
    }
    file.close();
}

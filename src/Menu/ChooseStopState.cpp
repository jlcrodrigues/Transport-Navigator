#include "ChooseStopState.h"

void ChooseStopState::display(App* app)
{
    cout << "\nChoose a stop.\n";
    cout << "3) Show available lines\n";
    cout << "2) Go back\n";
    cout << "0) Exit\n";
}

void ChooseStopState::step(App *app) {
    while (true) {
        int option = readOption(app);

        if (option == 2) {
            app->setState(new ChooseStartState());
            return;
        }
        if (option == 0) {
            app->setState(nullptr);
            return;
        }

        if (option == 3)
        {
            aux(app);
            app->setState(new PathState(src, dest));
            return;
        }
        printInvalidOption();
    }
}

void ChooseStopState::aux(App *app) {
    displayLines(app);
    string option = readOptionString(app);
    for_each(option.begin(), option.end(), [](char & c){c = ::toupper(c);});

    if (!checkLine(app, option)) {
        while (true) {
            cout << "Invalid line. Please try again: \n";
            string option = readOptionString(app);
            for_each(option.begin(), option.end(), [](char & c){c = ::toupper(c);});
            if (checkLine(app, option)) break;
        }
    }

    int dir = askDirection(app);
    string path = "../data/line_" + option + "_" + to_string(dir) + ".csv";
    loadLinesStops(path);
    displayLinesStops(app, path);

    cout << "Insert the code of source stop: ";
    src = askStop(app);

    displayLines(app);
    option = readOptionString(app);
    for_each(option.begin(), option.end(), [](char & c){c = ::toupper(c);});

    if (!checkLine(app, option)) {
        while (true) {
            cout << "Invalid line. Please try again: \n";
            string option = readOptionString(app);
            for_each(option.begin(), option.end(), [](char & c){c = ::toupper(c);});
            if (checkLine(app, option)) break;
        }
    }

    dir = askDirection(app);
    path = "../data/line_" + option + "_" + to_string(dir) + ".csv";
    loadLinesStops(path);
    displayLinesStops(app, path);

    cout << "Insert the code of destination stop: ";
    dest = askStop(app);

    while(src == dest) {
        cout << "Source stop and destination source must be different. Try another destination stop: ";
        dest = askStop(app);
    }

    cout << "You chose source stop " << src << " and destination stop " << dest << "\n";
}



void ChooseStopState::displayLines(App *app) {
    cout << "\nCode: " << "Name\n\n";
    for (auto l: app->getNavigator()->getLines())
    {
        if (app->getConfig()->isDayTravel() == (l.first.back() == 'M')) continue;
        cout << l.first << ": " << l.second << "\n";
    }
    cout << "\nInsert the code of the wanted line:";

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
        for_each(option.begin(), option.end(), [](char & c){c = ::toupper(c);});

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

bool ChooseStopState::checkLine(App *app, string option) {
    for (auto line: app->getNavigator()->getLines()) {
        if (option == line.first) {
            if (app->getConfig()->isDayTravel() == (line.first.back() == 'M')) continue;
            cout << "You chose line: " << line.second << "\n";
            return true;
        }
    }
    return false;
}
#include "CoordsState.h"

void CoordsState::display()
{
    cout << "Insert the starting position:\n\n";
}

void CoordsState::step(App *app)
{
    //Position aliados = Position(41.14813992199169, -8.611093751930307);
    Position pos;
    string src, dest;
    cout << "Choose the starting point:\n";
    pos = getPosition(app);
    src = chooseStop(app, pos);

    cout << "Choose the destination point:\n";
    pos = getPosition(app);
    dest = chooseStop(app, pos);

    app->setState(new PathState(src, dest));
}

Position CoordsState::getPosition(App* app)
{
    double latitude, longitude;
    latitude = getDouble(app, "Latitude:");
    longitude = getDouble(app, "Longitude:");
    return Position(latitude, longitude);
}

double CoordsState::getDouble(App* app, const string& message) const
{

    double number;
    cout << message;
    while (!(cin >> number))
    {
        if (cin.eof()) app->setState(nullptr);
        else
        {
            cin.clear();
            cin.ignore(100000, '\n');
            cout << message;
        }
    }
    return number;
}

string CoordsState::chooseStop(App* app, const Position& position) const
{
    string code = "";
    vector<Stop> stops = app->getNavigator()->getClosestStops(position, 5);
    cout << "Nearest stops:\n";
    for (auto stop: stops)
    {
        cout << stop.getCode() << " - " << stop.getName() << endl;
    }
    while (!in(code, stops))
    {
        cout << "\nChoose a stop:";
        cin >> code;
    }
    return code;
}

bool CoordsState::in(const string &code, const vector<Stop>& stops) const
{
    for (auto stop: stops)
    {
        if (stop.getCode() == code) return true;
    }
    return false;
}

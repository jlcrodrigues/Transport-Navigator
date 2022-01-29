#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include <string>
#include <sstream>
#include <utility>
#include <unordered_map>
#include <map>
#include <vector>
#include <fstream>

#include "graph.h"
#include "Stop.h"

class Navigator {
public:
   Navigator() = default;

   /**
    * Reads a file with bus stops and stores them to an hash table.
    * @param file_path Path of the file with the stops.
    */
   void loadStops(const string& file_path);

   /**
    * Reads a file with bus lines and stores them to an hash table.
    * @param file_path Path of the file with the lines.
    */
   void loadLines(const string& file_path);

   /**
    * Loads the files with the stops in each line and adds them to the graph.
    * @param dir_path Path of the directory where these files are located.
    */
   void loadLinesStops(const string& dir_path);

   /**
    * Checks if a stop is inside a radius in each direction.
    * This can be used to avoid computing the Haversine formula, which is expensive.
    * @param stop1 Origin stop.
    * @param stop2 Destination stop.
    * @param distance Minimum distance between the stops.
    * @return Returns true if the stops are closer than distance in each direction.
    */
   bool isClose(const Stop& stop1, const Stop& stop2, const double& distance) const;

   /**
    * Connects all the stops that are in walking range. This is done in O(n^2).
    *
    * @param max_distance Maximum walking distance.
    */
   void connectStops(const double& max_distance);

   /**
    * Calculate the closest n stops to a point in space in O(n) time.
    * @param src The origin point.
    * @param number_of_stops Number of closest stops to be returned.
    * @return Vector with n number of stops by order of distance;
    */
   vector<Stop> getClosestStops(const Position& src, const int& number_of_stops);

   /**
    * Reads a path with codes and gets the respective stops.
    * @param path A vector with codes of stops and lines.
    * @return A vector with stops and codes of lines.
    */
   vector<pair<Stop, string> > readPath(const vector<pair<string, string> >& path);

   /**
    * Get the path with the fewest stops.
    * @param src The starting stop.
    * @param dest The destination stop.
    * @return Vector with the stops from src to dest and the lines that make each transition.
    */
   vector<pair<Stop, string> > getFewestStops(const string& src, const string& dest);

   /**
    * Get the path with the fewest distance.
    * @param src The starting stop.
    * @param dest The destination stop.
    * @return Vector with the stops from src to dest and the lines that make each transition.
    */
   vector<pair<Stop, string> > getFewestDistance(const string &src, const string &dest);

   /**
    * Get the path with the fewest amount of lines used.
    * @param src The starting stop.
    * @param dest The destination stop.
    * @return Vector with the stops from src to dest and the lines that make each transition.
    */
   vector<pair<Stop, string> > getFewestLines(const string &src, const string &dest);

   /**
    * Get the path with the fewest amount of zones used.
    * @param src The starting stop.
    * @param dest The destination stop.
    * @return Vector with the stops from src to dest and the lines that make each transition.
    */
   vector<pair<Stop, string> > getFewestZones(const string &src, const string &dest);

   /**
    * Getter for lines.
    * @return Map with all the lines.
    */
    unordered_map<string, string> getLines();

    /**
     * Getter for stops.
     * @return Map with all the stops.
     */
    unordered_map<string, Stop> getStops();


private:
   string capitalize(const string& sentence) const;

   unordered_map<string, Stop> stops; //stops by code
   unordered_map<string, string> lines; //code, name

   map<string, int> stops_code;
   Graph network;

};


#endif

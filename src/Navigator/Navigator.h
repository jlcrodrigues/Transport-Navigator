#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include <string>
#include <sstream>
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
    * Get the path with the fewest stops.
    * @param src The starting stop.
    * @param dest The destination stop.
    * @return Vector with the stops from src to dest.
    */
   vector<Stop> getFewestStops(const string& src, const string& dest);

   /**
    * Getter for lines.
    * @return Map with all the lines.
    */
    unordered_map<string, string> getLines();

    /**
     * Getter for stops.
     * @return Mapp with all the stops.
     */
    unordered_map<string, Stop> getStops();


private:
   /**
    * Get a stop from the associated number.
    * @param number A number in stops_map.
    * @return Returns the correspondent stop for the number.
    */
   Stop getStop(const int& number);

   unordered_map<string, Stop> stops; //stops by code
   unordered_map<string, string> lines; //code, name

   map<string, int> stops_code;
   map<int, string> stops_number;
   Graph network;

};


#endif

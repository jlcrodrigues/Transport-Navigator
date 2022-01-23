#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include <string>
#include <sstream>
#include <unordered_map>
#include <map>
#include <fstream>

#include "Graph.h"
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

private:
   unordered_map<string, Stop> stops; //stops by code
   unordered_map<string, string> lines; //code, name

   unordered_map<string, int> stops_map;
   Graph network;
};


#endif

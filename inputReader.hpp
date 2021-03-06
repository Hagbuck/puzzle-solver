/* puzzle solver
 * inputReader.hpp
 */

#ifndef INPUT_READER_HPP
#define INPUT_READER_HPP

#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <stdexcept>

struct InputEntry{
    int   fragmentId;
    int   x;
    int   y;
    double rotation;

    std::string toString(void) const{
        return "[" + std::to_string(fragmentId) + "] (" + std::to_string(x) + "," + std::to_string(y) + ") (" + std::to_string(rotation) + ")";
    }
};

std::vector<InputEntry> getEntriesFromFile(std::string path);
std::map<int, InputEntry> getEntriesFromFileAsMap(std::string path);

std::ostream& operator<<(std::ostream &out, InputEntry const &entry);

#endif

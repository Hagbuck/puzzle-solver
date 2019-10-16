/* puzzle solver
 * inputReader.cpp
 */

 #include "inputReader.hpp"

std::vector<InputEntry> getEntriesFromFile(std::string path){
    std::vector<InputEntry> entries;
    
    std::ifstream file;
    file.open(path, std::ifstream::in);
    
    if(file.is_open()){
        int  fragmentId, x, y;
        float rotation;
        while(file >> fragmentId >> x >> y >> rotation){
            entries.push_back({fragmentId, x, y, rotation});
        }
    }
    
    return entries;
}

std::ostream& operator<<(std::ostream &out, InputEntry const &entry){
    out << entry.toString();
    return out;
}

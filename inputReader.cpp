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
        double rotation;
        while(file >> fragmentId >> x >> y >> rotation){
            entries.push_back({fragmentId, x, y, rotation});
        }
    } else {
		throw std::runtime_error(path + " doesn't exist...");
	}

    return entries;
}

std::map<int, InputEntry> getEntriesFromFileAsMap(std::string path)
{
	std::map<int, InputEntry> fragmentsMap;
	std::vector<InputEntry> fragments =  getEntriesFromFile(path);

	for(int i = 0; i < fragments.size(); ++i){
		fragmentsMap.insert( std::make_pair(fragments[i].fragmentId, fragments[i]));
	}
	return fragmentsMap;
}

std::ostream& operator<<(std::ostream &out, InputEntry const &entry){
    out << entry.toString();
    return out;
}

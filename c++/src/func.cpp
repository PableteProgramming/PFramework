#include <func.hpp>

char* StringToCharArray(std::string s){
	char* r= (char*)malloc(s.size());
	for(int i=0; i<s.size();i++){
		r[i]=s[i];
	}
	return r;
}

void PrintFile(std::string path){
	std::ifstream ifs(path.c_str(), std::ios::in | std::ios::binary | std::ios::ate);

    	std::ifstream::pos_type fileSize = ifs.tellg();
    	ifs.seekg(0, std::ios::beg);

    	std::vector<char> bytes(fileSize);
    	ifs.read(bytes.data(), fileSize);
	std::string r = std::string(bytes.data(),fileSize);
	std::cout<<r;
}

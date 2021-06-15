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

std::string EndStrip(std::string s){
	bool charFound = false;
	std::string r;
	int index = -1;
	r.clear();

	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] != '\n' && s[i] != '\t' && s[i] != ' ' && s[i] != '\t' && s[i] != '\v')
		{
			index = i;
			break;
		}
	}

	if (index == -1)
	{
		return "";
	}

	for (int i = 0; i < index + 1; i++)
	{
		r += s[i];
	}

	return r;
}

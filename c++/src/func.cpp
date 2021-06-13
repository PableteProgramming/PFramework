#include <func.hpp>

char* StringToCharArray(std::string s){
	char* r= (char*)malloc(s.size());
	for(int i=0; i<s.size();i++){
		r[i]=s[i];
	}
	return r;
}

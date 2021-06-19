#include <termColor.hpp>

void SetColor(std::vector<Color> c){
	std::string r="";
	for(int i=0; i<c.size();i++){
		r+=std::to_string(c[i]);
		if(i<c.size()-1){
			r+=";";
		}
	}
	std::cout<<"\033["+r+"m";	
}

void SetColor(Color c){
	std::cout<<"\033["+std::to_string(c)+"m";
}

void ResetColors(){
	std::cout<<"\033[0m";
}

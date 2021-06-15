#include <echo.hpp>
#include <termColor.hpp>

bool echo(std::string s){
	if (s!=""){
		std::vector<Color> c= {
			ForeBlue
		};
		SetColor(c);
		std::cout<<s;
		ResetColors();
		std::cout<<std::endl;
		return true;
	}
	return false;
}

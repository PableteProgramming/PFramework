#include <ls.hpp>
#include <PFramework.hpp>
#include <termColor.hpp>

bool ls(std::string p){
	std::string dir;
	if(p==""){
		dir=".";
	}
	else{
		std::vector<std::string> params= Split(p,' ');

		if(params.size()>1){
			return false;
		}
		
		dir= params[0];
	}	
	struct dirent* d;
        DIR* dr;
        dr = opendir(dir.c_str());
        std::string r;
        if (dr != NULL)
        {
            for (d = readdir(dr); d != NULL; d = readdir(dr))
            {
                if (std::string(d->d_name) != "." && std::string(d->d_name) != "..")
                {
			if(d->d_type==DT_DIR){
				SetColor(ForeBlue);
			}
			else{
				SetColor(ForeGreen);
			}
			std::cout<<d->d_name<<std::endl;
			ResetColors();
                }
            }
            closedir(dr);
        }
        else {
            std::cout<<dir<<" is not a valid directory !"<<std::endl;;
        }

	return true;
}

#include <iostream>
#include <vector>
#include <string>

enum Color{
	ForeBlack=30,
	BackBlack= 40,
	ForeRed=31,
	BackRed= 41,
	ForeGreen=32,
	BackGreen= 42,
	ForeYellow=33,
	BackYellow= 43,
	ForeBlue=34,
	BackBlue= 44,
	ForeMagenta=35,
	BackMagenta= 45,
	ForeCyan=36,
	BackCyan= 46,
	ForeWhite=37,
	BackWhite= 47,
};

void SetColor(std::vector<Color>);
void SetColor(Color);
void ResetColors();

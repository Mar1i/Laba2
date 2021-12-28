#include "Founder.h"
#include<string>
#define END ".!?"
#define DIVIDE " ,;-()"
Founder::Founder()
{
	//подсчитать нужное число слов	
	std::string path = "Text.txt",line = "",str="";
	std::ifstream f;
	int cnt = 0;
	f.open(path);
	if (f.is_open()) {
		while (getline(f, line, '\0'))
		{
			//std::cout << line;
			str = parse(line,5);
			std::cout << str;

		}
		f.close();
	}
	else 
		std::cout << "File was't opened\n";
	

}

std::string Founder::parse(std::string line,int _cnt)
{
	int pos1 = 0,pos2 = 0,i=0,cnt = 0;
	char c, cPrev;
	std::string out;
	while (line[i] != '\0') {
		c = line[i];
		
		
		if (c == DIVIDE[0] || c == DIVIDE[1] || c == DIVIDE[2] || c == DIVIDE[3] || c == DIVIDE[4] || c == DIVIDE[5] || c == DIVIDE[6]||c == END[0] || c == END[1] || c == END[2]) {
			cPrev = line[i - 1];
			if (cPrev != DIVIDE[0] && cPrev != DIVIDE[1] && cPrev != DIVIDE[2] && cPrev != DIVIDE[3]
				&& cPrev != DIVIDE[4] && cPrev != DIVIDE[5] && cPrev != DIVIDE[6] 
				&& cPrev != END[0] && cPrev != END[1] && cPrev != END[2]) {
				
				cnt++;
			}
			if (c == END[0] || c == END[1] || c == END[2]) { //конец предложения
				pos2 = i;

				if (cnt == _cnt)
					out += line.substr(pos1, pos2+1 - pos1+1) + "\n";
				cnt = 0;
				

			}
				
		}
		else
			if (i != 0) {
				if (i >= 2) {
					if ((line[i - 1] == DIVIDE[0] || line[i - 1] == DIVIDE[1] || line[i - 1] == DIVIDE[2] || line[i - 1] == DIVIDE[3]
						|| line[i - 1] == DIVIDE[4]|| line[i - 1] == DIVIDE[5] || line[i - 1] == DIVIDE[6])&& (line[i - 2] == END[0] 
							|| line[i - 2] == END[1] || line[i - 2] == END[2])) {
						
						pos2 = i;
						pos1 = i;
					}
				}
			}
		i++;
	}


	return std::string(out);
}

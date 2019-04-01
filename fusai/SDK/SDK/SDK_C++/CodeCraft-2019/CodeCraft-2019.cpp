#include "iostream"
#include "para.h"
#include "lib/io/basicStruct.h"
#include "lib/vector/Vector.h"
#include "lib/graph/AdjMatNet.h"
#include "lib/io/fileread.h"
#include "lib/DEBUG.h"
#include <stdlib.h>
#include <omp.h>

int main(int argc, char *argv[])
{
    std::cout << "Begin" << std::endl;

	if(argc < 6){
		std::cout << "please input args: carPath, roadPath, crossPath, answerPath" << std::endl;
		exit(1);
	}

	std::string carPath(argv[1]);
	std::string roadPath(argv[2]);
	std::string crossPath(argv[3]);
	std::string presetAnswerPath(argv[4]);
	std::string answerPath(argv[5]);

	std::cout << "carPath is " << carPath << std::endl;
	std::cout << "roadPath is " << roadPath << std::endl;
	std::cout << "crossPath is " << crossPath << std::endl;
	std::cout << "presetAnswerPath is " << presetAnswerPath << std::endl;
	std::cout << "answerPath is " << answerPath << std::endl;

	// TODO:read input filebuf
	// TODO:process
	// TODO:write output file

/* read txt */
    MyDSA::Vector<Car> carList;
    textread(carList,carPath,1);
    //carList.sort(); //排序需要调！
    //print(carList);

    MyDSA::Vector<Cross> vList;
    textread<Cross>(vList,crossPath,1);
    //print(vList);

    MyDSA::Vector<Road> eList;
    textread<Road>(eList,roadPath,1);
    //print(eList);

	std::vector<CarPath> pAList;
	textread<CarPath>(pAList,presetAnswerPath,1);
	//print(pAList);

/* read txt end */
    #pragma omp parallel for
    for(int i = 0; i < 100; i++)
    {
        std::cout << i << std::endl;
    }

	return 0;
}

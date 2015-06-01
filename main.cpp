#include <iostream> 
#include <fstream>

#define MAX_EQUIPOS 100

using namespace std;



int main() 

{

	Team listOfTeams[MAX_EQUIPOS];
    
	int option=1;
	while(option!=0){
		option=ShowMenu();
		switch (option){
			case 1:
				AddTeam();
				ShowMenu();
				break;
			case 2:
				DeleteTeam();
				ShowMenu();
				break;
			case 3:
				ShowTeams();
				ShowMenu();
				break;
			case 0:
                 
				exit(0);
				break;
			default:
				ShowMenu();
		}
	}

return 0;
}
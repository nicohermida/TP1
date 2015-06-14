#include <iostream> 
#include <fstream>

using namespace std;

#define MAX_EQUIPOS 100

struct Team {
	char ident[4];
	char name[32];
	int firePower;
	int defensePower;
};

int ShowMenu(){
	

	int option;
	
	cout << " Menu\n"<<" 1. Agregar Equipo\n"<<" 2. Eliminar Equipo\n"<< " 3. Ver Equipos\n"<< " 0. Salir\n"<< " Ingrese su opcion:\n ";
	cin >> option;
	return option;
}

bool SaveTeam(Team team){
	
    FILE *archive = fopen("EQUIPOS.BIN", "ab");
	fwrite(&team, sizeof(team), 1, archive);
	fclose(archive);
	return true;
}

bool IdentTaken(char ident[4]){
	
	FILE *archive = fopen("EQUIPOS.BIN", "rb");
	Team team;
	bool taken =false;
	while(!feof(archive)){
		fread(&team,sizeof(team),1,archive);
		
		if ( team.ident == ident ){
			
			taken=true;
		}
	}
	fclose(archive);
	return taken;
}

void EditTeam(char ident[4]){
	
	
}

void AddTeam(){
	

	Team team;
	char edit[2];

	cout << "Ingrese el identificador (3 caracteres): ";

	cin >> team.ident;

	if(IdentTaken(team.ident)){
		cout << " Este identificador se encuentra ocupado, desea modificar equipo ? :";
		cin >> edit;
		if(edit=="si"|| edit=="SI"|| edit=="Si"|| edit=="Si"){
			EditTeam(team.ident);
		}
	} else {
		cout << " Ingrese el nombre del equipo : \n";

		cin >> team.name;

		cout << " Ingrese potencia de ataque (0-100): \n";
		cin >> team.firePower;
		cout << " Ingrese potencia de defensa (0-100):\n ";
		cin >> team.defensePower;
		if(SaveTeam(team)){
			cout << " Equipo guardado\n";
		} 
	}
	return;
}







void DeleteTeam (){
     
     
     }


void ShowTeams(){
	
	FILE *archive = fopen("EQUIPOS.BIN", "rb");
	Team team;
	cout << "Lista de equipos:\n"; 
	fread(&team,sizeof(team),1,archive);
	while(!feof(archive)){
		cout << team.ident << " " << team.name << " (" << team.firePower << " - " << team.defensePower << ")\n";
  		fread(&team,sizeof(team),1,archive);
	}
	fclose(archive);
	return;
}


int main() {
	
    Team listOfTeam[MAX_EQUIPOS];
    
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


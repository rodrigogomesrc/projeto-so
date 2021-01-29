# include "processo.hpp"
#include <ctime>

string Processo::getTempo(){
	time_t tempo = time(0);
	tm local = * localtime(&tempo);
	string hora = to_string(local.tm_hour);
	string min = to_string(local.tm_min);
	string seg = to_string(local.tm_sec);
	return hora + ":" + min + ":" + seg;


}
void Processo::executar() {
	//pai
	nasc = getTempo();
	cout << "Pai nasce em: " << nasc << endl;
	pid_t pid;
	sleep(14);

	cout << "pai criando filho1 aos 14: " << getTempo() << endl; 
	pid = fork();
	if (pid < 0){
		cout << "erro" << endl;
	}else if(pid == 0){
		//filho 1
		nasc = getTempo();
		sleep(12);
		cout << "Pai é avô aos 26 do primeiro filho: "  << getTempo() << endl;
		pid = fork();
		if(pid < 0){
			cout << "erro" << endl;
		}else if(pid == 0){
			//neto1
			nasc = getTempo();
			sleep(12);
			cout << "neto 1 morre aos 12: nascimento: " << nasc << " morte: " << getTempo() << endl;
			exit(0);


		}else{
			//filho1
			sleep(18);
			cout << "filho 1 morre aos 30: nascimento: " << nasc << " morte: " << getTempo() << endl;
			exit(0);
		}
	}else{
		// pai
		sleep(2);
		cout << "pai criando filho2 aos 16: " << getTempo() << endl; 
		pid = fork();
		if(pid < 0){
			cout << "erro";
		}else if(pid == 0 ){
			//filho2
			nasc = getTempo();
			sleep(14);
			cout << "Pai é avô aos 30 do segundo filho: "  << getTempo() << endl;
			pid = fork();
			if(pid < 0){
				cout << "erro" << endl;
			}else if(pid == 0){
				//neto2
				nasc = getTempo();
				sleep(18);
				cout << "neto 2 morre aos 18: nascimento: " << nasc << " morte: " << getTempo() << endl;
			}else{
				//filho2
				sleep(16);
				cout << "filho 2 morre aos 30: nascimento: " << nasc << " morte: " << getTempo() << endl;
				exit(0);
			}
		}else{
			//pai
			sleep(44);
			cout << "pai morre aos 60: nascimento: " << nasc << " morte: " << getTempo() << endl;
			exit(0);
		}

	}
	






















}
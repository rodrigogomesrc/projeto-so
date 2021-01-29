# include "processo.hpp"
#include <ctime>

string Processo::getTempo(time_t tempo){

	tm local = * localtime(&tempo);
	string hora = to_string(local.tm_hour);
	string min = to_string(local.tm_min);
	string seg = to_string(local.tm_sec);
	return hora + ":" + min + ":" + seg;


}
void Processo::executar() {
	//pai
	nasc = time(0);
	cout << "Pai nasce em: " << getTempo(nasc) << endl;
	pid_t pid;
	sleep(14);

	cout << "pai criando filho1 aos 14: " << getTempo(time(0)) << endl; 
	pid = fork();
	if (pid < 0){
		cout << "erro" << endl;
	}else if(pid == 0){
		//filho 1
		nasc = time(0);
		sleep(12);
		cout << "Pai é avô aos 26 do primeiro filho: "  << getTempo(time(0)) << endl;
		pid = fork();
		if(pid < 0){
			cout << "erro" << endl;
		}else if(pid == 0){
			//neto1
			nasc = time(0);
			sleep(12);
			morte = time(0);
			cout << "neto 1 morre | nascimento: " << getTempo(nasc) << " morte: " << getTempo(morte)  << " vida: " << to_string(morte - nasc)  << endl;
			exit(0);


		}else{
			//filho1
			sleep(18);
			morte = time(0);
			cout << "filho 1 morre | nascimento: " << getTempo(nasc) << " morte: " << getTempo(morte)  << " vida: " << to_string(morte - nasc)  << endl;
			exit(0);
		}
	}else{
		// pai
		sleep(2);
		cout << "pai criando filho2 aos 16: " << getTempo(time(0)) << endl; 
		pid = fork();
		if(pid < 0){
			cout << "erro";
		}else if(pid == 0 ){
			//filho2
			nasc = time(0);
			sleep(14);
			cout << "Pai é avô aos 30 do segundo filho: "  << getTempo(time(0)) << endl;
			pid = fork();
			if(pid < 0){
				cout << "erro" << endl;
			}else if(pid == 0){
				//neto2
				nasc = time(0);
				sleep(18);
				morte = time(0);
				cout << "neto 2 morre | " << getTempo(nasc) << " morte: " << getTempo(morte)  << " vida: " << to_string(morte - nasc)  << endl;
			}else{
				//filho2
				sleep(16);
				morte = time(0);
				cout << "filho 2 morre | nascimento: " << getTempo(nasc) << " morte: " << getTempo(morte)  << " vida: " << to_string(morte - nasc)  << endl;
				exit(0);
			}
		}else{
			//pai
			sleep(44);
			morte = time(0);
			cout << "pai morre | nascimento: " << getTempo(nasc) << " morte: " << getTempo(morte) << " vida: " << to_string(morte - nasc) << endl;
			exit(0);
		}

	}
	






















}
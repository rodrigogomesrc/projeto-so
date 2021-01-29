#include "processo.hpp"

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

	cout << "Pai criando Filho 1 aos 14 anos: " << getTempo(time(0)) << endl; 
	pid = fork();

	if (pid < 0){
		cout << "erro" << endl;

	} else if(pid == 0){
		//filho 1
		nasc = time(0);
		sleep(12);
		cout << "Pai é avô aos 26 anos do primeiro filho: "  << getTempo(time(0)) << endl;
		pid = fork();

		if(pid < 0){
			cout << "erro" << endl;

		} else if(pid == 0){
			//neto1
			nasc = time(0);
			sleep(12);
			morte = time(0);
			cout << "Neto 1 morre | Nascimento: " << getTempo(nasc) << " Morte: " << getTempo(morte)  
			<< " Vida: " << to_string(morte - nasc)  << " anos" << endl;
			exit(0);


		} else {
			//filho1
			sleep(18);
			morte = time(0);
			cout << "Filho 1 morre | Nascimento: " << getTempo(nasc) << " Morte: " << getTempo(morte)  
			<< " Vida: " << to_string(morte - nasc)  << " anos" << endl;
			exit(0);
		}

	} else {
		// pai
		sleep(2);
		cout << "Pai criando Filho 2 aos 16 anos: " << getTempo(time(0)) << endl; 
		pid = fork();
		if(pid < 0){
			cout << "erro";

		} else if(pid == 0 ){
			//filho2
			nasc = time(0);
			sleep(14);
			cout << "Pai é avô aos 30 anos do segundo filho: "  << getTempo(time(0)) << endl;
			pid = fork();

			if(pid < 0){
				cout << "erro" << endl;

			} else if(pid == 0){
				//neto2
				nasc = time(0);
				sleep(18);
				morte = time(0);
				cout << "Neto 2 morre | " << getTempo(nasc) << " Morte: " << getTempo(morte)  
				<< " Vida: " << to_string(morte - nasc)  << " anos" << endl;

			} else {
				//filho2
				sleep(16);
				morte = time(0);
				cout << "Filho 2 morre | Nascimento: " << getTempo(nasc) << " Morte: " 
				<< getTempo(morte)  << " Vida: " << to_string(morte - nasc)  << " anos" << endl;
				exit(0);
			}

		} else { 
			//pai
			sleep(44);
			morte = time(0);
			cout << "Pai morre | Nascimento: " << getTempo(nasc) << " Morte: " << getTempo(morte) 
			<< " Vida: " << to_string(morte - nasc)  << " anos" << endl;
			exit(0);
		}

	}
	






















}
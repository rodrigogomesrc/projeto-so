# include "processo.hpp"

void Processo::executar() {

	std::cout << "Executando o processo pai..." << std::endl;
	pid_t pid;

	sleep(14);
	std::cout << "Criando primeiro filho após 14 anos" << std::endl;
	pid = fork();

	if(pid < 0){ //se erro
		std::cout << "erro na criação de um novo processo" << std::endl;

	} else if(pid == 0){ //se filho

		sleep(12);
		std::cout << "Criando o primeiro neto" << std::endl;
		pid = fork();

		if(pid < 0){ //se error
			std::cout << "erro na criação de um novo processo" << std::endl;

		} else if (pid == 0){ //se filho

			sleep(12);
			std::cout << "Neto 1 morrendo aos 12 anos" << std::endl;
			exit(0);

		} else { //se pai
					
			sleep(18);
			std::cout << "Filho 1 morrendo aos 30 anos" << std::endl;
			exit(0);

		}

	} else { //processo pai

		sleep(2);
		std::cout << "Criando o segundo filho após 16 anos" << std::endl;
		pid = fork();

		if(pid < 0){ //se error

		} else if (pid == 0){ //se filho

			sleep(14);
			std::cout << "Criando segundo neto" << std::endl;


			if(pid < 0){ //se error
				std::cout << "erro na criação de um novo processo" << std::endl;

			} else if (pid == 0){ //se filho

				sleep(18);
				std::cout << "Neto 2 morrendo aos 18 anos" << std::endl;
				exit(0);

			} else { //se pai

				sleep(16);
				std::cout << "Filho 2 morrendo aos 30 anos" << std::endl;
				exit(0);
						
			}

		} else { //se pai
			
			sleep(44);
			std::cout << "Pai morrendo após 60 anos" << std::endl;
			exit(0);
		}


		sleep(44);
		std::cout << "Pai morrendo após 60 anos" << std::endl;
		exit(0);

	}
} 
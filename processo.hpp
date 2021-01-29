#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/wait.h>
#include <ctime>

using namespace std;

class Processo {

	public:

		void executar();
		string getTempo(time_t tempo);
	 	time_t nasc;
		 time_t morte;
};
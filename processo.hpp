#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

class Processo {

	public:

		void executar();
		string getTempo();
	 	string nasc;
};
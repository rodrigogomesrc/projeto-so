# include "processo.hpp"


int main(int argc, char const *argv[])
{
	
	Processo *p = new Processo();
	p->executar();
	delete p;

	return 0;
}
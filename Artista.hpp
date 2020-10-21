// Artista.hpp (Roland Teodorowitsch; 28 set. 2020)

#ifndef _ARTISTA_HPP
#define _ARTISTA_HPP

#include <string>

using namespace std;

class Artista {
private:
	string nome;
public:
	Artista(string n="");
	void defineNome(string n);
	string obtemNome();
};

#endif

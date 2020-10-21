// Filme.hpp (Roland Teodorowitsch; 28 set. 2020)

#ifndef _FILME_HPP
#define _FILME_HPP

#include <string>
#include "Artista.hpp"

using namespace std;

#define MAX_ATORES 10

class Filme {
private:
	string nome;
	int ano;
	Artista *diretor;
	int numAtores;
	Artista *atores[MAX_ATORES];
public:
	Filme();
	Filme(string n,int a);
	void defineNome(string n);
	string obtemNome() const;
	void defineAno(int a);
	int obtemAno() const;
	void defineDiretor(Artista *d);
	Artista *obtemDiretor() const;
	int obtemNumeroAtores() const;
	Artista *obtemAtor(int i) const;
	bool adicionaAtor(Artista *a);
	Artista *removeAtor(int i);
	bool ehDiretor(Artista *a) const;
	bool ehDiretor(string n) const;
	bool ehAtor(Artista *a) const;
	bool ehAtor(string n) const;
    int indiceAtor(Artista *a) const;
    int indiceAtor(string n) const;
	string str(int codigo=-1) const;
    bool operator==(const Filme &f) const;
};

#endif

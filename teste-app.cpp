// teste-app.cpp (Roland Teodorowitsch; 20 out. 2020)

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#include "Artista.hpp"
// #include "Ator.hpp"
// #include "Diretor.hpp"
#include "Filme.hpp"


#ifdef _ARTISTA_HPP
bool testa_artista() {
    Artista *a;
    string teste1 = "Teste 1 2 3...";
    string teste2 = "3 2 1... Teste!";
    a = new Artista();
    if (a->obtemNome().compare("")!=0)
        return false;
    a->defineNome(teste1);
    if (a->obtemNome().compare(teste1)!=0)
        return false;
    delete a;
    a = new Artista(teste1);
    if (a->obtemNome().compare(teste1)!=0)
        return false;
    a->defineNome(teste2);
    if (a->obtemNome().compare(teste2)!=0)
        return false;
    delete a;
    return true;
}
#else
bool testa_ator() {
    Ator *a;
    string teste1 = "Teste 1 2 3...";
    string teste2 = "3 2 1... Teste!";
    a = new Ator();
    if (a->obtemNome().compare("")!=0)
        return false;
    a->defineNome(teste1);
    if (a->obtemNome().compare(teste1)!=0)
        return false;
    delete a;
    a = new Ator(teste1);
    if (a->obtemNome().compare(teste1)!=0)
        return false;
    a->defineNome(teste2);
    if (a->obtemNome().compare(teste2)!=0)
        return false;
    delete a;
    return true;
}

bool testa_diretor() {
    Diretor *d;
    string teste1 = "Teste 1 2 3...";
    string teste2 = "3 2 1... Teste!";
    d = new Diretor();
    if (d->obtemNome().compare("")!=0)
        return false;
    d->defineNome(teste1);
    if (d->obtemNome().compare(teste1)!=0)
        return false;
    delete d;
    d = new Diretor(teste1);
    if (d->obtemNome().compare(teste1)!=0)
        return false;
    d->defineNome(teste2);
    if (d->obtemNome().compare(teste2)!=0)
        return false;
    delete d;
    return true;
}
#endif

bool testa_filme() {
    Filme *f;
    string nome1 = "Teste 1 2 3 4...";
    string nome2 = "4 3 2 1... Teste!";
    int ano1 = 1234;
    int ano2 = 4321;
    string nomeDiretor1 = "Diretor 1";
    string nomeDiretor2 = "Diretor 2";
#ifdef _ARTISTA_HPP
    Artista *diretor1 = new Artista(nomeDiretor1);
    Artista *diretor2 = new Artista(nomeDiretor2);
#else
    Diretor *diretor1 = new Diretor(nomeDiretor1);
    Diretor *diretor2 = new Diretor(nomeDiretor2);
#endif

    f = new Filme();
    if (f->obtemNome().compare("")!=0 || f->obtemAno()!=0 ||
        f->obtemDiretor()!=nullptr || f->obtemNumeroAtores()!=0)
        return false;
    for (int i=0; i<=MAX_ATORES; ++i)
        if (f->obtemAtor(i)!=nullptr)
            return false;
    f->defineNome(nome1);
    f->defineAno(ano1);
    if (f->obtemNome().compare(nome1)!=0 || f->obtemAno()!=ano1 ||
        f->obtemDiretor()!=nullptr || f->obtemNumeroAtores()!=0)
        return false;
    for (int i=0; i<=MAX_ATORES; ++i)
        if (f->obtemAtor(i)!=nullptr)
            return false;
    f->defineDiretor(diretor1);
    if (f->obtemNome().compare(nome1)!=0 || f->obtemAno()!=ano1 ||
        f->obtemDiretor()!=diretor1 || f->obtemNumeroAtores()!=0 ||
        f->ehDiretor(diretor1)==false || f->ehDiretor(diretor2)==true ||
        f->ehDiretor(nomeDiretor1)==false || f->ehDiretor(nomeDiretor2)==true)
        return false;
    for (int i=0; i<=MAX_ATORES; ++i)
        if (f->obtemAtor(i)!=nullptr)
            return false;
    delete f;
    cout << "> Subteste 1 para filme (construtor vazio e métodos básicos): OK" << endl;

    f = new Filme(nome1,ano1);
    if (f->obtemNome().compare(nome1)!=0 || f->obtemAno()!=ano1 ||
        f->obtemDiretor()!=nullptr || f->obtemNumeroAtores()!=0)
        return false;
    for (int i=0; i<=MAX_ATORES; ++i)
        if (f->obtemAtor(i)!=nullptr)
            return false;
    f->defineNome(nome2);
    f->defineAno(ano2);
    if (f->obtemNome().compare(nome2)!=0 || f->obtemAno()!=ano2 ||
        f->obtemDiretor()!=nullptr || f->obtemNumeroAtores()!=0)
        return false;
    for (int i=0; i<=MAX_ATORES; ++i)
        if (f->obtemAtor(i)!=nullptr)
            return false;
    f->defineDiretor(diretor2);
    if (f->obtemNome().compare(nome2)!=0 || f->obtemAno()!=ano2 ||
        f->obtemDiretor()!=diretor2 || f->obtemNumeroAtores()!=0 ||
        f->ehDiretor(diretor2)==false || f->ehDiretor(diretor1)==true ||
        f->ehDiretor(nomeDiretor2)==false || f->ehDiretor(nomeDiretor1)==true)
        return false;
    for (int i=0; i<=MAX_ATORES; ++i)
        if (f->obtemAtor(i)!=nullptr)
            return false;
    delete f;
    cout << "> Subteste 2 para filme (construtor 2 e métodos básicos): OK" << endl;
    
#ifdef _ARTISTA_HPP
    Artista *atores[MAX_ATORES+1];
#else
    Ator *atores[MAX_ATORES+1];
#endif
    for (int i=0; i<MAX_ATORES+1; ++i) {
        stringstream ss;
        ss << "Ator " << (i+1);
#ifdef _ARTISTA_HPP
        atores[i] = new Artista(ss.str());
#else
        atores[i] = new Ator(ss.str());
#endif
    }
    f = new Filme(nome1,ano1);
    f->defineDiretor(diretor1);
    for (int i=0; i<MAX_ATORES; ++i) {
        if (f->obtemNumeroAtores() != i)
            return false;
        if (f->adicionaAtor(atores[i])!=true)
            return false;
        for (int j=0;j<=i;++j) {
            if (f->obtemAtor(j) != atores[j])
               return false;
            if (f->ehAtor(atores[j]) != true)
               return false;
            if (f->ehAtor(atores[j]->obtemNome()) != true)
               return false;
            if (f->indiceAtor(atores[j]) != j)
                return false;
            if (f->indiceAtor(atores[j]->obtemNome()) != j)
                return false;
        }
        for (int j=i+1;j<=MAX_ATORES;++j) {
            if (f->obtemAtor(j) != nullptr)
               return false;
            if (f->ehAtor(atores[j]) != false)
               return false;
            if (f->ehAtor(atores[j]->obtemNome()) != false)
               return false;
            if (f->indiceAtor(atores[j]) != -1)
                return false;
            if (f->indiceAtor(atores[j]->obtemNome()) != -1)
                return false;
        }
    }
    if (f->obtemNumeroAtores() != MAX_ATORES)
        return false;
    if (f->adicionaAtor(atores[MAX_ATORES])!=false)
        return false;
    if (f->obtemNumeroAtores() != MAX_ATORES)
        return false;
    if (f->obtemAtor(MAX_ATORES) != nullptr)
        return false;
    if (f->ehAtor(atores[MAX_ATORES]) != false)
        return false;
    if (f->ehAtor(atores[MAX_ATORES]->obtemNome()) != false)
        return false;
    if (f->indiceAtor(atores[MAX_ATORES]) != -1)
        return false;
    if (f->indiceAtor(atores[MAX_ATORES]->obtemNome()) != -1)
        return false;
    delete f;
    cout << "> Subteste 3 para filme (métodos para atores): OK" << endl;
    
    f = new Filme(nome1,ano1);
    f->defineDiretor(diretor1);
    for (int i=0; i<MAX_ATORES; ++i) {
        if (f->adicionaAtor(atores[i])!=true)
            return false;
    }
    if (f->removeAtor(-1)!=nullptr)
        return false;
    int numAtores = f->obtemNumeroAtores();
    for (int i=0; i<MAX_ATORES; i+=2) {
        int indice = f->indiceAtor(atores[i]->obtemNome());
        if (f->removeAtor(numAtores)!=nullptr)
            return false;
        if (f->removeAtor(indice)!=atores[i])
            return false;
        --numAtores;
        if (f->removeAtor(numAtores)!=nullptr)
            return false;
        if (f->obtemNumeroAtores() != numAtores)
            return false;
        if (f->ehAtor(atores[i]) != false)
            return false;
        if (f->ehAtor(atores[i]->obtemNome()) != false)
            return false;
        if (f->indiceAtor(atores[i]) != -1)
            return false;
        if (f->indiceAtor(atores[i]->obtemNome()) != -1)
            return false;
    }
    for (int i=1; i<MAX_ATORES; i+=2) {
        int indice = f->indiceAtor(atores[i]->obtemNome());
        if (f->removeAtor(numAtores)!=nullptr)
            return false;
        if (f->removeAtor(indice)!=atores[i])
            return false;
        --numAtores;
        if (f->removeAtor(numAtores)!=nullptr)
            return false;
        if (f->obtemNumeroAtores() != numAtores)
            return false;
        if (f->ehAtor(atores[i]) != false)
            return false;
        if (f->ehAtor(atores[i]->obtemNome()) != false)
            return false;
        if (f->indiceAtor(atores[i]) != -1)
            return false;
        if (f->indiceAtor(atores[i]->obtemNome()) != -1)
            return false;
    }
    delete f;
    cout << "> Subteste 4 para filme (método para remover ator): OK" << endl;

    f = new Filme(nome1,ano1);
    Filme filme;
    if (filme == *f)
        return false;
    filme.defineNome(nome1);
    if (filme == *f)
        return false;
    filme.defineNome("");
    filme.defineAno(ano1);
    if (filme == *f)
        return false;
    filme.defineNome(nome1);
    filme.defineAno(ano1);
    if (!(filme == *f))
        return false;
    delete f;
    cout << "> Subteste 5 para filme (sobrecarga de ==): OK" << endl;
    
    cout << "> Método str NÃO testado..." << endl;

    for (int i=0; i<MAX_ATORES+1; ++i)
        delete atores[i];
    delete diretor2;
    delete diretor1;
    return true;
}

int main() {
#ifdef _ARTISTA_HPP
    cout << "Teste para artista: " << (testa_artista()?"OK":"FALHOU") << endl;
#else
    cout << "Teste para ator:    " << (testa_ator()?"OK":"FALHOU") << endl;
    cout << "Teste para diretor: " << (testa_diretor()?"OK":"FALHOU") << endl;
#endif
    cout << "Teste para filme:   " << (testa_filme()?"OK":"FALHOU") << endl;
    return 0;
}

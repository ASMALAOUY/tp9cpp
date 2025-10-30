#include <iostream>
#include <string>
using namespace std;

class Personne {
protected:
    string nom;
    string prenom;

public:
    Personne(string n, string p) : nom(n), prenom(p) {}


    void afficher() const {
        cout << "Le nom est : " << nom << endl;
        cout << "Le prenom est : " << prenom << endl;
    }
};

class Chercheur {
protected:
    string domaineRecherche;

public:
    Chercheur(string domaine) : domaineRecherche(domaine) {}

    void afficher() const {
        cout << "Domaine de recherche : " << domaineRecherche << endl;
    }
};

class EnseignantChercheur : public Personne, public Chercheur {
public:
    EnseignantChercheur(string n, string p, string domaine)
        : Personne(n, p), Chercheur(domaine) {}

    void afficher() const {
        cout << "=== Informations Enseignant-Chercheur ===" << endl;
        Personne::afficher();
        Chercheur::afficher();
        cout << "=========================================" << endl;
    }
};

int main() {
    EnseignantChercheur ec("Laouy", "Asma", "Intelligence Artificielle");
    ec.afficher();

    return 0;
}

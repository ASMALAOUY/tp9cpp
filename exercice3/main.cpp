#include <iostream>
#include <string>
using namespace std;

class Vehicule {
protected:
    string marque;
    string modele;
public:
    Vehicule(string m = "", string mod = "") : marque(m), modele(mod) {}
    virtual void afficherCaracteristiques() const {
        cout << "Marque : " << marque << endl;
        cout << "Modèle : " << modele << endl;
    }
};

class Thermique : virtual public Vehicule {
protected:
    float consommation;
public:
    Thermique(string m = "", string mod = "", float c = 0.0)
        : Vehicule(m, mod), consommation(c) {}
    void afficherCaracteristiques() const override {
        Vehicule::afficherCaracteristiques();
        cout << "Consommation carburant : " << consommation << " L/100km" << endl;
    }
};

class Electrique : virtual public Vehicule {
protected:
    float autonomie;
public:
    Electrique(string m = "", string mod = "", float a = 0.0)
        : Vehicule(m, mod), autonomie(a) {}
    void afficherCaracteristiques() const override {
        Vehicule::afficherCaracteristiques();
        cout << "Autonomie batterie : " << autonomie << " km" << endl;
    }
};

class Hybride : public Thermique, public Electrique {
public:
    Hybride(string m, string mod, float c, float a)
        : Vehicule(m, mod), Thermique(m, mod, c), Electrique(m, mod, a) {}
    void afficherCaracteristiques() const override {
        cout << "=== Véhicule Hybride ===" << endl;
        Vehicule::afficherCaracteristiques();
        cout << "Consommation carburant : " << consommation << " L/100km" << endl;
        cout << "Autonomie batterie : " << autonomie << " km" << endl;
    }
};

int main() {
    Hybride h("Toyota", "Prius", 4.5, 50);
    h.afficherCaracteristiques();
    return 0;
}

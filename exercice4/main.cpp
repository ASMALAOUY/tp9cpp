#include <iostream>
#include <string>
using namespace std;

class Utilisateur {
protected:
    int id;
    string login;
public:
    Utilisateur(int i = 0, string l = "") : id(i), login(l) {}
    virtual void afficher() const {
        cout << "ID : " << id << endl;
        cout << "Login : " << login << endl;
    }
};

class Administrateur : virtual public Utilisateur {
protected:
    string droitsAcces;
public:
    Administrateur(int i = 0, string l = "", string d = "")
        : Utilisateur(i, l), droitsAcces(d) {}
    void gererSysteme() const {
        cout << login << " gère le système avec droits : " << droitsAcces << endl;
    }
    void afficher() const override {
        Utilisateur::afficher();
        cout << "Droits d'accès : " << droitsAcces << endl;
    }
};

class Moderateur : virtual public Utilisateur {
protected:
    int niveauModeration;
public:
    Moderateur(int i = 0, string l = "", int n = 0)
        : Utilisateur(i, l), niveauModeration(n) {}
    void modererContenu() const {
        cout << login << " modere le contenu avec niveau : " << niveauModeration << endl;
    }
    void afficher() const override {
        Utilisateur::afficher();
        cout << "Niveau de moderation : " << niveauModeration << endl;
    }
};

class SuperUtilisateur : public Administrateur, public Moderateur {
public:
    SuperUtilisateur(int i, string l, string d, int n)
        : Utilisateur(i, l), Administrateur(i, l, d), Moderateur(i, l, n) {}
    void afficher() const override {
        cout << "=== Super Utilisateur ===" << endl;
        Utilisateur::afficher();
        cout << "Droits d'acces : " << droitsAcces << endl;
        cout << "Niveau de moderation : " << niveauModeration << endl;
    }
    void actions() const {
        gererSysteme();
        modererContenu();
    }
};

int main() {
    int id, niveau;
    string login, droits;
    int choix;
    SuperUtilisateur* su = nullptr;

    do {
        cout << "\n=== Menu Système d'Utilisateurs ===" << endl;
        cout << "1. Creer un SuperUtilisateur" << endl;
        cout << "2. Afficher ses caracteristiques" << endl;
        cout << "3. Exécuter ses actions" << endl;
        cout << "0. Quitter" << endl;
        cout << "Choix : ";
        cin >> choix;
        cin.ignore();

        switch (choix) {
            case 1:
                cout << "ID : "; cin >> id; cin.ignore();
                cout << "Login : "; getline(cin, login);
                cout << "Droits d'acces : "; getline(cin, droits);
                cout << "Niveau de moderation : "; cin >> niveau;
                su = new SuperUtilisateur(id, login, droits, niveau);
                cout << "SuperUtilisateur cree avec succes." << endl;
                break;
            case 2:
                if (su) su->afficher();
                else cout << "Aucun SuperUtilisateur cree." << endl;
                break;
            case 3:
                if (su) su->actions();
                else cout << "Aucun SuperUtilisateur cree." << endl;
                break;
            case 0:
                cout << "Fin du programme." << endl;
                break;
            default:
                cout << "Choix invalide." << endl;
        }
    } while (choix != 0);

    delete su;
    return 0;
}

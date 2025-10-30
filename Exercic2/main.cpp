#include <iostream>
#include <string>
using namespace std;

class Technicien {
protected:
    double salaireTech;
public:
    Technicien(double s) : salaireTech(s) {}
    void afficherSalaire() const {
        cout << "Salaire du Technicien : " << salaireTech << " DH" << endl;
    }
};

class Comptable {
protected:
    double salaireComp;
public:
    Comptable(double s) : salaireComp(s) {}
    void afficherSalaire() const {
        cout << "Salaire du Comptable : " << salaireComp << " DH" << endl;
    }
};

class EmployePolyvalent : public Technicien, public Comptable {
public:
    EmployePolyvalent(double sTech, double sComp)
        : Technicien(sTech), Comptable(sComp) {}
    void afficherTousSalaires() const {
        Technicien::afficherSalaire();
        Comptable::afficherSalaire();
    }
};

int main() {
    EmployePolyvalent e1(5000.0, 7000.0);
    e1.afficherTousSalaires();
    return 0;
}

#ifndef PROJET4_H_INCLUDED
#define PROJET4_H_INCLUDED

#include<typeinfo>
#include<iostream>
#include"vector"
#include"string.h"
#include "fstream"

using namespace std;


class Produit
{
private:

    int num;
	string foodname;
	int quantity;
	float price;
 public:
     Produit();
     Produit(int,string,int,float);
     void affiche_produit();
     int get_num(){return num;};
     int get_quantity(){return quantity;};
     string get_foodname(){return foodname;};
     float get_price(){return price;};
     void set_food_name(string food){foodname=food;};
     void set_quantity(int quant){quantity=quant;};
     void set_price(float prix){price=prix;};
     void modif_quantity(int);
     ~Produit();
};

class Bakery_Item_List
{
private:
    vector<Produit*>tab1;
public:
    Bakery_Item_List();
    Produit get_produit(int i){return *tab1[i];};
    int get_size(){return tab1.size();};
    Bakery_Item_List(const  Bakery_Item_List&);
    void modif_list(Produit);
    int  recherche(int);
    void supprimer(int);
    void affiche_list();
    void ajout_produit(Produit );
    ~Bakery_Item_List();


};
class Fournisseur
{
private:
    string nom_fournisseur;
    string adresse_fournisseur;
    string nom_matiere_fournit;
public:
    Fournisseur();
    Fournisseur(string,string,string);
    void affiche_fournisseur();
    ~Fournisseur();
};

class Fournisseur_List
{
private:
    vector<Fournisseur*>tab2;
public:
    Fournisseur_List();
    Fournisseur_List(const Fournisseur_List& );
    void Ajout_Fournisseur(Fournisseur);
    void affiche_list();
    ~Fournisseur_List();
};

class Matiere
{
private:
    int id_matiere;
    string name;
    int quantity;
    float prix;
public:
    Matiere();
    Matiere(int,string,int,float);
    void affiche_matiere();
    ~Matiere();
};

class Matiere_List
{
private:
    vector<Matiere*>tab3;
public:
    Matiere_List();
    Matiere_List(const Matiere_List& );
    void Ajout_Matiere(Matiere);
    void affiche_list();
    ~Matiere_List();
};



class Order
{
private:
    string choice_name;
    int choice_quantity;
public:
    Order();
    Order(string ,int);
    void affiche();
    ~Order();
};

class Payement
{
private:
    float total;
    string methode;
public:
    Payement();
    Payement(float,string);
    void affiche();
    ~Payement();

};
class client
{
private:
    long cin_client;
    long Credit;

public:
    client();
    client(long,long);
    long get_cin_client(){return cin_client;};
    long get_Credit(){return Credit;};
    void affiche_client();
    void ouvrir( fstream& );
    void enregistrer( fstream&);
    void aff(fstream&);
    ~client();

};

class View_orders
{
private:
    vector <Order*>tab5;
public:
    View_orders();
    View_orders( const View_orders&);
    void remplir_ordre(Order);
    void affiche_list();
    ~View_orders();

};
class caisse
{
private:
    float revenus;
public:
    caisse();
    void Calcul_Total(float);
    void affiche_caisse();
    ~caisse();
};

class Personnel
{
protected:
    long cin_personel;
    string nom;
    string prenom;
    long numTele;
    float salaire;
public:
    Personnel();
    Personnel(long,string,string,long,float );
    virtual void affiche();
    virtual ~Personnel();
    friend ostream& operator<<( ostream& out,const Personnel& L);
    friend istream& operator>>( istream& in,Personnel& L);
};
class chef : public Personnel
{
private:
    string diplome;
public:
    chef();
    chef(long,string,string,long,float,string);
    ~chef();
    void affiche();
    friend ostream& operator<<( ostream& out,const chef& L);
    friend istream& operator>>( istream& in,chef& L);

};
class ouvrier : public Personnel
{
private:
   string service ;
public:
    ouvrier();
     ouvrier(long,string,string,long,float,string);
    ~ouvrier();
    void affiche();
    friend ostream& operator<<( ostream& out,const ouvrier& L);
    friend istream& operator>>( istream& in,ouvrier& L);

};







#endif // PROJET4_H_INCLUDED

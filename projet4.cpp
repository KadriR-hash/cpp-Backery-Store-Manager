#include<iostream>
#include<vector>
#include<string>
#include "fstream"
#include<typeinfo>
#include"projet4.h"

using namespace std;



 void Produit::modif_quantity(int c)
 {
     quantity=c;
 }

void Bakery_Item_List::modif_list(Produit p)
 {    int quant,no;
      string  food;
      float prix;

prix=p.get_price();
food=p.get_foodname();
quant=p.get_quantity();
no=p.get_num();

     for(int i=0;i<tab1.size();i++)
        {
        if(tab1[i]->get_num()==no)


            {
            tab1[i]->set_food_name(food);
            tab1[i]->set_quantity(quant);
            tab1[i]->set_price(prix);


            }

        }

 }


Produit::Produit(int num ,string foodname,int quantity,float price)
{
    this->num=num;
    this->foodname=foodname;
    this->quantity=quantity;
    this->price=price;

}
 void Produit:: affiche_produit()
 {
     cout<<"le num est:"<<num<<endl;
     cout<<"foodname est:"<<foodname<<endl;
     cout<<"quantity est:"<<quantity<<endl;
     cout<<"price est:"<<price<<endl;

 }
Produit::~Produit(){}


Bakery_Item_List:: Bakery_Item_List(const  Bakery_Item_List& w)
{
    Produit* P;
    for(unsigned int i=0;i<w.tab1.size();i++)
    {
        if(typeid(*w.tab1[i])==typeid(Produit))
        {
            P=new Produit();
            tab1.push_back(P);
        }
    }
}
void Bakery_Item_List::affiche_list()
{
    for(int i=1;i<tab1.size();i++)
        tab1[i]->affiche_produit();

}
void Bakery_Item_List::ajout_produit(Produit t )
{
    Produit* p=new Produit(t);
    tab1.push_back(p);
}


int Bakery_Item_List:: recherche(int x)
{
    int a=-1;
for (unsigned int i=0;i<tab1.size();i++)
{
    if(tab1[i]->get_num()==x)
    {
    return i;
    }
}
return a;
}


void Bakery_Item_List ::supprimer(int x)
{
if (recherche(x) !=-1)
tab1.erase(tab1.begin()+recherche(x)) ;
}

Bakery_Item_List::~Bakery_Item_List()
{
    for(int i=1;i<tab1.size();i++)
        delete tab1[i];

    tab1.clear();

}




Fournisseur::Fournisseur(string nom_fournisseur,string adresse_fournisseur ,string nom_matiere_fournit)
{
    this->nom_fournisseur=nom_fournisseur;
    this->adresse_fournisseur=adresse_fournisseur;
    this->nom_matiere_fournit=nom_matiere_fournit;

}
void Fournisseur::affiche_fournisseur()
{
    cout<<nom_fournisseur<<endl;
    cout<<adresse_fournisseur<<endl;
    cout<<nom_matiere_fournit<<endl;
}




Fournisseur_List::Fournisseur_List(const Fournisseur_List& F)
{
    Fournisseur* P;
    for(unsigned int i=0;i<F.tab2.size();i++)
    {
        if(typeid(*F.tab2[i])==typeid(Fournisseur))
        {
            P=new Fournisseur;
            tab2.push_back(P);
        }
    }
}

Fournisseur_List::~Fournisseur_List()
{
    for(unsigned int i=0;i<tab2.size();i++)
    {
        delete tab2[i];

    }
    tab2.clear();
}

void Fournisseur_List::Ajout_Fournisseur(Fournisseur F)
{
    Fournisseur* P= new Fournisseur(F);
    tab2.push_back(P);
}


void Fournisseur_List::affiche_list()
{
    for(int i=0;i<tab2.size();i++)
    {

      tab2[i]->affiche_fournisseur();
    }
}


Matiere::Matiere (int id_matiere,string name,int quantity ,float prix)
   {
       this->id_matiere=id_matiere;
       this->name=name;
       this->quantity=quantity;
       this->prix=prix;
   }
void Matiere::affiche_matiere()
{
    cout<<id_matiere<<endl;
    cout<<name<<endl;
    cout<<quantity<<endl;
    cout<<prix<<endl;
}

Matiere_List::Matiere_List(const Matiere_List& F)
{
    Matiere* P;
    for(unsigned int i=0;i<F.tab3.size();i++)
    {
        if(typeid(*F.tab3[i])==typeid(Matiere))
        {
            P=new Matiere;
            tab3.push_back(P);
        }
    }
}
Matiere_List::~Matiere_List()
{
    for(unsigned int i=0;i<tab3.size();i++)
    {
        delete tab3[i];

    }
    tab3.clear();
}

void Matiere_List::Ajout_Matiere(Matiere F)
{
    Matiere* P= new Matiere(F);
    tab3.push_back(P);
}

void Matiere_List::affiche_list()
{
    for(int i=0;i<tab3.size();i++)
    {
      tab3[i]->affiche_matiere();
    }
}



Personnel::Personnel(long cin_personel,string nom,string prenom,long numTele,float salaire )
{
    this->cin_personel=cin_personel;
    this->nom=nom;
    this->prenom=prenom;
    this->numTele=numTele;
    this->salaire=salaire;
}
chef::chef(long c,string ch,string sh,long num,float s,string d):Personnel(c,ch,sh,num,s)
{
    diplome=d;
}

ouvrier::ouvrier(long c,string ch,string sh,long num ,float s,string d):Personnel(c,ch,sh,num,s)
{
    service=d;
}

void chef::affiche()
{
    Personnel::affiche();
    cout<<diplome<<endl;
}
void ouvrier::affiche()
{
    Personnel::affiche();
    cout<<service<<endl;
}

ostream& operator<<( ostream& out,const Personnel& L)
{
out<<L.cin_personel<<endl;
out<<L.nom<<endl;
out<<L.prenom<<endl;
out<<L.numTele<<endl;
out<<L.salaire<<endl;
return out;
}

istream& operator>>( istream& in,Personnel& L)
{
cout<<" CIN  :"<<endl;
in>>L.cin_personel;
cout<<"NOM   :"<<endl;
in>>L.nom ;
cout<<"PRENOM :"<<endl;
in>>L.prenom;
cout<<"TELEPHONE  :"<<endl;
in>>L.numTele;
cout<<"SALAIRE  :"<<endl;
in>>L.salaire;
return in;
}

ostream& operator<<( ostream& out,const chef& L)
{
const Personnel *C = &L ;
out<<* C;

out<<L.cin_personel<<endl;
out<<L.nom<<endl;
out<<L.prenom<<endl;
out<<L.numTele<<endl;
out<<L.salaire<<endl;
out<<L.diplome<<endl;

return out;
}

istream& operator>>( istream& in,chef & L)
{
Personnel * C = &L ;
in>> *C;
cout<<" CIN  :"<<endl;
in>>L.cin_personel;
cout<<"NOM   :"<<endl;
in>>L.nom ;
cout<<"PRENOM :"<<endl;
in>>L.prenom;
cout<<"TELEPHONE  :"<<endl;
in>>L.numTele;
cout<<"SALAIRE  :"<<endl;
in>>L.salaire;
cout<<"DIPLOME  :"<<endl;
in>>L.diplome;

return in;
}

ostream& operator<<( ostream& out, const ouvrier& L)
{
const Personnel * C = &L ;
out<<* C;

out<<L.cin_personel<<endl;
out<<L.nom<<endl;
out<<L.prenom<<endl;
out<<L.numTele<<endl;
out<<L.salaire<<endl;
out<<L.service<<endl;

return out;
}

istream& operator>>( istream& in,ouvrier & L)
{
Personnel * C = &L ;
in>> *C;
cout<<" CIN  :"<<endl;
in>>L.cin_personel;
cout<<"NOM   :"<<endl;
in>>L.nom ;
cout<<"PRENOM :"<<endl;
in>>L.prenom;
cout<<"TELEPHONE  :"<<endl;
in>>L.numTele;
cout<<"SALAIRE  :"<<endl;
in>>L.salaire;
cout<<"SERVIVE  :"<<endl;
in>>L.service;

return in;
}



Order::Order (string choice_name ,int choice_quantity)
{
    this->choice_name=choice_name;
    this->choice_quantity=choice_quantity;

}
 void Order:: affiche()
 {
     cout<<"\n choice_name est:"<<choice_name<<endl;
     cout<<"\n choice_quantity est:"<<choice_quantity<<endl;

 }

  Payement::Payement(float total ,string methode)
  {
      this->total=total;
      this->methode= methode;
  }
  void caisse::Calcul_Total(float t)
  {
      revenus+=t;
  }

  void caisse::affiche_caisse()
  {
      cout<<revenus<<endl;
  }
   void Payement:: affiche()
   {
       cout<<"\n total est:"<<total<<endl;
       cout<<"\n methode est:"<<methode<<endl;
   }

   client ::client (long cin_client,long Credit )
   {
       this->cin_client=cin_client;
       this->Credit=Credit;

   }

    void client::affiche_client()
    {
        cout<<"\n cin_client:"<<cin_client<<endl;
        cout<<"\n credit:"<<Credit<<endl;

    }

    void  View_orders ::remplir_ordre(Order o1)
    {
           Order* o=new Order(o1);
           tab5.push_back(o);


    }

   void View_orders::affiche_list()
   {
    for(int i=0;i<tab5.size();i++)
    {
      tab5[i]->affiche();
    }

   }

View_orders::~View_orders()
{
    for(unsigned int i=0;i<tab5.size();i++)
    {
        delete tab5[i];

    }
    tab5.clear();
}

chef::~chef(){}

void Personnel :: affiche()
{
     cout<<cin_personel<<endl;
     cout<< nom <<endl;
     cout<<prenom<<endl;
     cout<<numTele <<endl;
     cout<<salaire<<endl;
}

caisse::caisse(){revenus=0;}

void client::ouvrir( fstream& f)
{
f.open("F:\\client.txt", ios::in|ios::out|ios::trunc);
if (!f.is_open())
      cout<<" ERROR ! "<<endl;
else
      cout<<"SUCCESS !"<<endl;

}

void client:: enregistrer( fstream& f)
{

long a,b;
a=get_cin_client();
b=get_Credit();
f<<a<<"  :  "<<b<<endl;
cout<<"ADD SUCCESS..."<<endl;


}

void client::aff(fstream& f)
{

char ch[100];
f.seekg(0);
while(f.getline(ch,100))
   {cout<<" Affichage   :"<<endl;
    cout<<ch<<endl;
   }
f.close();
}

Produit::Produit(){}
Bakery_Item_List::Bakery_Item_List(){}
Fournisseur::Fournisseur(){}
Fournisseur::~Fournisseur(){}
Fournisseur_List::Fournisseur_List(){}
Matiere::Matiere(){}
Matiere::~Matiere(){}
Matiere_List:: Matiere_List(){}
Order::Order(){}
Order::~Order(){}
Payement::Payement(){}
Payement::~Payement(){}
client::client(){}
client::~client(){}
View_orders:: View_orders(){}
caisse::~caisse(){}
Personnel::Personnel(){}
Personnel::~Personnel(){}
chef::chef(){}
ouvrier::ouvrier(){}
ouvrier::~ouvrier(){}






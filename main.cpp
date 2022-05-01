#include <iostream>
#include"string.h"
#include "fstream"
#include"projet4.h"



using namespace std;

int main()
{   int any;
    caisse C;
    chef ch1;
    ouvrier ou1;
    View_orders V;

    Bakery_Item_List list;
    Fournisseur_List list2;
    Matiere_List list3;


    Produit p1(5,"Birthday Cakes",23,120.23);
    list.ajout_produit(p1);
    Produit p2(6,"Pancakes",13,10.50);
    list.ajout_produit(p2);
    Produit p3(1,"Cookies",8,70);
    list.ajout_produit(p3);
	Produit p4(2,"Coffee  ",46,5);
	list.ajout_produit(p4);
	Produit p5(3,"Brownies   ",46,2.7);
	list.ajout_produit(p5);
	Produit p6(4,"Hot Pudding  ",34,20);
	list.ajout_produit(p6);
	Produit p7(7,"Chocolate Ice cream",7,20);
	list.ajout_produit(p7);
	Produit p8(8,"Grain Breads",121,35.5);
	list.ajout_produit(p8);
	Produit p9(9,"Cold drinks",73,4);
	list.ajout_produit(p9);

	Fournisseur f1("Warda","Avenue Hédi Nouira Sousse","Pastry Flour");
    list2.Ajout_Fournisseur(f1);
	Fournisseur f2("Jaouhara","Voie Z4 Saint Gobain 1009 Tunis","Leaveners" );
	list2.Ajout_Fournisseur(f2);
	Fournisseur f3("tunisie sucre"," Parc d’activités économiques, 7000 BIZERTE"," Sugar");
	list2.Ajout_Fournisseur(f3);
	Fournisseur f4("delice","Immeuble JOUMANA La Goulette (10,05 km) 2015 Tunis","Dairy");
	list2.Ajout_Fournisseur(f4);
	Fournisseur f5("CSM-Gias","Tunisie 8040,Z,I Bouargoub","Flavorings");
	list2.Ajout_Fournisseur(f5);


	Matiere m1(1,"Pastry Flour",70,2.5);
	list3.Ajout_Matiere(m1);
	Matiere m2(2,"Leaveners",35,4);
	list3.Ajout_Matiere(m2);
	Matiere m3(3," Sugar",50,1.7);
	list3.Ajout_Matiere(m3);
	Matiere m4(4,"Dairy",50,1);
	list3.Ajout_Matiere(m4);
	Matiere m5(5,"Flavorings",3,150);
	list3.Ajout_Matiere(m5);

    mainmenu:

    cout<<1<<"-"<<"Item List"<<endl;
    cout<<2<<"-"<<"Admin Panel"<<endl;
    cout<<3<<"-"<<"Exit"<<endl;

    int main_menu_choice;

    cout<<" \n enter your choice  :\n "<<endl;
    cin>>main_menu_choice;
    if((main_menu_choice >=1 && main_menu_choice <=3)){

		if(main_menu_choice == 1)
            {

			foodlist:
            cout<<" 0-Main Menu "<<endl;
			list.affiche_list();
			}

		else if( main_menu_choice == 2){

			adminpanelchoice:

			int admin_panel_choice;

			cout<<"1. Main Menu\n\n\t"<<endl;
			cout<<"Please Enter Password or ( 1 to Back in Main Menu ) : "<<endl;
            cin>>admin_panel_choice;
            if(admin_panel_choice==0000)

            {
                adminchoise:

                cout<<">>>> Admin Panel <<<<   \n\n"<<endl;
				cout<<(" 1. Total Cash  \n\n")<<endl;
				cout<<(" 2. order reviews \n\n")<<endl;
				cout<<(" 3. Add Bakery Item \n\n")<<endl;
				cout<<(" 4. Delete Item \n\n")<<endl;
				cout<<(" 5. Item List \n\n")<<endl;
				cout<<(" 6. provider list  \n\n")<<endl;
				cout<<(" 7. material list \n\n")<<endl;
				cout<<(" 8. staff list  \n\n")<<endl;
				cout<<(" 0. Main Menu \n\n")<<endl;


                int adminchoise;
				cout<<"  Enter your choice  :"<<endl;
                cin>>adminchoise;

				if(adminchoise==1){

					cout<<"Todays Total Cash : "<<endl;
					C.affiche_caisse();
					cout<<" Press Any Number To Go Back  : "<<endl;
                    cin>>any;

                goto adminchoise;
				}

                else if(adminchoise==2){
                   V.affiche_list();
                   cout<<" Press Any Number To Go Back  : "<<endl;
                   cin>>any;
                   goto adminchoise;
				}


				else if(adminchoise==3){



                          int num,quantity;
                          string foodname;
                          float price;

					      cout<<" Enter Bakery Item Number :  "<<endl;
					      cin>>num;

					      cout<<"Enter Bakery Item Name : "<<endl;
					      cin>>foodname;

                    fquantity:
					      cout<<"Enter Bakery Item Quantity : "<<endl;
					      cin>>quantity;
					      if(quantity==0)
                            goto fquantity;

                    fprice:
					      cout<<"Enter Bakery Item Price  :  "<<endl;
					      cin>>price;
					      if(price==0)
                            goto fprice;

					      Produit pp(num ,foodname,quantity,price);

					      list.ajout_produit(pp);
					      cout<<"Adding Item  Successfull......."<<endl;

					goto adminchoise;

				}
				else if(adminchoise==4){


					cout<<"Enter No of the Item To Delete : "<<endl;


					int fdelete;
					cin>>fdelete;

					list.supprimer(fdelete);




					goto adminchoise;
				}

				else if(adminchoise==5){

                   list.affiche_list();
                   cout<<" Press Any Number To Go Back  : "<<endl;
                   cin>>any;

					goto adminchoise;

				   }

				else if(adminchoise==6){

                   list2.affiche_list();
                   cout<<" Press Any Number To Go Back  : "<<endl;
                   cin>>any;
                   goto adminchoise;

					}

				else if(adminchoise==7){

                   list3.affiche_list();
                   cout<<" Press Any Number To Go Back  : "<<endl;
                   cin>>any;
                   goto adminchoise;

				}
				else if(adminchoise==8){

                     cout<<" Enter staff members  :"<<endl;

					 cin>>ch1;
					 cin>>ou1;

					 cout<<"Staff list  :"<<endl;
					 cout<<ch1<<endl;
					 cout<<ou1<<endl;

                   cout<<" Press Any Number To Go Back  : "<<endl;
                   cin>>any;
                   goto adminchoise;


				}

				else if(adminchoise==0){

					goto mainmenu;
				}

				else{
					cout<<"Please Select From List :  "<<endl;
					goto adminchoise;
				}



			}

			else if(admin_panel_choice==1){
				goto mainmenu;
			}
			else{
				cout<<"Please Enter Correct Choice :"<<endl;
				goto adminpanelchoice;
			}

		}
			else if(main_menu_choice==3){

            cout<<"Thank You For Using Our System"<<endl;
			exit(1);
			}

	        else{
		cout<<"Please Enter Correct Choice :"<<endl;
		goto mainmenu;


            }


    int get_food_choice;
    int fcquantity;

	cout<<"Place Your Order : "<<endl;
	cin>>get_food_choice;
    if (get_food_choice==0)
        goto mainmenu;


    cout<<"Enter Item Quantity : "<<endl;

    cin>>fcquantity;

    int w;
    string u;
    float z;

    for(int i=0;i<list.get_size();i++)
    {
        if(list.get_produit(i).get_num()==get_food_choice)
        {
            w=list.get_produit(i).get_quantity();
            u=list.get_produit(i).get_foodname();
            z=list.get_produit(i).get_price();

        }

    }

    if(fcquantity==0){
            cout<<"Quantity Can not be Zero "<<endl;

			goto foodlist;
		}
    else if(fcquantity>  w  ){
			cout<<"Out of Stock ! "<<endl;

			goto foodlist;
		}

    Order o1(u,fcquantity);// IMPORTANT
    cout<<"ordre:"<<endl;
    o1.affiche();

    V.remplir_ordre(o1);






    cout<<"Choice item :"<< u <<" its price is :" << z <<endl;
    cout<<"1. Confirm to buy this "<<endl;
    cout<<"2. Item List "<<endl;
    cout<<"Press 1 to confirm and 2 to back to list :"<<endl;

		confirm:
		int confirm;

		cin>>confirm;
		if(confirm == 1 )
            {


			cout<<" 1. Cash "<<endl;
            cout<<" 2. Credit"<<endl;
            cout<<"Select Method Of payment 1-2: "<<endl;


			int payment,uquantity;;

			cin>>payment;
            if(payment==1)
                {

                float totalmoney=0;

				totalmoney += z*fcquantity;
                Payement pa1( totalmoney ,"Cash");// IMPORTANT

                C.Calcul_Total(totalmoney);

				uquantity = w - fcquantity;

                Produit prod;
                for(int i=0;i<list.get_size();i++)
                {

                    if(list.get_produit(i).get_num()==get_food_choice)
                        {
                        prod=list.get_produit(i);

                        }

                }

                prod.modif_quantity(uquantity);

                list.modif_list(prod);
                pa1.affiche();

                cout<<" THANK YOU "<<endl;
                cout<<"Item Ordered Successfully ..."<<endl;
                cout<<"1. Wanna Buy Another Delicious ? "<<endl;
                cout<<"2. Main Menu "<<endl;
                cout<<"Select: "<<endl;

				psmenu:
				int ps_menu;

				cin>>ps_menu;

				if(ps_menu==1){goto foodlist;}
				else if(ps_menu==2){goto mainmenu;}
				else{cout<<"Please Choice from list : "<<endl; goto psmenu;}


			   }

            else if(payment==2){

				string card_number,CIN ;

                back1:

				cout<<"Enter CIN  : "<<endl;
				cin>>CIN;
				try
				{
				    if( CIN.size()!=8 )throw -1;
				    cout<<" CIN valid ! "<<endl;
				}
				catch(int e)
				{
				     cout<<" CIN must be composed of 8 numbers !"<<endl;
				     goto back1;

				}

                back2:

                cout<<"Enter Your Card No   : "<<endl;
                cin>>card_number;

                try
				{
				    if( card_number.size()!=6) throw -1;
				    cout<<" Card valid ! "<<endl;
				}
				catch(int e)
				{
				     cout<<" Card must be composed of 6 numbers !"<<endl;
				     goto back2;
				}





                client c1(std::stoi(CIN),std::stoi(card_number));

                fstream f;
                c1.ouvrir(f);
                c1.enregistrer(f);
                c1.aff(f);


                float totalmoney=0;
				totalmoney += z*fcquantity;
                Payement pa1( totalmoney ,"Credit");

                C.Calcul_Total(totalmoney);

				uquantity = w - fcquantity;

				list.get_produit(get_food_choice).modif_quantity(uquantity);

                pa1.affiche();



				cout<<"Payment Success..."<<endl;
				cout<<"Thank you for using our system !"<<endl;
				exit(1);



			 }

			else{

				cout<<"Enter Choice from List : "<<endl;

				goto foodlist;


			}



			}
        else if(confirm == 2){

			goto foodlist;

		}

		else{
			    cout<<"Enter Choice from List : "<<endl;

			goto confirm;


		}




    }

   return 0;
}







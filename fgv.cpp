
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "elofizetes.hpp"
#include "elofizetestar.hpp"
#include "fgv.h"
/**Menü függvény.
*Visszatérés, és paraméter nélküli.
*A menü függvények első példánya, a többit ez a függvény fogja hívni.*/
void menu()
{
	std::cout << "Udv a Telener rendszereben" << std::endl << "Mit szeretnel csinalni?" << std::endl;
	std::cout << "1) Beolvasni" << std::endl << "0) Kilepni" << std::endl;
	std::cout << "Kerem Valasszon: " << std::endl;
	int a;
	while (std::cin >> a && a != 0)
	{
		switch (a)
		{
		case 1: menu1(); return;
		}
	}

}

/**Menu1 függvény.
*Visszatérés, és paraméter nélküli.*/
void menu1()
{

	elofizetestar t1(1);
	t1.olvas();
	std::cout <<"\n \n \n"<< "---------------------------------------------------" << std::endl;
	std::cout << "Kerem valasszon!" << std::endl;
	std::cout << std::endl << "1) ugyfelet keresek telefonszam alapjan" << std::endl;
	std::cout << "2)Kiirom  az ugyfelek szamlait" << std::endl;
	std::cout << "0) Kilepek" << std::endl;
	std::cout << "---------------------------------------------------" << std::endl;
	int a;
	while (std::cin >> a && a != 0)
	{
		switch (a)
		{
		case 1: 
		{
			std::cout << "Kerem adja meg a telefonszamot" << std::endl;
			std::string tel; std::cin >> tel;
			elofizetes* k= t1.keres(tel); 
			menu2(k);
			break;
		}
		case 2: t1.mindki(); std::cout << std::endl; break;

		default: std::cout << "Hibas valasz" << std::endl;
			break;
		}
		std::cout << "\n\n\n---------------------------------------------------" << std::endl;
		std::cout << "Kerem valasszon!" << std::endl;
		std::cout << std::endl << "1) ugyfelet keresek telefonszam alapjan" << std::endl;
		std::cout << "2)Kiirom  az ugyfelek szamlait" << std::endl;
		std::cout << "0) Kilepek" << std::endl;
		std::cout << "---------------------------------------------------" << std::endl;
	}
}
/**Menu2 függvény.
*Visszatérés nélküli.
@param előfizetés *
*/
void menu2(elofizetes* e)
{
	if (e == NULL)
	{
		std::cout << std::endl << "\n---------------------------------------------------" << std::endl;
		std::cout << "Nincs ilyen talalat" << std::endl;
		std::cout << "---------------------------------------------------" << std::endl;
		return;
	}
	else
	{
		e->kiir();
		std::cout << "\n\n\n---------------------------------------------------" << std::endl;
		std::cout << " Kerem valasszon" << std::endl;
		std::cout << "Meg szeretnem nezni masik tarifacsomaggal:" << std::endl;
		std::cout << "1)alap tarifaval \n2)sms tarifaval \n3) net tarifaval" << std::endl;
		std::cout << "0) Kilepek" << std::endl;
		std::cout << "---------------------------------------------------" << std::endl;
		int a;
		while (std::cin >> a && a != 0)
		{
			switch (a)
			{
			case 1:
			{
				elofizetes temp = (*e);
				temp.get_t().s_dij(6000);
				temp.get_t().s_perc(100);
				temp.get_t().s_sms(50);
				temp.get_t().s_net(1000);
				temp.get_t().s_percdij(50);
				temp.get_t().s_smsdij(50);
				temp.get_t().s_netdij(4);
				temp.kiir();
				break;

				//alap: 6000, 100perc,  50 sms, 1000mb net, utána 50ft/perc 50/sms 4ft/MB

			}
			case 2:
			{
				elofizetes temp = *e;
				temp.get_t().s_dij(4500);
				temp.get_t().s_perc(45);
				temp.get_t().s_sms(100);
				temp.get_t().s_net(0);
				temp.get_t().s_percdij(55);
				temp.get_t().s_smsdij(30);
				temp.get_t().s_netdij(6);
				temp.kiir();
				break;
				//sms:4500Ft, 45 perc, 100 sms, 0mb, utána,  55/perc 30/sms 6/MB
			}
			case 3:
			{
				elofizetes temp = *e;
				temp.get_t().s_dij(6000);
				temp.get_t().s_perc(0);
				temp.get_t().s_sms(0);
				temp.get_t().s_net(0);
				temp.get_t().s_percdij(55);
				temp.get_t().s_smsdij(55);
				temp.get_t().s_netdij(0);
				temp.kiir();
				break;
			}
			//net 6000  0 perc, 0 sms,korlátlan net, utána 55/perc 55/sms	0mb/ft
			default:
			{
				std::cout << "Hibas valasz" << std::endl;
				break;
			}
			
			}
			std::cout <<"\n\n\n---------------------------------------------------" << std::endl;
			std::cout << " Kerem valasszon" << std::endl;
			std::cout << "Meg szeretnem nezni masik tarifacsomaggal:" << std::endl;
			std::cout << "1)alap tarifaval \n2)sms tarifaval \n3) net tarifaval" << std::endl;
			std::cout << "0) Kilepek" << std::endl;
			std::cout << "---------------------------------------------------" << std::endl;
		}
	}
}
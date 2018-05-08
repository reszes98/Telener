#ifndef ELOFIZETES_HPP
#define ELOFIZETES_HPP


#include "tarifa.hpp"
#include"ugyfel.hpp"

class elofizetes :public tarifa, public ugyfel {
public:
	elofizetes() {}
	elofizetes(const ugyfel u,const tarifa t):ugyfel(u), tarifa( t){}
	~elofizetes() {}
	int sum()
	{
		int sum = g_dij();
		if (g_felhperc() > g_perc())
			sum += (g_felhperc() - g_perc())*g_percdij();
		if (g_felhsms() > g_sms())
			sum += (g_felhsms() - g_sms())*g_smsdij();
		if (g_felhnet() > g_net())
			sum += (g_felhnet() - g_net())*g_netdij();
		return sum;

	}
	void kiir() //pointerrel megadott ugyfel adatait irja ki a standard bemenetre
	{
		std::cout<<std::endl<<"---------------------------------------------------" << std::endl;
		std::cout << "nev: " << g_nev() << std::endl;
		std::cout << "tel: " << g_tel() << std::endl;
		std::cout << "cim: " << g_cim() << std::endl;
		std::cout << "alapdij: " << g_dij() << std::endl;
		std::cout << "felhasznalt percek/ingyenes: " << g_felhperc() << "/" << g_perc() << std::endl;
		std::cout << "felhasznalt smsek/ingyenes: " << g_felhsms() << "/" << g_sms() << std::endl;
		std::cout << "felhasznalt MB-ok/ingyenes: " << g_felhnet() << "/" << g_net() << std::endl;
		std::cout << "Szamla osszege: " << sum() << "Ft" << std::endl;
		std::cout << "---------------------------------------------------" << std::endl;
	}
};

#endif // !ELOFIZETES_HPP


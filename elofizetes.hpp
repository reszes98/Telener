#ifndef ELOFIZETES_HPP
#define ELOFIZETES_HPP


#include "tarifa.hpp"
#include"ugyfel.hpp"
/**
@class elofizetes, a tarifa és ügyfél osztályok örökléséből jött létre. Itt rendszerezzük az adatokat.
*/
// tagváltozóként
class elofizetes  {
	ugyfel u;
	tarifa t;
public:
	
	/**
	*Konstruktor.
	@param ugyfél osztály
	@param tarifa osztály
	*/
	elofizetes(const ugyfel u,const tarifa t):u(u), t(t){}
	
	/**Destruktor.
	*Szabvány paraméter nélküli Destruktor
	*/
	~elofizetes() {}

	ugyfel& get_u() { return u; }

	tarifa& get_t() { return t; }
	/**sum függvény.
	*int visszatérésű, nincs paramétere.
	*Összeszámolja a számla végösszegét.
	@return Számla végösszege.
	*/
	int sum()
	{
		int sum = t.g_dij();
		if (u.g_felhperc() > t.g_perc())
			sum += (u.g_felhperc() - t.g_perc())*t.g_percdij();
		if (u.g_felhsms() > t.g_sms())
			sum += (u.g_felhsms() - t.g_sms())*t.g_smsdij();
		if (u.g_felhnet() > t.g_net())
			sum += (u.g_felhnet() - t.g_net())*t.g_netdij();
		return sum;

	}
	/**kiir függvény.
	* visszatérés nélküli, nincs paramétere.
	* Kiírja az ügyfél adatait a konzolra.
	*/
	void kiir() 
	{
		std::cout<<std::endl<<"---------------------------------------------------" << std::endl;
		std::cout << "nev: " << u.g_nev() << std::endl;
		std::cout << "tel: " << u.g_tel() << std::endl;
		std::cout << "cim: " << u.g_cim() << std::endl;
		std::cout << "alapdij: " << t.g_dij() << std::endl;
		std::cout << "felhasznalt percek/ingyenes: " << u.g_felhperc() << "/" << t.g_perc() << std::endl;
		std::cout << "felhasznalt smsek/ingyenes: " << u.g_felhsms() << "/" << t.g_sms() << std::endl;
		std::cout << "felhasznalt MB-ok/ingyenes: " << u.g_felhnet() << "/" <<t.g_net() << std::endl;
		std::cout << "Szamla osszege: " << sum() << "Ft" << std::endl;
		std::cout << "---------------------------------------------------" << std::endl;
	}
};

#endif // !ELOFIZETES_HPP


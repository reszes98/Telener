#ifndef ELOFIZETES_HPP
#define ELOFIZETES_HPP


#include "tarifa.hpp"
#include"ugyfel.hpp"
/**
*Az ügyfél és a tarifa adatokat csoportosítjuk.
*/
class elofizetes  {
	
	ugyfel u;///<Ügyfél adatai.
	tarifa t;///<Tarifa adatai.
public:
	
	/**
	*Konstruktor. Paraméterrel hívható csak.
	*/
	elofizetes(const ugyfel u,const tarifa t):u(u), t(t){}
	
	/**Destruktor.
	*Szabvány paraméter nélküli Destruktor
	*/
	~elofizetes() {}
	/**@brief  Ügyfél adatait hívja elő.
	*@return ugyfel&.
	*/
	ugyfel& get_u() { return u; }

	/**@brief Paraméter nélküli, tarifa adatait hívja elő.
	@return tarifa&*/
	tarifa& get_t() { return t; }
	/**
	*@brief Összeszámolja a számla végösszegét.
	@return Számla végösszege, int típusban.
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
	/**
	* @brief visszatérés nélküli, nincs paramétere.
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


﻿#ifndef ELOFIZETESTAR
#define ELOFIZETESTAR
#include <string>
#include "elofizetes.hpp"
#include <iostream>
#include <fstream>

/**
@class elofizetestar, az előfizetéseket tárolja egy fix méretű tömbbe pointerelve.
*/
class elofizetestar : public elofizetes {
	/**Privát változó. tar változó méretét tároljuk benne*/
	size_t meret;

	/**Privát változó. Ebben tároljuk az előfizetéseket pointer formájában, fix méretű.*/
	elofizetes* tar[100];

	/**Privát változó. Az aktuálisan felhasznált méretet tároljuk.*/
	size_t elem;

	/**Másoló konstruktor. TILTVA, a tömb miatt nem lehetséges implicit másolása.*/
	elofizetestar(const elofizetestar&);
public:
	/**Default konstruktor. Adattag nélkül hívható, az adatokat később töltjük bele.*/
	elofizetestar() { elem = 0; meret = 100;}

	/**size függvény.
	*size_t  visszatérésű függvény, nincs paramétere.
		@return aktuálisan felhasznált méret.*/
	size_t size() { return elem; }

	/**capacity függvény
	*size_t  visszatérésű, nincs paramétere.
	@return tároló mérete.*/
	size_t capacity() { return meret; }

	/**operátor[] átdefiniálás. Tömb címzése kivülről*/
	elofizetes* operator[](unsigned int idx)
	{ 
		if (idx > meret)
			throw("rossz index");
		else 
			return tar[idx]; 
	}
	/**add függvény.
	Visszatérés nélküli.
	@param elofizetes*
	* a tömbhöz hozzáadd elofizetes elemet, amennyiben van hely, ha nincs jelez.*/
	void add(elofizetes* p) 
	{
		if (elem < meret)
		{
			tar[elem] = p; elem += 1;
		}
		else { delete p; throw("Nincs eleg hely"); }
	}
	~elofizetestar() { for (size_t i = 0; i < elem; i++) if(tar[i]!=NULL)delete tar[i];}


		
		
	/** olvas függvény.
	*  visszatérés nélküli függvény.
	* fájlból olvas adatokat be, az add függvény segítségével egyből hozzá is adja a tömbhöz.*/
	void olvas()//filebol olvassa be az ugyfeleket
	{
		std::ifstream file("ugyfel.txt");
		std::string dij, nev, cim, line, tel;
		unsigned int felh_perc, felh_sms, felh_net;
		if (file.is_open())
		{
			while (std::getline(file, line))
			{
				size_t i;
				
				int k[6] = { 0 }, l = 0;
				//char* a = line.c_str;
				for (i=0; i < line.size(); i++)
				{
					if (line[i] == ' ')
						k[l++] = i;
				}

				dij = line.substr(0, k[0]);
				tel = line.substr(k[0]+1, k[1] -k[0]-1);
				nev = line.substr(k[1]+1, k[2] - k[1]-1);
				cim = line.substr(k[2]+1, k[3] - k[2]-1);
				std::string felh = line.substr(k[3], k[4] - k[3]);
				sscanf(felh.c_str(), "%d", &felh_perc);
				felh = line.substr(k[4], k[5] - k[4]);
				sscanf(felh.c_str(), "%d", &felh_sms);
				felh = line.substr(k[5], k[6] - k[5]);
				sscanf(felh.c_str(), "%d", &felh_net);
				
				
				ugyfel u(tel, nev, cim, felh_perc, felh_sms, felh_net);
				int err = 0;
				if (dij == "sms")
				{
					//sms:4500Ft, 45 perc, 100 sms, 0mb, utána,  55/perc 30/sms 6/MB
					tarifa t(4500, 45, 100, 0, 55, 30, 6);
					add(new elofizetes(u, t));

				}
				else err++;
				if (dij == "alap")
				{
					//alap: 6000, 100perc,  50 sms, 1000mb net, utána 50ft/perc 50/sms 4ft/MB
					tarifa t(6000, 100, 50, 1000, 50, 50, 4);
					add(new elofizetes(u, t));
				}
				else err++;
				if (dij == "net")
				{
					//net 6000  0 perc, 0 sms,korlátlan net, utána 55/perc 55/sms	0mb/ft
					tarifa t(6000, 0, 0, 0, 55, 55, 0);
					add(new elofizetes(u, t));
				}
				else err++;
				if (err == 3)throw ("rossz dijcsomag");

			}
		}
		else { throw("nem talalja a fajlt"); }
		file.close();

	}

	/**keres függvény.
	@param string
	@return elofizetes*
	*a stringként kapott telefonszámot kikeresi a számlák közül, és kiírja, ha talált ilyet.
	*/
	elofizetes* keres(std::string keresett)// a lancolt listaban keres telefonszam alapjan
	{
		
		for (size_t i = 0; i < elem; i++)
		{
			if (!keresett.compare(tar[i]->g_tel()))
			{
				
				return tar[i];
			}
		}
		return NULL;
	}

	/**mindki függvény.
	*Az összes a tárban lévő ügyfelet kiírja a konzolra.*/
	void mindki()
	{
		for (size_t i = 0; i < elem; i++)
			tar[i]->kiir();
	}
};


	
	
#endif // !ELOFIZETESTAR


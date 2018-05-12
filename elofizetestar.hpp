#ifndef ELOFIZETESTAR
#define ELOFIZETESTAR
#include <string>
#include "elofizetes.hpp"
#include <iostream>
#include <fstream>

/**
* Az előfizetéseket tárolja egy dinamikus méretű tömbbe pointerelve.
*/
class elofizetestar{
	/**Privát változó. tar változó méretét tároljuk benne*/
	size_t meret;
	//ne legyen fix méretű , dinamikus
	/**Privát változó. Ebben tároljuk az előfizetéseket pointer formájában, fix méretű.*/
	elofizetes** tar;

	/**Privát változó. Az aktuálisan felhasznált méretet tároljuk.*/
	size_t elem;

	/**Másoló konstruktor. TILTVA, a tömb miatt nem lehetséges implicit másolása.*/
	elofizetestar(const elofizetestar&);
public:
	/**@brief Konstruktor. Adattag nélkül hívható, az adatokat később töltjük bele.*/
	elofizetestar(size_t meret) :meret(meret) { elem = 0; tar = new elofizetes*[meret]; }

	/**
	*@brief meghatározza a következő elem helyét a tárolóban.
	*@return aktuálisan felhasznált méret, size_t formátumban.*/
	size_t size() { return elem; }

	/**
	*@brief meghatározza a tároló aktuális méretét.
	*@return tároló mérete, size_t formátumban.*/
	size_t capacity() { return meret; }

	/**@brief operátor[] átdefiniálás. Tömb címzése kivülről
	*Ellenőrzi a helyes indexelést.*/
	elofizetes* operator[](unsigned int idx)
	{ 
		if (idx > meret || idx<0)
			throw("rossz index");
		else 
			return tar[idx]; 
	}
	/**
	* @brief a tömbhöz hozzáadd elofizetes elemet, amennyiben van hely, ha nincs növeli a tároló nagyságát.*/
	void add(elofizetes *p) 
	{
		if (elem < meret)
		{
			tar[elem++] = p; 
		}
		else 
		{ 
			elofizetes**temp = new elofizetes*[2 * meret];
			
			for(unsigned int i=0; i<meret;i++)
				temp[i] = tar[i];
			delete[] tar;
			meret = 2 * meret;
			tar = temp;
			tar[elem++] = p;

		}
	}
	~elofizetestar() {
		for (size_t i = 0; i < elem; i++)
			delete tar[i]; 
		delete[] tar;
	}


		
		
	/** 
	*  @brief visszatérés nélküli függvény, ájlból olvas adatokat be, az add függvény segítségével egyből hozzá is adja a tömbhöz.*/
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

	/**
	*@brief a stringként kapott telefonszámot kikeresi a számlák közül, és kiírja, ha talált ilyet.
	*@return elofizetes*
	*/
	elofizetes* keres(std::string keresett)// a lancolt listaban keres telefonszam alapjan
	{
		
		for (size_t i = 0; i < elem; i++)
		{
			if (!keresett.compare(tar[i]->get_u().g_tel()))
			{
				
				return tar[i];
			}
		}
		return NULL;
	}

	/**
	*@brief Az összes a tárban lévő ügyfelet kiírja a konzolra.*/
	void mindki()
	{
		for (size_t i = 0; i < elem; i++)
			tar[i]->kiir();
	}
};


	
	
#endif // !ELOFIZETESTAR


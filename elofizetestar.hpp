#ifndef ELOFIZETESTAR
#define ELOFIZETESTAR
#include <string>
#include "elofizetes.hpp"
#include <iostream>
#include <fstream>
//template<size_t siz=100>
class elofizetestar : public elofizetes {
	size_t meret;
	elofizetes* tar[100];
	size_t elem;
	//elofizetestar(const elofizetestar&){throw"nincs másoló"}
public:
	elofizetestar() { elem = 0; meret = 100;}
	size_t size() { return elem; }
	size_t capacity() { return meret; }
	elofizetes* operator[](unsigned int idx)
	{ 
		if (idx > meret)
			throw("rossz index");
		else 
			return tar[idx]; 
	}
	void add(elofizetes* p) 
	{
		if (elem < meret)
		{
			tar[elem] = p; elem += 1;
		}
		else { delete p; throw("Nincs eleg hely"); }
	}
	~elofizetestar() { for (size_t i = 0; i < elem; i++) if(tar[i]!=NULL)delete tar[i];}
	/*
	void szetszed(std::string& dij, std::string& nev, std::string& cim, std::string& line, std::string& tel, 
		unsigned int& perc, unsigned int& sms, unsigned int& net)
	{
		size_t first = 0, last = 0;
		int i = 0;
		for (last; last<line.size(); last++);
		if (line[last] == " "&& i = 0)
		{
			i++;
		}
		if (line[last] == " "&& i = 0)
		{

		}
		if (line[last] == " "&& i = 0)
		{

		}
		if (line[last] == " "&& i=0)
		{

		}
		//enumos szetvalaszto
		
	}*/
	void olvas()//filebol olvassa be az ugyfeleket
	{
		std::ifstream file("ugyfel.txt");
		std::string dij, nev, cim, line, tel;
		unsigned int felh_perc, felh_sms, felh_net;
		if (file.is_open())
		{
			while (std::getline(file, line))
			{
				std::stringstream iss(line);//helytelen
				
				iss>> dij >> tel >> nev >> cim >> felh_perc >> felh_sms >> felh_net;
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


	void mindki()
	{
		for (size_t i = 0; i < elem; i++)
			tar[i]->kiir();
	}
};


	
	
#endif // !ELOFIZETESTAR



#include <iostream>
#include <fstream>
#include <string>
#include "memtrace.h"
//#include <vld.h>
#include "tarifa.hpp"
#include "ugyfel.hpp"


#include "elofizetes.hpp"
#include "elofizetestar.hpp"
#include "gtest_lite.h"

#include "fgv.h"

//#define CPORTA


#ifdef CPORTA
/**Tesztelő függvény.
*Visszatérés és paraméter nélküli.
*Teszteli a beolvasást, a számítást és a kereső függvényt*/
void teszt()//teszteli a beolvasas eredmenyet, az elso 2 ugyfelre
{
	//meret teszt
	TEST(test1, letrehoz)
	{
		elofizetestar t1(1);
		int a = t1.capacity();
		EXPECT_EQ(1, a);
		t1.olvas();
		a = t1.capacity();
		EXPECT_EQ(4, a);
		t1.mindki();
		
	}ENDM

	TEST(test2, beolvasas)
	{
		elofizetestar t3(1);
		t3.olvas();
		std::string a;
		a= t3[0]->get_u().g_tel();
		EXPECT_STREQ("201234567", t3[0]->get_u().g_tel().c_str());
		EXPECT_STREQ("Kis_Pista", t3[0]->get_u().g_nev().c_str());
		EXPECT_STREQ("Nagy_Lajos_utca_12", t3[0]->get_u().g_cim().c_str());
		EXPECT_STREQ("202020202", t3[1]->get_u().g_tel().c_str());
		EXPECT_STREQ("Nagy_Pista", t3[1]->get_u().g_nev().c_str());
		EXPECT_STREQ("06205002256", t3[2]->get_u().g_tel().c_str());
		EXPECT_STREQ("Kis_Geri", t3[2]->get_u().g_nev().c_str());
		EXPECT_STREQ("Nem_Lakik_Sehol_23", t3[2]->get_u().g_cim().c_str());
	}ENDM
	
	TEST(test3, sum)
	{
		elofizetestar t3(1);
		t3.olvas();
		EXPECT_EQ(4530, t3[0]->sum());
		EXPECT_EQ(6000, t3[1]->sum());
		EXPECT_EQ(8420, t3[2]->sum());
	}ENDM
	TEST(test4, keres)
	{
		elofizetestar t3(1);
		t3.olvas();
		EXPECT_STREQ("201234567", t3.keres("201234567")->get_u().g_tel().c_str());
		EXPECT_STREQ("202020202", t3.keres("202020202")->get_u().g_tel().c_str());
		EXPECT_STREQ("06205002256", t3.keres("06205002256")->get_u().g_tel().c_str());
	}ENDM
}
#endif //CPORTA
//alap: 6000, 100perc,  50 sms, 1000mb net, utána 50ft/perc 50/sms 4ft/MB
//net 6000  0 perc, 0 sms,korlátlan net, utána 55/perc 55/sms	0mb/ft
//sms:4500Ft, 45 perc, 100 sms, 0mb, utána,  55/perc 30/sms 6/MB
#ifdef CPORTA
int main()
{
	teszt();
	std::cin.get();
	return 0;
}
#endif // CPORTA
#ifndef CPORTA
int main()


{
	try {
		menu();
	}
	catch (const char*p) { std::cout << p; std::cin.get(); std::cin.get(); return -1; }
	std::cout << "sikeresen kilepett a programbol!(egy enter meg kell)" << std::endl;
	std::cin.get();
	std::cin.get();
	
	return 0;
	
}
#endif // !CPORTA



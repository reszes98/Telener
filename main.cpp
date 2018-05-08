
#include <iostream>
#include "tarifa.hpp"
#include "ugyfel.hpp"
#include <fstream>
#include <string>
#include <sstream>
#include "elofizetes.hpp"
#include "elofizetestar.hpp"
#include "gtest_lite.h"
#include "memtrace.h"
#include "fgv.h"
//#define CPORTA


#ifdef CPORTA
void teszt()//teszteli a beolvasas eredmenyet, az elso 2 ugyfelre
{
	//meret teszt
	TEST(test1, letrehoz)
	{
		elofizetestar t1;
		int a = t1.capacity();
		std::cout << "teszt1" << std::endl;
		std::cout << "merete: " << a << "elvart: 100" << std::endl;
		EXPECT_EQ(100, a);
		t1.olvas();
		
		/*elofizetestar t2;
		std::cout << "er";
		EXPECT_THROW(t2.olvas(), const char*);*/
	}ENDM

	TEST(test2, beolvasas)
	{
		elofizetestar t3;
		t3.olvas();
		std::string a;
		a= t3[0]->g_tel();
		EXPECT_STREQ("201234567", t3[0]->g_tel().c_str());
		EXPECT_STREQ("Kis_Pista", t3[0]->g_nev().c_str());
		EXPECT_STREQ("Nagy_Lajos_utca_12", t3[0]->g_cim().c_str());
		EXPECT_STREQ("202020202", t3[1]->g_tel().c_str());
		EXPECT_STREQ("Nagy_Pista", t3[1]->g_nev().c_str());
		EXPECT_STREQ("Bp_Nagy_Lajos_kiraly_utja_8/b", t3[1]->g_cim().c_str());
	}ENDM
	
	TEST(test3, sum)
	{
		elofizetestar t3;
		t3.olvas();
		EXPECT_EQ(4530, t3[0]->sum());
		EXPECT_EQ(6000, t3[1]->sum());
	}ENDM
		TEST(test4, keres)
	{
		elofizetestar t4;
		t4.olvas();
		EXPECT_NO_THROW(t4.keres("202020202"));
		EXPECT_THROW(t4.keres("010101"), const char*);
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



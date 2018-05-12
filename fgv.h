#ifndef FGV_H
#define FGV_H
#include "elofizetes.hpp"


/**
@brief A menü függvények első példánya, a többit ez a függvény fogja hívni.
* Itt csak a beolvasást indíthatjuk el.
*/
void menu();

/**
@brief a második menü függvény.
* Itt található a kereső és a mindenkit kiíró menüpontok.*/
void menu1();

/**
@brief a harmadik menü függvény.
* Ez a telefonszám kereső al menüje, itt tudjuk megnézni az ügyfeleket másik tarifa csomaggal.
*/
void menu2(elofizetes* k);
#endif // !FGV_H

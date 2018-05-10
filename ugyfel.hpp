#ifndef UGYFEL
#define UGYFEL


#include <string>
/**
  @class ugyfel, itt tároljuk az ügyfelek adatait.
 */
class ugyfel{
	/**Privát változó. Telefonszámot tárolunk benne*/
	std::string tel;
	/**Privát változó. Nevet tárolunk benne*/
	std::string nev;
	/**Privát változó. Címet tárolunk benne*/
	std::string cim;
	/**Privát változó. Felhasznált percek számát tárolunk benne*/
	unsigned int felh_perc;
	/**Privát változó. Felhasznált sms-ek számát tárolunk benne*/
	unsigned int felh_sms;
	/**Privát változó. Felhasznált Megabyte-ok számát tárolunk benne*/
	unsigned int felh_net;
public:

	/**
	 Konstruktor.
	 Adattal és nélküle is meg lehet hívni.
	 */
	ugyfel(std::string tel=" ", std::string nev=" ", std::string cim=" ", unsigned int felh_perc=0, unsigned int felh_sms=0, unsigned int felh_net=0)
		:tel(tel),  nev(nev), cim(cim), felh_perc(felh_perc),  felh_sms(felh_sms), felh_net(felh_net) {}
	/**Destruktor. Szabvány paraméter nélküli Destruktor*/
	~ugyfel() {}

	/**g_tel függvény.
	*String& visszatérésű függvény, nincs paramétere.
	@return Ügyfél telefonszáma.
	*/
	std::string& g_tel() { return tel; }

	/**g_nev függvény.
	*String& visszatérésű függvény, nincs paramétere.
	@return Ügyfél neve.
	*/
	std::string& g_nev() { return nev; }

	/**g_cim függvény.
	*String& visszatérésű függvény, nincs paramétere.
	@return Ügyfél címe.
	*/
	std::string& g_cim() { return cim; }

	/**g_felhperc függvény.
	* Unsigend int visszatérésű függvény, nincs paramétere.
	@return ügyfél felhasznált perceinek száma.
	*/
	unsigned int g_felhperc() { return felh_perc; }

	/**g_felhsms függvény.
	* Unsigend int visszatérésű függvény, nincs paramétere.
	@return ügyfél felhasznált smseinek száma.
	*/
	unsigned int g_felhsms() { return felh_sms; }

	/**g_felhnet függvény.
	* Unsigend int visszatérésű függvény, nincs paramétere.
	@return ügyfél felhasznált Megabyte-jainak száma.
	*/
	unsigned int g_felhnet() { return felh_net; }

	/**s_tel függvény.
	*void visszatérésű függvény, string paraméterrel.
	Az ügyfél telefonszámát állíthatjuk így be
	*/
	void s_tel(std::string p) { tel = p; }

	/**s_nev függvény.
	*void visszatérésű függvény, string paraméterrel.
	Az ügyfél nevét állíthatjuk így be
	*/
	void s_nev(std::string p) { nev = p; }

	/**s_cim függvény.
	*void visszatérésű függvény, string paraméterrel.
	Az ügyfél címét állíthatjuk így be
	*/
	void s_cim(std::string p) { cim = p; }

	/**s_felhperc függvény.
	*void visszatérésű függvény, string paraméterrel.
	Az ügyfél felhasznált perceinek számát állíthatjuk így be
	*/
	void s_felhperc(unsigned int p) { felh_perc = p; }

	/**s_felhsms függvény.
	*void visszatérésű függvény, string paraméterrel.
	Az ügyfél felhasznált sms-einek a számát állíthatjuk így be
	*/
	void s_felhsms(unsigned int p) { felh_sms = p; }

	/**s_felhnet függvény.
	*void visszatérésű függvény, string paraméterrel.
	Az ugyfel felhasznált Megabyte-jainkak számát állíthatjuk így be
	*/
	void s_felhnet(unsigned int p) { felh_net = p; }
};



#endif // !UGYFEL_HPP
#ifndef UGYFEL
#define UGYFEL


#include <string>
/**
  @class �gyf�l. Itt t�roljuk az �gyfelek adatait.
 */
class ugyfel{
	/**Priv�t v�ltoz�. Telefonsz�mot t�rolunk benne*/
	std::string tel;
	/**Priv�t v�ltoz�. Nevet t�rolunk benne*/
	std::string nev;
	/**Priv�t v�ltoz�. C�met t�rolunk benne*/
	std::string cim;
	/**Priv�t v�ltoz�. Felhaszn�lt percek sz�m�t t�rolunk benne*/
	unsigned int felh_perc;
	/**Priv�t v�ltoz�. Felhaszn�lt sms-ek sz�m�t t�rolunk benne*/
	unsigned int felh_sms;
	/**Priv�t v�ltoz�. Felhaszn�lt Megabyte-ok sz�m�t t�rolunk benne*/
	unsigned int felh_net;
public:

	/**
	 Konstruktor.
	 Adattal �s n�lk�le is meg lehet h�vni.
	 */
	ugyfel(std::string tel=" ", std::string nev=" ", std::string cim=" ", unsigned int felh_perc=0, unsigned int felh_sms=0, unsigned int felh_net=0)
		:tel(tel),  nev(nev), cim(cim), felh_perc(felh_perc),  felh_sms(felh_sms), felh_net(felh_net) {}
	/**Destruktor. Szabv�ny param�ter n�lk�li Destruktor*/
	~ugyfel() {}

	/**String& visszat�r�s� f�ggv�ny, nincs param�tere.
	@return �gyf�l telefonsz�ma.
	*/
	std::string& g_tel() { return tel; }

	/**String& visszat�r�s� f�ggv�ny, nincs param�tere.
	@return �gyf�l neve.
	*/
	std::string& g_nev() { return nev; }

	/**String& visszat�r�s� f�ggv�ny, nincs param�tere.
	@return �gyf�l c�me.
	*/
	std::string& g_cim() { return cim; }

	/** Unsigend int visszat�r�s� f�ggv�ny, nincs param�tere.
	@return �gyf�l felhaszn�lt perceinek sz�ma.
	*/
	unsigned int g_felhperc() { return felh_perc; }

	/** Unsigend int visszat�r�s� f�ggv�ny, nincs param�tere.
	@return �gyf�l felhaszn�lt smseinek sz�ma.
	*/
	unsigned int g_felhsms() { return felh_sms; }

	/** Unsigend int visszat�r�s� f�ggv�ny, nincs param�tere.
	@return �gyf�l felhaszn�lt Megabyte-jainak sz�ma.
	*/
	unsigned int g_felhnet() { return felh_net; }

	/**void visszat�r�s� f�ggv�ny, string param�terrel.
	Az �gyf�l telefonsz�m�t �ll�thatjuk �gy be
	*/
	void s_tel(std::string p) { tel = p; }

	/**void visszat�r�s� f�ggv�ny, string param�terrel.
	Az �gyf�l nev�t �ll�thatjuk �gy be
	*/
	void s_nev(std::string p) { nev = p; }

	/**void visszat�r�s� f�ggv�ny, string param�terrel.
	Az �gyf�l c�m�t �ll�thatjuk �gy be
	*/
	void s_cim(std::string p) { cim = p; }

	/**void visszat�r�s� f�ggv�ny, string param�terrel.
	Az �gyf�l felhaszn�lt perceinek sz�m�t �ll�thatjuk �gy be
	*/
	void s_felhperc(unsigned int p) { felh_perc = p; }

	/**void visszat�r�s� f�ggv�ny, string param�terrel.
	Az �gyf�l felhaszn�lt sms-einek a sz�m�t �ll�thatjuk �gy be
	*/
	void s_felhsms(unsigned int p) { felh_sms = p; }

	/**void visszat�r�s� f�ggv�ny, string param�terrel.
	Az ugyfel felhaszn�lt Megabyte-jainkak sz�m�t �ll�thatjuk �gy be
	*/
	void s_felhnet(unsigned int p) { felh_net = p; }
};



#endif // !UGYFEL_HPP
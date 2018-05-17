#ifndef TARIFA
#define TARIFA

//#include "memtrace.h"

//#include <vld.h>
/**
* A tarifák adatait tároljuk itt.
*/
class tarifa  {
	 /**Privát változó. A számla alapdíját tároljuk benne.*/
	 unsigned int alap_dij;
	 /**Privát változó. Tarifában foglalt ingyenes percek számát tároljuk benne.*/
	 unsigned int alap_perc;
	 /**Privát változó. Tarifában foglalt ingyenes sms-ek számát tároljuk benne.*/
	 unsigned int alap_sms;
	 /**Privát változó. Tarifában foglalt ingyenes Megabyte-ok számát tároljuk benne.*/
	 unsigned int alap_net;
	 /**Privát változó. Ingyenes percek felhasználása utáni percdíj.*/
	 unsigned int perc_dij;
	 /**Privát változó. Sms keret felhasználása utáni sms díj.*/
	 unsigned int sms_dij;
	 /**Privát változó. Az internet keret felhasználása utáni internet díj.*/
	 unsigned int net_dij;
	 
public:

	/**
	*Konstruktor.
	*Adattal és nélküle is meg lehet hívni.
	*/
	tarifa(unsigned int alap_dij= 0, unsigned int alap_perc = 0, unsigned int alap_sms=0,  unsigned int alap_net = 0,
		unsigned int perc_dij = 0, unsigned int sms_dij=0, unsigned int net_dij=0 )
		:alap_dij(alap_dij), alap_perc(alap_perc), alap_sms(alap_sms), alap_net(alap_net), 
		perc_dij(perc_dij), sms_dij(sms_dij), net_dij(net_dij){}
	/**Destruktor.
	*Szabvány paraméter nélküli Destruktor
	*/
//	~tarifa() { }

	/**
	*@brief Beállítja az alapdíjat.
	*visszatérés nélküli.
	*/
	void s_dij(unsigned int p) { alap_dij = p; }

	/**
	*@brief Beállítja az ingyenes smsek számát.
	*visszatérés nélküli.
	*/
	void s_sms(unsigned int p) { alap_sms = p; }

	/**
	*@brief Beállítja az ingyenes Megabyte-ok számát.
	*visszatérés nélküli.
	*/
	void s_net(unsigned int p) { alap_net = p; }

	/**
	*@brief Beállítja az ingyenes percek számát.
	*visszatérés nélküli.
	*/
	void s_perc(unsigned int p) { alap_perc = p; }

	/**
	*@brief Beállítja az sms díját.
	*visszatérés nélküli.
	*/
	void s_smsdij(unsigned int p) { sms_dij = p; }

	/**
	*@brief Beállítja az internet díját.
	*visszatérés nélküli.
	*/
	void s_netdij(unsigned int p) { net_dij = p; }

	/**
	*@brief Beállítja az sms díját.
	*visszatérés nélküli.
	*/
	void s_percdij(unsigned int p) { perc_dij = p; }

	/**
	*nincs paramétere.
	@return tarifa alapdíja.
	*/
	unsigned int g_dij() { return alap_dij; }

	/**
	*nincs paramétere.
	@return ingyenes sms.
	*/
	unsigned int g_sms() { return alap_sms; }

	/**
	* nincs paramétere.
	@return ingyenes Megabyte-ok.
	*/
	unsigned int g_net() { return alap_net; }

	/**
	*unsigned int  visszatérésű, nincs paramétere.
	@return ingyenes percek.
	*/
	unsigned int g_perc() { return alap_perc; }

	/**
	*unsigned int  visszatérésű, nincs paramétere.
	@return smsdíj.
	*/
	unsigned int g_smsdij() { return sms_dij; }

	/**
	*nincs paramétere.
	@return netdíj.
	*/
	unsigned int g_netdij() { return net_dij; }

	/**
	*nincs paramétere.
	@return percdíj.
	*/
	unsigned int g_percdij() { return perc_dij; }

};



#endif // !TARIFA_HPP

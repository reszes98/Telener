#ifndef TARIFA
#define TARIFA

/**
	@class tarifa, a tarifák adatait tároljuk itt.
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
	~tarifa() { }

	/**s_dij függvény
	@param unsigned int
	*Beállítja az alapdíjat.
	*visszatérés nélküli.
	*/
	void s_dij(unsigned int p) { alap_dij = p; }

	/**s_sms függvény
	@param unsigned int
	*Beállítja az ingyenes smsek számát.
	*visszatérés nélküli.
	*/
	void s_sms(unsigned int p) { alap_sms = p; }

	/**s_net függvény
	@param unsigned int
	*Beállítja az ingyenes Megabyte-ok számát.
	*visszatérés nélküli.
	*/
	void s_net(unsigned int p) { alap_net = p; }

	/**s_perc függvény
	@param unsigned int
	*Beállítja az ingyenes percek számát.
	*visszatérés nélküli.
	*/
	void s_perc(unsigned int p) { alap_perc = p; }

	/**s_smsdij függvény
	@param unsigned int
	*Beállítja az sms díját.
	*visszatérés nélküli.
	*/
	void s_smsdij(unsigned int p) { sms_dij = p; }

	/**s_netdij függvény
	@param unsigned int
	*Beállítja az internet díját.
	*visszatérés nélküli.
	*/
	void s_netdij(unsigned int p) { net_dij = p; }

	/**s_percdij függvény
	@param unsigned int
	*Beállítja az sms díját.
	*visszatérés nélküli.
	*/
	void s_percdij(unsigned int p) { perc_dij = p; }

	/**g_dij függvény.
	*unsigned int  visszatérésű, nincs paramétere.
	@return tarifa alapdíja.
	*/
	unsigned int g_dij() { return alap_dij; }

	/**g_sms függvény.
	*unsigned int  visszatérésű, nincs paramétere.
	@return ingyenes sms.
	*/
	unsigned int g_sms() { return alap_sms; }

	/**g_net függvény.
	*unsigned int  visszatérésű, nincs paramétere.
	@return ingyenes Megabyte-ok.
	*/
	unsigned int g_net() { return alap_net; }

	/**g_perc függvény.
	*unsigned int  visszatérésű, nincs paramétere.
	@return ingyenes percek.
	*/
	unsigned int g_perc() { return alap_perc; }

	/**g_smsdij függvény.
	*unsigned int  visszatérésű, nincs paramétere.
	@return smsdíj.
	*/
	unsigned int g_smsdij() { return sms_dij; }

	/**g_netdij függvény.
	*unsigned int  visszatérésű, nincs paramétere.
	@return netdíj.
	*/
	unsigned int g_netdij() { return net_dij; }

	/**g_percdij függvény.
	*unsigned int  visszatérésű, nincs paramétere.
	@return percdíj.
	*/
	unsigned int g_percdij() { return perc_dij; }

};



#endif // !TARIFA_HPP

#ifndef UGYFEL
#define UGYFEL


#include <string>
class ugyfel{
	std::string tel;
	std::string nev;
	std::string cim;
	unsigned int felh_perc;//felhasznalt percek
	unsigned int felh_sms;//felhasznalt smsek
	unsigned int felh_net;//felhasznalt mb
public:

	//konst és dek

	ugyfel(std::string tel=" ", std::string nev=" ", std::string cim=" ", unsigned int felh_perc=0, unsigned int felh_sms=0, unsigned int felh_net=0)
		:tel(tel),  nev(nev), cim(cim), felh_perc(felh_perc),  felh_sms(felh_sms), felh_net(felh_net) {}
	~ugyfel() {}

	// getterek
	std::string& g_tel() { return tel; }
	std::string& g_nev() { return nev; }
	std::string& g_cim() { return cim; }
	unsigned int g_felhperc() { return felh_perc; }
	unsigned int g_felhsms() { return felh_sms; }
	unsigned int g_felhnet() { return felh_net; }

	//setterek
	void s_tel(std::string p) { tel = p; }
	void s_nev(std::string p) { nev = p; }
	void s_cim(std::string p) { cim = p; }
	void s_felhperc(unsigned int p) { felh_perc = p; }
	void s_felhsms(unsigned int p) { felh_sms = p; }
	void s_felhnet(unsigned int p) { felh_net = p; }
};



#endif // !UGYFEL_HPP
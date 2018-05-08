#ifndef TARIFA
#define TARIFA


class tarifa  {
	 unsigned int alap_dij;//szamla alapdija
	 unsigned int alap_perc;//szamlaban foglalt lebeszelheto percek
	 unsigned int alap_sms;//szamlaban foglalt felhasznalhato smsek
	 unsigned int alap_net;//szamlaban foglalt felhasznalhato mbok

	 unsigned int perc_dij;//szamlaban foglaltakon feluli telefonhivas percenkenti dija
	 unsigned int sms_dij;// szamlaban foglaltakon feluli sms dij
	 unsigned int net_dij;// szamlaban foglaltakon feluli adat dij
	 
public:

	//konstr, dek
	//net 6000  0 perc,korlátlan net, 0 sms, utána 55/perc 55/sms
	tarifa(unsigned int alap_dij= 0, unsigned int alap_perc = 0, unsigned int alap_sms=0,  unsigned int alap_net = 0,
		unsigned int perc_dij = 0, unsigned int sms_dij=0, unsigned int net_dij=0 )
		:alap_dij(alap_dij), alap_perc(alap_perc), alap_sms(alap_sms), alap_net(alap_net), 
		perc_dij(perc_dij), sms_dij(sms_dij), net_dij(net_dij){}
	~tarifa() { }
	//setter
	void s_dij(unsigned int p) { alap_dij = p; }
	void s_sms(unsigned int p) { alap_sms = p; }
	void s_net(unsigned int p) { alap_net = p; }
	void s_perc(unsigned int p) { alap_perc = p; }
	void s_smsdij(unsigned int p) { sms_dij = p; }
	void s_netdij(unsigned int p) { net_dij = p; }
	void s_percdij(unsigned int p) { perc_dij = p; }
	//getter
	unsigned int g_dij() { return alap_dij; }
	unsigned int g_sms() { return alap_sms; }
	unsigned int g_net() { return alap_net; }
	unsigned int g_perc() { return alap_perc; }
	unsigned int g_smsdij() { return sms_dij; }
	unsigned int g_netdij() { return net_dij; }
	unsigned int g_percdij() { return perc_dij; }

};



#endif // !TARIFA_HPP

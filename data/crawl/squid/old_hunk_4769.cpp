};

char *ntlmGetString(ntlmhdr * hdr, strhdr * str, int flags);
void ntlmMakeChallenge(struct ntlm_challenge *chal);
int ntlmCheckHeader(ntlmhdr * hdr, int type);
int ntlmCheckNegotiation(struct ntlm_negotiate *neg);
int ntlmAuthenticate(struct ntlm_authenticate *neg);

#endif /* _NTLM_H_ */
/* send ERR result to Squid with a string parameter. */
#define SEND_BH(x)	fprintf(stdout, "BH %s\n",x)

/* send TT result to Squid with a string parameter. */
#define SEND_TT(x)	fprintf(stdout, "TT %s\n",x)

#endif /* __SQUID_HELPERS_DEFINES_H */

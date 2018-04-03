/* send ERR result to Squid with a string parameter. */
#define SEND_ERR(x)	fprintf(stdout, "ERR %s\n",x)

/* send ERR result to Squid with a string parameter. */
#define SEND_BH(x)	fprintf(stdout, "BH %s\n",x)

#endif /* __SQUID_HELPERS_DEFINES_H */
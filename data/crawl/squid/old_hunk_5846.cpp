#define debug(X...)		/* */
#endif /* DEBUG */
#else /* __GNUC__ */
#define debug(char *format, ...) {}	/* Too lazy to write va_args stuff */
#endif


/* A couple of harmless helper macros */
#define SEND(X) debug("sending '%s' to squid\n",X); printf(X); printf("\n");
#define SEND2(X,Y...) debug("sending '" X "' to squid\n",Y); printf(X,Y);\
         printf("\n");

extern int ntlm_errno;
#define NTLM_NO_ERROR 0



/* A couple of harmless helper macros */
#define SEND(X) debug("sending '%s' to squid\n",X); printf(X); printf("\n");
#ifdef __GNUC__
#define SEND2(X,Y...) debug("sending '" X "' to squid\n",Y); printf(X,Y);\
         printf("\n");
#else
/* no gcc, no debugging. varargs macros are a gcc extension */
#define SEND2 printf
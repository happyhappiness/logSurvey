#if HAVE_ASSERT_H
#include <assert.h>
#endif
#if HAVE_TIME_H
#include <time.h>
#endif


/************* CONFIGURATION ***************/

#define DEAD_DC_RETRY_INTERVAL 30

/************* END CONFIGURATION ***************/

/* A couple of harmless helper macros */
#define SEND(X) debug("sending '%s' to squid\n",X); printf(X "\n");
#ifdef __GNUC__
#define SEND2(X,Y...) debug("sending '" X "' to squid\n",Y); printf(X "\n",Y);
#define SEND3(X,Y...) debug("sending '" X "' to squid\n",Y); printf(X "\n",Y);
#else
/* no gcc, no debugging. varargs macros are a gcc extension */
#define SEND2 printf
#define SEND3 printf
#endif

const char *make_challenge(char *domain, char *controller);
char *ntlm_check_auth(ntlm_authenticate * auth, int auth_length);
void dc_disconnect(void);
int connectedp(void);
int is_dc_ok(char *domain, char *domain_controller);

typedef struct _dc dc;
struct _dc {
    char *domain;
    char *controller;
    time_t dead;		/* 0 if it's alive, otherwise time of death */
    dc *next;
};

/* local functions */
void send_bh_or_ld(char const *bhmessage, ntlm_authenticate * failedauth, int authlen);

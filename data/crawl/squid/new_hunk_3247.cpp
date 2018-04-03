 *
 *
 */
#include "config.h"
#include "helpers/defines.h"
#include "libntlmauth/support_bits.cci"
#include "sspwin32.h"
#include "util.h"

#include <windows.h>
#include <sspi.h>
#include <security.h>
#if HAVE_GETOPT_H
#include <getopt.h>
#endif
#if HAVE_CTYPE_H
#include <ctype.h>
#endif

int Negotiate_packet_debug_enabled = 0;
static int have_serverblob;

/* A couple of harmless helper macros */
#define SEND(X) debug("sending '%s' to squid\n",X); printf(X "\n");
#ifdef __GNUC__
#define SEND2(X,Y...) debug("sending '" X "' to squid\n",Y); printf(X "\n",Y);
#define SEND3(X,Y...) debug("sending '" X "' to squid\n",Y); printf(X "\n",Y);
#else
/* no gcc, no debugging. varargs macros are a gcc extension */
#define SEND2(X,Y) debug("sending '" X "' to squid\n",Y); printf(X "\n",Y);
#define SEND3(X,Y,Z) debug("sending '" X "' to squid\n",Y,Z); printf(X "\n",Y,Z);
#endif

char *negotiate_check_auth(SSP_blobP auth, int auth_length);

/*
 * options:

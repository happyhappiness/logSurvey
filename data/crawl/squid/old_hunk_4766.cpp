#if HAVE_PWD_H
#include <pwd.h>
#endif


#define ERR    "ERR\n"
#define OK     "OK\n"

#if 0
#define NTLM_STATIC_CHALLENGE "deadbeef"
#endif
static char *authenticate_ntlm_domain = "LIFELESSWKS";

/* NTLM authentication by ad@interlude.eu.org - 07/1999 */
/* XXX this is not done cleanly... */

/* makes a null-terminated string lower-case. Changes CONTENTS! */
static void
lc(char *string)

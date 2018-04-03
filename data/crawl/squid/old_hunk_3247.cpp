 *
 *
 */

#include "util.h"
#if HAVE_GETOPT_H
#include <getopt.h>
#endif
#include "negotiate.h"
#if HAVE_CTYPE_H
#include <ctype.h>
#endif

#define BUFFER_SIZE 10240

int debug_enabled = 0;
int Negotiate_packet_debug_enabled = 0;

static int have_serverblob;

/* makes a null-terminated string upper-case. Changes CONTENTS! */
void
uc(char *string)
{
    char *p = string, c;
    while ((c = *p)) {
        *p = xtoupper(c);
        p++;
    }
}

/* makes a null-terminated string lower-case. Changes CONTENTS! */
static void
lc(char *string)
{
    char *p = string, c;
    while ((c = *p)) {
        *p = xtolower(c);
        p++;
    }
}

void
helperfail(const char *reason)
{
#if FAIL_DEBUG
    fail_debug_enabled = 1;
#endif
    SEND2("BH %s", reason);
}

/*
 * options:

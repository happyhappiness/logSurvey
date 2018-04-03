 *   Florian octo Forster <octo at collectd.org>
 */

#include "common.h"

static int fail_count = 0;
static int check_count = 0;

#define TEST(func) do { \
  int status; \
  printf ("Testing %s ...\n", #func); \
  status = test_ ## func (); \
  printf ("%s.\n", (status == 0) ? "Success" : "FAILURE"); \
  if (status != 0) { fail_count++; } \
} while (0);

#define OK1(cond, text) do { \
  _Bool result = (cond); \
  printf ("%s %i - %s\n", result ? "ok" : "not ok", ++check_count, text); \
  if (!result) { return (-1); } \
} while (0);

#define STREQ(expect, actual) do { \
  if (strcmp (expect, actual) != 0) { \
    printf ("not ok %i - %s incorrect: expected \"%s\", got \"%s\"\n", \
        ++check_count, #actual, expect, actual); \
    return (-1); \
  } \
  printf ("ok %i - %s evaluates to \"%s\"\n", ++check_count, #actual, expect); \
} while (0)

#define OK(cond) OK1(cond, #cond)

static int test_sstrncpy (void)
{
  char buffer[16] = "";
  char *ptr = &buffer[4];

 *   Florian octo Forster <octo at collectd.org>
 */

#include "tests/macros.h"
#include "common.h"

DEF_TEST(sstrncpy)
{
  char buffer[16] = "";
  char *ptr = &buffer[4];

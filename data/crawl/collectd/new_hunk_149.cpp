 *   Florian octo Forster <octo at collectd.org>
 */

#include "tests/macros.h"
#include "collectd.h"
#include "utils_avltree.h"

static int compare_total_count = 0;
#define RESET_COUNTS() do { compare_total_count = 0; } while (0)


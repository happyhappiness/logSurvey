 *
 * Authors:
 *   Florian octo Forster <octo at collectd.org>
 *   Sebastian tokkee Harl <sh at tokkee.org>
 **/

#include "collectd.h"

#include "common.h"
#include "plugin.h"

#include "utils_cmds.h"
#include "utils_cmd_putval.h"
#include "utils_parse_option.h"
#include "utils_cmd_putval.h"

/*
 * private helper functions
 */

static int set_option (value_list_t *vl, const char *key, const char *value)
{

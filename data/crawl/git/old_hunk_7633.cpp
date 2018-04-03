#include "exec_cmd.h"
#include "common-cmds.h"

/* most GUI terminals set COLUMNS (although some don't export it) */
static int term_columns(void)
{

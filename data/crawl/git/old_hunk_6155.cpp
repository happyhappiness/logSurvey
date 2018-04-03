static char delim = '=';
static char key_delim = ' ';
static char term = '\n';
static enum { T_RAW, T_INT, T_BOOL, T_BOOL_OR_INT } type = T_RAW;

static int show_all_config(const char *key_, const char *value_, void *cb)
{

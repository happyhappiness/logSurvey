	die("unable to grep from object of type %s", typename(obj->type));
}

static const char builtin_grep_usage[] =
"git grep <option>* [-e] <pattern> <rev>* [[--] <path>...]";

static const char emsg_invalid_context_len[] =
"%s: invalid context length argument";
static const char emsg_missing_context_len[] =
"missing context length argument";
static const char emsg_missing_argument[] =
"option requires an argument -%s";

int cmd_grep(int argc, const char **argv, const char *prefix)
{

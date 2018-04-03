	return status;
}

/*
 * main "reflog"
 */

static const char reflog_usage[] =
"git reflog [ show | expire | delete ]";

int cmd_reflog(int argc, const char **argv, const char *prefix)
{

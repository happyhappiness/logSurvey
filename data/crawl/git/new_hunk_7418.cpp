#include "builtin.h"
#include "exec_cmd.h"
#include "common-cmds.h"
#include "parse-options.h"

enum help_format {
	HELP_FORMAT_MAN,
	HELP_FORMAT_INFO,
	HELP_FORMAT_WEB,
};

static int show_all = 0;
static enum help_format help_format = HELP_FORMAT_MAN;
static struct option builtin_help_options[] = {
	OPT_BOOLEAN('a', "all", &show_all, "print all available commands"),
	OPT_SET_INT('m', "man", &help_format, "show man page", HELP_FORMAT_MAN),
	OPT_SET_INT('w', "web", &help_format, "show manual in web browser",
			HELP_FORMAT_WEB),
	OPT_SET_INT('i', "info", &help_format, "show info page",
			HELP_FORMAT_INFO),
};

static const char * const builtin_help_usage[] = {
	"git-help [--all] [--man|--web|--info] [command]",
	NULL
};

static enum help_format parse_help_format(const char *format)
{
	if (!strcmp(format, "man"))
		return HELP_FORMAT_MAN;
	if (!strcmp(format, "info"))
		return HELP_FORMAT_INFO;
	if (!strcmp(format, "web") || !strcmp(format, "html"))
		return HELP_FORMAT_WEB;
	die("unrecognized help format '%s'", format);
}

static int git_help_config(const char *var, const char *value)
{
	if (!strcmp(var, "help.format")) {
		if (!value)
			return config_error_nonbool(var);
		help_format = parse_help_format(value);
		return 0;
	}
	return git_default_config(var, value);
}


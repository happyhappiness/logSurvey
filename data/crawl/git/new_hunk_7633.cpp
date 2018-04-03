#include "exec_cmd.h"
#include "common-cmds.h"

static const char *help_default_format;

static enum help_format {
	man_format,
	info_format,
	web_format,
} help_format = man_format;

static void parse_help_format(const char *format)
{
	if (!format) {
		help_format = man_format;
		return;
	}
	if (!strcmp(format, "man")) {
		help_format = man_format;
		return;
	}
	if (!strcmp(format, "info")) {
		help_format = info_format;
		return;
	}
	if (!strcmp(format, "web") || !strcmp(format, "html")) {
		help_format = web_format;
		return;
	}
	die("unrecognized help format '%s'", format);
}

static int git_help_config(const char *var, const char *value)
{
	if (!strcmp(var, "help.format")) {
		help_default_format = xstrdup(value);
		return 0;
	}
	return git_default_config(var, value);
}

/* most GUI terminals set COLUMNS (although some don't export it) */
static int term_columns(void)
{

static char delim = '=';
static char key_delim = ' ';
static char term = '\n';

static int use_global_config, use_system_config;
static const char *given_config_file;
static int actions, types;
static const char *get_color_slot, *get_colorbool_slot;
static int end_null;

#define ACTION_GET (1<<0)
#define ACTION_GET_ALL (1<<1)
#define ACTION_GET_REGEXP (1<<2)
#define ACTION_REPLACE_ALL (1<<3)
#define ACTION_ADD (1<<4)
#define ACTION_UNSET (1<<5)
#define ACTION_UNSET_ALL (1<<6)
#define ACTION_RENAME_SECTION (1<<7)
#define ACTION_REMOVE_SECTION (1<<8)
#define ACTION_LIST (1<<9)
#define ACTION_EDIT (1<<10)
#define ACTION_SET (1<<11)
#define ACTION_SET_ALL (1<<12)
#define ACTION_GET_COLOR (1<<13)
#define ACTION_GET_COLORBOOL (1<<14)

#define TYPE_BOOL (1<<0)
#define TYPE_INT (1<<1)
#define TYPE_BOOL_OR_INT (1<<2)

static struct option builtin_config_options[] = {
	OPT_GROUP("Config file location"),
	OPT_BOOLEAN(0, "global", &use_global_config, "use global config file"),
	OPT_BOOLEAN(0, "system", &use_system_config, "use system config file"),
	OPT_STRING('f', "file", &given_config_file, "FILE", "use given config file"),
	OPT_GROUP("Action"),
	OPT_BIT(0, "get", &actions, "get value: name [value-regex]", ACTION_GET),
	OPT_BIT(0, "get-all", &actions, "get all values: key [value-regex]", ACTION_GET_ALL),
	OPT_BIT(0, "get-regexp", &actions, "get values for regexp: name-regex [value-regex]", ACTION_GET_REGEXP),
	OPT_BIT(0, "replace-all", &actions, "replace all matching variables: name value [value_regex]", ACTION_REPLACE_ALL),
	OPT_BIT(0, "add", &actions, "adds a new variable: name value", ACTION_ADD),
	OPT_BIT(0, "unset", &actions, "removes a variable: name [value-regex]", ACTION_UNSET),
	OPT_BIT(0, "unset-all", &actions, "removes all matches: name [value-regex]", ACTION_UNSET_ALL),
	OPT_BIT(0, "rename-section", &actions, "rename section: old-name new-name", ACTION_RENAME_SECTION),
	OPT_BIT(0, "remove-section", &actions, "remove a section: name", ACTION_REMOVE_SECTION),
	OPT_BIT('l', "list", &actions, "list all", ACTION_LIST),
	OPT_BIT('e', "edit", &actions, "opens an editor", ACTION_EDIT),
	OPT_STRING(0, "get-color", &get_color_slot, "slot", "find the color configured: [default]"),
	OPT_STRING(0, "get-colorbool", &get_colorbool_slot, "slot", "find the color setting: [stdout-is-tty]"),
	OPT_GROUP("Type"),
	OPT_BIT(0, "bool", &types, "value is \"true\" or \"false\"", TYPE_BOOL),
	OPT_BIT(0, "int", &types, "value is decimal number", TYPE_INT),
	OPT_BIT(0, "bool-or-int", &types, "value is --bool or --int", TYPE_BOOL_OR_INT),
	OPT_GROUP("Other"),
	OPT_BOOLEAN('z', "null", &end_null, "terminate values with NUL byte"),
	OPT_END(),
};

static void check_argc(int argc, int min, int max) {
	if (argc >= min && argc <= max)
		return;
	error("wrong number of arguments");
	usage_with_options(builtin_config_usage, builtin_config_options);
}

static int show_all_config(const char *key_, const char *value_, void *cb)
{

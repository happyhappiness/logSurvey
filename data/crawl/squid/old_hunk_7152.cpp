static void
parse_regexlist(relist ** var)
{
    aclParseRegexList(var, 0);
}

static void
dump_regexlist_icase(relist * var)
{
    debug(0,0)("XXX need to fix\n");
}

static void
parse_regexlist_icase(relist ** var)
{
    aclParseRegexList(var, 1);
}

static void
dump_string(char var[])
{
    printf("%s", var);
}

static void
parse_string(char *var[])
{
    char *token = strtok(NULL, w_space);

    safe_free(*var);
    if (token == NULL)
	self_destruct();
    *var = xstrdup(token);
}

static void
dump_string_optional(const char *var)
{
    printf("%s", var);
}

static void
parse_string_optional(char *volatile *var)
{
    char *token = strtok(NULL, null_string);

    safe_free(*var);
    if (token == NULL) {
	*var = NULL;

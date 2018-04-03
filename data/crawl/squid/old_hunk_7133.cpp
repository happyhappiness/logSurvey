	xfree(*var);
	*var = NULL;
}
static void
dump_string_optional(const char *var)
{
    printf("%s", var);
}

static void
parse_volatile_string(char *volatile *var)
{
    char *token = strtok(NULL, null_string);
    safe_free(*var);
    if (token == NULL) {
	*var = NULL;
	return;
    }
    *var = xstrdup(token);
}

static void
dump_time_min(int var)
{
    printf("%d", var / 60);
}

static void
parse_time_min(int *var)
{
    parseTimeLine(var, T_MINUTE_STR);
}

static void
dump_time_sec(int var)
{
    printf("%d", var);
}

static void
parse_time_sec(int *var)
{
    parseTimeLine(var, T_SECOND_STR);
}

static void
dump_ushort(u_short var)

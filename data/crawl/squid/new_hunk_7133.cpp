	xfree(*var);
	*var = NULL;
}

static void
parse_eol(char *volatile *var)
{
    char *token = strtok(NULL, null_string);
    safe_free(*var);
    if (token == NULL)
	self_destruct();
    *var = xstrdup(token);
}

static void
dump_time_t(time_t var)
{
    printf("%d", (int) var);
}

static void
parse_time_t(time_t *var)
{
    parseTimeLine(var, T_SECOND_STR);
}

static void
free_time_t(time_t *var)
{
	*var = 0;
}
	

static void
dump_ushort(u_short var)

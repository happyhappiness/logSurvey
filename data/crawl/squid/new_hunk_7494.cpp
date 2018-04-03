static void parseMinutesLine _PARAMS((int *));
static void ip_acl_destroy _PARAMS((ip_acl **));

static void
self_destruct(void)
{
    sprintf(fatal_str, "Bungled %s line %d: %s",
	cfg_filename, config_lineno, config_input_line);
    fatal(fatal_str);
}

static int
ip_acl_match(struct in_addr c, ip_acl * a)
{
    static struct in_addr h;

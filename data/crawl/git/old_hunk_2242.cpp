
static void check_write(void)
{
	if (given_config_source.use_stdin)
		die("writing to stdin is not supported");


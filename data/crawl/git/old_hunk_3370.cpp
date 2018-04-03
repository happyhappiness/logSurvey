	/* nothing */
}

static void daemonize(void)
{
	die("--detach not supported on this platform");
}

static struct credentials *prepare_credentials(const char *user_name,
    const char *group_name)
{

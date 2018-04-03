
static void check_write(void)
{
	if (given_config_source.blob)
		die("writing config blobs is not supported");
}

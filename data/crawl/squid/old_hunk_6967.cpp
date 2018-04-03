void
unlinkdInit(void)
{
    unlinkd_count = 0;
    unlinkd_fd = unlinkdCreate();
    if (unlinkd_fd < 0)
	fatal("unlinkdInit: failed to start unlinkd\n");
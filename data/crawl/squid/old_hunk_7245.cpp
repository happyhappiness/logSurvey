sigusr2_handle(int sig)
{
    static int state = 0;
    debug(21, 1, "sigusr2_handle: SIGUSR2 received.\n");
    if (state == 0) {
	_db_init(Config.Log.log, "ALL,10");
	state = 1;

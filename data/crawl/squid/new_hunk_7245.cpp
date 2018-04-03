sigusr2_handle(int sig)
{
    static int state = 0;
    /* no debug() here; bad things happen if the signal is delivered during _db_print() */
    if (state == 0) {
	_db_init(Config.Log.log, "ALL,10");
	state = 1;

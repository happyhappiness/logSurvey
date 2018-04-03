    shut_down(0);
}

static void
cachemgrOfflineToggle(StoreEntry * sentry)
{
    Config.onoff.offline = !Config.onoff.offline;
    debug(16, 0) ("offline_mode now %s.\n",
	Config.onoff.offline ? "ON" : "OFF");
    storeAppendPrintf(sentry, "offline_mode is now %s\n",
	Config.onoff.offline ? "ON" : "OFF");
}

static const char *
cachemgrActionProtection(const action_table * at)
{

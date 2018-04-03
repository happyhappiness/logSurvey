static void
shortStringStatDump(StoreEntry * e)
{
    storeAppendPrintf(e, "<h3>Short String Stats</h3>\n<p>");
	memPoolReport(shortStrings, e);
    storeAppendPrintf(e, "\n</p>\n");
    storeAppendPrintf(e, "<br><h3>Long String Stats</h3>\n");
    storeAppendPrintf(e, "alive: %3d (%5.1f KB) high-water:  %3d (%5.1f KB)\n",
	longStrAliveCount, (double) longStrAliveSize / 1024.,
	longStrHighWaterCount, (double) longStrHighWaterSize / 1024.);
}

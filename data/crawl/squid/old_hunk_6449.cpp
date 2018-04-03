    storeAppendPrintf(e, "\t deletion attempts: %d\n",
	cd->del_count
	);
    storeAppendPrintf(e, "\t bits: on: %d capacity: %d util: %d%%\n",
	stats.bit_on_count, stats.bit_count,
	xpercentInt(stats.bit_on_count, stats.bit_count)
	);

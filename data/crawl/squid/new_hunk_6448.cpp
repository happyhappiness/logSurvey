	hit_count, xpercent(hit_count, tot_count),
	miss_count, xpercent(miss_count, tot_count),
	tot_count, xpercent(tot_count, tot_count));
    storeAppendPrintf(sentry, "\tclose_hits: %d ( %d%%) /* cd said hit, doc was in the peer cache, but we got a miss */\n",
	stats->close_hits, xpercentInt(stats->close_hits, stats->false_hits));
}

void

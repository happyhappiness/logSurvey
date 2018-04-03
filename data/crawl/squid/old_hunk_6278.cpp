		percent(e->htcp.counts[1], e->stats.pings_acked));
	} else {
#endif
	for (op = ICP_INVALID; op < ICP_END; op++) {
	    if (e->icp.counts[op] == 0)
		continue;
	    storeAppendPrintf(sentry, "    %12.12s : %8d %3d%%\n",
		icp_opcode_str[op],
		e->icp.counts[op],
		percent(e->icp.counts[op], e->stats.pings_acked));
	}
#if USE_HTCP
}
#endif
	if (e->last_fail_time) {
	    storeAppendPrintf(sentry, "Last failed connect() at: %s\n",

	    continue;
	key = storeKeyPublic(url, method_id);
	/*fprintf(stdout, "%s:%d: %s %s %s %s\n",
	    fname, count, method, storeKeyText(key), url, hier);*/
	cacheIndexQueryPeer(idx, key);
	icp_count++;
    }
    fprintf(stderr, "%s: scanned %d access log entries; bad: %d\n",
	fname, scanned_count, scanned_count-count);
    fprintf(stderr, "%s: icp: %d (%d%%)\n",
	fname, icp_count, xpercentInt(icp_count, count));
    return count;

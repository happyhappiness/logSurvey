	storeMemObjectDump(mem);
	mem->log_url = xstrdup(mem->url);
    }
    reply = mem->reply;
    logfilePrintf(storelog, "%9d.%03d %-7s %08X %4d %9d %9d %9d %s %d/%d %s %s\n",
	(int) current_time.tv_sec,
	(int) current_time.tv_usec / 1000,
	storeLogTags[tag],

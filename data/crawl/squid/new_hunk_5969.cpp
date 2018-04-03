	    (int) n->next_ping_time,
	    (int) n->last_use_time);
	for (x = n->hosts; x; x = x->next)
	    logfilePrintf(lf, " %s", x->name);
	logfilePrintf(lf, "\n");
	count++;
#undef RBUF_SZ
    }
    logfileClose(lf);
    getCurrentTime();
    debug(38, 1) ("NETDB state saved; %d entries, %d msec\n",
	count, tvSubMsec(start, current_time));

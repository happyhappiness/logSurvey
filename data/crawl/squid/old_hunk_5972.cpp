	    (int) n->next_ping_time,
	    (int) n->last_use_time);
	for (x = n->hosts; x; x = x->next)
	    fprintf(fp, " %s", x->name);
	fprintf(fp, "\n");
	count++;
    }
    fclose(fp);
    getCurrentTime();
    debug(38, 1) ("NETDB state saved; %d entries, %d msec\n",
	count, tvSubMsec(start, current_time));

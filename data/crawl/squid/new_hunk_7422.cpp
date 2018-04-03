		ReplyHeaderStats.cc[SCC_PROXYREVALIDATE]++;
	    } else if (!strncasecmp(t, "max-age", 7)) {
		if ((t = strchr(t, '='))) {
		    delta = (time_t) atoi(++t);
		    reply->expires = squid_curtime + delta;
		    EBIT_SET(reply->cache_control, SCC_MAXAGE);
		    ReplyHeaderStats.cc[SCC_MAXAGE]++;
		}
	    }
	}
	t = strtok(NULL, "\n");
    }
    safe_free(headers);
}


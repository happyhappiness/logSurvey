 		ReplyHeaderStats.cc[SCC_PROXYREVALIDATE]++;
 	    } else if (!strncasecmp(t, "max-age", 7)) {
 		if ((t = strchr(t, '='))) {
-		    delta = atoi(++t);
+		    delta = (time_t) atoi(++t);
+		    reply->expires = squid_curtime + delta;
 		    EBIT_SET(reply->cache_control, SCC_MAXAGE);
 		    ReplyHeaderStats.cc[SCC_MAXAGE]++;
-		    strcpy(reply->expires, mkrfc1123(squid_curtime + delta));
 		}
 	    }
 	}
 	t = strtok(NULL, "\n");
     }
-#if LOG_TIMESTAMPS
-    fprintf(timestamp_log, "T %9d D %9d L %9d E %9d\n",
-	squid_curtime,
-	parse_rfc1123(reply->date),
-	parse_rfc1123(reply->last_modified),
-	parse_rfc1123(reply->expires));
-#endif /* LOG_TIMESTAMPS */
     safe_free(headers);
 }
 

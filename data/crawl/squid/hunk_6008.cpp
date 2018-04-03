 	mem->log_url);
     } else {
 	/* no mem object. Most RELEASE cases */
-	logfilePrintf(storelog, "%9d.%03d %-7s %02d %08X    ?         ?         ?         ? ?/? ?/? ? %s\n",
+	logfilePrintf(storelog, "%9d.%03d %-7s %02d %08X %s   ?         ?         ?         ? ?/? ?/? ? ?\n",
 	    (int) current_time.tv_sec,
 	    (int) current_time.tv_usec / 1000,
 	    storeLogTags[tag],

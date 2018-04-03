     timeout = squid_curtime + sec;
 
     do {
+	if (sec > 60)
+		fatal_dump(NULL);
 	if (0 < failtime && failtime < squid_curtime)
 	    break;
 
 #if LOG_TIMESTAMPS
     fprintf(timestamp_log, "T %9d D %9d L %9d E %9d\n",
 	squid_curtime,
-	parse_rfc850(reply->date),
-	parse_rfc850(reply->last_modified),
-	parse_rfc850(reply->expires));
+	parse_rfc1123(reply->date),
+	parse_rfc1123(reply->last_modified),
+	parse_rfc1123(reply->expires));
 #endif /* LOG_TIMESTAMPS */
     safe_free(headers);
 }

 	if (args->depth > 0)
 		packet_buf_write(&req_buf, "deepen %d", args->depth);
 	if (args->deepen_since) {
-		unsigned long max_age = approxidate(args->deepen_since);
+		timestamp_t max_age = approxidate(args->deepen_since);
 		packet_buf_write(&req_buf, "deepen-since %"PRItime, max_age);
 	}
 	if (args->deepen_not) {

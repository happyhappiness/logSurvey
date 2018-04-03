 		write_or_die(1, sha1_to_hex(sha1), GIT_SHA1_HEXSZ);
 }
 
-static void dos_time(time_t *time, int *dos_date, int *dos_time)
+static void dos_time(timestamp_t *timestamp, int *dos_date, int *dos_time)
 {
-	struct tm *t = localtime(time);
+	time_t time;
+	struct tm *t;
+
+	if (date_overflows(*timestamp))
+		die("timestamp too large for this system: %"PRItime,
+		    *timestamp);
+	time = (time_t)*timestamp;
+	t = localtime(&time);
+	*timestamp = time;
 
 	*dos_date = t->tm_mday + (t->tm_mon + 1) * 32 +
 	            (t->tm_year + 1900 - 1980) * 512;

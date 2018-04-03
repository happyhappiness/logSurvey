 				return 0;
 			}
 		}
-		if (snprintf(buf, sizeof(buf),
-			     progress->delayed_title, progress->total))
-			fprintf(stderr, "%s\n", buf);
 	}
+
+	progress->last_value = n;
+	eol = done ? ", done.   \n" : "   \r";
 	if (progress->total) {
 		unsigned percent = n * 100 / progress->total;
 		if (percent != progress->last_percent || progress_update) {
 			progress->last_percent = percent;
-			fprintf(stderr, "%s%4u%% (%u/%u) done\r",
-				progress->prefix, percent, n, progress->total);
+			fprintf(stderr, "%s: %3u%% (%u/%u)%s", progress->title,
+				percent, n, progress->total, eol);
 			progress_update = 0;
-			progress->need_lf = 1;
 			return 1;
 		}
 	} else if (progress_update) {
-		fprintf(stderr, "%s%u\r", progress->prefix, n);
+		fprintf(stderr, "%s: %u%s", progress->title, n, eol);
 		progress_update = 0;
-		progress->need_lf = 1;
 		return 1;
 	}
+
 	return 0;
 }
 
-void start_progress(struct progress *progress, const char *title,
-		    const char *prefix, unsigned total)
+int display_progress(struct progress *progress, unsigned n)
 {
-	char buf[80];
-	progress->prefix = prefix;
-	progress->total = total;
-	progress->last_percent = -1;
-	progress->delay = 0;
-	progress->need_lf = 0;
-	if (snprintf(buf, sizeof(buf), title, total))
-		fprintf(stderr, "%s\n", buf);
-	set_progress_signal();
+	return display(progress, n, 0);
 }
 
 void start_progress_delay(struct progress *progress, const char *title,
-			  const char *prefix, unsigned total,
-			  unsigned percent_treshold, unsigned delay)
+			  unsigned total, unsigned percent_treshold, unsigned delay)
 {
-	progress->prefix = prefix;
+	progress->title = title;
 	progress->total = total;
+	progress->last_value = -1;
 	progress->last_percent = -1;
 	progress->delayed_percent_treshold = percent_treshold;
-	progress->delayed_title = title;
 	progress->delay = delay;
-	progress->need_lf = 0;
 	set_progress_signal();
 }
 
+void start_progress(struct progress *progress, const char *title, unsigned total)
+{
+	start_progress_delay(progress, title, total, 0, 0);
+}
+
 void stop_progress(struct progress *progress)
 {
+	if (progress->last_value != -1) {
+		/* Force the last update */
+		progress_update = 1;
+		display(progress, progress->last_value, 1);
+	}
 	clear_progress_signal();
-	if (progress->need_lf)
-		fputc('\n', stderr);
 }

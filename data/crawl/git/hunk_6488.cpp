 		cache.track_flags = track_flags;
 		cache.prefix_len_stat_func = prefix_len_stat_func;
 		match_len = last_slash = 0;
+		cache_switches++;
+		if (cache_switches > SWITCHES_BEFORE_WARNING) {
+			if (number_of_warnings < 10 || number_of_warnings % 1000 == 0)
+				printf("warning from %s:%d cache_switches:%u > %u "\
+				       "(current:%u last:%u total:%u)\n",
+				       __FILE__, __LINE__,
+				       cache_switches, SWITCHES_BEFORE_WARNING,
+				       current_cache_func, last_cache_func,
+				       total_calls);
+			number_of_warnings++;
+		}
 	} else {
 		/*
 		 * Check to see if we have a match from the cache for

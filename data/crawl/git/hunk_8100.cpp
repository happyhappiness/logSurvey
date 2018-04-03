 		cache_max_small_delta_size = git_config_int(k, v);
 		return 0;
 	}
+	if (!strcmp(k, "pack.threads")) {
+		delta_search_threads = git_config_int(k, v);
+		if (delta_search_threads < 1)
+			die("invalid number of threads specified (%d)",
+			    delta_search_threads);
+#ifndef THREADED_DELTA_SEARCH
+		if (delta_search_threads > 1)
+			warning("no threads support, ignoring %s", k);
+#endif
+		return 0;
+	}
 	return git_default_config(k, v);
 }
 
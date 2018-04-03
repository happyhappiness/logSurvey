 	else if (num_threads < 0)
 		die(_("invalid number of threads specified (%d)"), num_threads);
 #else
+	if (num_threads)
+		warning(_("no threads support, ignoring --threads"));
 	num_threads = 0;
 #endif
 

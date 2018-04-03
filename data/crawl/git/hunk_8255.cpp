 		shown = 1;
 	}
 	opt->loginfo = NULL;
+	maybe_flush_or_die(stdout, "stdout");
 	return shown;
 }

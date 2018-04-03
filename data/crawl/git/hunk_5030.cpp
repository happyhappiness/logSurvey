 		}
 		strbuf_trim(&line);
 		rawargs = strbuf_detach(&line, NULL);
-		if (split_cmdline(rawargs, &argv) == -1) {
+		split_args = xstrdup(rawargs);
+		count = split_cmdline(split_args, &argv);
+		if (count < 0) {
+			fprintf(stderr, "invalid command format '%s': %s\n", rawargs,
+				split_cmdline_strerror(count));
+			free(split_args);
 			free(rawargs);
 			continue;
 		}

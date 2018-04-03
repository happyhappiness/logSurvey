 		die("unrecognized command '%s'", argv[2]);
 	} else {
 		free(prog);
-		die("invalid command format '%s'", argv[2]);
+		die("invalid command format '%s': %s", argv[2],
+		    split_cmdline_strerror(count));
 	}
 }
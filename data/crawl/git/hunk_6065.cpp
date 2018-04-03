 			fprintf(stderr, "Server supports side-band\n");
 		use_sideband = 1;
 	}
+	if (server_supports("ofs-delta")) {
+		if (args.verbose)
+			fprintf(stderr, "Server supports ofs-delta\n");
+	} else
+		prefer_ofs_delta = 0;
 	if (everything_local(&ref, nr_match, match)) {
 		packet_flush(fd[1]);
 		goto all_done;

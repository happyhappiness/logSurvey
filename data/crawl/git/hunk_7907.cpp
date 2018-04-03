 
 	if (finish_command(&cmd))
 		die("%s failed", argv[0]);
+	if (use_sideband && finish_async(&demux))
+		die("error in sideband demultiplexer");
 	return 0;
 }
 
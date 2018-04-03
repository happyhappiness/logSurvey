 		deepen_not_ok = 1;
 	else if (args->deepen_not)
 		die(_("Server does not support --shallow-exclude"));
+	if (!server_supports("deepen-relative") && args->deepen_relative)
+		die(_("Server does not support --deepen"));
 
 	if (everything_local(args, &ref, sought, nr_sought)) {
 		packet_flush(fd[1]);

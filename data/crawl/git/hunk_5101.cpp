 	int exit_code;
 
 	if (!remote)
-		die("Where do you want to fetch from today?");
+		die("No remote repository specified.  Please, specify either a URL or a\n"
+		    "remote name from which new revisions should be fetched.");
 
 	transport = transport_get(remote, NULL);
 	transport_set_verbosity(transport, verbosity, progress);

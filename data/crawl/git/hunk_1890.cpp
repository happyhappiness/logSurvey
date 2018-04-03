 		die(_("No remote repository specified.  Please, specify either a URL or a\n"
 		    "remote name from which new revisions should be fetched."));
 
-	gtransport = prepare_transport(remote);
+	gtransport = prepare_transport(remote, 1);
 
 	if (prune < 0) {
 		/* no command line request */

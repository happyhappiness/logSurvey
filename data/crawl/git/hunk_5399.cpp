 		die("Where do you want to fetch from today?");
 
 	transport = transport_get(remote, NULL);
-	transport_set_verbosity(transport, verbosity, 0);
+	transport_set_verbosity(transport, verbosity, progress);
 	if (upload_pack)
 		set_option(TRANS_OPT_UPLOADPACK, upload_pack);
 	if (keep)

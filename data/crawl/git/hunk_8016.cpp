 	if (quiet)
 		transport->verbose = 0;
 	if (upload_pack)
-		transport_set_option(transport, TRANS_OPT_UPLOADPACK, upload_pack);
+		set_option(TRANS_OPT_UPLOADPACK, upload_pack);
 	if (keep)
-		transport_set_option(transport, TRANS_OPT_KEEP, "yes");
-	transport_set_option(transport, TRANS_OPT_DEPTH, depth);
+		set_option(TRANS_OPT_KEEP, "yes");
+	if (depth)
+		set_option(TRANS_OPT_DEPTH, depth);
 
 	if (!transport->url)
 		die("Where do you want to fetch from today?");

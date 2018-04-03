 	if (depth)
 		set_option(TRANS_OPT_DEPTH, depth);
 
-	if (!transport->url)
-		die("Where do you want to fetch from today?");
-
 	if (argc > 1) {
 		int j = 0;
 		refs = xcalloc(argc + 1, sizeof(const char *));

 	is_local = option_local != 0 && path && !is_bundle;
 	if (is_local && option_depth)
 		warning(_("--depth is ignored in local clones; use file:// instead."));
+	if (option_local > 0 && !is_local)
+		warning(_("--local is ignored"));
 
 	if (argc == 2)
 		dir = xstrdup(argv[1]);

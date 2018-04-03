 	if (reduce && (show_all || octopus))
 		die("--independent cannot be used with other options");
 
-	if (octopus || reduce)
-		return handle_octopus(argc, argv, reduce, show_all);
+	if (octopus)
+		return handle_octopus(argc, argv, show_all);
+	else if (reduce)
+		return handle_independent(argc, argv);
 
 	rev = xmalloc(argc * sizeof(*rev));
 	while (argc-- > 0)
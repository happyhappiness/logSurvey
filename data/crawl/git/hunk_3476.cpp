 	if (!argc)
 		return 0;
 
-	if (!strcmp(argv[0], "--"))	/* case (2) */
-		return 1;
-
 	arg = argv[0];
-	has_dash_dash = (argc > 1) && !strcmp(argv[1], "--");
+	dash_dash_pos = -1;
+	for (i = 0; i < argc; i++) {
+		if (!strcmp(argv[i], "--")) {
+			dash_dash_pos = i;
+			break;
+		}
+	}
+	if (dash_dash_pos == 0)
+		return 1; /* case (2) */
+	else if (dash_dash_pos == 1)
+		has_dash_dash = 1; /* case (3) or (1) */
+	else if (dash_dash_pos >= 2)
+		die(_("only one reference expected, %d given."), dash_dash_pos);
 
 	if (!strcmp(arg, "-"))
 		arg = "@{-1}";

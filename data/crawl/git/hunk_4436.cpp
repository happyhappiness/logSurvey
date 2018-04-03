 		;
 
 	if (i + 2 >= max_length)
-		die("Too many options specified");
+		die(_("Too many options specified"));
 	cmd[i++] = opt;
 	cmd[i] = NULL;
 }

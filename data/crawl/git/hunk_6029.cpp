 	if (*ep == ',')
 		*base = ep + 1;
 	else if (*ep)
-		die("unrecognized reflog param '%s'", arg + 9);
+		die("unrecognized reflog param '%s'", arg);
 	else
 		*base = NULL;
 	if (*cnt <= 0)
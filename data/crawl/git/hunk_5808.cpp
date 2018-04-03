 	}
 
 	if (*cwd && chdir(cwd))
-		die ("Could not change back to '%s'", cwd);
+		die_errno ("Could not change back to '%s'", cwd);
 
 	return buf;
 }

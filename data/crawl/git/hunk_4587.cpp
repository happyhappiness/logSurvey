 		} else if (!strcmp(arg, "-h")) {
 			usage(builtin_log_usage);
 		} else
-			die("unrecognized argument: %s", arg);
+			die(_("unrecognized argument: %s"), arg);
 	}
 
 	/*

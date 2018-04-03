 		}
 
 		if (stat(arg, &argstat) == -1) {
-			error("cannot stat %s (%s)", arg, strerror(errno));
+			error_errno("cannot stat %s", arg);
 			return 1;
 		}
 
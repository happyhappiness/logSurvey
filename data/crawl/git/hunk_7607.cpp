 		int recno;
 
 		if (!spec) {
-			status |= error("Not a reflog: %s", ref);
+			status |= error("Not a reflog: %s", argv[i]);
 			continue;
 		}
 
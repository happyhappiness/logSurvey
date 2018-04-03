 
 	n = cmit->util;
 	if (n) {
-		printf("%s\n", n->path);
+		if (!longformat)
+			printf("%s\n", n->path);
+		else
+			printf("%s-0-g%s\n", n->path,
+				find_unique_abbrev(cmit->object.sha1, abbrev));
 		return;
 	}
 

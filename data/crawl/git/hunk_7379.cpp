 
 	n = cmit->util;
 	if (n) {
-		printf("%s\n", n->path);
+		display_name(n);
+		printf("\n");
 		return;
 	}
 

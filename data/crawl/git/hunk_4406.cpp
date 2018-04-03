 		if (*p == '\n')
 			p++;
 	}
-	die ("No author information found in %s",
+	die (_("No author information found in %s"),
 			sha1_to_hex(commit->object.sha1));
 }
 

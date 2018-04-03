 	    groups[n] = group;
 	groups[n] = NULL;
 
+        if (NULL == username) {
+            warn("Invalid Request\n");
+            goto error;
+        }
+
 	if (Valid_Groups(username, groups)) {
 	    printf ("OK\n");
 	} else {
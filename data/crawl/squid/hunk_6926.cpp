 	}
     }
 
-    if (root == NULL){
+    if (root == NULL) {
 	fprintf(stderr, "Mib not initialized.  Exiting.\n");
 	exit(1);
     }
     if ((*out_len =
-	 parse_subtree(root, input, output, out_len)) == 0)
+	    parse_subtree(root, input, output, out_len)) == 0)
 	return (0);
     *out_len += output - op;
 

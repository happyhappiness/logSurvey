 	else
 	    print_error("Warning: This entry is pretty silly", np->label, type);
     } else {
-	print_error("No end to oid", (char *)NULL, type);
+	print_error("No end to oid", (char *) NULL, type);
 	free_node(np);
 	np = 0;
     }
     /* free oid array */
-    for(count = 0; count < length; count++){
+    for (count = 0; count < length; count++) {
 	if (SubOid[count].label)
 	    xfree(SubOid[count].label);
 	SubOid[count].label = 0;

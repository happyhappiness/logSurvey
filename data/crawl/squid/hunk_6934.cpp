     print_subtree(tp, 0);
 #endif /* TEST */
     /* If any nodes are left, the tree is probably inconsistent */
-    for(bucket = 0; bucket < NHASHSIZE; bucket++){
-        if (nbuckets[bucket]){
+    for (bucket = 0; bucket < NHASHSIZE; bucket++) {
+	if (nbuckets[bucket]) {
 	    nodes_left = 1;
 	    break;
 	}
     }
-    if (nodes_left){
+    if (nodes_left) {
 	fprintf(stderr, "The mib description doesn't seem to be consistent.\n");
 	fprintf(stderr, "Some nodes couldn't be linked under the \"iso\" tree.\n");
 	fprintf(stderr, "these nodes are left:\n");
-	for(bucket = 0; bucket < NHASHSIZE; bucket++){
-	    for(np = nbuckets[bucket]; np; np = np->next)
-	        fprintf(stderr, "%s ::= { %s %ld } (%d)\n", np->label,
-			np->parent, np->subid, np->type);
+	for (bucket = 0; bucket < NHASHSIZE; bucket++) {
+	    for (np = nbuckets[bucket]; np; np = np->next)
+		fprintf(stderr, "%s ::= { %s %ld } (%d)\n", np->label,
+		    np->parent, np->subid, np->type);
 	}
     }
     return tp;

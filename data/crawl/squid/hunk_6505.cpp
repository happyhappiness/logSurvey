 		    return NULL;
 	    }
 	} else {
-	    print_error("Missing end of oid", (char *)NULL, type);
-	    free_node(np);   /* the last node allocated wasn't used */
+	    print_error("Missing end of oid", (char *) NULL, type);
+	    free_node(np);	/* the last node allocated wasn't used */
 	    if (oldnp)
 		oldnp->next = NULL;
 	    return NULL;
 	}
 	/* free the oid array */
-	for(count = 0, op = SubOid; count < length; count++, op++){
+	for (count = 0, op = SubOid; count < length; count++, op++) {
 	    if (op->label)
 		xfree(op->label);
 	    op->label = 0;
 	}
 	return root;
     } else {
-	print_error("Bad object identifier", (char *)NULL, type);
+	print_error("Bad object identifier", (char *) NULL, type);
 	return 0;
     }
 }

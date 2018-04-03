 
 void
 print_value(objid, objidlen, variable)
-    oid     *objid;
-    int	    objidlen;
-    struct  variable_list *variable;
+     oid *objid;
+     int objidlen;
+     struct variable_list *variable;
 {
-    char    tempbuf[2048];
+    char tempbuf[2048];
 
     sprint_value(tempbuf, objid, objidlen, variable);
     printf("%s\n", tempbuf);
 }
 
 static struct tree *
 get_symbol(objid, objidlen, subtree, buf)
-    oid	    *objid;
-    int	    objidlen;
-    struct tree    *subtree;
-    char    *buf;
+     oid *objid;
+     int objidlen;
+     struct tree *subtree;
+     char *buf;
 {
-    struct tree    *return_tree = NULL;
+    struct tree *return_tree = NULL;
 
-    for(; subtree; subtree = subtree->next_peer){
-	if (*objid == subtree->subid){
+    for (; subtree; subtree = subtree->next_peer) {
+	if (*objid == subtree->subid) {
 	    strcpy(buf, subtree->label);
 	    goto found;
 	}
     }
 
     /* subtree not found */
-    while(objidlen--){	/* output rest of name, uninterpreted */
+    while (objidlen--) {	/* output rest of name, uninterpreted */
 	sprintf(buf, "%lu.", *objid++);
-	while(*buf)
+	while (*buf)
 	    buf++;
     }
-    *(buf - 1) = '\0'; /* remove trailing dot */
+    *(buf - 1) = '\0';		/* remove trailing dot */
     return NULL;
 
-found:
-    if (objidlen > 1){
-	while(*buf)
+  found:
+    if (objidlen > 1) {
+	while (*buf)
 	    buf++;
 	*buf++ = '.';
 	*buf = '\0';
 	return_tree = get_symbol(objid + 1, objidlen - 1, subtree->child_list,
-				 buf);
-    } 
+	    buf);
+    }
     if (return_tree != NULL)
 	return return_tree;
     else

  */
 static struct tree *
 get_tree(objid, objidlen, subtree)
-    oid     *objid;
-    int     objidlen;
-    struct tree    *subtree;
+     oid *objid;
+     int objidlen;
+     struct tree *subtree;
 {
-    struct tree    *return_tree = NULL;
+    struct tree *return_tree = NULL;
 
-    for(; subtree; subtree = subtree->next_peer){
-        if (*objid == subtree->subid)
-            goto found;
+    for (; subtree; subtree = subtree->next_peer) {
+	if (*objid == subtree->subid)
+	    goto found;
     }
 
     return NULL;
 
-found:
+  found:
     if (objidlen > 1)
-        return_tree = get_tree(objid + 1, objidlen - 1, subtree->child_list);
+	return_tree = get_tree(objid + 1, objidlen - 1, subtree->child_list);
     if (return_tree != NULL)
-        return return_tree;
+	return return_tree;
     else
-        return subtree;
+	return subtree;
 }
 
 
 #if 0
 static char *
 get_description(objid, objidlen)
-    oid     *objid;
-    int     objidlen;   /* number of subidentifiers */
+     oid *objid;
+     int objidlen;		/* number of subidentifiers */
 {
-    struct tree    *subtree = Mib;
+    struct tree *subtree = Mib;
 
     subtree = get_tree(objid, objidlen, subtree);
     if (subtree)
-        return (subtree->description);
+	return (subtree->description);
     else
-        return NULL;
+	return NULL;
 }
 #endif
 
 
 #if 0
 static void
 print_description(objid, objidlen)
-    oid     *objid;
-    int     objidlen;   /* number of subidentifiers */
+     oid *objid;
+     int objidlen;		/* number of subidentifiers */
 {
     char *desc = get_description(objid, objidlen);
 
     if (desc && desc[0] != '\0')
-        printf("Description: \"%s\"\n", desc);
+	printf("Description: \"%s\"\n", desc);
     else
-        printf("No description\n");
+	printf("No description\n");
 }
 #endif
 
 
 static struct tree *
 find_node(name, subtree)
-    char *name;
-    struct tree *subtree;
+     char *name;
+     struct tree *subtree;
 {
     struct tree *tp, *ret;
 
-    for(tp = subtree; tp; tp = tp->next_peer){
+    for (tp = subtree; tp; tp = tp->next_peer) {
 	if (!strcasecmp(name, tp->label))
 	    return tp;
 	ret = find_node(name, tp->child_list);

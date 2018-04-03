 
 void
 print_objid(objid, objidlen)
-    oid	    *objid;
-    int	    objidlen;	/* number of subidentifiers */
+     oid *objid;
+     int objidlen;		/* number of subidentifiers */
 {
-    char    buf[256];
+    char buf[256];
 
     sprint_objid(buf, objid, objidlen);
     printf("%s\n", buf);

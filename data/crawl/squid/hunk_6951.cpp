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
 	if (oid[count].label)
 	    free(oid[count].label);
 	oid[count].label = 0;
     }
     return np;
 }
 
-int parse_mib_header(fp, name)
-    FILE *fp;
-    char *name;
+int 
+parse_mib_header(fp, name)
+     FILE *fp;
+     char *name;
 {
     int type = DEFINITIONS;
     char token[MAXTOKEN];
-    
+
     /* This probably isn't good enough.  If there is no
-       imports clause we can't go around waiting (forever) for a semicolon.
-       We need to check for semi following an EXPORTS clause or an IMPORTS
-       clause of both.  Look for BEGIN; in my initial MIBs to see those
-       that I needed to hack to get to parse because they didn't have
-       an IMPORTS or and EXPORTS clause.
-       */
-    while(type != SEMI && type != ENDOFFILE){
+     * imports clause we can't go around waiting (forever) for a semicolon.
+     * We need to check for semi following an EXPORTS clause or an IMPORTS
+     * clause of both.  Look for BEGIN; in my initial MIBs to see those
+     * that I needed to hack to get to parse because they didn't have
+     * an IMPORTS or and EXPORTS clause.
+     */
+    while (type != SEMI && type != ENDOFFILE) {
 	type = get_token(fp, token);
     }
     return (type == SEMI);

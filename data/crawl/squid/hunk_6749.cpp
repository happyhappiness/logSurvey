  * Returns NULL on error.
  */
 static int
-getoid(FILE * fp, struct subid *oid, int length)
+getoid(fp, SubOid,  length)
+    register FILE *fp;
+    register struct subid *SubOid;	/* an array of subids */
+    int length;	    /* the length of the array */
 {
-    int count;
+    register int count;
     int type;
-    char token[MAXTOKEN];
-    char *cp;
+    char token[128];
+    register char *cp;
 
-    if ((type = get_token(fp, token)) != LEFTBRACKET) {
+    if ((type = get_token(fp, token)) != LEFTBRACKET){
 	print_error("Expected \"{\"", token, type);
 	return 0;
     }
     type = get_token(fp, token);
-    for (count = 0; count < length; count++, oid++) {
-	oid->label = 0;
-	oid->subid = -1;
-	if (type == RIGHTBRACKET) {
+    for(count = 0; count < length; count++, SubOid++){
+	SubOid->label = 0;
+	SubOid->subid = -1;
+	if (type == RIGHTBRACKET){
 	    return count;
-	} else if (type != LABEL && type != NUMBER) {
+	} else if (type != LABEL && type != NUMBER){
 	    print_error("Not valid for object identifier", token, type);
 	    return 0;
 	}
-	if (type == LABEL) {
+	if (type == LABEL){
 	    /* this entry has a label */
-	    cp = (char *) Malloc((unsigned) strlen(token) + 1);
+	    cp = (char *)xmalloc((unsigned)strlen(token) + 1);
 	    strcpy(cp, token);
-	    oid->label = cp;
+	    SubOid->label = cp;
 	    type = get_token(fp, token);
-	    if (type == LEFTPAREN) {
+	    if (type == LEFTPAREN){
 		type = get_token(fp, token);
-		if (type == NUMBER) {
-		    oid->subid = atoi(token);
-		    if ((type = get_token(fp, token)) != RIGHTPAREN) {
+		if (type == NUMBER){
+		    SubOid->subid = atoi(token);
+		    if ((type = get_token(fp, token)) != RIGHTPAREN){
 			print_error("Unexpected a closing parenthesis", token, type);
 			return 0;
 		    }

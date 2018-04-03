  * Returns NULL on error.
  */
 static int
-getoid(fp, SubOid,  length)
-    register FILE *fp;
-    register struct subid *SubOid;	/* an array of subids */
-    int length;	    /* the length of the array */
+getoid(fp, SubOid, length)
+     register FILE *fp;
+     register struct subid *SubOid;	/* an array of subids */
+     int length;		/* the length of the array */
 {
     register int count;
     int type;
     char token[128];
     register char *cp;
 
-    if ((type = get_token(fp, token)) != LEFTBRACKET){
+    if ((type = get_token(fp, token)) != LEFTBRACKET) {
 	print_error("Expected \"{\"", token, type);
 	return 0;
     }
     type = get_token(fp, token);
-    for(count = 0; count < length; count++, SubOid++){
+    for (count = 0; count < length; count++, SubOid++) {
 	SubOid->label = 0;
 	SubOid->subid = -1;
-	if (type == RIGHTBRACKET){
+	if (type == RIGHTBRACKET) {
 	    return count;
-	} else if (type != LABEL && type != NUMBER){
+	} else if (type != LABEL && type != NUMBER) {
 	    print_error("Not valid for object identifier", token, type);
 	    return 0;
 	}
-	if (type == LABEL){
+	if (type == LABEL) {
 	    /* this entry has a label */
-	    cp = (char *)xmalloc((unsigned)strlen(token) + 1);
+	    cp = (char *) xmalloc((unsigned) strlen(token) + 1);
 	    strcpy(cp, token);
 	    SubOid->label = cp;
 	    type = get_token(fp, token);
-	    if (type == LEFTPAREN){
+	    if (type == LEFTPAREN) {
 		type = get_token(fp, token);
-		if (type == NUMBER){
+		if (type == NUMBER) {
 		    SubOid->subid = atoi(token);
-		    if ((type = get_token(fp, token)) != RIGHTPAREN){
+		    if ((type = get_token(fp, token)) != RIGHTPAREN) {
 			print_error("Unexpected a closing parenthesis", token, type);
 			return 0;
 		    }

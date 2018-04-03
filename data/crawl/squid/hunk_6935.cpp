  * Returns NULL on error.
  */
 static int
-getoid(fp, oid,  length)
-    FILE *fp;
-    struct subid *oid;	/* an array of subids */
-    int length;	    /* the length of the array */
+getoid(fp, oid, length)
+     FILE *fp;
+     struct subid *oid;		/* an array of subids */
+     int length;		/* the length of the array */
 {
     int count;
     int type;
     char token[MAXTOKEN];
     char *cp;
 
-    if ((type = get_token(fp, token)) != LEFTBRACKET){
+    if ((type = get_token(fp, token)) != LEFTBRACKET) {
 	print_error("Expected \"{\"", token, type);
 	return 0;
     }
     type = get_token(fp, token);
-    for(count = 0; count < length; count++, oid++){
+    for (count = 0; count < length; count++, oid++) {
 	oid->label = 0;
 	oid->subid = -1;
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
-	    cp = (char *)Malloc((unsigned)strlen(token) + 1);
+	    cp = (char *) Malloc((unsigned) strlen(token) + 1);
 	    strcpy(cp, token);
 	    oid->label = cp;
 	    type = get_token(fp, token);
-	    if (type == LEFTPAREN){
+	    if (type == LEFTPAREN) {
 		type = get_token(fp, token);
-		if (type == NUMBER){
+		if (type == NUMBER) {
 		    oid->subid = atoi(token);
-		    if ((type = get_token(fp, token)) != RIGHTPAREN){
+		    if ((type = get_token(fp, token)) != RIGHTPAREN) {
 			print_error("Unexpected a closing parenthesis", token, type);
 			return 0;
 		    }

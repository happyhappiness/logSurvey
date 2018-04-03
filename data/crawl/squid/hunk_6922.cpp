 #ifdef UNUSED
 int
 read_rawobjid(input, output, out_len)
-    char *input;
-    oid *output;
-    int	*out_len;
+     char *input;
+     oid *output;
+     int *out_len;
 {
-    char    buf[12], *cp;
-    oid	    *op = output;
-    u_long  subid;
+    char buf[12], *cp;
+    oid *op = output;
+    u_long subid;
 
-    while(*input != '\0'){
+    while (*input != '\0') {
 	if (!isdigit(*input))
 	    break;
 	cp = buf;
-	while(isdigit(*input))
+	while (isdigit(*input))
 	    *cp++ = *input++;
 	*cp = '\0';
 	subid = atoi(buf);
-	if(subid > MAX_SUBID){
+	if (subid > MAX_SUBID) {
 	    fprintf(stderr, "sub-identifier too large: %s\n", buf);
 	    return 0;
 	}
-	if((*out_len)-- <= 0){
+	if ((*out_len)-- <= 0) {
 	    fprintf(stderr, "object identifier too long\n");
 	    return 0;
 	}
 	*op++ = subid;
-	if(*input++ != '.')
+	if (*input++ != '.')
 	    break;
     }
     *out_len = op - output;

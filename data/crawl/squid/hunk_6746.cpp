     }
     return root;
 }
-#endif
 
-int
-read_objid(input, output, out_len)
-     char *input;
-     oid *output;
-     int *out_len;		/* number of subid's in "output" */
-{
-    struct tree *root = Mib;
-    oid *op = output;
-    char buf[512];
-
-    memset(buf, '\0', sizeof(buf));
-
-    if (*input == '.')
-	input++;
-    else {
-	strcpy(buf, Prefix);
-	strcat(buf, input);
-	input = buf;
-    }
-
-    if (root == NULL) {
-	fprintf(stderr, "Mib not initialized.  Exiting.\n");
-	exit(1);
-    }
-    if ((*out_len =
-	    parse_subtree(root, input, output, out_len)) == 0)
-	return (0);
-    *out_len += output - op;
-
-    return (1);
-}
-
-#ifdef notdef
-int
-read_objid(input, output, out_len)
-     char *input;
-     oid *output;
-     int *out_len;		/* number of subid's in "output" */
+static int
+lc_cmp(s1, s2)
+    char *s1, *s2;
 {
-    struct tree *root = Mib;
-    oid *op = output;
-    int i;
-
-    if (*input == '.')
-	input++;
-    else {
-	root = find_rfc1213_mib(root);
-	for (i = 0; i < sizeof(RFC1213_MIB) / sizeof(oid); i++) {
-	    if ((*out_len)-- > 0)
-		*output++ = RFC1213_MIB[i];
-	    else {
-		fprintf(stderr, "object identifier too long\n");
-		return (0);
-	    }
-	}
-    }
+    char c1, c2;
 
-    if (root == NULL) {
-	fprintf(stderr, "Mib not initialized.  Exiting.\n");
-	exit(1);
+    while(*s1 && *s2){
+	if (isupper(*s1))
+	    c1 = tolower(*s1);
+	else
+	    c1 = *s1;
+	if (isupper(*s2))
+	    c2 = tolower(*s2);
+	else
+	    c2 = *s2;
+	if (c1 != c2)
+	    return ((c1 - c2) > 0 ? 1 : -1);
+	s1++;
+	s2++;
     }
-    if ((*out_len =
-	    parse_subtree(root, input, output, out_len)) == 0)
-	return (0);
-    *out_len += output - op;
 
-    return (1);
+    if (*s1)
+	return -1;
+    if (*s2)
+	return 1;
+    return 0;
 }
-#endif
 
 static int
 parse_subtree(subtree, input, output, out_len)
-     struct tree *subtree;
-     char *input;
-     oid *output;
-     int *out_len;		/* number of subid's */
+    struct snmp_mib_tree *subtree;
+    char *input;
+    oid	*output;
+    int	*out_len;   /* number of subid's */
 {
     char buf[128], *to = buf;
-    u_long subid = 0;
-    struct tree *tp;
+    u_int subid = 0;
+    struct snmp_mib_tree *tp;
 
     /*
      * No empty strings.  Can happen if there is a trailing '.' or two '.'s

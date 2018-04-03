     struct enum_list *ep = 0;
 
     type = get_token(fp, token);
-    if (type != SYNTAX){
+    if (type != SYNTAX) {
 	print_error("Bad format for OBJECT TYPE", token, type);
 	return 0;
     }
-    np = (struct node *)Malloc(sizeof(struct node));
+    np = (struct node *) Malloc(sizeof(struct node));
     np->next = 0;
     np->enums = 0;
-    np->description = NULL;        /* default to an empty description */
+    np->description = NULL;	/* default to an empty description */
     type = get_token(fp, token);
-    if (type == LABEL){
+    if (type == LABEL) {
 	tctype = get_tc(token, &(np->enums));
 #if 0
-	if (tctype == LABEL){
+	if (tctype == LABEL) {
 	    print_error("No known translation for type", token, type);
 	    return 0;
 	}

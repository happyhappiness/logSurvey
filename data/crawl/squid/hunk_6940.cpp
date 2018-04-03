 		    ep->next = 0;
 		    /* a reasonable approximation for the length */
 		    ep->label =
-			(char *)Malloc((unsigned)strlen(token) + 1);
+			(char *) Malloc((unsigned) strlen(token) + 1);
 		    strcpy(ep->label, token);
 		    type = get_token(fp, token);
-		    if (type != LEFTPAREN){
+		    if (type != LEFTPAREN) {
 			print_error("Expected \"(\"", token, type);
 			/* free_node(np); */
 			return 0;
 		    }
 		    type = get_token(fp, token);
-		    if (type != NUMBER){
+		    if (type != NUMBER) {
 			print_error("Expected integer", token, type);
 			/* free_node(np); */
 			return 0;
 		    }
 		    ep->value = atoi(token);
 		    type = get_token(fp, token);
-		    if (type != RIGHTPAREN){
+		    if (type != RIGHTPAREN) {
 			print_error("Expected \")\"", token, type);
 			/* free_node(np); */
 			return 0;
 		    }
 		}
 	    }
-	    if (type == ENDOFFILE){
+	    if (type == ENDOFFILE) {
 		print_error("Expected \"}\"", token, type);
 		/* free_node(np); */
 		return 0;

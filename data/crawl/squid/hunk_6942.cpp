     }
     np->type = type;
     nexttype = get_token(fp, nexttoken);
-    switch(type){
-	case SEQUENCE:
-	    strcpy(syntax, token);
-	    if (nexttype == OF){
-		strcat(syntax, " ");
-		strcat(syntax, nexttoken);
-		nexttype = get_token(fp, nexttoken);
-		strcat(syntax, " ");
-		strcat(syntax, nexttoken);
-		nexttype = get_token(fp, nexttoken);
-	    }
-	    break;
-	case INTEGER:
-	case UINTEGER32:
-	    strcpy(syntax, token);
-	    if (nexttype == LEFTBRACKET) {
-		/* if there is an enumeration list, parse it */
-		while((type = get_token(fp, token)) != ENDOFFILE){
-		    if (type == RIGHTBRACKET)
-			break;
-		    if (type == LABEL){
-			/* this is an enumerated label */
-			if (np->enums == 0){
-			    ep = np->enums = (struct enum_list *)
-					Malloc(sizeof(struct enum_list));
-			} else {
-			    ep->next = (struct enum_list *)
-					Malloc(sizeof(struct enum_list));
-			    ep = ep->next;
-			}
-			ep->next = 0;
-			/* a reasonable approximation for the length */
-			ep->label =
-			    (char *)Malloc((unsigned)strlen(token) + 1);
-			strcpy(ep->label, token);
-			type = get_token(fp, token);
-			if (type != LEFTPAREN){
-			    print_error("Expected \"(\"", token, type);
-			    free_node(np);
-			    return 0;
-			}
-			type = get_token(fp, token);
-			if (type != NUMBER){
-			    print_error("Expected integer", token, type);
-			    free_node(np);
-			    return 0;
-			}
-			ep->value = atoi(token);
-			type = get_token(fp, token);
-			if (type != RIGHTPAREN){
-			    print_error("Expected \")\"", token, type);
-			    free_node(np);
-			    return 0;
-			}
+    switch (type) {
+    case SEQUENCE:
+	strcpy(syntax, token);
+	if (nexttype == OF) {
+	    strcat(syntax, " ");
+	    strcat(syntax, nexttoken);
+	    nexttype = get_token(fp, nexttoken);
+	    strcat(syntax, " ");
+	    strcat(syntax, nexttoken);
+	    nexttype = get_token(fp, nexttoken);
+	}
+	break;
+    case INTEGER:
+    case UINTEGER32:
+	strcpy(syntax, token);
+	if (nexttype == LEFTBRACKET) {
+	    /* if there is an enumeration list, parse it */
+	    while ((type = get_token(fp, token)) != ENDOFFILE) {
+		if (type == RIGHTBRACKET)
+		    break;
+		if (type == LABEL) {
+		    /* this is an enumerated label */
+		    if (np->enums == 0) {
+			ep = np->enums = (struct enum_list *)
+			    Malloc(sizeof(struct enum_list));
+		    } else {
+			ep->next = (struct enum_list *)
+			    Malloc(sizeof(struct enum_list));
+			ep = ep->next;
+		    }
+		    ep->next = 0;
+		    /* a reasonable approximation for the length */
+		    ep->label =
+			(char *) Malloc((unsigned) strlen(token) + 1);
+		    strcpy(ep->label, token);
+		    type = get_token(fp, token);
+		    if (type != LEFTPAREN) {
+			print_error("Expected \"(\"", token, type);
+			free_node(np);
+			return 0;
+		    }
+		    type = get_token(fp, token);
+		    if (type != NUMBER) {
+			print_error("Expected integer", token, type);
+			free_node(np);
+			return 0;
+		    }
+		    ep->value = atoi(token);
+		    type = get_token(fp, token);
+		    if (type != RIGHTPAREN) {
+			print_error("Expected \")\"", token, type);
+			free_node(np);
+			return 0;
 		    }
 		}
-		if (type == ENDOFFILE){
-		    print_error("Expected \"}\"", token, type);
-		    free_node(np);
-		    return 0;
+	    }
+	    if (type == ENDOFFILE) {
+		print_error("Expected \"}\"", token, type);
+		free_node(np);
+		return 0;
+	    }
+	    nexttype = get_token(fp, nexttoken);
+	} else if (nexttype == LEFTPAREN) {
+	    /* ignore the "constrained integer" for now */
+	    nexttype = get_token(fp, nexttoken);
+	    nexttype = get_token(fp, nexttoken);
+	    nexttype = get_token(fp, nexttoken);
+	}
+	break;
+    case BITSTRING:
+	strcpy(syntax, token);
+	if (nexttype == LEFTBRACKET) {
+	    /* if there is an enumeration list, parse it */
+	    while ((type = get_token(fp, token)) != ENDOFFILE) {
+		if (type == RIGHTBRACKET)
+		    break;
+		if (type == LABEL) {
+		    /* this is an enumerated label */
+		    if (np->enums == 0) {
+			ep = np->enums = (struct enum_list *)
+			    Malloc(sizeof(struct enum_list));
+		    } else {
+			ep->next = (struct enum_list *)
+			    Malloc(sizeof(struct enum_list));
+			ep = ep->next;
+		    }
+		    ep->next = 0;
+		    /* a reasonable approximation for the length */
+		    ep->label =
+			(char *) Malloc((unsigned) strlen(token) + 1);
+		    strcpy(ep->label, token);
+		    type = get_token(fp, token);
+		    if (type != LEFTPAREN) {
+			print_error("Expected \"(\"", token, type);
+			free_node(np);
+			return 0;
+		    }
+		    type = get_token(fp, token);
+		    if (type != NUMBER) {
+			print_error("Expected integer", token, type);
+			free_node(np);
+			return 0;
+		    }
+		    ep->value = atoi(token);
+		    type = get_token(fp, token);
+		    if (type != RIGHTPAREN) {
+			print_error("Expected \")\"", token, type);
+			free_node(np);
+			return 0;
+		    }
 		}
-		nexttype = get_token(fp, nexttoken);
-	    } else if (nexttype == LEFTPAREN){
-		/* ignore the "constrained integer" for now */
-		nexttype = get_token(fp, nexttoken);
-		nexttype = get_token(fp, nexttoken);
-		nexttype = get_token(fp, nexttoken);
 	    }
-	    break;
-	case BITSTRING:
-	    strcpy(syntax, token);
-	    if (nexttype == LEFTBRACKET) {
-		/* if there is an enumeration list, parse it */
-		while((type = get_token(fp, token)) != ENDOFFILE){
-		    if (type == RIGHTBRACKET)
+	    if (type == ENDOFFILE) {
+		print_error("Expected \"}\"", token, type);
+		free_node(np);
+		return 0;
+	    }
+	    nexttype = get_token(fp, nexttoken);
+	} else if (nexttype == LEFTPAREN) {
+	    /* ignore the "constrained integer" for now */
+	    nexttype = get_token(fp, nexttoken);
+	    nexttype = get_token(fp, nexttoken);
+	    nexttype = get_token(fp, nexttoken);
+	}
+	break;
+    case OCTETSTR:
+	strcpy(syntax, token);
+	/* ignore the "constrained octet string" for now */
+	if (nexttype == LEFTPAREN) {
+	    nexttype = get_token(fp, nexttoken);
+	    if (nexttype == SIZE) {
+		nexttype = get_token(fp, nexttoken);
+		if (nexttype == LEFTPAREN) {
+		    nexttype = get_token(fp, nexttoken);	/* 0..255 */
+		    nexttype = get_token(fp, nexttoken);	/* ) */
+		    nexttype = get_token(fp, nexttoken);	/* ) */
+		    if (nexttype == RIGHTPAREN) {
+			nexttype = get_token(fp, nexttoken);
 			break;
-		    if (type == LABEL){
-			/* this is an enumerated label */
-			if (np->enums == 0){
-			    ep = np->enums = (struct enum_list *)
-					Malloc(sizeof(struct enum_list));
-			} else {
-			    ep->next = (struct enum_list *)
-					Malloc(sizeof(struct enum_list));
-			    ep = ep->next;
-			}
-			ep->next = 0;
-			/* a reasonable approximation for the length */
-			ep->label =
-			    (char *)Malloc((unsigned)strlen(token) + 1);
-			strcpy(ep->label, token);
-			type = get_token(fp, token);
-			if (type != LEFTPAREN){
-			    print_error("Expected \"(\"", token, type);
-			    free_node(np);
-			    return 0;
-			}
-			type = get_token(fp, token);
-			if (type != NUMBER){
-			    print_error("Expected integer", token, type);
-			    free_node(np);
-			    return 0;
-			}
-			ep->value = atoi(token);
-			type = get_token(fp, token);
-			if (type != RIGHTPAREN){
-			    print_error("Expected \")\"", token, type);
-			    free_node(np);
-			    return 0;
-			}
 		    }
 		}
-		if (type == ENDOFFILE){
-		    print_error("Expected \"}\"", token, type);
-		    free_node(np);
-		    return 0;
-		}
-		nexttype = get_token(fp, nexttoken);
-	    } else if (nexttype == LEFTPAREN){
-		/* ignore the "constrained integer" for now */
-		nexttype = get_token(fp, nexttoken);
-		nexttype = get_token(fp, nexttoken);
-		nexttype = get_token(fp, nexttoken);
 	    }
-	    break;
-	case OCTETSTR:
-	    strcpy(syntax, token);
-            /* ignore the "constrained octet string" for now */
-            if (nexttype == LEFTPAREN) {
-                nexttype = get_token(fp, nexttoken);
-                if (nexttype == SIZE) {
-                    nexttype = get_token(fp, nexttoken);
-                    if (nexttype == LEFTPAREN) {
-                        nexttype = get_token(fp, nexttoken); /* 0..255 */
-                        nexttype = get_token(fp, nexttoken); /* ) */
-                        nexttype = get_token(fp, nexttoken); /* ) */
-                        if (nexttype == RIGHTPAREN)
-                        {
-                            nexttype = get_token(fp, nexttoken);
-                            break;
-                        }
-                    }
-                }
-                print_error("Bad syntax", token, type);
-                free_node(np);
-                return 0;
-            }
-	    break;
-	case OBJID:
-	case NETADDR:
-	case IPADDR:
-	case COUNTER:
-	case GAUGE:
-	case TIMETICKS:
-	case OPAQUE:
-	case NUL:
-	case LABEL:
-	case NSAPADDRESS:
-	case COUNTER64:
-	    strcpy(syntax, token);
-	    break;
-	default:
 	    print_error("Bad syntax", token, type);
 	    free_node(np);
 	    return 0;
+	}
+	break;
+    case OBJID:
+    case NETADDR:
+    case IPADDR:
+    case COUNTER:
+    case GAUGE:
+    case TIMETICKS:
+    case OPAQUE:
+    case NUL:
+    case LABEL:
+    case NSAPADDRESS:
+    case COUNTER64:
+	strcpy(syntax, token);
+	break;
+    default:
+	print_error("Bad syntax", token, type);
+	free_node(np);
+	return 0;
     }
-    if (nexttype == UNITS){
+    if (nexttype == UNITS) {
 	type = get_token(fp, token);
 	if (type != QUOTESTRING) {
 	    print_error("Bad DESCRIPTION", token, type);

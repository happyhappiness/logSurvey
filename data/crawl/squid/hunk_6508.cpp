      */
     type = get_token(fp, token);
     if ((type != DESCRIPTION) && (type != INDEX) && (type != EQUALS)) {
-      print_error("Should be DESCRIPTION, INDEX, or EQUALS", token, nexttype);
-      free_node(np);
-      return 0;
-    }
-
-    if (type == DESCRIPTION) {
-
-      type = get_token(fp, token);
-      if (type != QUOTE) {
-	print_error("Should be Description open quote", token, nexttype);
+	print_error("Should be DESCRIPTION, INDEX, or EQUALS", token, nexttype);
 	free_node(np);
 	return 0;
-      }    
-
-      /* Fetch description string */
-      {
-	int   ReadChar;
+    }
+    if (type == DESCRIPTION) {
 
-	ReadChar = last;
-	/* skip everything until closing quote */
-	while((ReadChar != '"') && (ReadChar != -1)) {
-	  ReadChar = getc(fp);
-	  if (ReadChar == '\n')
-	    Line++;
+	type = get_token(fp, token);
+	if (type != QUOTE) {
+	    print_error("Should be Description open quote", token, nexttype);
+	    free_node(np);
+	    return 0;
+	}
+	/* Fetch description string */
+	{
+	    int ReadChar;
+
+	    ReadChar = last;
+	    /* skip everything until closing quote */
+	    while ((ReadChar != '"') && (ReadChar != -1)) {
+		ReadChar = getc(fp);
+		if (ReadChar == '\n')
+		    Line++;
+	    }
+	    last = ' ';
 	}
-	last = ' ';
-      }
-      /* ASSERT:  Done with description. */
-      type = get_token(fp, token);
+	/* ASSERT:  Done with description. */
+	type = get_token(fp, token);
     }
-
     if ((type != INDEX) && (type != EQUALS)) {
-      print_error("Should be INDEX, or EQUALS", token, nexttype);
-      free_node(np);
-      return 0;
-    }
-
-    if (type == INDEX) {
-
-      /* Scarf INDEX */
-
-      type = get_token(fp, token);
-      if (type != LEFTBRACKET){
-	print_error("Should be INDEX left brace", token, type);
+	print_error("Should be INDEX, or EQUALS", token, nexttype);
 	free_node(np);
 	return 0;
-      }
+    }
+    if (type == INDEX) {
 
-      /* Fetch description string */
-      {
-	int   ReadChar;
+	/* Scarf INDEX */
 
-	ReadChar = last;
-	/* skip everything until closing quote */
-	while((ReadChar != '}') && (ReadChar != -1)) {
-	  ReadChar = getc(fp);
-	  if (ReadChar == '\n')
-	    Line++;
+	type = get_token(fp, token);
+	if (type != LEFTBRACKET) {
+	    print_error("Should be INDEX left brace", token, type);
+	    free_node(np);
+	    return 0;
+	}
+	/* Fetch description string */
+	{
+	    int ReadChar;
+
+	    ReadChar = last;
+	    /* skip everything until closing quote */
+	    while ((ReadChar != '}') && (ReadChar != -1)) {
+		ReadChar = getc(fp);
+		if (ReadChar == '\n')
+		    Line++;
+	    }
+	    last = ' ';
 	}
-	last = ' ';
-      }
-      /* ASSERT:  Done with INDEX. */
-      type = get_token(fp, token);
+	/* ASSERT:  Done with INDEX. */
+	type = get_token(fp, token);
     }
-
-    if (type != EQUALS){
+    if (type != EQUALS) {
 	print_error("Bad format", token, type);
 	free_node(np);
 	return 0;
     }
     length = getoid(fp, SubOid, 32);
-    if (length > 1 && length <= 32){
+    if (length > 1 && length <= 32) {
 	/* just take the last pair in the oid list */
 	if (SubOid[length - 2].label)
 	    strncpy(np->parent, SubOid[length - 2].label, 64);

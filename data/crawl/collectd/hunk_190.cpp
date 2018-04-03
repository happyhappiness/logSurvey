 }
 
 #if HAVE_REGEX_H
-static int ignorelist_append_regex(ignorelist_t *il, const char *entry)
+static int ignorelist_append_regex(ignorelist_t *il, const char *re_str)
 {
-	int rcompile;
-	regex_t *regtemp;
-	int errsize;
-	char *regerr = NULL;
-	ignorelist_item_t *new;
+	regex_t *re;
+	ignorelist_item_t *entry;
+	int status;
 
-	/* create buffer */
-	if ((regtemp = malloc(sizeof(regex_t))) == NULL)
+	re = malloc (sizeof (*re));
+	if (re == NULL)
 	{
-		ERROR ("cannot allocate new config entry");
-		return (1);
+		ERROR ("utils_ignorelist: malloc failed");
+		return (ENOMEM);
 	}
-	memset (regtemp, '\0', sizeof(regex_t));
+	memset (re, 0, sizeof (*re));
 
-	/* compile regex */
-	if ((rcompile = regcomp (regtemp, entry, REG_EXTENDED)) != 0)
+	status = regcomp (re, re_str, REG_EXTENDED);
+	if (status != 0)
 	{
-		/* prepare message buffer */
-		errsize = regerror(rcompile, regtemp, NULL, 0);
-		if (errsize)
-			regerr = smalloc(errsize);
-		/* get error message */
-		if (regerror (rcompile, regtemp, regerr, errsize))
-		{
-			fprintf (stderr, "Cannot compile regex %s: %i/%s",
-					entry, rcompile, regerr);
-			ERROR ("Cannot compile regex %s: %i/%s",
-					entry, rcompile, regerr);
-		}
-		else
-		{
-			fprintf (stderr, "Cannot compile regex %s: %i",
-					entry, rcompile);
-			ERROR ("Cannot compile regex %s: %i",
-					entry, rcompile);
-		}
-
-		if (errsize)
-			sfree (regerr);
-		regfree (regtemp);
-		sfree (regtemp);
-		return (1);
+		char errbuf[1024] = "";
+		regerror (status, re, errbuf, sizeof (errbuf));
+		ERROR ("utils_ignorelist: regcomp failed: %s", errbuf);
+		regfree (re);
+		sfree (re);
+		return (status);
 	}
-	DEBUG("regex compiled: %s - %i", entry, rcompile);
 
-	/* create new entry */
-	if ((new = malloc(sizeof(ignorelist_item_t))) == NULL)
+	entry = malloc (sizeof (*entry));
+	if (entry == NULL)
 	{
-		ERROR ("cannot allocate new config entry");
-		regfree (regtemp);
-		sfree (regtemp);
-		return (1);
+		ERROR ("utils_ignorelist: malloc failed");
+		regfree (re);
+		sfree (re);
+		return (ENOMEM);
 	}
-	memset (new, '\0', sizeof(ignorelist_item_t));
-	new->rmatch = regtemp;
-
-	/* append new entry */
-	ignorelist_append (il, new);
+	memset (entry, 0, sizeof (*entry));
+	entry->rmatch = re;
 
+	ignorelist_append (il, entry);
 	return (0);
-} /* int ignorelist_append_regex(ignorelist_t *il, const char *entry) */
+} /* int ignorelist_append_regex */
 #endif
 
 static int ignorelist_append_string(ignorelist_t *il, const char *entry)

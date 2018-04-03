     }
 }
 
-static void
-dump_httpanonymizer(StoreEntry * entry, const char *name, int var)
-{
-    switch (var) {
-    case ANONYMIZER_NONE:
-	storeAppendPrintf(entry, "%s off\n", name);
-	break;
-    case ANONYMIZER_STANDARD:
-	storeAppendPrintf(entry, "%s paranoid\n", name);
-	break;
-    case ANONYMIZER_PARANOID:
-	storeAppendPrintf(entry, "%s standard\n", name);
-	break;
-    }
-}
-
-static void
-parse_httpanonymizer(int *var)
-{
-    char *token;
-    token = strtok(NULL, w_space);
-    if (token == NULL)
-	self_destruct();
-    if (!strcasecmp(token, "off"))
-	*var = ANONYMIZER_NONE;
-    else if (!strcasecmp(token, "paranoid"))
-	*var = ANONYMIZER_PARANOID;
-    else
-	*var = ANONYMIZER_STANDARD;
-}
-
-
 static void
 dump_ushortlist(StoreEntry * entry, const char *name, ushortlist * u)
 {

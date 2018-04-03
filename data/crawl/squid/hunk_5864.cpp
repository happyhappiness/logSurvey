 static void
 storeCossDirParse(SwapDir * sd, int index, char *path)
 {
-    char *token;
     unsigned int i;
     unsigned int size;
-    unsigned int read_only = 0;
     CossInfo *cs;
 
     i = GetInteger();
     size = i << 10;		/* Mbytes to Kbytes */
     if (size <= 0)
 	fatal("storeCossDirParse: invalid size value");
-    if ((token = strtok(NULL, w_space)))
-	if (!strcasecmp(token, "read-only"))
-	    read_only = 1;
 
     cs = xmalloc(sizeof(CossInfo));
     if (cs == NULL)

     if (fp == NULL)
 	return NULL;
     nodes = parse(fp);
-    if (!nodes){
+    if (!nodes) {
 	fprintf(stderr, "Mib table is bad.  Exiting\n");
 	exit(1);
     }

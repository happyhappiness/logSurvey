 	const char *basename = strrchr(name,'/');
 
 	basename = (basename) ? basename + 1 : name;
-	fprintf(stderr, "Usage: %s <", basename);
+	fprintf(stderr, "usage: %s <", basename);
 	while(try_op->name) {
 		fprintf(stderr,"%s",(try_op++)->name);
 		if(try_op->name)

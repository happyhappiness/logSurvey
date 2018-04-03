 	FILE *rpt = fopen(loc, "w");
 	struct branch *b;
 	unsigned long lu;
+	struct recent_command *rc;
 
 	if (!rpt) {
 		error("can't write crash report %s: %s", loc, strerror(errno));

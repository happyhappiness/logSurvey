 	char line[512];
 	FILE *f = fopen(input_file, "r");
 	if (!f)
-		die("cannot read %s: %s", input_file, strerror(errno));
+		die_errno("cannot read '%s'", input_file);
 	while (fgets(line, sizeof(line), f)) {
 		uintmax_t mark;
 		char *end;

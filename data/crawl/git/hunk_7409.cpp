 	return 0;
 }
 
-static int copy_file(const char *src, const char *dest)
-{
-	FILE *in, *out;
-	char buffer[32768];
-	int count;
-
-	if (!(in = fopen(src, "r")))
-		return error("Could not open %s", src);
-	if (!(out = fopen(dest, "w")))
-		return error("Could not open %s", dest);
-	while ((count = fread(buffer, 1, sizeof(buffer), in)))
-		fwrite(buffer, 1, count, out);
-	fclose(in);
-	fclose(out);
-	return 0;
-}
-
 static int do_plain_rerere(struct path_list *rr, int fd)
 {
 	struct path_list conflict = { NULL, 0, 0, 1 };

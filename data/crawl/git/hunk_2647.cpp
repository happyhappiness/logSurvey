 	fprintf(fout, "\n");
 }
 
-static int mailinfo(FILE *in, FILE *out, const char *msg, const char *patch)
+static int mailinfo(struct mailinfo *mi,
+		    FILE *in, FILE *out, const char *msg, const char *patch)
 {
 	int peek;
 	struct strbuf line = STRBUF_INIT;

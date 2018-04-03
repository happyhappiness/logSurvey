 	printf("%s\n", sha1_to_hex(sha1));
 }
 
+static void hash_stdin_paths(const char *type, int write_objects)
+{
+	struct strbuf buf, nbuf;
+
+	strbuf_init(&buf, 0);
+	strbuf_init(&nbuf, 0);
+	while (strbuf_getline(&buf, stdin, '\n') != EOF) {
+		if (buf.buf[0] == '"') {
+			strbuf_reset(&nbuf);
+			if (unquote_c_style(&nbuf, buf.buf, NULL))
+				die("line is badly quoted");
+			strbuf_swap(&buf, &nbuf);
+		}
+		hash_object(buf.buf, type_from_string(type), write_objects);
+	}
+	strbuf_release(&buf);
+	strbuf_release(&nbuf);
+}
+
 static const char hash_object_usage[] =
-"git-hash-object [-t <type>] [-w] [--stdin] <file>...";
+"git-hash-object [ [-t <type>] [-w] [--stdin] <file>... | --stdin-paths < <list-of-paths> ]";
 
 int main(int argc, char **argv)
 {

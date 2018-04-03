 	return refs;
 }
 
+static int fetch_dumb(int nr_heads, struct ref **to_fetch)
+{
+	char **targets = xmalloc(nr_heads * sizeof(char*));
+	int ret, i;
+
+	for (i = 0; i < nr_heads; i++)
+		targets[i] = xstrdup(sha1_to_hex(to_fetch[i]->old_sha1));
+
+	init_walker();
+	walker->get_all = 1;
+	walker->get_tree = 1;
+	walker->get_history = 1;
+	walker->get_verbosely = 0;
+	walker->get_recover = 0;
+	ret = walker_fetch(walker, nr_heads, targets, NULL, NULL);
+
+	for (i = 0; i < nr_heads; i++)
+		free(targets[i]);
+	free(targets);
+
+	return ret ? error("Fetch failed.") : 0;
+}
+
+static void parse_fetch(struct strbuf *buf)
+{
+	struct ref **to_fetch = NULL;
+	struct ref *list_head = NULL;
+	struct ref **list = &list_head;
+	int alloc_heads = 0, nr_heads = 0;
+
+	do {
+		if (!prefixcmp(buf->buf, "fetch ")) {
+			char *p = buf->buf + strlen("fetch ");
+			char *name;
+			struct ref *ref;
+			unsigned char old_sha1[20];
+
+			if (strlen(p) < 40 || get_sha1_hex(p, old_sha1))
+				die("protocol error: expected sha/ref, got %s'", p);
+			if (p[40] == ' ')
+				name = p + 41;
+			else if (!p[40])
+				name = "";
+			else
+				die("protocol error: expected sha/ref, got %s'", p);
+
+			ref = alloc_ref(name);
+			hashcpy(ref->old_sha1, old_sha1);
+
+			*list = ref;
+			list = &ref->next;
+
+			ALLOC_GROW(to_fetch, nr_heads + 1, alloc_heads);
+			to_fetch[nr_heads++] = ref;
+		}
+		else
+			die("http transport does not support %s", buf->buf);
+
+		strbuf_reset(buf);
+		if (strbuf_getline(buf, stdin, '\n') == EOF)
+			return;
+		if (!*buf->buf)
+			break;
+	} while (1);
+
+	if (fetch_dumb(nr_heads, to_fetch))
+		exit(128); /* error already reported */
+	free_refs(list_head);
+	free(to_fetch);
+
+	printf("\n");
+	fflush(stdout);
+	strbuf_reset(buf);
+}
+
 int main(int argc, const char **argv)
 {
 	struct strbuf buf = STRBUF_INIT;

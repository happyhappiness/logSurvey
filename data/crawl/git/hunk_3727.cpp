 				die("line is badly quoted");
 			strbuf_swap(&buf, &nbuf);
 		}
-		ALLOC_GROW(pathspec, nr + 1, alloc);
-		pathspec[nr] = xcalloc(strlen(buf.buf) + 1, sizeof(*buf.buf));
-		strcpy(pathspec[nr++], buf.buf);
+		pathspec[0] = buf.buf;
+		num_ignored += check_ignore(check, prefix, (const char **)pathspec);
+		maybe_flush_or_die(stdout, "check-ignore to stdout");
 	}
-	ALLOC_GROW(pathspec, nr + 1, alloc);
-	pathspec[nr] = NULL;
-	num_ignored = check_ignore(check, prefix, (const char **)pathspec);
-	maybe_flush_or_die(stdout, "attribute to stdout");
 	strbuf_release(&buf);
 	strbuf_release(&nbuf);
 	return num_ignored;

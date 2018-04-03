 
 	if (!strcmp(metainfo_charset, charset))
 		return;
-	out = reencode_string(line, metainfo_charset, charset);
+	out = reencode_string(line->buf, metainfo_charset, charset);
 	if (!out)
 		die("cannot convert from %s to %s\n",
 		    charset, metainfo_charset);
-	strlcpy(line, out, linesize);
-	free(out);
+	strbuf_attach(line, out, strlen(out), strlen(out));
 }
 
-static int decode_header_bq(char *it, unsigned itsize)
+static int decode_header_bq(struct strbuf *it)
 {
-	char *in, *out, *ep, *cp, *sp;
-	char outbuf[1000];
+	char *in, *ep, *cp;
+	struct strbuf outbuf = STRBUF_INIT, *dec;
+	struct strbuf charset_q = STRBUF_INIT, piecebuf = STRBUF_INIT;
 	int rfc2047 = 0;
 
-	in = it;
-	out = outbuf;
-	while ((ep = strstr(in, "=?")) != NULL) {
-		int sz, encoding;
-		char charset_q[256], piecebuf[256];
+	in = it->buf;
+	while (in - it->buf <= it->len && (ep = strstr(in, "=?")) != NULL) {
+		int encoding;
+		strbuf_reset(&charset_q);
+		strbuf_reset(&piecebuf);
 		rfc2047 = 1;
 
 		if (in != ep) {
-			sz = ep - in;
-			memcpy(out, in, sz);
-			out += sz;
-			in += sz;
+			strbuf_add(&outbuf, in, ep - in);
+			in = ep;
 		}
 		/* E.g.
 		 * ep : "=?iso-2022-jp?B?GyR...?= foo"
 		 * ep : "=?ISO-8859-1?Q?Foo=FCbar?= baz"
 		 */
 		ep += 2;
-		cp = strchr(ep, '?');
-		if (!cp)
-			return rfc2047; /* no munging */
-		for (sp = ep; sp < cp; sp++)
-			charset_q[sp - ep] = tolower(*sp);
-		charset_q[cp - ep] = 0;
+
+		if (ep - it->buf >= it->len || !(cp = strchr(ep, '?')))
+			goto decode_header_bq_out;
+
+		if (cp + 3 - it->buf > it->len)
+			goto decode_header_bq_out;
+		strbuf_add(&charset_q, ep, cp - ep);
+		strbuf_tolower(&charset_q);
+
 		encoding = cp[1];
 		if (!encoding || cp[2] != '?')
-			return rfc2047; /* no munging */
+			goto decode_header_bq_out;
 		ep = strstr(cp + 3, "?=");
 		if (!ep)
-			return rfc2047; /* no munging */
+			goto decode_header_bq_out;
+		strbuf_add(&piecebuf, cp + 3, ep - cp - 3);
 		switch (tolower(encoding)) {
 		default:
-			return rfc2047; /* no munging */
+			goto decode_header_bq_out;
 		case 'b':
-			sz = decode_b_segment(cp + 3, piecebuf, sizeof(piecebuf), ep);
+			dec = decode_b_segment(&piecebuf);
 			break;
 		case 'q':
-			sz = decode_q_segment(cp + 3, piecebuf, sizeof(piecebuf), ep, 1);
+			dec = decode_q_segment(&piecebuf, 1);
 			break;
 		}
-		if (sz < 0)
-			return rfc2047;
 		if (metainfo_charset)
-			convert_to_utf8(piecebuf, sizeof(piecebuf), charset_q);
+			convert_to_utf8(dec, charset_q.buf);
 
-		sz = strlen(piecebuf);
-		if (outbuf + sizeof(outbuf) <= out + sz)
-			return rfc2047; /* no munging */
-		strcpy(out, piecebuf);
-		out += sz;
+		strbuf_addbuf(&outbuf, dec);
+		strbuf_release(dec);
+		free(dec);
 		in = ep + 2;
 	}
-	strcpy(out, in);
-	strlcpy(it, outbuf, itsize);
+	strbuf_addstr(&outbuf, in);
+	strbuf_reset(it);
+	strbuf_addbuf(it, &outbuf);
+decode_header_bq_out:
+	strbuf_release(&outbuf);
+	strbuf_release(&charset_q);
+	strbuf_release(&piecebuf);
 	return rfc2047;
 }
 
-static void decode_header(char *it, unsigned itsize)
+static void decode_header(struct strbuf *it)
 {
-
-	if (decode_header_bq(it, itsize))
+	if (decode_header_bq(it))
 		return;
 	/* otherwise "it" is a straight copy of the input.
 	 * This can be binary guck but there is no charset specified.
 	 */
 	if (metainfo_charset)
-		convert_to_utf8(it, itsize, "");
+		convert_to_utf8(it, "");
 }
 
-static int decode_transfer_encoding(char *line, unsigned linesize, int inputlen)
+static void decode_transfer_encoding(struct strbuf *line)
 {
-	char *ep;
+	struct strbuf *ret;
 
 	switch (transfer_encoding) {
 	case TE_QP:
-		ep = line + inputlen;
-		return decode_q_segment(line, line, linesize, ep, 0);
+		ret = decode_q_segment(line, 0);
+		break;
 	case TE_BASE64:
-		ep = line + inputlen;
-		return decode_b_segment(line, line, linesize, ep);
+		ret = decode_b_segment(line);
+		break;
 	case TE_DONTCARE:
 	default:
-		return inputlen;
+		return;
 	}
+	strbuf_reset(line);
+	strbuf_addbuf(line, ret);
+	strbuf_release(ret);
+	free(ret);
 }
 
-static int handle_filter(char *line, unsigned linesize, int linelen);
+static void handle_filter(struct strbuf *line);
 
 static int find_boundary(void)
 {
-	while(fgets(line, sizeof(line), fin) != NULL) {
-		if (is_multipart_boundary(line))
+	while (!strbuf_getline(&line, fin, '\n')) {
+		if (is_multipart_boundary(&line))
 			return 1;
 	}
 	return 0;
 }
 
 static int handle_boundary(void)
 {
-	char newline[]="\n";
+	struct strbuf newline = STRBUF_INIT;
+
+	strbuf_addch(&newline, '\n');
 again:
-	if (!memcmp(line+content_top->boundary_len, "--", 2)) {
+	if (line.len >= (*content_top)->len + 2 &&
+	    !memcmp(line.buf + (*content_top)->len, "--", 2)) {
 		/* we hit an end boundary */
 		/* pop the current boundary off the stack */
-		free(content_top->boundary);
+		strbuf_release(*content_top);
+		free(*content_top);
+		*content_top = NULL;
 
 		/* technically won't happen as is_multipart_boundary()
 		   will fail first.  But just in case..

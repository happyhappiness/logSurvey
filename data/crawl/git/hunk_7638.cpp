 			slot = slot->next;
 		}
 }
+
+static inline int needs_quote(int ch)
+{
+	if (((ch >= 'A') && (ch <= 'Z'))
+			|| ((ch >= 'a') && (ch <= 'z'))
+			|| ((ch >= '0') && (ch <= '9'))
+			|| (ch == '/')
+			|| (ch == '-')
+			|| (ch == '.'))
+		return 0;
+	return 1;
+}
+
+static inline int hex(int v)
+{
+	if (v < 10) return '0' + v;
+	else return 'A' + v - 10;
+}
+
+static char *quote_ref_url(const char *base, const char *ref)
+{
+	const char *cp;
+	char *dp, *qref;
+	int len, baselen, ch;
+
+	baselen = strlen(base);
+	len = baselen + 7; /* "/refs/" + NUL */
+	for (cp = ref; (ch = *cp) != 0; cp++, len++)
+		if (needs_quote(ch))
+			len += 2; /* extra two hex plus replacement % */
+	qref = xmalloc(len);
+	memcpy(qref, base, baselen);
+	memcpy(qref + baselen, "/refs/", 6);
+	for (cp = ref, dp = qref + baselen + 6; (ch = *cp) != 0; cp++) {
+		if (needs_quote(ch)) {
+			*dp++ = '%';
+			*dp++ = hex((ch >> 4) & 0xF);
+			*dp++ = hex(ch & 0xF);
+		}
+		else
+			*dp++ = ch;
+	}
+	*dp = 0;
+
+	return qref;
+}
+
+int http_fetch_ref(const char *base, const char *ref, unsigned char *sha1)
+{
+	char *url;
+	struct strbuf buffer = STRBUF_INIT;
+	struct active_request_slot *slot;
+	struct slot_results results;
+	int ret;
+
+	url = quote_ref_url(base, ref);
+	slot = get_active_slot();
+	slot->results = &results;
+	curl_easy_setopt(slot->curl, CURLOPT_FILE, &buffer);
+	curl_easy_setopt(slot->curl, CURLOPT_WRITEFUNCTION, fwrite_buffer);
+	curl_easy_setopt(slot->curl, CURLOPT_HTTPHEADER, NULL);
+	curl_easy_setopt(slot->curl, CURLOPT_URL, url);
+	if (start_active_slot(slot)) {
+		run_active_slot(slot);
+		if (results.curl_result == CURLE_OK) {
+			strbuf_rtrim(&buffer);
+			if (buffer.len == 40)
+				ret = get_sha1_hex(buffer.buf, sha1);
+			else
+				ret = 1;
+		} else {
+			ret = error("Couldn't get %s for %s\n%s",
+				    url, ref, curl_errorstr);
+		}
+	} else {
+		ret = error("Unable to start request");
+	}
+
+	strbuf_release(&buffer);
+	free(url);
+	return ret;
+}

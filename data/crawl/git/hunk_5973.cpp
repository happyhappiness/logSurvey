 	free(filename);
 	return NULL;
 }
+
+/* Helpers for fetching objects (loose) */
+static size_t fwrite_sha1_file(void *ptr, size_t eltsize, size_t nmemb,
+			       void *data)
+{
+	unsigned char expn[4096];
+	size_t size = eltsize * nmemb;
+	int posn = 0;
+	struct http_object_request *freq =
+		(struct http_object_request *)data;
+	do {
+		ssize_t retval = xwrite(freq->localfile,
+					(char *) ptr + posn, size - posn);
+		if (retval < 0)
+			return posn;
+		posn += retval;
+	} while (posn < size);
+
+	freq->stream.avail_in = size;
+	freq->stream.next_in = ptr;
+	do {
+		freq->stream.next_out = expn;
+		freq->stream.avail_out = sizeof(expn);
+		freq->zret = git_inflate(&freq->stream, Z_SYNC_FLUSH);
+		git_SHA1_Update(&freq->c, expn,
+				sizeof(expn) - freq->stream.avail_out);
+	} while (freq->stream.avail_in && freq->zret == Z_OK);
+	data_received++;
+	return size;
+}
+
+struct http_object_request *new_http_object_request(const char *base_url,
+	unsigned char *sha1)
+{
+	char *hex = sha1_to_hex(sha1);
+	char *filename;
+	char prevfile[PATH_MAX];
+	char *url;
+	int prevlocal;
+	unsigned char prev_buf[PREV_BUF_SIZE];
+	ssize_t prev_read = 0;
+	long prev_posn = 0;
+	char range[RANGE_HEADER_SIZE];
+	struct curl_slist *range_header = NULL;
+	struct http_object_request *freq;
+
+	freq = xmalloc(sizeof(*freq));
+	hashcpy(freq->sha1, sha1);
+	freq->localfile = -1;
+
+	filename = sha1_file_name(sha1);
+	snprintf(freq->filename, sizeof(freq->filename), "%s", filename);
+	snprintf(freq->tmpfile, sizeof(freq->tmpfile),
+		 "%s.temp", filename);
+
+	snprintf(prevfile, sizeof(prevfile), "%s.prev", filename);
+	unlink_or_warn(prevfile);
+	rename(freq->tmpfile, prevfile);
+	unlink_or_warn(freq->tmpfile);
+
+	if (freq->localfile != -1)
+		error("fd leakage in start: %d", freq->localfile);
+	freq->localfile = open(freq->tmpfile,
+			       O_WRONLY | O_CREAT | O_EXCL, 0666);
+	/*
+	 * This could have failed due to the "lazy directory creation";
+	 * try to mkdir the last path component.
+	 */
+	if (freq->localfile < 0 && errno == ENOENT) {
+		char *dir = strrchr(freq->tmpfile, '/');
+		if (dir) {
+			*dir = 0;
+			mkdir(freq->tmpfile, 0777);
+			*dir = '/';
+		}
+		freq->localfile = open(freq->tmpfile,
+				       O_WRONLY | O_CREAT | O_EXCL, 0666);
+	}
+
+	if (freq->localfile < 0) {
+		error("Couldn't create temporary file %s for %s: %s",
+		      freq->tmpfile, freq->filename, strerror(errno));
+		goto abort;
+	}
+
+	memset(&freq->stream, 0, sizeof(freq->stream));
+
+	git_inflate_init(&freq->stream);
+
+	git_SHA1_Init(&freq->c);
+
+	url = get_remote_object_url(base_url, hex, 0);
+	freq->url = xstrdup(url);
+
+	/*
+	 * If a previous temp file is present, process what was already
+	 * fetched.
+	 */
+	prevlocal = open(prevfile, O_RDONLY);
+	if (prevlocal != -1) {
+		do {
+			prev_read = xread(prevlocal, prev_buf, PREV_BUF_SIZE);
+			if (prev_read>0) {
+				if (fwrite_sha1_file(prev_buf,
+						     1,
+						     prev_read,
+						     freq) == prev_read) {
+					prev_posn += prev_read;
+				} else {
+					prev_read = -1;
+				}
+			}
+		} while (prev_read > 0);
+		close(prevlocal);
+	}
+	unlink_or_warn(prevfile);
+
+	/*
+	 * Reset inflate/SHA1 if there was an error reading the previous temp
+	 * file; also rewind to the beginning of the local file.
+	 */
+	if (prev_read == -1) {
+		memset(&freq->stream, 0, sizeof(freq->stream));
+		git_inflate_init(&freq->stream);
+		git_SHA1_Init(&freq->c);
+		if (prev_posn>0) {
+			prev_posn = 0;
+			lseek(freq->localfile, 0, SEEK_SET);
+			ftruncate(freq->localfile, 0);
+		}
+	}
+
+	freq->slot = get_active_slot();
+
+	curl_easy_setopt(freq->slot->curl, CURLOPT_FILE, freq);
+	curl_easy_setopt(freq->slot->curl, CURLOPT_WRITEFUNCTION, fwrite_sha1_file);
+	curl_easy_setopt(freq->slot->curl, CURLOPT_ERRORBUFFER, freq->errorstr);
+	curl_easy_setopt(freq->slot->curl, CURLOPT_URL, url);
+	curl_easy_setopt(freq->slot->curl, CURLOPT_HTTPHEADER, no_pragma_header);
+
+	/*
+	 * If we have successfully processed data from a previous fetch
+	 * attempt, only fetch the data we don't already have.
+	 */
+	if (prev_posn>0) {
+		if (http_is_verbose)
+			fprintf(stderr,
+				"Resuming fetch of object %s at byte %ld\n",
+				hex, prev_posn);
+		sprintf(range, "Range: bytes=%ld-", prev_posn);
+		range_header = curl_slist_append(range_header, range);
+		curl_easy_setopt(freq->slot->curl,
+				 CURLOPT_HTTPHEADER, range_header);
+	}
+
+	return freq;
+
+	free(url);
+abort:
+	free(filename);
+	free(freq);
+	return NULL;
+}
+
+void process_http_object_request(struct http_object_request *freq)
+{
+	if (freq->slot == NULL)
+		return;
+	freq->curl_result = freq->slot->curl_result;
+	freq->http_code = freq->slot->http_code;
+	freq->slot = NULL;
+}
+
+int finish_http_object_request(struct http_object_request *freq)
+{
+	struct stat st;
+
+	close(freq->localfile);
+	freq->localfile = -1;
+
+	process_http_object_request(freq);
+
+	if (freq->http_code == 416) {
+		fprintf(stderr, "Warning: requested range invalid; we may already have all the data.\n");
+	} else if (freq->curl_result != CURLE_OK) {
+		if (stat(freq->tmpfile, &st) == 0)
+			if (st.st_size == 0)
+				unlink_or_warn(freq->tmpfile);
+		return -1;
+	}
+
+	git_inflate_end(&freq->stream);
+	git_SHA1_Final(freq->real_sha1, &freq->c);
+	if (freq->zret != Z_STREAM_END) {
+		unlink_or_warn(freq->tmpfile);
+		return -1;
+	}
+	if (hashcmp(freq->sha1, freq->real_sha1)) {
+		unlink_or_warn(freq->tmpfile);
+		return -1;
+	}
+	freq->rename =
+		move_temp_to_file(freq->tmpfile, freq->filename);
+
+	return freq->rename;
+}
+
+void abort_http_object_request(struct http_object_request *freq)
+{
+	unlink_or_warn(freq->tmpfile);
+
+	release_http_object_request(freq);
+}
+
+void release_http_object_request(struct http_object_request *freq)
+{
+	if (freq->localfile != -1) {
+		close(freq->localfile);
+		freq->localfile = -1;
+	}
+	if (freq->url != NULL) {
+		free(freq->url);
+		freq->url = NULL;
+	}
+	freq->slot = NULL;
+}

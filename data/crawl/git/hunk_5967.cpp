 
 #ifdef USE_CURL_MULTI
 
-static char *get_remote_object_url(const char *url, const char *hex,
-				   int only_two_digit_prefix)
-{
-	struct strbuf buf = STRBUF_INIT;
-	append_remote_object_url(&buf, url, hex, only_two_digit_prefix);
-	return strbuf_detach(&buf, NULL);
-}
-
-static size_t fwrite_sha1_file(void *ptr, size_t eltsize, size_t nmemb,
-			       void *data)
-{
-	unsigned char expn[4096];
-	size_t size = eltsize * nmemb;
-	int posn = 0;
-	struct transfer_request *request = (struct transfer_request *)data;
-	do {
-		ssize_t retval = xwrite(request->local_fileno,
-					(char *) ptr + posn, size - posn);
-		if (retval < 0)
-			return posn;
-		posn += retval;
-	} while (posn < size);
-
-	request->stream.avail_in = size;
-	request->stream.next_in = ptr;
-	do {
-		request->stream.next_out = expn;
-		request->stream.avail_out = sizeof(expn);
-		request->zret = git_inflate(&request->stream, Z_SYNC_FLUSH);
-		git_SHA1_Update(&request->c, expn,
-				sizeof(expn) - request->stream.avail_out);
-	} while (request->stream.avail_in && request->zret == Z_OK);
-	data_received++;
-	return size;
-}
-
 static void start_fetch_loose(struct transfer_request *request)
 {
-	char *hex = sha1_to_hex(request->obj->sha1);
-	char *filename;
-	char prevfile[PATH_MAX];
-	char *url;
-	int prevlocal;
-	unsigned char prev_buf[PREV_BUF_SIZE];
-	ssize_t prev_read = 0;
-	long prev_posn = 0;
-	char range[RANGE_HEADER_SIZE];
-	struct curl_slist *range_header = NULL;
 	struct active_request_slot *slot;
+	struct http_object_request *obj_req;
 
-	filename = sha1_file_name(request->obj->sha1);
-	snprintf(request->filename, sizeof(request->filename), "%s", filename);
-	snprintf(request->tmpfile, sizeof(request->tmpfile),
-		 "%s.temp", filename);
-
-	snprintf(prevfile, sizeof(prevfile), "%s.prev", request->filename);
-	unlink_or_warn(prevfile);
-	rename(request->tmpfile, prevfile);
-	unlink_or_warn(request->tmpfile);
-
-	if (request->local_fileno != -1)
-		error("fd leakage in start: %d", request->local_fileno);
-	request->local_fileno = open(request->tmpfile,
-				     O_WRONLY | O_CREAT | O_EXCL, 0666);
-	/*
-	 * This could have failed due to the "lazy directory creation";
-	 * try to mkdir the last path component.
-	 */
-	if (request->local_fileno < 0 && errno == ENOENT) {
-		char *dir = strrchr(request->tmpfile, '/');
-		if (dir) {
-			*dir = 0;
-			mkdir(request->tmpfile, 0777);
-			*dir = '/';
-		}
-		request->local_fileno = open(request->tmpfile,
-					     O_WRONLY | O_CREAT | O_EXCL, 0666);
-	}
-
-	if (request->local_fileno < 0) {
+	obj_req = new_http_object_request(repo->url, request->obj->sha1);
+	if (obj_req == NULL) {
 		request->state = ABORTED;
-		error("Couldn't create temporary file %s for %s: %s",
-		      request->tmpfile, request->filename, strerror(errno));
 		return;
 	}
 
-	memset(&request->stream, 0, sizeof(request->stream));
-
-	git_inflate_init(&request->stream);
-
-	git_SHA1_Init(&request->c);
-
-	url = get_remote_object_url(repo->url, hex, 0);
-	request->url = xstrdup(url);
-
-	/*
-	 * If a previous temp file is present, process what was already
-	 * fetched.
-	 */
-	prevlocal = open(prevfile, O_RDONLY);
-	if (prevlocal != -1) {
-		do {
-			prev_read = xread(prevlocal, prev_buf, PREV_BUF_SIZE);
-			if (prev_read>0) {
-				if (fwrite_sha1_file(prev_buf,
-						     1,
-						     prev_read,
-						     request) == prev_read)
-					prev_posn += prev_read;
-				else
-					prev_read = -1;
-			}
-		} while (prev_read > 0);
-		close(prevlocal);
-	}
-	unlink_or_warn(prevfile);
-
-	/*
-	 * Reset inflate/SHA1 if there was an error reading the previous temp
-	 * file; also rewind to the beginning of the local file.
-	 */
-	if (prev_read == -1) {
-		memset(&request->stream, 0, sizeof(request->stream));
-		git_inflate_init(&request->stream);
-		git_SHA1_Init(&request->c);
-		if (prev_posn>0) {
-			prev_posn = 0;
-			lseek(request->local_fileno, 0, SEEK_SET);
-			ftruncate(request->local_fileno, 0);
-		}
-	}
-
-	slot = get_active_slot();
+	slot = obj_req->slot;
 	slot->callback_func = process_response;
 	slot->callback_data = request;
 	request->slot = slot;
-
-	curl_easy_setopt(slot->curl, CURLOPT_FILE, request);
-	curl_easy_setopt(slot->curl, CURLOPT_WRITEFUNCTION, fwrite_sha1_file);
-	curl_easy_setopt(slot->curl, CURLOPT_ERRORBUFFER, request->errorstr);
-	curl_easy_setopt(slot->curl, CURLOPT_URL, url);
-	curl_easy_setopt(slot->curl, CURLOPT_HTTPHEADER, no_pragma_header);
-
-	/*
-	 * If we have successfully processed data from a previous fetch
-	 * attempt, only fetch the data we don't already have.
-	 */
-	if (prev_posn>0) {
-		if (push_verbosely)
-			fprintf(stderr,
-				"Resuming fetch of object %s at byte %ld\n",
-				hex, prev_posn);
-		sprintf(range, "Range: bytes=%ld-", prev_posn);
-		range_header = curl_slist_append(range_header, range);
-		curl_easy_setopt(slot->curl,
-				 CURLOPT_HTTPHEADER, range_header);
-	}
+	request->userData = obj_req;
 
 	/* Try to get the request started, abort the request on error */
 	request->state = RUN_FETCH_LOOSE;
 	if (!start_active_slot(slot)) {
 		fprintf(stderr, "Unable to start GET request\n");
 		repo->can_update_info_refs = 0;
+		release_http_object_request(obj_req);
 		release_request(request);
 	}
 }

 
 static struct object_request *object_queue_head;
 
-static size_t fwrite_sha1_file(void *ptr, size_t eltsize, size_t nmemb,
-			       void *data)
-{
-	unsigned char expn[4096];
-	size_t size = eltsize * nmemb;
-	int posn = 0;
-	struct object_request *obj_req = (struct object_request *)data;
-	do {
-		ssize_t retval = xwrite(obj_req->local,
-					(char *) ptr + posn, size - posn);
-		if (retval < 0)
-			return posn;
-		posn += retval;
-	} while (posn < size);
-
-	obj_req->stream.avail_in = size;
-	obj_req->stream.next_in = ptr;
-	do {
-		obj_req->stream.next_out = expn;
-		obj_req->stream.avail_out = sizeof(expn);
-		obj_req->zret = git_inflate(&obj_req->stream, Z_SYNC_FLUSH);
-		git_SHA1_Update(&obj_req->c, expn,
-				sizeof(expn) - obj_req->stream.avail_out);
-	} while (obj_req->stream.avail_in && obj_req->zret == Z_OK);
-	data_received++;
-	return size;
-}
-
 static void fetch_alternates(struct walker *walker, const char *base);
 
 static void process_object_response(void *callback_data);
 
 static void start_object_request(struct walker *walker,
 				 struct object_request *obj_req)
 {
-	char *hex = sha1_to_hex(obj_req->sha1);
-	char prevfile[PATH_MAX];
-	char *url;
-	char *posn;
-	int prevlocal;
-	unsigned char prev_buf[PREV_BUF_SIZE];
-	ssize_t prev_read = 0;
-	long prev_posn = 0;
-	char range[RANGE_HEADER_SIZE];
-	struct curl_slist *range_header = NULL;
 	struct active_request_slot *slot;
+	struct http_object_request *req;
 
-	snprintf(prevfile, sizeof(prevfile), "%s.prev", obj_req->filename);
-	unlink_or_warn(prevfile);
-	rename(obj_req->tmpfile, prevfile);
-	unlink_or_warn(obj_req->tmpfile);
-
-	if (obj_req->local != -1)
-		error("fd leakage in start: %d", obj_req->local);
-	obj_req->local = open(obj_req->tmpfile,
-			      O_WRONLY | O_CREAT | O_EXCL, 0666);
-	/*
-	 * This could have failed due to the "lazy directory creation";
-	 * try to mkdir the last path component.
-	 */
-	if (obj_req->local < 0 && errno == ENOENT) {
-		char *dir = strrchr(obj_req->tmpfile, '/');
-		if (dir) {
-			*dir = 0;
-			mkdir(obj_req->tmpfile, 0777);
-			*dir = '/';
-		}
-		obj_req->local = open(obj_req->tmpfile,
-				      O_WRONLY | O_CREAT | O_EXCL, 0666);
-	}
-
-	if (obj_req->local < 0) {
+	req = new_http_object_request(obj_req->repo->base, obj_req->sha1);
+	if (req == NULL) {
 		obj_req->state = ABORTED;
-		error("Couldn't create temporary file %s for %s: %s",
-		      obj_req->tmpfile, obj_req->filename, strerror(errno));
 		return;
 	}
+	obj_req->req = req;
 
-	memset(&obj_req->stream, 0, sizeof(obj_req->stream));
-
-	git_inflate_init(&obj_req->stream);
-
-	git_SHA1_Init(&obj_req->c);
-
-	url = xmalloc(strlen(obj_req->repo->base) + 51);
-	obj_req->url = xmalloc(strlen(obj_req->repo->base) + 51);
-	strcpy(url, obj_req->repo->base);
-	posn = url + strlen(obj_req->repo->base);
-	strcpy(posn, "/objects/");
-	posn += 9;
-	memcpy(posn, hex, 2);
-	posn += 2;
-	*(posn++) = '/';
-	strcpy(posn, hex + 2);
-	strcpy(obj_req->url, url);
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
-						     obj_req) == prev_read)
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
-		memset(&obj_req->stream, 0, sizeof(obj_req->stream));
-		git_inflate_init(&obj_req->stream);
-		git_SHA1_Init(&obj_req->c);
-		if (prev_posn>0) {
-			prev_posn = 0;
-			lseek(obj_req->local, 0, SEEK_SET);
-			ftruncate(obj_req->local, 0);
-		}
-	}
-
-	slot = get_active_slot();
+	slot = req->slot;
 	slot->callback_func = process_object_response;
 	slot->callback_data = obj_req;
-	obj_req->slot = slot;
-
-	curl_easy_setopt(slot->curl, CURLOPT_FILE, obj_req);
-	curl_easy_setopt(slot->curl, CURLOPT_WRITEFUNCTION, fwrite_sha1_file);
-	curl_easy_setopt(slot->curl, CURLOPT_ERRORBUFFER, obj_req->errorstr);
-	curl_easy_setopt(slot->curl, CURLOPT_URL, url);
-	curl_easy_setopt(slot->curl, CURLOPT_HTTPHEADER, no_pragma_header);
-
-	/*
-	 * If we have successfully processed data from a previous fetch
-	 * attempt, only fetch the data we don't already have.
-	 */
-	if (prev_posn>0) {
-		if (walker->get_verbosely)
-			fprintf(stderr,
-				"Resuming fetch of object %s at byte %ld\n",
-				hex, prev_posn);
-		sprintf(range, "Range: bytes=%ld-", prev_posn);
-		range_header = curl_slist_append(range_header, range);
-		curl_easy_setopt(slot->curl,
-				 CURLOPT_HTTPHEADER, range_header);
-	}
 
 	/* Try to get the request started, abort the request on error */
 	obj_req->state = ACTIVE;
 	if (!start_active_slot(slot)) {
 		obj_req->state = ABORTED;
-		obj_req->slot = NULL;
-		close(obj_req->local);
-		obj_req->local = -1;
-		free(obj_req->url);
+		release_http_object_request(req);
 		return;
 	}
 }
 
 static void finish_object_request(struct object_request *obj_req)
 {
-	struct stat st;
-
-	close(obj_req->local);
-	obj_req->local = -1;
-
-	if (obj_req->http_code == 416) {
-		fprintf(stderr, "Warning: requested range invalid; we may already have all the data.\n");
-	} else if (obj_req->curl_result != CURLE_OK) {
-		if (stat(obj_req->tmpfile, &st) == 0)
-			if (st.st_size == 0)
-				unlink_or_warn(obj_req->tmpfile);
+	if (finish_http_object_request(obj_req->req))
 		return;
-	}
-
-	git_inflate_end(&obj_req->stream);
-	git_SHA1_Final(obj_req->real_sha1, &obj_req->c);
-	if (obj_req->zret != Z_STREAM_END) {
-		unlink_or_warn(obj_req->tmpfile);
-		return;
-	}
-	if (hashcmp(obj_req->sha1, obj_req->real_sha1)) {
-		unlink_or_warn(obj_req->tmpfile);
-		return;
-	}
-	obj_req->rename =
-		move_temp_to_file(obj_req->tmpfile, obj_req->filename);
 
-	if (obj_req->rename == 0)
+	if (obj_req->req->rename == 0)
 		walker_say(obj_req->walker, "got %s\n", sha1_to_hex(obj_req->sha1));
 }
 

 			fflush(stderr);
 		}
 
+	} else if (use_gzip && 1024 < rpc->len) {
+		/* The client backend isn't giving us compressed data so
+		 * we can try to deflate it ourselves, this may save on.
+		 * the transfer time.
+		 */
+		size_t size;
+		z_stream stream;
+		int ret;
+
+		memset(&stream, 0, sizeof(stream));
+		ret = deflateInit2(&stream, Z_BEST_COMPRESSION,
+				Z_DEFLATED, (15 + 16),
+				8, Z_DEFAULT_STRATEGY);
+		if (ret != Z_OK)
+			die("cannot deflate request; zlib init error %d", ret);
+		size = deflateBound(&stream, rpc->len);
+		gzip_body = xmalloc(size);
+
+		stream.next_in = (unsigned char *)rpc->buf;
+		stream.avail_in = rpc->len;
+		stream.next_out = (unsigned char *)gzip_body;
+		stream.avail_out = size;
+
+		ret = deflate(&stream, Z_FINISH);
+		if (ret != Z_STREAM_END)
+			die("cannot deflate request; zlib deflate error %d", ret);
+
+		ret = deflateEnd(&stream);
+		if (ret != Z_OK)
+			die("cannot deflate request; zlib end error %d", ret);
+
+		size = stream.total_out;
+
+		headers = curl_slist_append(headers, "Content-Encoding: gzip");
+		curl_easy_setopt(slot->curl, CURLOPT_POSTFIELDS, gzip_body);
+		curl_easy_setopt(slot->curl, CURLOPT_POSTFIELDSIZE, size);
+
+		if (options.verbosity > 1) {
+			fprintf(stderr, "POST %s (gzip %lu to %lu bytes)\n",
+				rpc->service_name,
+				(unsigned long)rpc->len, (unsigned long)size);
+			fflush(stderr);
+		}
 	} else {
 		/* We know the complete request size in advance, use the
 		 * more normal Content-Length approach.

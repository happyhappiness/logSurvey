 			fprintf(stderr,
 				"Resuming fetch of pack %s at byte %ld\n",
 				sha1_to_hex(target->sha1), prev_posn);
-		sprintf(range, "Range: bytes=%ld-", prev_posn);
+		xsnprintf(range, sizeof(range), "Range: bytes=%ld-", prev_posn);
 		preq->range_header = curl_slist_append(NULL, range);
 		curl_easy_setopt(preq->slot->curl, CURLOPT_HTTPHEADER,
 			preq->range_header);

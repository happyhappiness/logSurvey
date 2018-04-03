 	int i;
 	struct progress *progress = NULL;
 	struct pack_header *hdr = fill(sizeof(struct pack_header));
-
-	nr_objects = ntohl(hdr->hdr_entries);
+	unsigned nr_objects = ntohl(hdr->hdr_entries);
 
 	if (ntohl(hdr->hdr_signature) != PACK_SIGNATURE)
 		die("bad pack file");

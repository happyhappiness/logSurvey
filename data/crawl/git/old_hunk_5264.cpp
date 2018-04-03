		ret = error("File %s has bad hash", hex);
	} else if (req->rename < 0) {
		ret = error("unable to write sha1 filename %s",
			    req->filename);
	}

	release_http_object_request(req);

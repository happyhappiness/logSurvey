 			}
 		} else {
 			if (request->http_code == 416)
-				fprintf(stderr, "Warning: requested range invalid; we may already have all the data.\n");
+				warning("requested range invalid; we may already have all the data.");
 
 			git_inflate_end(&request->stream);
 			git_SHA1_Final(request->real_sha1, &request->c);

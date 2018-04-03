 			}
 			XML_ParserFree(parser);
 			if (!lock_flags)
-				error("Error: no DAV locking support on %s",
-				      remote->url);
+				error("no DAV locking support on %s",
+				      repo->url);
 
 		} else {
 			error("Cannot access URL %s, return code %d",
-			      remote->url, results.curl_result);
+			      repo->url, results.curl_result);
 			lock_flags = 0;
 		}
 	} else {
-		error("Unable to start PROPFIND request on %s", remote->url);
+		error("Unable to start PROPFIND request on %s", repo->url);
 	}
 
 	strbuf_release(&out_buffer.buf);

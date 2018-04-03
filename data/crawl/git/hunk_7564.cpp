 				lock_flags = 0;
 			}
 			XML_ParserFree(parser);
+			if (!lock_flags)
+				error("Error: no DAV locking support on %s",
+				      remote->url);
+
+		} else {
+			error("Cannot access URL %s, return code %d",
+			      remote->url, results.curl_result);
+			lock_flags = 0;
 		}
 	} else {
-		fprintf(stderr, "Unable to start PROPFIND request\n");
+		error("Unable to start PROPFIND request on %s", remote->url);
 	}
 
 	strbuf_release(&out_buffer.buf);

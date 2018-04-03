 				lock->timeout = -1;
 			}
 			XML_ParserFree(parser);
+		} else {
+			fprintf(stderr,
+				"error: curl result=%d, HTTP code=%ld\n",
+				results.curl_result, results.http_code);
 		}
 	} else {
 		fprintf(stderr, "Unable to start LOCK request\n");
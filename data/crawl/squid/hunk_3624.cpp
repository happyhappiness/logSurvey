 
 	snprintf(loginbuf, sizeof(loginbuf), "%s%s", username, orig_request->peer_login + 1);
 
-	httpHeaderPutStrf(hdr_out, HDR_PROXY_AUTHORIZATION, "Basic %s",
+	httpHeaderPutStrf(hdr_out, header, "Basic %s",
 			  base64_encode(loginbuf));
 	return;
     }

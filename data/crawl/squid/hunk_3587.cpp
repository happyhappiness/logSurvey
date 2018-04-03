 #endif /* HAVE_KRB5 && HAVE_GSSAPI */
 
     httpHeaderPutStrf(hdr_out, header, "Basic %s",
-		      base64_encode(orig_request->peer_login));
+                      base64_encode(orig_request->peer_login));
     return;
 }
 

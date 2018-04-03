         }
         Token = peer_proxy_negotiate_auth(PrincipalName, request->peer_host);
         if (Token) {
-            httpHeaderPutStrf(hdr_out, HDR_PROXY_AUTHORIZATION, "Negotiate %s",Token);
+            httpHeaderPutStrf(hdr_out, header, "Negotiate %s",Token);
         }
         return;
     }
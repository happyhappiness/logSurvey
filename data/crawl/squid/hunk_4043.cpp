          * went through our redirector and the admin configured
          * 'redir_rewrites_host' to be off.
          */
-	if (orig_request->peer_domain)
+        if (orig_request->peer_domain)
             hdr_out->putStr(HDR_HOST, orig_request->peer_domain);
         else if (request->flags.redirected && !Config.onoff.redir_rewrites_host)
             hdr_out->addEntry(e->clone());
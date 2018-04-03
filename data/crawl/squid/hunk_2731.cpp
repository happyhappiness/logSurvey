 
     /* append Front-End-Https */
     if (flags.front_end_https) {
-        if (flags.front_end_https == 1 || request->protocol == PROTO_HTTPS)
+        if (flags.front_end_https == 1 || request->protocol == AnyP::PROTO_HTTPS)
             hdr_out->putStr(HDR_FRONT_END_HTTPS, "On");
     }
 

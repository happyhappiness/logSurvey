         switch (request->protocol) {
 #if USE_SSL
 
-        case PROTO_HTTPS:
+        case AnyP::PROTO_HTTPS:
             httpStart(this);
             break;
 #endif
 
-        case PROTO_HTTP:
+        case AnyP::PROTO_HTTP:
             httpStart(this);
             break;
 
-        case PROTO_GOPHER:
+        case AnyP::PROTO_GOPHER:
             gopherStart(this);
             break;
 
-        case PROTO_FTP:
+        case AnyP::PROTO_FTP:
             ftpStart(this);
             break;
 
-        case PROTO_CACHEOBJ:
+        case AnyP::PROTO_CACHEOBJ:
 
-        case PROTO_INTERNAL:
+        case AnyP::PROTO_INTERNAL:
 
-        case PROTO_URN:
+        case AnyP::PROTO_URN:
             fatal_dump("Should never get here");
             break;
 
-        case PROTO_WHOIS:
+        case AnyP::PROTO_WHOIS:
             whoisStart(this);
             break;
 
-        case PROTO_WAIS:	/* Not implemented */
+        case AnyP::PROTO_WAIS:	/* Not implemented */
 
         default:
             debugs(17, 1, "fwdDispatch: Cannot retrieve '" << entry->url() << "'" );

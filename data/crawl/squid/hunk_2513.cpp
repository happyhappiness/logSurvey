                 fatalf("parse_peer: non-parent carp peer %s/%d\n", p->host, p->http_port);
 
             p->options.carp = 1;
+        } else if (!strncasecmp(token, "carp-key=", 9)) {
+            if (p->options.carp != 1)
+                fatalf("parse_peer: carp-key specified on non-carp peer %s/%d\n", p->host, p->http_port);
+            p->options.carp_key.set=1;
+            char *nextkey=token+strlen("carp-key="), *key=nextkey;
+            for (; key; key = nextkey) {
+            	nextkey=strchr(key,',');
+            	if (nextkey) ++nextkey; // skip the comma, any
+            	if (0==strncasecmp(key,"scheme",6)) {
+            		p->options.carp_key.scheme=1;
+            	} else if (0==strncasecmp(key,"host",4)) {
+            		p->options.carp_key.host=1;
+            	} else if (0==strncasecmp(key,"port",4)) {
+            		p->options.carp_key.port=1;
+            	} else if (0==strncasecmp(key,"path",4)) {
+            		p->options.carp_key.path=1;
+            	} else if (0==strncasecmp(key,"params",6)) {
+            		p->options.carp_key.params=1;
+            	} else {
+            		fatalf("invalid carp-key '%s'",key);
+            	}
+            }
         } else if (!strcasecmp(token, "userhash")) {
 #if USE_AUTH
             if (p->type != PEER_PARENT)

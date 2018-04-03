                 fatalf("parse_peer: non-parent carp peer %s/%d\n", p->host, p->http_port);
 
             p->options.carp = 1;
-
         } else if (!strcasecmp(token, "userhash")) {
+#if USE_AUTH
             if (p->type != PEER_PARENT)
                 fatalf("parse_peer: non-parent userhash peer %s/%d\n", p->host, p->http_port);
 
             p->options.userhash = 1;
-
+#else
+            fatalf("parse_peer: userhash requires authentication. peer %s/%d\n", p->host, p->http_port);
+#endif
         } else if (!strcasecmp(token, "sourcehash")) {
             if (p->type != PEER_PARENT)
                 fatalf("parse_peer: non-parent sourcehash peer %s/%d\n", p->host, p->http_port);

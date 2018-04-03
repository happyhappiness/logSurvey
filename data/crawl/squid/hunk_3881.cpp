 {
     const Adaptation::Service &s = service();
     const String uri = s.cfg().uri;
-    buf.Printf("OPTIONS %.*s ICAP/1.0\r\n", uri.size(), uri.rawBuf());
+    buf.Printf("OPTIONS " SQUIDSTRINGPH " ICAP/1.0\r\n", SQUIDSTRINGPRINT(uri));
     const String host = s.cfg().host;
-    buf.Printf("Host: %.*s:%d\r\n", host.size(), host.rawBuf(), s.cfg().port);
+    buf.Printf("Host: " SQUIDSTRINGPH ":%d\r\n", SQUIDSTRINGPRINT(host), s.cfg().port);
     buf.append(ICAP::crlf, 2);
 }
 

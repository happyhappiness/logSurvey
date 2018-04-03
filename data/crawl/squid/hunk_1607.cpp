 static void
 usage(const char *progname)
 {
-    fprintf(stderr,
-            "Version: %s\n"
-            "Usage: %s [-arsv] [-A 'string'] [-g count] [-h remote host] [-H 'string'] [-i IMS] [-I ping-interval] [-j 'Host-header']"
-            "[-k] [-l local-host] [-m method] "
-#if HAVE_GSSAPI
-            "[-n] [-N] "
-#endif
-            "[-p port] [-P file] [-t count] [-T timeout] [-u proxy-user] [-U www-user] "
-            "[-V version] [-w proxy-password] [-W www-password] url\n"
-            "\n"
-            "Options:\n"
-            "    -a           Do NOT include Accept: header.\n"
-            "    -A           User-Agent: header. Use \"\" to omit.\n"
-            "    -g count     Ping mode, perform \"count\" iterations (0 to loop until interrupted).\n"
-            "    -h host      Retrieve URL from cache on hostname.  Default is localhost.\n"
-            "    -H 'string'  Extra headers to send. Use '\\n' for new lines.\n"
-            "    -i IMS       If-Modified-Since time (in Epoch seconds).\n"
-            "    -I interval  Ping interval in seconds (default 1 second).\n"
-            "    -j hosthdr   Host header content\n"
-            "    -k           Keep the connection active. Default is to do only one request then close.\n"
-            "    -l host      Specify a local IP address to bind to.  Default is none.\n"
-            "    -m method    Request method, default is GET.\n"
+    std::cerr << "Version: " << VERSION << std::endl
+            << "Usage: " << progname << " [Basic Options] [HTTP Options]" << std::endl
+            << std::endl
+            << "Basic Options:" << std::endl
+            << "    -g count     Ping mode, perform \"count\" iterations (0 to loop until interrupted)." << std::endl
+            << "    -h host      Send message to server on 'host'.  Default is localhost." << std::endl
+            << "    -I interval  Ping interval in seconds (default 1 second)." << std::endl
+            << "    -l host      Specify a local IP address to bind to.  Default is none." << std::endl
+            << "    -p port      Port number on server to contact. Default is " << CACHE_HTTP_PORT << "." << std::endl
+            << "    -s           Silent.  Do not print response message to stdout." << std::endl
+            << "    -T timeout   Timeout value (seconds) for read/write operations." << std::endl
+            << "    -v           Verbose. Print outgoing request message and actions to stderr." << std::endl
+            << std::endl
+            << "HTTP Options:" << std::endl
+            << "    -a           Do NOT include Accept: header." << std::endl
+            << "    -A           User-Agent: header. Use \"\" to omit." << std::endl
+            << "    -H 'string'  Extra headers to send. Use '\\n' for new lines." << std::endl
+            << "    -i IMS       If-Modified-Since time (in Epoch seconds)." << std::endl
+            << "    -j hosthdr   Host header content" << std::endl
+            << "    -k           Keep the connection active. Default is to do only one request then close." << std::endl
+            << "    -m method    Request method, default is GET." << std::endl
 #if HAVE_GSSAPI
-            "    -n           Proxy Negotiate(Kerberos) authentication\n"
-            "    -N           WWW Negotiate(Kerberos) authentication\n"
-#endif
-            "    -p port      Port number of cache.  Default is %d.\n"
-            "    -P file      PUT request. Using the named file\n"
-            "    -r           Force cache to reload URL.\n"
-            "    -s           Silent.  Do not print data to stdout.\n"
-            "    -t count     Trace count cache-hops\n"
-            "    -T timeout   Timeout value (seconds) for read/write operations.\n"
-            "    -u user      Proxy authentication username\n"
-            "    -U user      WWW authentication username\n"
-            "    -v           Verbose. Print outgoing message to stderr.\n"
-            "    -V version   HTTP Version. Use '-' for HTTP/0.9 omitted case\n"
-            "    -w password  Proxy authentication password\n"
-            "    -W password  WWW authentication password\n",
-            VERSION, progname, CACHE_HTTP_PORT);
+            << "    -n           Proxy Negotiate(Kerberos) authentication" << std::endl
+            << "    -N           WWW Negotiate(Kerberos) authentication" << std::endl
+#endif
+            << "    -P file      PUT request. Using the named file" << std::endl
+            << "    -r           Force cache to reload URL." << std::endl
+            << "    -t count     Trace count cache-hops" << std::endl
+            << "    -u user      Proxy authentication username" << std::endl
+            << "    -U user      WWW authentication username" << std::endl
+            << "    -V version   HTTP Version. Use '-' for HTTP/0.9 omitted case" << std::endl
+            << "    -w password  Proxy authentication password" << std::endl
+            << "    -W password  WWW authentication password" << std::endl
+    ;
     exit(1);
 }
 
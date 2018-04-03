 2003-11-05  Hrvoje Niksic  <hniksic@xemacs.org>
 
+	* connect.c (resolve_bind_address): Use a more accurate error
+	message -- we're not binding to ANY, we're disabling bind
+	altogether.
+
+2003-11-05  Hrvoje Niksic  <hniksic@xemacs.org>
+
 	* cookies.c (save_cookies_mapper): Respect the setting of
 	keep-session-cookies.
 	(cookie_jar_load): Import session cookies.

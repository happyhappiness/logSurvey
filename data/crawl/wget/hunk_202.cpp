+2014-11-19  Darshit Shah  <darnir@gmail.com>
+
+	* exits.c (get_status_for_err): GATEWAYTIMEOUT is a Server Error and Wget's
+	exit code should reflect that
+	* wget.h: Add GATEWAYTIMEOUT as an error
+	* http.c (http_loop): Gateway timeout errors should be non-fatal
+
 2014-11-19  Tim Ruehsen  <tim.ruehsen@gmx.de>
 
 	* openssl.c (ssl_check_certificate): Fix memory leak

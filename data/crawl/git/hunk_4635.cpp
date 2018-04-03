 {
 	int r = transport_set_option(transport, name, value);
 	if (r < 0)
-		die("Option \"%s\" value \"%s\" is not valid for %s",
+		die(_("Option \"%s\" value \"%s\" is not valid for %s"),
 			name, value, transport->url);
 	if (r > 0)
-		warning("Option \"%s\" is ignored for %s\n",
+		warning(_("Option \"%s\" is ignored for %s\n"),
 			name, transport->url);
 }
 

 	return 0;
 }
 
+static void set_option(const char *name, const char *value)
+{
+	int r = transport_set_option(transport, name, value);
+	if (r < 0)
+		die("Option \"%s\" value \"%s\" is not valid for %s\n",
+			name, value, transport->url);
+	if (r > 0)
+		warning("Option \"%s\" is ignored for %s\n",
+			name, transport->url);
+}
+
 int cmd_fetch(int argc, const char **argv, const char *prefix)
 {
 	struct remote *remote;

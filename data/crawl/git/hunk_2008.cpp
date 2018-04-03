 static int ambiguous;
 static struct string_list list;
 
+static struct {
+	int called;
+	const char *arg;
+	int unset;
+} length_cb;
+
 static int length_callback(const struct option *opt, const char *arg, int unset)
 {
-	printf("Callback: \"%s\", %d\n",
-		(arg ? arg : "not set"), unset);
+	length_cb.called = 1;
+	length_cb.arg = arg;
+	length_cb.unset = unset;
+
 	if (unset)
 		return 1; /* do not support unset */
 

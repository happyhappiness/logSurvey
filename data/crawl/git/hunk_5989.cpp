 
 #define missing_target(a) missing__target((a)->http_code, (a)->curl_result)
 
+/* Options for http_request_*() */
+#define HTTP_NO_CACHE		1
+
+/* Return values for http_request_*() */
+#define HTTP_OK			0
+#define HTTP_MISSING_TARGET	1
+#define HTTP_ERROR		2
+#define HTTP_START_FAILED	3
+
+/*
+ * Requests an url and stores the result in a strbuf.
+ *
+ * If the result pointer is NULL, a HTTP HEAD request is made instead of GET.
+ */
+int http_get_strbuf(const char *url, struct strbuf *result, int options);
+
+/*
+ * Downloads an url and stores the result in the given file.
+ *
+ * If a previous interrupted download is detected (i.e. a previous temporary
+ * file is still around) the download is resumed.
+ */
+int http_get_file(const char *url, const char *filename, int options);
+
+/*
+ * Prints an error message using error() containing url and curl_errorstr,
+ * and returns ret.
+ */
+int http_error(const char *url, int ret);
+
 extern int http_fetch_ref(const char *base, struct ref *ref);
 
 #endif /* HTTP_H */
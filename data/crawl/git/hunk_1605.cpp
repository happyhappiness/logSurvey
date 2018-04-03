 	strbuf_release(&summary);
 }
 
-static void wt_status_print_other(struct wt_status *s,
-				  struct string_list *l,
-				  const char *what,
-				  const char *how)
+static void wt_longstatus_print_other(struct wt_status *s,
+				      struct string_list *l,
+				      const char *what,
+				      const char *how)
 {
 	int i;
 	struct strbuf buf = STRBUF_INIT;

 	}
 }
 
-void wt_porcelain_print(struct wt_status *s)
+static void wt_porcelain_print(struct wt_status *s)
 {
 	s->use_color = 0;
 	s->relative_paths = 0;
 	s->prefix = NULL;
 	s->no_gettext = 1;
 	wt_shortstatus_print(s);
 }
+
+void wt_status_print(struct wt_status *s)
+{
+	switch (s->status_format) {
+	case STATUS_FORMAT_SHORT:
+		wt_shortstatus_print(s);
+		break;
+	case STATUS_FORMAT_PORCELAIN:
+		wt_porcelain_print(s);
+		break;
+	case STATUS_FORMAT_UNSPECIFIED:
+		die("BUG: finalize_deferred_config() should have been called");
+		break;
+	case STATUS_FORMAT_NONE:
+	case STATUS_FORMAT_LONG:
+		wt_longstatus_print(s);
+		break;
+	}
+}

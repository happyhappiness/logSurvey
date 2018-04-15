 		XSRETURN_EMPTY;
 } /* static XS (Collectd_plugin_dispatch_values) */
 
+/*
+ * Collectd::plugin_log (level, message).
+ *
+ * level:
+ *   log level (LOG_DEBUG, ... LOG_ERR)
+ *
+ * message:
+ *   log message
+ */
+static XS (Collectd_plugin_log)
+{
+	dXSARGS;
+
+	if (2 != items) {
+		log_err ("Usage: Collectd::plugin_log(level, message)");
+		XSRETURN_EMPTY;
+	}
+
+	log_debug ("Collectd::plugin_log: level = %i, message = \"%s\"",
+			SvIV (ST (0)), SvPV_nolen (ST (1)));
+	plugin_log (SvIV (ST (0)), SvPV_nolen (ST (1)));
+	XSRETURN_YES;
+} /* static XS (Collectd_plugin_log) */
+
 /*
  * Collectd::bootstrap ().
  */
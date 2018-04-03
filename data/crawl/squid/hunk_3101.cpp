 
     gettimeofday(&now, NULL);
     if (now.tv_sec != last_t) {
-        tm = localtime((const time_t*)&now.tv_sec);
-        strftime(buf, 127, "%Y/%m/%d %H:%M:%S", tm);
-        last_t = now.tv_sec;
+	tm = localtime((const time_t *) &now.tv_sec);
+	strftime(buf, 127, "%Y/%m/%d %H:%M:%S", tm);
+	last_t = now.tv_sec;
     }
     return buf;
 }
 
 #ifndef gss_mech_spnego
-static gss_OID_desc _gss_mech_spnego = { 6, (void *) "\x2b\x06\x01\x05\x05\x02" };
+static gss_OID_desc _gss_mech_spnego =
+{6, (void *) "\x2b\x06\x01\x05\x05\x02"};
 gss_OID gss_mech_spnego = &_gss_mech_spnego;
 #endif
 
 int
 check_gss_err(OM_uint32 major_status, OM_uint32 minor_status,
-              const char *function)
+    const char *function)
 {
     if (GSS_ERROR(major_status)) {
-        OM_uint32 maj_stat, min_stat;
-        OM_uint32 msg_ctx = 0;
-        gss_buffer_desc status_string;
-        char buf[1024];
-        size_t len;
-
-        len = 0;
-        msg_ctx = 0;
-        while (!msg_ctx) {
-            /* convert major status code (GSS-API error) to text */
-            maj_stat = gss_display_status(&min_stat, major_status,
-                                          GSS_C_GSS_CODE, GSS_C_NULL_OID, &msg_ctx, &status_string);
-            if (maj_stat == GSS_S_COMPLETE) {
-                if (sizeof(buf) > len + status_string.length + 1) {
-                    snprintf(buf + len, (sizeof(buf)-len), "%s", (char *)status_string.value);
-                    len += status_string.length;
-                }
-                gss_release_buffer(&min_stat, &status_string);
-                break;
-            }
-            gss_release_buffer(&min_stat, &status_string);
-        }
-        if (sizeof(buf) > len + 2) {
-            snprintf(buf + len, (sizeof(buf)-len), "%s", ". ");
-            len += 2;
-        }
-        msg_ctx = 0;
-        while (!msg_ctx) {
-            /* convert minor status code (underlying routine error) to text */
-            maj_stat = gss_display_status(&min_stat, minor_status,
-                                          GSS_C_MECH_CODE, GSS_C_NULL_OID, &msg_ctx, &status_string);
-            if (maj_stat == GSS_S_COMPLETE) {
-                if (sizeof(buf) > len + status_string.length) {
-                    snprintf(buf + len, (sizeof(buf)-len), "%s", (char *) status_string.value);
-                    len += status_string.length;
-                }
-                gss_release_buffer(&min_stat, &status_string);
-                break;
-            }
-            gss_release_buffer(&min_stat, &status_string);
-        }
-        fprintf(stderr, "%s| %s: %s failed: %s\n", LogTime(), PROGRAM, function,
-                buf);
-        return (1);
+	OM_uint32 maj_stat, min_stat;
+	OM_uint32 msg_ctx = 0;
+	gss_buffer_desc status_string;
+	char buf[1024];
+	size_t len;
+
+	len = 0;
+	msg_ctx = 0;
+	while (!msg_ctx) {
+	    /* convert major status code (GSS-API error) to text */
+	    maj_stat = gss_display_status(&min_stat, major_status,
+		GSS_C_GSS_CODE, GSS_C_NULL_OID, &msg_ctx, &status_string);
+	    if (maj_stat == GSS_S_COMPLETE) {
+		if (sizeof(buf) > len + status_string.length + 1) {
+		    snprintf(buf + len, (sizeof(buf) - len), "%s", (char *) status_string.value);
+		    len += status_string.length;
+		}
+		gss_release_buffer(&min_stat, &status_string);
+		break;
+	    }
+	    gss_release_buffer(&min_stat, &status_string);
+	}
+	if (sizeof(buf) > len + 2) {
+	    snprintf(buf + len, (sizeof(buf) - len), "%s", ". ");
+	    len += 2;
+	}
+	msg_ctx = 0;
+	while (!msg_ctx) {
+	    /* convert minor status code (underlying routine error) to text */
+	    maj_stat = gss_display_status(&min_stat, minor_status,
+		GSS_C_MECH_CODE, GSS_C_NULL_OID, &msg_ctx, &status_string);
+	    if (maj_stat == GSS_S_COMPLETE) {
+		if (sizeof(buf) > len + status_string.length) {
+		    snprintf(buf + len, (sizeof(buf) - len), "%s", (char *) status_string.value);
+		    len += status_string.length;
+		}
+		gss_release_buffer(&min_stat, &status_string);
+		break;
+	    }
+	    gss_release_buffer(&min_stat, &status_string);
+	}
+	fprintf(stderr, "%s| %s: %s failed: %s\n", LogTime(), PROGRAM, function,
+	    buf);
+	return (1);
     }
     return (0);
 }

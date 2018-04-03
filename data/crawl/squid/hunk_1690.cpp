             if (norealm && (p = strchr(user, '@')) != NULL) {
                 *p = '\0';
             }
+
+#if HAVE_PAC_SUPPORT
+            ret = krb5_init_context(&context);
+            if (!check_k5_err(context, "krb5_init_context", ret)) {
+#if HAVE_HEIMDAL_KERBEROS
+#define ADWIN2KPAC 128
+                major_status = gsskrb5_extract_authz_data_from_sec_context(&minor_status,
+                               gss_context, ADWIN2KPAC, &data_set);
+                if (!check_gss_err(major_status, minor_status,
+                                   "gsskrb5_extract_authz_data_from_sec_context()", log, 0)) {
+                    ret = krb5_pac_parse(context, data_set.value, data_set.length, &pac);
+                    gss_release_buffer(&minor_status, &data_set);
+                    if (!check_k5_err(context, "krb5_pac_parse", ret)) {
+                        ag = get_ad_groups((char *)&ad_groups, context, pac);
+                        krb5_pac_free(context, pac);
+                    }
+                    krb5_free_context(context);
+                }
+#else
+                type_id.value = (void *)"mspac";
+                type_id.length = strlen((char *)type_id.value);
+#define KRB5PACLOGONINFO        1
+                major_status = gss_map_name_to_any(&minor_status, client_name, KRB5PACLOGONINFO, &type_id, (gss_any_t *)&pac);
+                if (!check_gss_err(major_status, minor_status, "gss_map_name_to_any()", log, 0)) {
+                    ag = get_ad_groups((char *)&ad_groups,context, pac);
+                }
+                (void)gss_release_any_name_mapping(&minor_status, client_name, &type_id, (gss_any_t *)&pac);
+                krb5_free_context(context);
+#endif
+            }
+            if (ag) {
+                debug((char *) "%s| %s: DEBUG: Groups %s\n", LogTime(), PROGRAM, ag);
+            }
+#endif
             fprintf(stdout, "AF %s %s\n", token, user);
-            debug((char *) "%s| %s: DEBUG: AF %s %s\n", LogTime(), PROGRAM, token, rfc1738_escape(user));
+            rfc_user = rfc1738_escape(user);
+            debug((char *) "%s| %s: DEBUG: AF %s %s\n", LogTime(), PROGRAM, token, rfc_user);
             if (log)
                 fprintf(stderr, "%s| %s: INFO: User %s authenticated\n", LogTime(),
                         PROGRAM, rfc1738_escape(user));
             goto cleanup;
         } else {
-            if (check_gss_err(major_status, minor_status, "gss_accept_sec_context()", log))
+            if (check_gss_err(major_status, minor_status, "gss_accept_sec_context()", log, 1))
                 goto cleanup;
             if (major_status & GSS_S_CONTINUE_NEEDED) {
                 debug((char *) "%s| %s: INFO: continuation needed\n", LogTime(), PROGRAM);

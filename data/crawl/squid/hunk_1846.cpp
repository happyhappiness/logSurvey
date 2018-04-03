     msg += '\n';
     helperSubmit(ssl_crtd, msg.c_str(), callback, data);
 }
+#endif //USE_SSL_CRTD
+
+#if 1 // USE_SSL_CERT_VALIDATOR
+/*ssl_crtd_validator*/
+
+Ssl::CertValidationHelper * Ssl::CertValidationHelper::GetInstance()
+{
+    static Ssl::CertValidationHelper sslHelper;
+    if (!Ssl::TheConfig.ssl_crt_validator)
+        return NULL;
+    return &sslHelper;
+}
+
+Ssl::CertValidationHelper::CertValidationHelper() : ssl_crt_validator(NULL)
+{
+}
+
+Ssl::CertValidationHelper::~CertValidationHelper()
+{
+    Shutdown();
+}
+
+void Ssl::CertValidationHelper::Init()
+{
+    assert(ssl_crt_validator == NULL);
+
+    // we need to start ssl_crtd only if some port(s) need to bump SSL
+    bool found = false;
+    for (AnyP::PortCfg *s = ::Config.Sockaddr.http; !found && s; s = s->next)
+        found = s->sslBump;
+    for (AnyP::PortCfg *s = ::Config.Sockaddr.https; !found && s; s = s->next)
+        found = s->sslBump;
+    if (!found)
+        return;
+
+    ssl_crt_validator = new helper("ssl_crt_validator");
+    ssl_crt_validator->childs.updateLimits(Ssl::TheConfig.ssl_crt_validator_Children);
+    ssl_crt_validator->ipc_type = IPC_STREAM;
+    // The crtd messages may contain the eol ('\n') character. We are
+    // going to use the '\1' char as the end-of-message mark.
+    ssl_crt_validator->eom = '\1';
+    assert(ssl_crt_validator->cmdline == NULL);
+    {
+        char *tmp = xstrdup(Ssl::TheConfig.ssl_crt_validator);
+        char *tmp_begin = tmp;
+        char * token = NULL;
+        while ((token = strwordtok(NULL, &tmp))) {
+            wordlistAdd(&ssl_crt_validator->cmdline, token);
+        }
+        xfree(tmp_begin);
+    }
+    helperOpenServers(ssl_crt_validator);
+}
+
+void Ssl::CertValidationHelper::Shutdown()
+{
+    if (!ssl_crt_validator)
+        return;
+    helperShutdown(ssl_crt_validator);
+    wordlistDestroy(&ssl_crt_validator->cmdline);
+    delete ssl_crt_validator;
+    ssl_crt_validator = NULL;
+}
+
+void Ssl::CertValidationHelper::sslSubmit(CrtdMessage const & message, HLPCB * callback, void * data)
+{
+    static time_t first_warn = 0;
+    assert(ssl_crt_validator);
+
+    if (ssl_crt_validator->stats.queue_size >= (int)(ssl_crt_validator->childs.n_running * 2)) {
+        if (first_warn == 0)
+            first_warn = squid_curtime;
+        if (squid_curtime - first_warn > 3 * 60)
+            fatal("ssl_crtvd queue being overloaded for long time");
+        debugs(83, DBG_IMPORTANT, "WARNING: ssl_crtvd queue overload, rejecting");
+        HelperReply failReply;
+        failReply.result = HelperReply::BrokenHelper;
+        failReply.notes.add("message", "error 45 Temporary network problem, please retry later");
+        callback(data, failReply);
+        return;
+    }
+
+    first_warn = 0;
+    std::string msg = message.compose();
+    msg += '\n';
+    helperSubmit(ssl_crt_validator, msg.c_str(), callback, data);
+}
+#endif // USE_SSL_CERT_VALIDATOR

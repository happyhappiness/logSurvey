 
 void Ssl::CertValidationHelper::sslSubmit(Ssl::CertValidationRequest const &request, Ssl::CertValidationHelper::CVHCB * callback, void * data)
 {
-    static time_t first_warn = 0;
     assert(ssl_crt_validator);
 
-    if (ssl_crt_validator->stats.queue_size >= (int)(ssl_crt_validator->childs.n_running * 2)) {
-        if (first_warn == 0)
-            first_warn = squid_curtime;
-        if (squid_curtime - first_warn > 3 * 60)
-            fatal("ssl_crtvd queue being overloaded for long time");
-        debugs(83, DBG_IMPORTANT, "WARNING: ssl_crtvd queue overload, rejecting");
-        Ssl::CertValidationResponse resp;
-        resp.resultCode = ::Helper::BrokenHelper;
-        callback(data, resp);
-        return;
-    }
-    first_warn = 0;
-
     Ssl::CertValidationMsg message(Ssl::CrtdMessage::REQUEST);
     message.setCode(Ssl::CertValidationMsg::code_cert_validate);
     message.composeRequest(request);

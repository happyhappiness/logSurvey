         if (squid_curtime - first_warn > 3 * 60)
             fatal("ssl_crtvd queue being overloaded for long time");
         debugs(83, DBG_IMPORTANT, "WARNING: ssl_crtvd queue overload, rejecting");
-        HelperReply failReply;
-        failReply.result = HelperReply::BrokenHelper;
-        failReply.notes.add("message", "error 45 Temporary network problem, please retry later");
-        callback(data, failReply);
+        Ssl::CertValidationResponse resp;
+        resp.resultCode = HelperReply::BrokenHelper;
+        callback(data, resp);
         return;
     }
-
     first_warn = 0;
-    std::string msg = message.compose();
-    msg += '\n';
-    helperSubmit(ssl_crt_validator, msg.c_str(), callback, data);
+
+    Ssl::CertValidationMsg message(Ssl::CrtdMessage::REQUEST);
+    message.setCode(Ssl::CertValidationMsg::code_cert_validate);
+    message.composeRequest(request);
+    debugs(83, 5, "SSL crtvd request: " << message.compose().c_str());
+
+    submitData *crtdvdData = new submitData;
+    crtdvdData->query = message.compose();
+    crtdvdData->query += '\n';
+    crtdvdData->callback = callback;
+    crtdvdData->data = cbdataReference(data);
+    crtdvdData->ssl = request.ssl;
+    CRYPTO_add(&crtdvdData->ssl->references,1,CRYPTO_LOCK_SSL);
+    Ssl::CertValidationResponse const*validationResponse;
+
+    if (CertValidationHelper::HelperCache &&
+        (validationResponse = CertValidationHelper::HelperCache->get(crtdvdData->query.c_str()))) {
+        callback(data, *validationResponse);
+        cbdataReferenceDone(crtdvdData->data);
+        SSL_free(crtdvdData->ssl);
+        delete crtdvdData;
+        return;
+    }
+    helperSubmit(ssl_crt_validator, crtdvdData->query.c_str(), sslCrtvdHandleReplyWrapper, crtdvdData);
 }

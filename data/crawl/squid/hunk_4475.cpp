         fatalf("authenticateNTLMHandleReply: *** Unsupported helper response ***, '%s'\n", reply);
     }
 
+    if (ntlm_request->request) {
+	HTTPMSGUNLOCK(ntlm_request->request);
+	ntlm_request->request = NULL;
+    }
     r->handler(r->data, NULL);
     cbdataReferenceDone(r->data);
     authenticateStateFree(r);

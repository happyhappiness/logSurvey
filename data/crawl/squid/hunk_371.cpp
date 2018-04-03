         // no default so that a compiler can check that we have covered all cases
     }
 
-    ClientSocketContext *context = abortRequestParsing(errUri);
+    Http::Stream *context = abortRequestParsing(errUri);
     clientStreamNode *node = context->getClientReplyContext();
     Must(node);
     clientReplyContext *repContext = dynamic_cast<clientReplyContext *>(node->data.getRaw());

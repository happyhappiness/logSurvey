     AsyncCall::Pointer call = commCbCall(33, 5, "ClientSocketContext::wroteControlMsg",
                                          CommIoCbPtrFun(&WroteControlMsg, this));
 
-    if (getConn()->isFtp) {
-        FtpWriteForwardedReply(this, rep.getRaw(), call);
-        return;
-    }
-
-    // apply selected clientReplyContext::buildReplyHeader() mods
-    // it is not clear what headers are required for control messages
-    rep->header.removeHopByHopEntries();
-    rep->header.putStr(HDR_CONNECTION, "keep-alive");
-    httpHdrMangleList(&rep->header, http->request, ROR_REPLY);
-
-    MemBuf *mb = rep->pack();
-
-    debugs(11, 2, "HTTP Client " << clientConnection);
-    debugs(11, 2, "HTTP Client CONTROL MSG:\n---------\n" << mb->buf << "\n----------");
-
-    Comm::Write(clientConnection, mb, call);
-
-    delete mb;
+    getConn()->writeControlMsgAndCall(this, rep.getRaw(), call);
 }
 
 /// called when we wrote the 1xx response

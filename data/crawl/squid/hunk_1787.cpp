 
     comm_add_close_handler(conn->fd, Ident::Close, state);
 
-    MemBuf mb;
-    mb.init();
-    mb.Printf("%d, %d\r\n",
-              conn->remote.GetPort(),
-              conn->local.GetPort());
     AsyncCall::Pointer writeCall = commCbCall(5,4, "Ident::WriteFeedback",
                                    CommIoCbPtrFun(Ident::WriteFeedback, state));
-    Comm::Write(conn, &mb, writeCall);
+    Comm::Write(conn, &queryMsg, writeCall);
     AsyncCall::Pointer readCall = commCbCall(5,4, "Ident::ReadReply",
                                   CommIoCbPtrFun(Ident::ReadReply, state));
     comm_read(conn, state->buf, IDENT_BUFSIZE, readCall);

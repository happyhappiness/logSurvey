 #define CVT_BUF_SZ 512
 
 const char *
-ErrorState::Convert(char token)
+ErrorState::Convert(char token, bool url_presentable)
 {
     static MemBuf mb;
     const char *p = NULL;	/* takes priority over mb if set */
     int do_quote = 1;
+    int no_urlescape = 1;       /* item is NOT to be further URL-encoded */
     char ntoabuf[MAX_IPSTRLEN];
 
     mb.reset();
 
     switch (token) {
 
     case 'a':
-
         if (request && request->auth_user_request)
             p = request->auth_user_request->username();
-
         if (!p)
             p = "-";
-
         break;
 
     case 'B':
+        if (url_presentable) break;
         p = request ? ftpUrlWith2f(request) : "[no URL]";
-
+        no_urlescape = 1;
         break;
 
     case 'c':
+        if (url_presentable) break;
         p = errorPageName(type);
-
         break;
 
     case 'e':
         mb.Printf("%d", xerrno);
-
         break;
 
     case 'E':
-
         if (xerrno)
             mb.Printf("(%d) %s", xerrno, strerror(xerrno));
         else
             mb.Printf("[No Error]");
-
         break;
 
     case 'f':
+        if (url_presentable) break;
         /* FTP REQUEST LINE */
         if (ftp.request)
             p = ftp.request;
         else
             p = "nothing";
-
         break;
 
     case 'F':
+        if (url_presentable) break;
         /* FTP REPLY LINE */
         if (ftp.request)
             p = ftp.reply;
         else
             p = "nothing";
-
         break;
 
     case 'g':
+        if (url_presentable) break;
         /* FTP SERVER MESSAGE */
         wordlistCat(ftp.server_msg, &mb);
-
         break;
 
     case 'h':

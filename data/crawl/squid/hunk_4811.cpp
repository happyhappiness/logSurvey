 #include "squid.h"
 #include "HttpReply.h"
 
+HttpReply::HttpReply() : HttpMsg(hoReply)
+{
+    fatal ("Not implemented.");
+}
+
+HttpReply::~HttpReply()
+{
+    fatal ("Not implemented.");
+}
+
 void
 HttpReply::absorb(HttpReply * new_rep)
 {

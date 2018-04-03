 msgid "Failed to get certificate key from %s\n"
 msgstr "無法由 %s 載入相關認證的 key\n"
 
-#: src/http.c:666 src/http.c:1592
+#: src/http.c:662 src/http.c:1592
 msgid "Unable to establish SSL connection.\n"
-msgstr "不能建立 SSL 連線.\n"
+msgstr "不能建立 SSL 連線。\n"
 
-#: src/http.c:674
+#: src/http.c:670
 #, c-format
 msgid "Reusing connection to %s:%hu.\n"
-msgstr "再使用到 %s:%hu 的連線.\n"
+msgstr "再使用連到 %s:%hu 的連線。\n"
 
 #: src/http.c:860
 #, c-format
 msgid "Failed writing HTTP request: %s.\n"
-msgstr "無法寫入 HTTP 要求: %s.\n"
+msgstr "無法寫入 HTTP 要求：%s。\n"
 
 #: src/http.c:865
 #, c-format
 msgid "%s request sent, awaiting response... "
-msgstr "已送出 %s 要求，等候回應中…"
+msgstr "已送出 %s 要求，等候回應中… "
 
 #: src/http.c:909
 msgid "End of file while parsing headers.\n"
 msgstr "分析標頭時檔案結束。\n"
 
-#: src/http.c:920
+#: src/http.c:919
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "讀取標頭時發生錯誤(%s)。\n"
 
-#: src/http.c:960
+#: src/http.c:958
 msgid "No data received"
 msgstr "沒收到資料"
 
-#: src/http.c:962
+#: src/http.c:960
 msgid "Malformed status line"
 msgstr "畸形的狀態行"
 
-#: src/http.c:967
+#: src/http.c:965
 msgid "(no description)"
 msgstr "(沒有描述)"
 
-#: src/http.c:1090
+#: src/http.c:1088
 msgid "Authorization failed.\n"
-msgstr "認證失敗!\n"
+msgstr "認證失敗！\n"
 
-#: src/http.c:1097
+#: src/http.c:1095
 msgid "Unknown authentication scheme.\n"
-msgstr "未知的認證方式.\n"
+msgstr "未知的認證方式。\n"
 
-#: src/http.c:1173
+#: src/http.c:1135
+#, c-format
+msgid "Location: %s%s\n"
+msgstr "位置：%s%s\n"
+
+#: src/http.c:1136 src/http.c:1268
+msgid "unspecified"
+msgstr "沒有指定"
+
+#: src/http.c:1137
+msgid " [following]"
+msgstr " [跟隨中]"
+
+#: src/http.c:1199
 msgid ""
 "\n"
 "    The file is already fully retrieved; nothing to do.\n"

 "Content-Type: text/plain; charset=big5\n"
 "Content-Transfer-Encoding: 8bit\n"
 
+#: src/ftp-ls.c:698 src/ftp-ls.c:700
+#, c-format
+msgid "Index of /%s on %s:%d"
+msgstr "/%s 的索引在 %s:%d"
+
+#: src/ftp-ls.c:722
+msgid "time unknown       "
+msgstr "時間不明           "
+
+#: src/ftp-ls.c:726
+msgid "File        "
+msgstr "檔案        "
+
+#: src/ftp-ls.c:729
+msgid "Directory   "
+msgstr "目錄        "
+
+#: src/ftp-ls.c:732
+msgid "Link        "
+msgstr "連結        "
+
+#: src/ftp-ls.c:735
+msgid "Not sure    "
+msgstr "沒有確定    "
+
+#: src/ftp-ls.c:753
+#, c-format
+msgid " (%s bytes)"
+msgstr " (%s 位元組)"
+
 #. Login to the server:
 #. First: Establish the control connection.
-#: src/ftp.c:146 src/http.c:337
+#: src/ftp.c:152 src/http.c:582
 #, c-format
 msgid "Connecting to %s:%hu... "
 msgstr "正連往 %s: %hu... "
 
-#: src/ftp.c:168 src/ftp.c:409 src/http.c:354
+#: src/ftp.c:174 src/ftp.c:520 src/http.c:599
 #, c-format
 msgid "Connection to %s:%hu refused.\n"
 msgstr "連線到 %s: %hu 被拒絕. \n"
 
 #. Second: Login with proper USER/PASS sequence.
-#: src/ftp.c:189 src/http.c:365
+#: src/ftp.c:195 src/http.c:610
 msgid "connected!\n"
 msgstr "連上了!\n"
 
-#: src/ftp.c:190
+#: src/ftp.c:196
 #, c-format
 msgid "Logging in as %s ... "
 msgstr "使用 %s 簽入... "
 
-#: src/ftp.c:199 src/ftp.c:251 src/ftp.c:299 src/ftp.c:351 src/ftp.c:445
-#: src/ftp.c:518 src/ftp.c:566 src/ftp.c:614
+#: src/ftp.c:205 src/ftp.c:258 src/ftp.c:289 src/ftp.c:314 src/ftp.c:410
+#: src/ftp.c:462 src/ftp.c:556 src/ftp.c:629 src/ftp.c:677 src/ftp.c:725
 msgid "Error in server response, closing control connection.\n"
 msgstr "伺服器端回應時發生錯誤，正在關閉連線控制.\n"
 
-#: src/ftp.c:207
+#: src/ftp.c:213
 msgid "Error in server greeting.\n"
 msgstr "與伺服器連線時發生錯誤.\n"
 
-#: src/ftp.c:214 src/ftp.c:260 src/ftp.c:308 src/ftp.c:360 src/ftp.c:455
-#: src/ftp.c:528 src/ftp.c:576 src/ftp.c:624
+#: src/ftp.c:221 src/ftp.c:323 src/ftp.c:419 src/ftp.c:471 src/ftp.c:566
+#: src/ftp.c:639 src/ftp.c:687 src/ftp.c:735
 msgid "Write failed, closing control connection.\n"
 msgstr "寫入失敗, 正在關閉連線控制.\n"
 
-#: src/ftp.c:221
+#: src/ftp.c:228
 msgid "The server refuses login.\n"
 msgstr "伺服器拒絕簽入.\n"
 
-#: src/ftp.c:228
+#: src/ftp.c:235
 msgid "Login incorrect.\n"
 msgstr "簽入不正確.\n"
 
-#: src/ftp.c:235
+#: src/ftp.c:242
 msgid "Logged in!\n"
 msgstr "已經簽入了!\n"
 
-#: src/ftp.c:268
+#: src/ftp.c:267
+msgid "Server error, can't determine system type.\n"
+msgstr ""
+
+#: src/ftp.c:277 src/ftp.c:541 src/ftp.c:613 src/ftp.c:657
+msgid "done.    "
+msgstr "完成.    "
+
+#: src/ftp.c:303 src/ftp.c:440 src/ftp.c:708 src/ftp.c:756 src/url.c:1432
+msgid "done.\n"
+msgstr "完成.\n"
+
+#: src/ftp.c:331
 #, c-format
 msgid "Unknown type `%c', closing control connection.\n"
 msgstr "不明的形式 `%c', 正在關閉連線控制.\n"
 
-#: src/ftp.c:281
+#: src/ftp.c:344
 msgid "done.  "
 msgstr "完成.  "
 
-#: src/ftp.c:287
+#: src/ftp.c:350
 msgid "==> CWD not needed.\n"
 msgstr "==> 不需要 CWD.\n"
 
-#: src/ftp.c:315
+#: src/ftp.c:426
 #, c-format
-msgid "No such directory `%s'.\n\n"
-msgstr "沒有 `%s' 這個目錄.\n\n"
-
-#: src/ftp.c:329 src/ftp.c:597 src/ftp.c:645 src/url.c:1421
-msgid "done.\n"
-msgstr "完成.\n"
+msgid ""
+"No such directory `%s'.\n"
+"\n"
+msgstr ""
+"沒有 `%s' 這個目錄.\n"
+"\n"
 
 #. do not CWD
-#: src/ftp.c:333
+#: src/ftp.c:444
 msgid "==> CWD not required.\n"
 msgstr "==> 不需要 CWD.\n"
 
-#: src/ftp.c:367
+#: src/ftp.c:478
 msgid "Cannot initiate PASV transfer.\n"
 msgstr "無法啟動 PASV 傳輸.\n"
 
-#: src/ftp.c:371
+#: src/ftp.c:482
 msgid "Cannot parse PASV response.\n"
 msgstr "無法分析 PASV 回應內容.\n"
 
-#: src/ftp.c:385
+#: src/ftp.c:496
 #, c-format
 msgid "Will try connecting to %s:%hu.\n"
 msgstr "將會繼續嘗試與 %s 連線: %hu.\n"
 
-#: src/ftp.c:472
+#: src/ftp.c:583
 #, c-format
 msgid "Bind error (%s).\n"
 msgstr "BIND 錯誤 (%s).\n"
 
-#: src/ftp.c:488
+#: src/ftp.c:599
 msgid "Invalid PORT.\n"
 msgstr "無效的 PORT.\n"
 
-#: src/ftp.c:502 src/ftp.c:546
-msgid "done.    "
-msgstr "完成.    "
-
-#: src/ftp.c:535
-msgid "\nREST failed, starting from scratch.\n"
-msgstr "\nRSET 失敗，正由錯亂中開始中.\n"
+#: src/ftp.c:646
+msgid ""
+"\n"
+"REST failed, starting from scratch.\n"
+msgstr ""
+"\n"
+"RSET 失敗，正由錯亂中開始中.\n"
 
-#: src/ftp.c:584
+#: src/ftp.c:695
 #, c-format
-msgid "No such file `%s'.\n\n"
-msgstr "沒有 `%s' 這個檔案.\n\n"
+msgid ""
+"No such file `%s'.\n"
+"\n"
+msgstr ""
+"沒有 `%s' 這個檔案.\n"
+"\n"
 
-#: src/ftp.c:632
+#: src/ftp.c:743
 #, c-format
-msgid "No such file or directory `%s'.\n\n"
-msgstr "沒有 `%s' 這個檔案或目錄.\n\n"
+msgid ""
+"No such file or directory `%s'.\n"
+"\n"
+msgstr ""
+"沒有 `%s' 這個檔案或目錄.\n"
+"\n"
 
-#: src/ftp.c:690 src/ftp.c:697
+#: src/ftp.c:819 src/ftp.c:826
 #, c-format
 msgid "Length: %s"
 msgstr "長度: %s"
 
-#: src/ftp.c:692 src/ftp.c:699
+#: src/ftp.c:821 src/ftp.c:828
 #, c-format
 msgid " [%s to go]"
 msgstr " [%s 開始]"
 
-#: src/ftp.c:701
+#: src/ftp.c:830
 msgid " (unauthoritative)\n"
 msgstr " (未獲認可的)\n"
 
-#: src/ftp.c:719
+#: src/ftp.c:856
 #, c-format
 msgid "%s: %s, closing control connection.\n"
 msgstr "%s: %s, 正在關閉連線控制.\n"
 
-#: src/ftp.c:727
+#: src/ftp.c:864
 #, c-format
 msgid "%s (%s) - Data connection: %s; "
 msgstr "%s (%s) - 資料連線: %s; "
 
-#: src/ftp.c:744
+#: src/ftp.c:881
 msgid "Control connection closed.\n"
 msgstr "連線控制已經被關閉了.\n"
 
-#: src/ftp.c:762
+#: src/ftp.c:899
 msgid "Data transfer aborted.\n"
 msgstr "資料傳輸已經被中斷了.\n"
 
-#: src/ftp.c:828
+#: src/ftp.c:963
 #, c-format
 msgid "File `%s' already there, not retrieving.\n"
 msgstr "檔案 `%s' 已經存在，不會接收.\n"
 
-#: src/ftp.c:894 src/http.c:913
-#, c-format
+#: src/ftp.c:1024 src/http.c:1358
+#, c-format, ycp-format
 msgid "(try:%2d)"
 msgstr "(嘗試:%2d)"
 
-#: src/ftp.c:953 src/http.c:1099
+#: src/ftp.c:1088 src/http.c:1585
 #, c-format
-msgid "%s (%s) - `%s' saved [%ld]\n\n"
-msgstr "%s (%s) - `%s' 被儲存 [%ld]\n\n"
+msgid ""
+"%s (%s) - `%s' saved [%ld]\n"
+"\n"
+msgstr ""
+"%s (%s) - `%s' 被儲存 [%ld]\n"
+"\n"
+
+#: src/ftp.c:1130 src/main.c:771 src/recur.c:505 src/retr.c:580
+#, c-format
+msgid "Removing %s.\n"
+msgstr "正在移除 %s.\n"
 
-#: src/ftp.c:999
+#: src/ftp.c:1171
 #, c-format
 msgid "Using `%s' as listing tmp file.\n"
 msgstr "使用 `%s' 作為列表之暫存檔.\n"
 
-#: src/ftp.c:1011
+#: src/ftp.c:1183
 #, c-format
 msgid "Removed `%s'.\n"
 msgstr "移除 `%s'.\n"
 
-#: src/ftp.c:1047
+#: src/ftp.c:1219
 #, c-format
 msgid "Recursion depth %d exceeded max. depth %d.\n"
 msgstr "遞迴層次 %d 已經超過最大的 %d 層次值. \n"
 
-#: src/ftp.c:1094 src/http.c:1037
+#: src/ftp.c:1271 src/http.c:1512
 #, c-format
-msgid "Local file `%s' is more recent, not retrieving.\n\n"
-msgstr "本地的 `%s' 檔案比較新，所以將不取回.\n\n"
+msgid ""
+"Server file no newer than local file `%s' -- not retrieving.\n"
+"\n"
+msgstr ""
 
-#: src/ftp.c:1100 src/http.c:1043
-#, c-format
-msgid "The sizes do not match (local %ld), retrieving.\n"
+#: src/ftp.c:1279
+msgid "Cannot compare sizes, remote system is VMS.\n"
+msgstr ""
+
+#: src/ftp.c:1285 src/http.c:1520
+#, fuzzy, c-format
+msgid "The sizes do not match (local %ld) -- retrieving.\n"
 msgstr "檔案大小並不相符合 (本地的為 %ld)，正在取回中.\n"
 
-#: src/ftp.c:1117
+#: src/ftp.c:1303
 msgid "Invalid name of the symlink, skipping.\n"
 msgstr "無效的連結裝置名稱，正在跳過中.\n"
 
-#: src/ftp.c:1134
+#: src/ftp.c:1320
 #, c-format
-msgid "Already have correct symlink %s -> %s\n\n"
-msgstr "已經存在正確的 %s -> %s 象徵連結\n\n"
+msgid ""
+"Already have correct symlink %s -> %s\n"
+"\n"
+msgstr ""
+"已經存在正確的 %s -> %s 象徵連結\n"
+"\n"
 
-#: src/ftp.c:1141
+#: src/ftp.c:1328
 #, c-format
 msgid "Creating symlink %s -> %s\n"
 msgstr "正在建立 %s -> %s 的象徵連結\n"
 
-#: src/ftp.c:1152
+#: src/ftp.c:1339
 #, c-format
 msgid "Symlinks not supported, skipping symlink `%s'.\n"
 msgstr "不支援連結裝置，正在跳過 `%s' 這個象徵連結.\n"
 
-#: src/ftp.c:1164
+#: src/ftp.c:1351
 #, c-format
 msgid "Skipping directory `%s'.\n"
 msgstr "正跳過 `%s' 目錄.\n"
 
-#: src/ftp.c:1173
+#: src/ftp.c:1360
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
 msgstr "%s: 不明的/不支援的檔案格式.\n"
 
-#: src/ftp.c:1189
+#: src/ftp.c:1377
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
 msgstr "%s: 錯誤的時間戳記.\n"
 
-#: src/ftp.c:1209
+#: src/ftp.c:1398
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
 msgstr "將不取回從 %d (最大值為 %d) 層後的目錄.\n"
 
-#: src/ftp.c:1248
+#: src/ftp.c:1437
 #, c-format
 msgid "Not descending to `%s' as it is excluded/not-included.\n"
 msgstr "不下行到 `%s' 因為他是被排除的或是非包含進來的.\n"
 
-#: src/ftp.c:1293
+#: src/ftp.c:1482
 #, c-format
 msgid "Rejecting `%s'.\n"
 msgstr "正放棄 `%s' 中.\n"

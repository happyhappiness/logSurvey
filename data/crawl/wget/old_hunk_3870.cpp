"Content-Type: text/plain; charset=big5\n"
"Content-Transfer-Encoding: 8bit\n"

#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:146 src/http.c:337
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "正連往 %s: %hu... "

#: src/ftp.c:168 src/ftp.c:409 src/http.c:354
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "連線到 %s: %hu 被拒絕. \n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:189 src/http.c:365
msgid "connected!\n"
msgstr "連上了!\n"

#: src/ftp.c:190
#, c-format
msgid "Logging in as %s ... "
msgstr "使用 %s 簽入... "

#: src/ftp.c:199 src/ftp.c:251 src/ftp.c:299 src/ftp.c:351 src/ftp.c:445
#: src/ftp.c:518 src/ftp.c:566 src/ftp.c:614
msgid "Error in server response, closing control connection.\n"
msgstr "伺服器端回應時發生錯誤，正在關閉連線控制.\n"

#: src/ftp.c:207
msgid "Error in server greeting.\n"
msgstr "與伺服器連線時發生錯誤.\n"

#: src/ftp.c:214 src/ftp.c:260 src/ftp.c:308 src/ftp.c:360 src/ftp.c:455
#: src/ftp.c:528 src/ftp.c:576 src/ftp.c:624
msgid "Write failed, closing control connection.\n"
msgstr "寫入失敗, 正在關閉連線控制.\n"

#: src/ftp.c:221
msgid "The server refuses login.\n"
msgstr "伺服器拒絕簽入.\n"

#: src/ftp.c:228
msgid "Login incorrect.\n"
msgstr "簽入不正確.\n"

#: src/ftp.c:235
msgid "Logged in!\n"
msgstr "已經簽入了!\n"

#: src/ftp.c:268
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "不明的形式 `%c', 正在關閉連線控制.\n"

#: src/ftp.c:281
msgid "done.  "
msgstr "完成.  "

#: src/ftp.c:287
msgid "==> CWD not needed.\n"
msgstr "==> 不需要 CWD.\n"

#: src/ftp.c:315
#, c-format
msgid "No such directory `%s'.\n\n"
msgstr "沒有 `%s' 這個目錄.\n\n"

#: src/ftp.c:329 src/ftp.c:597 src/ftp.c:645 src/url.c:1421
msgid "done.\n"
msgstr "完成.\n"

#. do not CWD
#: src/ftp.c:333
msgid "==> CWD not required.\n"
msgstr "==> 不需要 CWD.\n"

#: src/ftp.c:367
msgid "Cannot initiate PASV transfer.\n"
msgstr "無法啟動 PASV 傳輸.\n"

#: src/ftp.c:371
msgid "Cannot parse PASV response.\n"
msgstr "無法分析 PASV 回應內容.\n"

#: src/ftp.c:385
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "將會繼續嘗試與 %s 連線: %hu.\n"

#: src/ftp.c:472
#, c-format
msgid "Bind error (%s).\n"
msgstr "BIND 錯誤 (%s).\n"

#: src/ftp.c:488
msgid "Invalid PORT.\n"
msgstr "無效的 PORT.\n"

#: src/ftp.c:502 src/ftp.c:546
msgid "done.    "
msgstr "完成.    "

#: src/ftp.c:535
msgid "\nREST failed, starting from scratch.\n"
msgstr "\nRSET 失敗，正由錯亂中開始中.\n"

#: src/ftp.c:584
#, c-format
msgid "No such file `%s'.\n\n"
msgstr "沒有 `%s' 這個檔案.\n\n"

#: src/ftp.c:632
#, c-format
msgid "No such file or directory `%s'.\n\n"
msgstr "沒有 `%s' 這個檔案或目錄.\n\n"

#: src/ftp.c:690 src/ftp.c:697
#, c-format
msgid "Length: %s"
msgstr "長度: %s"

#: src/ftp.c:692 src/ftp.c:699
#, c-format
msgid " [%s to go]"
msgstr " [%s 開始]"

#: src/ftp.c:701
msgid " (unauthoritative)\n"
msgstr " (未獲認可的)\n"

#: src/ftp.c:719
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, 正在關閉連線控制.\n"

#: src/ftp.c:727
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - 資料連線: %s; "

#: src/ftp.c:744
msgid "Control connection closed.\n"
msgstr "連線控制已經被關閉了.\n"

#: src/ftp.c:762
msgid "Data transfer aborted.\n"
msgstr "資料傳輸已經被中斷了.\n"

#: src/ftp.c:828
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "檔案 `%s' 已經存在，不會接收.\n"

#: src/ftp.c:894 src/http.c:913
#, c-format
msgid "(try:%2d)"
msgstr "(嘗試:%2d)"

#: src/ftp.c:953 src/http.c:1099
#, c-format
msgid "%s (%s) - `%s' saved [%ld]\n\n"
msgstr "%s (%s) - `%s' 被儲存 [%ld]\n\n"

#: src/ftp.c:999
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "使用 `%s' 作為列表之暫存檔.\n"

#: src/ftp.c:1011
#, c-format
msgid "Removed `%s'.\n"
msgstr "移除 `%s'.\n"

#: src/ftp.c:1047
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "遞迴層次 %d 已經超過最大的 %d 層次值. \n"

#: src/ftp.c:1094 src/http.c:1037
#, c-format
msgid "Local file `%s' is more recent, not retrieving.\n\n"
msgstr "本地的 `%s' 檔案比較新，所以將不取回.\n\n"

#: src/ftp.c:1100 src/http.c:1043
#, c-format
msgid "The sizes do not match (local %ld), retrieving.\n"
msgstr "檔案大小並不相符合 (本地的為 %ld)，正在取回中.\n"

#: src/ftp.c:1117
msgid "Invalid name of the symlink, skipping.\n"
msgstr "無效的連結裝置名稱，正在跳過中.\n"

#: src/ftp.c:1134
#, c-format
msgid "Already have correct symlink %s -> %s\n\n"
msgstr "已經存在正確的 %s -> %s 象徵連結\n\n"

#: src/ftp.c:1141
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "正在建立 %s -> %s 的象徵連結\n"

#: src/ftp.c:1152
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "不支援連結裝置，正在跳過 `%s' 這個象徵連結.\n"

#: src/ftp.c:1164
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "正跳過 `%s' 目錄.\n"

#: src/ftp.c:1173
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: 不明的/不支援的檔案格式.\n"

#: src/ftp.c:1189
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: 錯誤的時間戳記.\n"

#: src/ftp.c:1209
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "將不取回從 %d (最大值為 %d) 層後的目錄.\n"

#: src/ftp.c:1248
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "不下行到 `%s' 因為他是被排除的或是非包含進來的.\n"

#: src/ftp.c:1293
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "正放棄 `%s' 中.\n"

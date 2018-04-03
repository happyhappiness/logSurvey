msgid "Failed writing HTTP request: %s.\n"
msgstr "HTTP による接続要求の送信に失敗しました: %s\n"

#: src/http.c:745
msgid "No headers, assuming HTTP/0.9"
msgstr "ヘッダがないので、HTTP/0.9 だと仮定します"

#: src/http.c:1430
msgid "Disabling SSL due to encountered errors.\n"
msgstr "エラーが発生したので SSL を無効にします\n"

#: src/http.c:1548
#, fuzzy, c-format
msgid "POST data file %s missing: %s\n"
msgstr "POST データファイル `%s' がありません: %s\n"

#: src/http.c:1632
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "%s:%d への接続を再利用します。\n"

#: src/http.c:1701
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "プロクシからの読み込みに失敗しました: %s\n"

#: src/http.c:1721
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "プロクシのトンネリングに失敗しました: %s"

#: src/http.c:1766
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s による接続要求を送信しました、応答を待っています... "

#: src/http.c:1777
msgid "No data received.\n"
msgstr "データが受信されませんでした\n"

#: src/http.c:1784
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "ヘッダ内で読み込みエラー(%s)です\n"

#: src/http.c:1831 src/http.c:2385
#, fuzzy, c-format
msgid ""
"File %s already there; not retrieving.\n"
"\n"
msgstr ""
"ファイル `%s' はすでに存在するので、取得しません。\n"
"\n"

#: src/http.c:1985
msgid "Unknown authentication scheme.\n"
msgstr "不明な認証形式です。\n"

#: src/http.c:2016
msgid "Authorization failed.\n"
msgstr "認証に失敗しました。\n"

#: src/http.c:2030
msgid "Malformed status line"
msgstr "奇妙なステータス行です"

#: src/http.c:2032
msgid "(no description)"
msgstr "(説明なし)"

#: src/http.c:2098
#, c-format
msgid "Location: %s%s\n"
msgstr "場所: %s%s\n"

#: src/http.c:2099 src/http.c:2209
msgid "unspecified"
msgstr "特定できません"

#: src/http.c:2100
msgid " [following]"
msgstr " [続く]"

#: src/http.c:2156
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"

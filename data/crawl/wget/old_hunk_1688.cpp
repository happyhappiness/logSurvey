msgid "Failed writing HTTP request: %s.\n"
msgstr "HTTP による接続要求の送信に失敗しました: %s\n"

#: src/http.c:737
msgid "No headers, assuming HTTP/0.9"
msgstr "ヘッダがないので、HTTP/0.9 だと仮定します"

#: src/http.c:1417
msgid "Disabling SSL due to encountered errors.\n"
msgstr "エラーが発生したので SSL を無効にします\n"

#: src/http.c:1570
#, c-format
msgid "POST data file `%s' missing: %s\n"
msgstr "POST データファイル `%s' がありません: %s\n"

#: src/http.c:1619
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "%s:%d への接続を再利用します。\n"

#: src/http.c:1687
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "プロクシからの読み込みに失敗しました: %s\n"

#: src/http.c:1707
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "プロクシのトンネリングに失敗しました: %s"

#: src/http.c:1752
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s による接続要求を送信しました、応答を待っています... "

#: src/http.c:1763
msgid "No data received.\n"
msgstr "データが受信されませんでした\n"

#: src/http.c:1770
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "ヘッダ内で読み込みエラー(%s)です\n"

#: src/http.c:1816 src/http.c:2368
#, c-format
msgid ""
"File `%s' already there; not retrieving.\n"
"\n"
msgstr ""
"ファイル `%s' はすでに存在するので、取得しません。\n"
"\n"

#: src/http.c:1969
msgid "Unknown authentication scheme.\n"
msgstr "不明な認証形式です。\n"

#: src/http.c:2000
msgid "Authorization failed.\n"
msgstr "認証に失敗しました。\n"

#: src/http.c:2014
msgid "Malformed status line"
msgstr "奇妙なステータス行です"

#: src/http.c:2016
msgid "(no description)"
msgstr "(説明なし)"

#: src/http.c:2082
#, c-format
msgid "Location: %s%s\n"
msgstr "場所: %s%s\n"

#: src/http.c:2083 src/http.c:2193
msgid "unspecified"
msgstr "特定できません"

#: src/http.c:2084
msgid " [following]"
msgstr " [続く]"

#: src/http.c:2140
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"

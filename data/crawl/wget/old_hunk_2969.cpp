msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: オプション `-W %s' は引数を取りません\n"

#: src/host.c:636
#, c-format
msgid "Resolving %s... "
msgstr "%s をDNSに問いあわせています... "

#: src/host.c:656 src/host.c:672
#, c-format
msgid "failed: %s.\n"
msgstr "失敗しました: %s.\n"

#: src/host.c:674
msgid "failed: timed out.\n"
msgstr "失敗しました: タイムアウト.\n"

#: src/host.c:762
msgid "Host not found"
msgstr "ホストが見つかりません"

#: src/host.c:764
msgid "Unknown error"
msgstr "不明なエラーです"

#: src/html-url.c:293
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: 不完全なリンク %s を解決できません。\n"

#. this is fatal
#: src/http.c:674
msgid "Failed to set up an SSL context\n"
msgstr "SSL contextの準備に失敗しました。\n"

#: src/http.c:680
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "%s からの証明書を読み込みに失敗しました。\n"

#: src/http.c:684 src/http.c:692
msgid "Trying without the specified certificate\n"
msgstr "指定された証明書なしで試みます。\n"

#: src/http.c:688
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "%s からの証明書の鍵の読み込みに失敗しました。\n"

#: src/http.c:761 src/http.c:1809
msgid "Unable to establish SSL connection.\n"
msgstr "SSL による接続が確立できません。\n"

#: src/http.c:770
#, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "%s:%hu への接続を再利用します。\n"

#: src/http.c:1034
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "HTTP による接続要求の送信に失敗しました: %s\n"

#: src/http.c:1039
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s による接続要求を送信しました、応答を待っています... "

#: src/http.c:1083
msgid "End of file while parsing headers.\n"
msgstr "ヘッダの解析中に終端まできてしまいました。\n"

#: src/http.c:1093
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "ヘッダ内で読み込みエラー(%s)です\n"

#: src/http.c:1128
msgid "No data received"
msgstr "データが受信されませんでした"

#: src/http.c:1130
msgid "Malformed status line"
msgstr "奇妙なステータス行です"

#: src/http.c:1135
msgid "(no description)"
msgstr "(説明なし)"

#: src/http.c:1267
msgid "Authorization failed.\n"
msgstr "認証に失敗しました。\n"

#: src/http.c:1274
msgid "Unknown authentication scheme.\n"
msgstr "不明な認証形式です。\n"

#: src/http.c:1314
#, c-format
msgid "Location: %s%s\n"
msgstr "場所: %s%s\n"

#: src/http.c:1315 src/http.c:1454
msgid "unspecified"
msgstr "特定できません"

#: src/http.c:1316
msgid " [following]"
msgstr " [続く]"

#: src/http.c:1383
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"

#. that there can be valid reasons for the local host
#. name not to be an FQDN, so I've decided to remove the
#. annoying warning.
#: src/host.c:473
#, c-format
msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
msgstr "%s: 警告: ローカルアドレスの逆引き結果がFQDNではありません!\n"

#: src/host.c:501
msgid "Host not found"
msgstr "ホストが見つかりません"

#: src/host.c:503
msgid "Unknown error"
msgstr "不明なエラーです"

#. this is fatal
#: src/http.c:549
msgid "Failed to set up an SSL context\n"
msgstr ""

#: src/http.c:555
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr ""

#: src/http.c:559 src/http.c:567
msgid "Trying without the specified certificate\n"
msgstr ""

#: src/http.c:563
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr ""

#: src/http.c:657 src/http.c:1470
msgid "Unable to establish SSL connection.\n"
msgstr ""

#: src/http.c:665
#, fuzzy, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "%s:%hu への接続を試みています。\n"

#: src/http.c:841
#, fuzzy, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "HTTP による接続要求の送信に失敗しました。\n"

#: src/http.c:846
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s による接続要求を送信しました、応答を待っています... "

#: src/http.c:890
msgid "End of file while parsing headers.\n"
msgstr "ヘッダの解析中にファイルの終端になりました。\n"

#: src/http.c:901
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "ヘッダ内で読み込みエラー(%s)です\n"

#: src/http.c:941
msgid "No data received"
msgstr "データが受信されませんでした"

#: src/http.c:943
msgid "Malformed status line"
msgstr "奇妙な状態です"

#: src/http.c:948
msgid "(no description)"
msgstr "(説明なし)"

#: src/http.c:1066
msgid "Authorization failed.\n"
msgstr "認証に失敗しました。\n"

#: src/http.c:1073
msgid "Unknown authentication scheme.\n"
msgstr "不明な認証形式です。\n"

#: src/http.c:1163
#, c-format
msgid "Location: %s%s\n"
msgstr "場所: %s%s\n"

#: src/http.c:1164 src/http.c:1189
msgid "unspecified"
msgstr "特定できません"

#: src/http.c:1165
msgid " [following]"
msgstr " [続く]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1179
msgid "Length: "
msgstr "長さ: "

#: src/http.c:1184
#, c-format
msgid " (%s to go)"
msgstr " (のこり%s)"

#: src/http.c:1189
msgid "ignored"
msgstr "無視しました"

#: src/http.c:1290
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "警告: HTTPはワイルドカードに対応していません。\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1311
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "ファイル `%s' はすでに存在するので、転送しません。\n"

#: src/http.c:1462
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "`%s' (%s)へ書き込めません。\n"

#: src/http.c:1480
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "エラー: 場所が存在しないリディレクション(%d)です。\n"

#: src/http.c:1505
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s エラー %d: %s。\n"

#: src/http.c:1518
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Last-modified ヘッダがありません -- 日付を無効にします。\n"

#: src/http.c:1526
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "Last-modified ヘッダが無効です -- 日付を無視します。\n"

#: src/http.c:1549
#, c-format
msgid ""
"Server file no newer than local file `%s' -- not retrieving.\n"
"\n"
msgstr ""

#: src/http.c:1557
#, fuzzy, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n"
msgstr "大きさが合わないので(ローカルは %ld)、転送します。\n"

#: src/http.c:1561
msgid "Remote file is newer, retrieving.\n"
msgstr "リモートファイルのほうが新しいので、転送します。\n"

#: src/http.c:1606
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"

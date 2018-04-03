msgid "Unknown error"
msgstr "不明なエラーです"

#: src/http.c:621 src/http.c:1433
msgid "Unable to establish SSL connection.\n"
msgstr ""

#: src/http.c:629
#, fuzzy, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "%s:%hu への接続を試みています。\n"

#: src/http.c:805
#, fuzzy, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "HTTP による接続要求の送信に失敗しました。\n"

#: src/http.c:810
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s による接続要求を送信しました、応答を待っています... "

#: src/http.c:854
msgid "End of file while parsing headers.\n"
msgstr "ヘッダの解析中にファイルの終端になりました。\n"

#: src/http.c:865
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "ヘッダ内で読み込みエラー(%s)です\n"

#: src/http.c:905
msgid "No data received"
msgstr "データが受信されませんでした"

#: src/http.c:907
msgid "Malformed status line"
msgstr "奇妙な状態です"

#: src/http.c:912
msgid "(no description)"
msgstr "(説明なし)"

#: src/http.c:1030
msgid "Authorization failed.\n"
msgstr "認証に失敗しました。\n"

#: src/http.c:1037
msgid "Unknown authentication scheme.\n"
msgstr "不明な認証形式です。\n"

#: src/http.c:1127
#, c-format
msgid "Location: %s%s\n"
msgstr "場所: %s%s\n"

#: src/http.c:1128 src/http.c:1153
msgid "unspecified"
msgstr "特定できません"

#: src/http.c:1129
msgid " [following]"
msgstr " [続く]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1143
msgid "Length: "
msgstr "長さ: "

#: src/http.c:1148
#, c-format
msgid " (%s to go)"
msgstr " (のこり%s)"

#: src/http.c:1153
msgid "ignored"
msgstr "無視しました"

#: src/http.c:1254
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "警告: HTTPはワイルドカードに対応していません。\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1275
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "ファイル `%s' はすでに存在するので、転送しません。\n"

#: src/http.c:1425
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "`%s' (%s)へ書き込めません。\n"

#: src/http.c:1443
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "エラー: 場所が存在しないリディレクション(%d)です。\n"

#: src/http.c:1468
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s エラー %d: %s。\n"

#: src/http.c:1481
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Last-modified ヘッダがありません -- 日付を無効にします。\n"

#: src/http.c:1489
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "Last-modified ヘッダが無効です -- 日付を無視します。\n"

#: src/http.c:1524
msgid "Remote file is newer, retrieving.\n"
msgstr "リモートファイルのほうが新しいので、転送します。\n"

#: src/http.c:1559
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"

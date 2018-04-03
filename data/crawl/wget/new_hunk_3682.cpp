#. that there can be valid reasons for the local host
#. name not to be an FQDN, so I've decided to remove the
#. annoying warning.
#: src/host.c:517
#, c-format
msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
msgstr "%s: 警告: ローカルアドレスの逆引き結果がFQDNではありません!\n"

#: src/host.c:545
msgid "Host not found"
msgstr "ホストが見つかりません"

#: src/host.c:547
msgid "Unknown error"
msgstr "不明なエラーです"

#: src/html.c:615 src/html.c:617
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "/%s (%s:%d 上)の見出し(index)です"

#: src/html.c:639
msgid "time unknown       "
msgstr "時間が不明です       "

#: src/html.c:643
msgid "File        "
msgstr "ファイル        "

#: src/html.c:646
msgid "Directory   "
msgstr "ディレクトリ   "

#: src/html.c:649
msgid "Link        "
msgstr "リンク        "

#: src/html.c:652
msgid "Not sure    "
msgstr "不確実    "

#: src/html.c:670
#, c-format
msgid " (%s bytes)"
msgstr " (%s バイト)"

#: src/http.c:512
msgid "Failed writing HTTP request.\n"
msgstr "HTTP による接続要求の送信に失敗しました。\n"

#: src/http.c:516
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s による接続要求を送信しました、応答を待っています... "

#: src/http.c:555
msgid "End of file while parsing headers.\n"
msgstr "ヘッダの解析中に終端まできてしまいました。\n"

#: src/http.c:566
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "ヘッダ内で読み込みエラー(%s)です\n"

#: src/http.c:606
msgid "No data received"
msgstr "データが受信されませんでした"

#: src/http.c:608
msgid "Malformed status line"
msgstr "奇妙なステータス行です"

#: src/http.c:613
msgid "(no description)"
msgstr "(説明なし)"

#. If we have tried it already, then there is not point
#. retrying it.
#: src/http.c:697
msgid "Authorization failed.\n"
msgstr "認証に失敗しました。\n"

#: src/http.c:704
msgid "Unknown authentication scheme.\n"
msgstr "不明な認証形式です。\n"

#: src/http.c:787
#, c-format
msgid "Location: %s%s\n"
msgstr "場所: %s%s\n"

#: src/http.c:788 src/http.c:813
msgid "unspecified"
msgstr "特定できません"

#: src/http.c:789
msgid " [following]"
msgstr " [続く]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:803
msgid "Length: "
msgstr "長さ: "

#: src/http.c:808
#, c-format
msgid " (%s to go)"
msgstr " (のこり%s)"

#: src/http.c:813
msgid "ignored"
msgstr "無視しました"

#: src/http.c:914
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "警告: HTTPはワイルドカードに対応していません。\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:935
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "ファイル `%s' はすでに存在するので、転送しません。\n"

#: src/http.c:1085
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "`%s' (%s)へ書き込めません。\n"

#: src/http.c:1096
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "エラー: 場所が存在しないリダイレクション(%d)です。\n"

#: src/http.c:1121
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s エラー %d: %s。\n"

#: src/http.c:1134
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Last-modified ヘッダがありません -- 日付を無効にします。\n"

#: src/http.c:1142
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "Last-modified ヘッダが無効です -- 日付を無視します。\n"

#: src/http.c:1177
msgid "Remote file is newer, retrieving.\n"
msgstr "リモートファイルのほうが新しいので、転送します。\n"

#: src/http.c:1222
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"

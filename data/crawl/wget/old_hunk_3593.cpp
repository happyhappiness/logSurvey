msgid "%s: option requires an argument -- %c\n"
msgstr "%s: オプションは引数を必要とします -- %c\n"

#: src/host.c:438
#, c-format
msgid "%s: Cannot determine user-id.\n"
msgstr "%s: user-idを決定できません。\n"

#: src/host.c:450
#, c-format
msgid "%s: Warning: uname failed: %s\n"
msgstr "%s: 警告: unameに失敗しました: %s\n"

#: src/host.c:462
#, c-format
msgid "%s: Warning: gethostname failed\n"
msgstr "%s: 警告: gethostnameに失敗しました\n"

#: src/host.c:490
#, c-format
msgid "%s: Warning: cannot determine local IP address.\n"
msgstr "%s: 警告: ローカルIPアドレスを決定できません。\n"

#: src/host.c:504
#, c-format
msgid "%s: Warning: cannot reverse-lookup local IP address.\n"
msgstr "%s: 警告: ローカルIPアドレスの逆引きができません。\n"

#. This gets ticked pretty often.  Karl Berry reports
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
"\n"
msgstr ""
"%s (%s) - `%s' を保存しました [%ld/%ld]\n"
"\n"

#: src/http.c:1270
#, c-format
msgid "%s (%s) - Connection closed at byte %ld. "
msgstr "%s (%s) - %ld バイトで接続が終了しました。 "

#: src/http.c:1278
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld])\n"
"\n"
msgstr ""
"%s (%s) - `%s' を保存しました [%ld/%ld])\n"
"\n"

#: src/http.c:1298
#, c-format
msgid "%s (%s) - Connection closed at byte %ld/%ld. "
msgstr "%s (%s) - %ld/%ld バイトで接続が終了しました。 "

#: src/http.c:1309
#, c-format
msgid "%s (%s) - Read error at byte %ld (%s)."
msgstr "%s (%s) - %ld バイトで読み込みエラーです (%s)。"

#: src/http.c:1317
#, c-format
msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
msgstr "%s (%s) - %ld/%ld バイトで読み込みエラーです (%s)。 "

#: src/init.c:329 src/netrc.c:260
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: %s (%s)を読み込めません。\n"

#: src/init.c:347 src/init.c:353
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: %s 内の %d 行でエラーです\n"

#: src/init.c:384
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr "%s: 警告: システムとユーザのwgetrcの両方が `%s' を指定しています。\n"

#: src/init.c:476
#, c-format
msgid "%s: BUG: unknown command `%s', value `%s'.\n"
msgstr "%s: バグ: `%s' は不明な命令です、値は `%s' です。\n"

#: src/init.c:497
#, c-format
msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
msgstr "%s: %s: `%s' をIPアドレスに変換できません。\n"

#: src/init.c:525
#, c-format
msgid "%s: %s: Please specify on or off.\n"
msgstr "%s: %s: onかoffかを指定してください。\n"

#: src/init.c:569
#, c-format
msgid "%s: %s: Please specify always, on, off, or never.\n"
msgstr "%s: %s: always, on, offまたはneverのいずれかを指定してください。\n"

#: src/init.c:588 src/init.c:845 src/init.c:867 src/init.c:931
#, c-format
msgid "%s: %s: Invalid specification `%s'.\n"
msgstr "%s: %s: 無効な指定 `%s' です。\n"

#: src/init.c:701 src/init.c:723 src/init.c:745 src/init.c:771
#, c-format
msgid "%s: Invalid specification `%s'\n"
msgstr "%s: 無効な指定 `%s' です。\n"

#: src/main.c:106
#, c-format
msgid "Usage: %s [OPTION]... [URL]...\n"
msgstr "使い方: %s [オプション]... [URL]...\n"

#: src/main.c:114
#, c-format
msgid "GNU Wget %s, a non-interactive network retriever.\n"
msgstr "GNU Wget %s, 非対話的ネットワーク転送ソフト\n"

#. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
#. don't bitch.  Also, it makes translation much easier.
#: src/main.c:119
msgid ""
"\n"
"Mandatory arguments to long options are mandatory for short options too.\n"
"\n"
msgstr ""
"\n"
"長いオプションで不可欠な引数は短いオプションでも不可欠です。\n"
"\n"

#: src/main.c:122
msgid ""
"Startup:\n"
"  -V,  --version           display the version of Wget and exit.\n"

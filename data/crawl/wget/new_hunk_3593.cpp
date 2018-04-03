msgid "%s: option requires an argument -- %c\n"
msgstr "%s: オプションは引数を必要とします -- %c\n"

#: src/host.c:374
msgid "Host not found"
msgstr "ホストが見つかりません"

#: src/host.c:376
msgid "Unknown error"
msgstr "不明なエラーです"

#. this is fatal
#: src/http.c:555
msgid "Failed to set up an SSL context\n"
msgstr "SSL contextの準備に失敗しました。\n"

#: src/http.c:561
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "%s からの証明書を読み込みに失敗しました。\n"

#: src/http.c:565 src/http.c:573
msgid "Trying without the specified certificate\n"
msgstr "指定された証明書なしで試みます。\n"

#: src/http.c:569
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "%s からの証明書の鍵の読み込みに失敗しました。\n"

#: src/http.c:663 src/http.c:1593
msgid "Unable to establish SSL connection.\n"
msgstr "SSL による接続が確立できません。\n"

#: src/http.c:671
#, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "%s:%hu への接続を再利用します。\n"

#: src/http.c:861
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "HTTP による接続要求の送信に失敗しました: %s\n"

#: src/http.c:866
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s による接続要求を送信しました、応答を待っています... "

#: src/http.c:910
msgid "End of file while parsing headers.\n"
msgstr "ヘッダの解析中に終端まできてしまいました。\n"

#: src/http.c:920
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "ヘッダ内で読み込みエラー(%s)です\n"

#: src/http.c:959
msgid "No data received"
msgstr "データが受信されませんでした"

#: src/http.c:961
msgid "Malformed status line"
msgstr "奇妙なステータス行です"

#: src/http.c:966
msgid "(no description)"
msgstr "(説明なし)"

#: src/http.c:1089
msgid "Authorization failed.\n"
msgstr "認証に失敗しました。\n"

#: src/http.c:1096
msgid "Unknown authentication scheme.\n"
msgstr "不明な認証形式です。\n"

#: src/http.c:1136
#, c-format
msgid "Location: %s%s\n"
msgstr "場所: %s%s\n"

#: src/http.c:1137 src/http.c:1269
msgid "unspecified"
msgstr "特定できません"

#: src/http.c:1138
msgid " [following]"
msgstr " [続く]"

#: src/http.c:1200
msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
msgstr "\n    このファイルは既に全部取得しおわっています。何もすることはありません。\n\n"

#: src/http.c:1216
#, c-format
msgid ""
"\n"
"Continued download failed on this file, which conflicts with `-c'.\n"
"Refusing to truncate existing file `%s'.\n"
"\n"
msgstr ""
"\n"
"途中からのダウンロードに失敗しましたので、`-c'が有効に働きません。\n"
"既に存在しているファイル `%s' を切りつめはしません。\n"
"\n"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1259
msgid "Length: "
msgstr "長さ: "

#: src/http.c:1264
#, c-format
msgid " (%s to go)"
msgstr " (のこり%s)"

#: src/http.c:1269
msgid "ignored"
msgstr "無視しました"

#: src/http.c:1399
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "警告: HTTPはワイルドカードに対応していません。\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1417
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "ファイル `%s' はすでに存在するので、転送しません。\n"

#: src/http.c:1585
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "`%s' (%s)へ書き込めません。\n"

#: src/http.c:1602
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "エラー: 場所が存在しないリダイレクション(%d)です。\n"

#: src/http.c:1630
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s エラー %d: %s。\n"

#: src/http.c:1642
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Last-modified ヘッダがありません -- 日付を無効にします。\n"

#: src/http.c:1650
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "Last-modified ヘッダが無効です -- 日付を無視します。\n"

#: src/http.c:1673
#, c-format
msgid "Server file no newer than local file `%s' -- not retrieving.\n\n"
msgstr "サーバ側のファイルよりローカルのファイル `%s' の方が新しいので取得しません。\n\n"

#: src/http.c:1680
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n"
msgstr "大きさが合わないので(ローカルは %ld)、転送します。\n"

#: src/http.c:1684
msgid "Remote file is newer, retrieving.\n"
msgstr "リモートファイルのほうが新しいので、転送します。\n"

#: src/http.c:1728
#, c-format
msgid "%s (%s) - `%s' saved [%ld/%ld]\n\n"
msgstr "%s (%s) - `%s' を保存しました [%ld/%ld]\n\n"

#: src/http.c:1774
#, c-format
msgid "%s (%s) - Connection closed at byte %ld. "
msgstr "%s (%s) - %ld バイトで接続が終了しました。 "

#: src/http.c:1782
#, c-format
msgid "%s (%s) - `%s' saved [%ld/%ld])\n\n"
msgstr "%s (%s) - `%s' を保存しました [%ld/%ld])\n\n"

#: src/http.c:1801
#, c-format
msgid "%s (%s) - Connection closed at byte %ld/%ld. "
msgstr "%s (%s) - %ld/%ld バイトで接続が終了しました。 "

#: src/http.c:1812
#, c-format
msgid "%s (%s) - Read error at byte %ld (%s)."
msgstr "%s (%s) - %ld バイトで読み込みエラーです (%s)。"

#: src/http.c:1820
#, c-format
msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
msgstr "%s (%s) - %ld/%ld バイトで読み込みエラーです (%s)。 "

#: src/init.c:349 src/netrc.c:267
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: %s (%s)を読み込めません。\n"

#: src/init.c:367 src/init.c:373
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: %s 内の %d 行でエラーです\n"

#: src/init.c:405
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr "%s: 警告: システムとユーザのwgetrcの両方が `%s' を指定しています。\n"

#: src/init.c:497
#, c-format
msgid "%s: BUG: unknown command `%s', value `%s'.\n"
msgstr "%s: バグ: `%s' は不明な命令です、値は `%s' です。\n"

#: src/init.c:529
#, c-format
msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
msgstr "%s: %s: `%s' をIPアドレスに変換できません。\n"

#: src/init.c:559
#, c-format
msgid "%s: %s: Please specify on or off.\n"
msgstr "%s: %s: onかoffかを指定してください。\n"

#: src/init.c:603
#, c-format
msgid "%s: %s: Please specify always, on, off, or never.\n"
msgstr "%s: %s: always, on, offまたはneverのいずれかを指定してください。\n"

#: src/init.c:622 src/init.c:919 src/init.c:941 src/init.c:1005
#, c-format
msgid "%s: %s: Invalid specification `%s'.\n"
msgstr "%s: %s: 無効な指定 `%s' です。\n"

#: src/init.c:775 src/init.c:797 src/init.c:819 src/init.c:845
#, c-format
msgid "%s: Invalid specification `%s'\n"
msgstr "%s: 無効な指定 `%s' です。\n"

#: src/main.c:120
#, c-format
msgid "Usage: %s [OPTION]... [URL]...\n"
msgstr "使い方: %s [オプション]... [URL]...\n"

#: src/main.c:128
#, c-format
msgid "GNU Wget %s, a non-interactive network retriever.\n"
msgstr "GNU Wget %s, 非対話的ネットワーク転送ソフト\n"

#. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
#. don't bitch.  Also, it makes translation much easier.
#: src/main.c:133
msgid "\nMandatory arguments to long options are mandatory for short options too.\n\n"
msgstr "\n長いオプションで不可欠な引数は短いオプションでも不可欠です。\n\n"

#: src/main.c:137
msgid ""
"Startup:\n"
"  -V,  --version           display the version of Wget and exit.\n"

#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1753
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "パターン `%s' に適合するものがありません。\n"

#: src/ftp.c:1819
#, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr "`%s' [%s]に対するHTML化された見出し(index)を書きました。\n"

#: src/ftp.c:1824
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "`%s' に対するHTML化された見出し(index)を書きました。\n"

#: src/getopt.c:670
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: オプション `%s' は曖昧です\n"

#: src/getopt.c:695
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: オプション `--%s' は引数を必要としません\n"

#: src/getopt.c:700
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: オプション `%c%s' は引数を必要としません\n"

#: src/getopt.c:718 src/getopt.c:891
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: オプション `%s' は引数を必要とします\n"

#. --option
#: src/getopt.c:747
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: `--%s' は認識できないオプションです\n"

#. +option or -option
#: src/getopt.c:751
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: `%c%s' は認識できないオプションです\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:777
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: 不正なオプションです -- %c\n"

#: src/getopt.c:780
#, c-format
msgid "%s: invalid option -- %c\n"
msgstr "%s: 不正なオプションです -- %c\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:810 src/getopt.c:940
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: オプションは引数を必要とします -- %c\n"

#: src/getopt.c:857
#, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s: オプション `-W %s' は曖昧です\n"

#: src/getopt.c:875
#, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: オプション `-W %s' は引数を取りません\n"

#: src/host.c:347
msgid "Unknown host"
msgstr "不明なホストです"

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:351
msgid "Temporary failure in name resolution"
msgstr "名前解決中に一時的な失敗が発生しました"

#: src/host.c:353
msgid "Unknown error"
msgstr "不明なエラーです"

#: src/host.c:714
#, c-format
msgid "Resolving %s... "
msgstr "%s をDNSに問いあわせています... "

#: src/host.c:761
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "失敗: ホストに IPv4/IPv6 アドレスがありません。\n"

#: src/host.c:784
msgid "failed: timed out.\n"
msgstr "失敗しました: タイムアウト.\n"

#: src/html-url.c:288
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: 不完全なリンク %s を解決できません。\n"

#: src/html-url.c:695
#, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: %s は無効な URL です(%s)。\n"

#: src/http.c:367
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "HTTP による接続要求の送信に失敗しました: %s\n"

#: src/http.c:736
msgid "No headers, assuming HTTP/0.9"
msgstr "ヘッダがないので、HTTP/0.9 だと仮定します"

#: src/http.c:1413
msgid "Disabling SSL due to encountered errors.\n"
msgstr "エラーが発生したので SSL を無効にします\n"

#: src/http.c:1566
#, c-format
msgid "POST data file `%s' missing: %s\n"
msgstr "POST データファイル `%s' がありません: %s\n"

#: src/http.c:1615
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "%s:%d への接続を再利用します。\n"

#: src/http.c:1684
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "プロクシからの読み込みに失敗しました: %s\n"

#: src/http.c:1704
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "プロクシのトンネリングに失敗しました: %s"

#: src/http.c:1749
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s による接続要求を送信しました、応答を待っています... "

#: src/http.c:1760
msgid "No data received.\n"
msgstr "データが受信されませんでした\n"

#: src/http.c:1767
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "ヘッダ内で読み込みエラー(%s)です\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1813
#, c-format
msgid ""
"File `%s' already there; not retrieving.\n"
"\n"
msgstr ""
"ファイル `%s' はすでに存在するので、取得しません。\n"
"\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1966
msgid "Unknown authentication scheme.\n"
msgstr "不明な認証形式です。\n"

#: src/http.c:1997
msgid "Authorization failed.\n"
msgstr "認証に失敗しました。\n"

#: src/http.c:2011
msgid "Malformed status line"
msgstr "奇妙なステータス行です"

#: src/http.c:2013
msgid "(no description)"
msgstr "(説明なし)"

#: src/http.c:2076
#, c-format
msgid "Location: %s%s\n"
msgstr "場所: %s%s\n"

#: src/http.c:2077 src/http.c:2184
msgid "unspecified"
msgstr "特定できません"

#: src/http.c:2078
msgid " [following]"
msgstr " [続く]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:2134
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"

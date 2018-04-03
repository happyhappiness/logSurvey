#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1778
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "パターン `%s' に適合するものがありません。\n"

#: src/ftp.c:1844
#, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr "`%s' [%s]に対するHTML化された見出し(index)を書きました。\n"

#: src/ftp.c:1849
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "`%s' に対するHTML化された見出し(index)を書きました。\n"

#: src/getopt.c:675
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: オプション `%s' は曖昧です\n"

#: src/getopt.c:700
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: オプション `--%s' は引数を必要としません\n"

#: src/getopt.c:705
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: オプション `%c%s' は引数を必要としません\n"

#: src/getopt.c:723 src/getopt.c:896
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: オプション `%s' は引数を必要とします\n"

#. --option
#: src/getopt.c:752
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: `--%s' は認識できないオプションです\n"

#. +option or -option
#: src/getopt.c:756
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: `%c%s' は認識できないオプションです\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:782
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: 不正なオプションです -- %c\n"

#: src/getopt.c:785
#, c-format
msgid "%s: invalid option -- %c\n"
msgstr "%s: 不正なオプションです -- %c\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:815 src/getopt.c:945
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: オプションは引数を必要とします -- %c\n"

#: src/getopt.c:862
#, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s: オプション `-W %s' は曖昧です\n"

#: src/getopt.c:880
#, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: オプション `-W %s' は引数を取りません\n"

#: src/host.c:366
msgid "Unknown host"
msgstr "不明なホストです"

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:370
msgid "Temporary failure in name resolution"
msgstr "名前解決中に一時的な失敗が発生しました"

#: src/host.c:372
msgid "Unknown error"
msgstr "不明なエラーです"

#: src/host.c:751
#, c-format
msgid "Resolving %s... "
msgstr "%s をDNSに問いあわせています... "

#: src/host.c:798
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "失敗: ホストに IPv4/IPv6 アドレスがありません。\n"

#: src/host.c:821
msgid "failed: timed out.\n"
msgstr "失敗しました: タイムアウト.\n"

#: src/html-url.c:298
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: 不完全なリンク %s を解決できません。\n"

#: src/html-url.c:705
#, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: %s は無効な URL です(%s)。\n"

#: src/http.c:373
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "HTTP による接続要求の送信に失敗しました: %s\n"

#: src/http.c:687
msgid "No headers, assuming HTTP/0.9"
msgstr "ヘッダがないので、HTTP/0.9 だと仮定します"

#: src/http.c:1204
msgid "Disabling SSL due to encountered errors.\n"
msgstr "エラーが発生したので SSL を無効にします\n"

#: src/http.c:1374
#, c-format
msgid "POST data file `%s' missing: %s\n"
msgstr "POST データファイル `%s' がありません: %s\n"

#: src/http.c:1423
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "%s:%d への接続を再利用します。\n"

#: src/http.c:1492
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "プロクシからの読み込みに失敗しました: %s\n"

#: src/http.c:1512
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "プロクシのトンネリングに失敗しました: %s"

#: src/http.c:1557
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s による接続要求を送信しました、応答を待っています... "

#: src/http.c:1568
msgid "No data received.\n"
msgstr "データが受信されませんでした\n"

#: src/http.c:1575
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "ヘッダ内で読み込みエラー(%s)です\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1660
msgid "Unknown authentication scheme.\n"
msgstr "不明な認証形式です。\n"

#: src/http.c:1684
msgid "Authorization failed.\n"
msgstr "認証に失敗しました。\n"

#: src/http.c:1698
msgid "Malformed status line"
msgstr "奇妙なステータス行です"

#: src/http.c:1700
msgid "(no description)"
msgstr "(説明なし)"

#: src/http.c:1763
#, c-format
msgid "Location: %s%s\n"
msgstr "場所: %s%s\n"

#: src/http.c:1764 src/http.c:1871
msgid "unspecified"
msgstr "特定できません"

#: src/http.c:1765
msgid " [following]"
msgstr " [続く]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:1821
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"

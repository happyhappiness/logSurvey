"すでに %s -> %s という正しいシンボリックリンクがあります\n"
"\n"

#: src/ftp.c:1533
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "%s -> %s というシンボリックリンクを作成しています\n"

#: src/ftp.c:1543
#, fuzzy, c-format
msgid "Symlinks not supported, skipping symlink %s.\n"
msgstr ""
"シンボリックリンクに対応していないので、シンボリックリンク `%s' をとばしま"
"す。\n"

#: src/ftp.c:1555
#, fuzzy, c-format
msgid "Skipping directory %s.\n"
msgstr "ディレクトリ `%s' をとばします。\n"

#: src/ftp.c:1564
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: 不明なまたは対応していないファイルの種類です。\n"

#: src/ftp.c:1591
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: 日付が壊れています。\n"

#: src/ftp.c:1619
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "深さが %d (最大 %d)なのでディレクトリを転送しません。\n"

#: src/ftp.c:1669
#, fuzzy, c-format
msgid "Not descending to %s as it is excluded/not-included.\n"
msgstr "除外されているか含まれていないので `%s' に移動しません。\n"

#: src/ftp.c:1735 src/ftp.c:1749
#, fuzzy, c-format
msgid "Rejecting %s.\n"
msgstr "`%s' を除外します。\n"

#: src/ftp.c:1772
#, c-format
msgid "Error matching %s against %s: %s\n"
msgstr "%s は %s に対してマッチしませんでした: %s\n"

#: src/ftp.c:1814
#, fuzzy, c-format
msgid "No matches on pattern %s.\n"
msgstr "パターン `%s' に適合するものがありません。\n"

#: src/ftp.c:1880
#, fuzzy, c-format
msgid "Wrote HTML-ized index to %s [%s].\n"
msgstr "`%s' [%s]に対するHTML化された見出し(index)を書きました。\n"

#: src/ftp.c:1885
#, fuzzy, c-format
msgid "Wrote HTML-ized index to %s.\n"
msgstr "`%s' に対するHTML化された見出し(index)を書きました。\n"

#: src/host.c:348
msgid "Unknown host"
msgstr "不明なホストです"

#: src/host.c:352
msgid "Temporary failure in name resolution"
msgstr "名前解決中に一時的な失敗が発生しました"

#: src/host.c:354
msgid "Unknown error"
msgstr "不明なエラーです"

#: src/host.c:715
#, c-format
msgid "Resolving %s... "
msgstr "%s をDNSに問いあわせています... "

#: src/host.c:763
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "失敗: ホストに IPv4/IPv6 アドレスがありません。\n"

#: src/host.c:786
msgid "failed: timed out.\n"
msgstr "失敗しました: タイムアウト.\n"

#: src/html-url.c:289
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: 不完全なリンク %s を解決できません。\n"

#: src/html-url.c:696
#, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: %s は無効な URL です(%s)。\n"

#: src/http.c:368
#, c-format
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

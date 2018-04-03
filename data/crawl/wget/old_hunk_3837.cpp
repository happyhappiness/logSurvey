msgid "%s: Couldn't find usable socket driver.\n"
msgstr "%s: 使用可能なソケットドライバを見つけられません。\n"

#: src/netrc.c:334
#, c-format
msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
msgstr "%s: %s:%d: 警告: 区切り記号(token) \"%s\" はすべてのマシン名の前に現われます\n"

#: src/netrc.c:365
#, c-format
msgid "%s: %s:%d: unknown token \"%s\"\n"
msgstr "%s: %s:%d: \"%s\" は不明な区切り記号(token)です\n"

#: src/netrc.c:429
#, c-format
msgid "Usage: %s NETRC [HOSTNAME]\n"
msgstr "使い方: %s NETRC [ホスト名]\n"

#: src/netrc.c:439
#, c-format
msgid "%s: cannot stat %s: %s\n"
msgstr "%s: %sの情報を取得できません: %s \n"

#: src/recur.c:449 src/retr.c:462
#, c-format
msgid "Removing %s.\n"
msgstr "%s を削除しました。\n"

#: src/recur.c:450
#, c-format
msgid "Removing %s since it should be rejected.\n"
msgstr "拒否すべきなので、%s を削除しました。\n"

#: src/recur.c:609
msgid "Loading robots.txt; please ignore errors.\n"
msgstr "robots.txtを読み込んでいます、エラーは無視してください。\n"

#: src/retr.c:193
#, c-format
msgid "\n          [ skipping %dK ]"
msgstr "\n          [ %dK とばします ]"

#: src/retr.c:344
msgid "Could not find proxy host.\n"
msgstr "代理ホスト(proxy host)が見つかりません。\n"

#: src/retr.c:355
#, c-format
msgid "Proxy %s: Must be HTTP.\n"
msgstr "代理サーバ(proxy) %s: HTTPである必要があります。\n"

#: src/retr.c:398
#, c-format
msgid "%s: Redirection to itself.\n"
msgstr "%s は自分自身へのリディレクションです。\n"

#: src/retr.c:483
msgid "Giving up.\n\n"
msgstr "中止しました。\n\n"

#: src/retr.c:483
msgid "Retrying.\n\n"
msgstr "再試行しています。\n\n"

#: src/url.c:940
#, c-format
msgid "Error (%s): Link %s without a base provided.\n"
msgstr "エラー (%s): %s というリンクに対するベースが与えられていません。\n"

#: src/url.c:955
#, c-format
msgid "Error (%s): Base %s relative, without referer URL.\n"
msgstr "エラー(%s): Base URL %s が相対指定で、参照するURL(Referer)が存在しません。\n"

#: src/url.c:1373
#, c-format
msgid "Converting %s... "
msgstr "%s を変換しています... "

#: src/url.c:1378 src/url.c:1389
#, c-format
msgid "Cannot convert links in %s: %s\n"
msgstr "%s 内のリンクを変換できません: %s\n"

#: src/utils.c:71
#, c-format
msgid "%s: %s: Not enough memory.\n"
msgstr "%s: %s: 十分なメモリがありません。\n"

#: src/utils.c:203
msgid "Unknown/unsupported protocol"
msgstr "不明な、または対応していないプロトコルです"

#: src/utils.c:206
msgid "Invalid port specification"
msgstr "無効なポート番号です"

#: src/utils.c:209
msgid "Invalid host name"
msgstr "無効なホスト名です"

#: src/utils.c:430
#, c-format
msgid "Failed to unlink symlink `%s': %s\n"
msgstr "シンボリックリンク `%s' の削除に失敗しました: %s\n"

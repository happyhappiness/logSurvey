"CTRL+ALT+DELETE を押せば、Wget を停止できます。\n"

#. parent, no error
#: src/mswindows.c:106 src/utils.c:458
msgid "Continuing in background.\n"
msgstr "バックグラウンドで継続します。\n"

#: src/mswindows.c:108 src/utils.c:460
#, c-format
msgid "Output will be written to `%s'.\n"
msgstr "出力を `%s' に書き込みます。\n"

#: src/mswindows.c:188
#, c-format
msgid "Starting WinHelp %s\n"
msgstr "WinHelp %s を開始します。\n"

#: src/mswindows.c:215 src/mswindows.c:222
#, c-format
msgid "%s: Couldn't find usable socket driver.\n"
msgstr "%s: 使用可能なソケットドライバを見つけられません。\n"

#: src/netrc.c:367
#, c-format
msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
msgstr "%s: %s:%d: 警告: 区切り記号(token) \"%s\" はすべてのマシン名の前に現われます\n"

#: src/netrc.c:398
#, c-format
msgid "%s: %s:%d: unknown token \"%s\"\n"
msgstr "%s: %s:%d: \"%s\" は不明な区切り記号(token)です\n"

#: src/netrc.c:462
#, c-format
msgid "Usage: %s NETRC [HOSTNAME]\n"
msgstr "使い方: %s NETRC [ホスト名]\n"

#: src/netrc.c:472
#, c-format
msgid "%s: cannot stat %s: %s\n"
msgstr "%s: %sの情報を取得できません: %s\n"

#: src/recur.c:484
#, c-format
msgid "Removing %s since it should be rejected.\n"
msgstr "拒否すべきなので、%s を削除しました。\n"

#: src/recur.c:679
msgid "Loading robots.txt; please ignore errors.\n"
msgstr "robots.txtを読み込んでいます、エラーは無視してください。\n"

#: src/retr.c:227
#, c-format
msgid "\n          [ skipping %dK ]"
msgstr "\n          [ %dK とばします ]"

#: src/retr.c:373
msgid "Could not find proxy host.\n"
msgstr "代理ホスト(proxy host)が見つかりません。\n"

#: src/retr.c:387
#, c-format
msgid "Proxy %s: Must be HTTP.\n"
msgstr "代理サーバ(proxy) %s: HTTPである必要があります。\n"

#: src/retr.c:481
#, c-format
msgid "%s: Redirection cycle detected.\n"
msgstr "%s: リダイレクションのサイクルが検出されました。\n"

#: src/retr.c:587
msgid "Giving up.\n\n"
msgstr "中止しました。\n\n"

#: src/retr.c:587
msgid "Retrying.\n\n"
msgstr "再試行しています。\n\n"

#: src/url.c:1329
#, c-format
msgid "Converting %s... "
msgstr "%s を変換しています... "

#: src/url.c:1342
msgid "nothing to do.\n"
msgstr "なにもすることはありません。\n"

#: src/url.c:1350 src/url.c:1374
#, c-format
msgid "Cannot convert links in %s: %s\n"
msgstr "%s 内のリンクを変換できません: %s\n"

#: src/url.c:1365
#, c-format
msgid "Unable to delete `%s': %s\n"
msgstr "`%s' の削除に失敗しました: %s\n"

#: src/url.c:1555
#, c-format
msgid "Cannot back up %s as %s: %s\n"
msgstr "%s のバックアップ %s が作れません: %s\n"

#: src/utils.c:94
#, c-format
msgid "%s: %s: Not enough memory.\n"
msgstr "%s: %s: 十分なメモリがありません。\n"

#: src/utils.c:417
msgid "Unknown/unsupported protocol"
msgstr "不明な、または対応していないプロトコルです"

#: src/utils.c:420
msgid "Invalid port specification"
msgstr "無効なポート番号です"

#: src/utils.c:423
msgid "Invalid host name"
msgstr "無効なホスト名です"

#: src/utils.c:620
#, c-format
msgid "Failed to unlink symlink `%s': %s\n"
msgstr "シンボリックリンク `%s' の削除に失敗しました: %s\n"

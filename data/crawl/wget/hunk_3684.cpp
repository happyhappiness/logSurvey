 "再試行しています。\n"
 "\n"
 
-#: src/url.c:1332
+#: src/url.c:983
 #, c-format
-msgid "Converting %s... "
-msgstr "%s を変換しています... "
+msgid "Error (%s): Link %s without a base provided.\n"
+msgstr "エラー (%s): %s というリンクに対するベースが与えられていません。\n"
 
-#: src/url.c:1345
-msgid "nothing to do.\n"
+#: src/url.c:999
+#, c-format
+msgid "Error (%s): Base %s relative, without referer URL.\n"
 msgstr ""
+"エラー(%s): Base URL %s が相対指定で、参照するURL(Referer)が存在しません。\n"
+
+#: src/url.c:1540
+#, c-format
+msgid "Converting %s... "
+msgstr "%s を変換しています... "
 
-#: src/url.c:1353 src/url.c:1377
+#: src/url.c:1545 src/url.c:1632
 #, c-format
 msgid "Cannot convert links in %s: %s\n"
 msgstr "%s 内のリンクを変換できません: %s\n"
 
-#: src/url.c:1368
-#, fuzzy, c-format
-msgid "Unable to delete `%s': %s\n"
-msgstr "シンボリックリンク `%s' の削除に失敗しました: %s\n"
-
-#: src/url.c:1558
-#, fuzzy, c-format
+#: src/url.c:1608
+#, c-format
 msgid "Cannot back up %s as %s: %s\n"
-msgstr "%s 内のリンクを変換できません: %s\n"
+msgstr "%s のバックアップ %s が作れません: %s\n"
 
-#: src/utils.c:94
+#: src/utils.c:72
 #, c-format
 msgid "%s: %s: Not enough memory.\n"
 msgstr "%s: %s: 十分なメモリがありません。\n"
 
-#: src/utils.c:386
+#: src/utils.c:204
 msgid "Unknown/unsupported protocol"
 msgstr "不明な、または対応していないプロトコルです"
 
-#: src/utils.c:389
+#: src/utils.c:207
 msgid "Invalid port specification"
 msgstr "無効なポート番号です"
 
-#: src/utils.c:392
+#: src/utils.c:210
 msgid "Invalid host name"
 msgstr "無効なホスト名です"
 
-#: src/utils.c:613
+#: src/utils.c:431
 #, c-format
 msgid "Failed to unlink symlink `%s': %s\n"
 msgstr "シンボリックリンク `%s' の削除に失敗しました: %s\n"
-
-#, fuzzy
-#~ msgid "%s: Out of memory.\n"
-#~ msgstr "%s: %s: 十分なメモリがありません。\n"
-
-#~ msgid ""
-#~ "Local file `%s' is more recent, not retrieving.\n"
-#~ "\n"
-#~ msgstr ""
-#~ "ローカルファイル `%s' のほうが新しいので、転送しません。\n"
-#~ "\n"
-
-#~ msgid "Error (%s): Link %s without a base provided.\n"
-#~ msgstr "エラー (%s): %s というリンクに対するベースが与えられていません。\n"
-
-#~ msgid "Error (%s): Base %s relative, without referer URL.\n"
-#~ msgstr ""
-#~ "エラー(%s): Base URL %s が相対指定で、参照するURL(Referer)が存在しません。\n"

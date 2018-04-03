 msgid "%s: cannot stat %s: %s\n"
 msgstr "%s: ne morem pognati stat na %s: %s\n"
 
-#: src/recur.c:510
+#: src/recur.c:484
 #, c-format
 msgid "Removing %s since it should be rejected.\n"
 msgstr "Odstranjam %s, saj bi moral biti zavrnjen.\n"
 
-#: src/recur.c:684
+#: src/recur.c:679
 msgid "Loading robots.txt; please ignore errors.\n"
 msgstr "Nalagam robots.txt; prosim, prezrite napake.\n"
 
-#: src/retr.c:229
+#: src/retr.c:227
 #, c-format
-msgid ""
-"\n"
-"          [ skipping %dK ]"
-msgstr ""
-"\n"
-"         [ preskakujem %dK ]"
+msgid "\n          [ skipping %dK ]"
+msgstr "\n         [ preskakujem %dK ]"
 
-#: src/retr.c:421
+#: src/retr.c:373
 msgid "Could not find proxy host.\n"
 msgstr "Ne morem najti zastopnika.\n"
 
-#: src/retr.c:435
+#: src/retr.c:387
 #, c-format
 msgid "Proxy %s: Must be HTTP.\n"
 msgstr "Zastopnik %s: Mora biti HTTP.\n"
 
-#: src/retr.c:529
-#, fuzzy, c-format
+#: src/retr.c:481
+#, c-format
 msgid "%s: Redirection cycle detected.\n"
-msgstr "%s: Preusmeritev na samega sebe.\n"
+msgstr "%s: Zaznana ciklièna preusmeritev.\n"
 
-#: src/retr.c:623
-msgid ""
-"Giving up.\n"
-"\n"
-msgstr ""
-"Odneham.\n"
-"\n"
+#: src/retr.c:587
+msgid "Giving up.\n\n"
+msgstr "Odneham.\n\n"
 
-#: src/retr.c:623
-msgid ""
-"Retrying.\n"
-"\n"
-msgstr ""
-"Posku¹am ponovno.\n"
-"\n"
+#: src/retr.c:587
+msgid "Retrying.\n\n"
+msgstr "Posku¹am ponovno.\n\n"
 
-#: src/url.c:1332
+#: src/url.c:1329
 #, c-format
 msgid "Converting %s... "
 msgstr "Pretvarjam %s... "
 
-#: src/url.c:1345
+#: src/url.c:1342
 msgid "nothing to do.\n"
-msgstr ""
+msgstr "niè za storiti.\n"
 
-#: src/url.c:1353 src/url.c:1377
+#: src/url.c:1350 src/url.c:1374
 #, c-format
 msgid "Cannot convert links in %s: %s\n"
 msgstr "Ne morem pretvoriti povezav v %s: %s\n"
 
-#: src/url.c:1368
-#, fuzzy, c-format
+#: src/url.c:1365
+#, c-format
 msgid "Unable to delete `%s': %s\n"
-msgstr "Ne morem odstraniti simbolne povezave `%s': %s\n"
+msgstr "Ni moè izbrisati ,%s`: %s\n"
 
-#: src/url.c:1558
-#, fuzzy, c-format
+#: src/url.c:1555
+#, c-format
 msgid "Cannot back up %s as %s: %s\n"
-msgstr "Ne morem pretvoriti povezav v %s: %s\n"
+msgstr "Ni mogoèe varnostno shraniti %s kot %s: %s\n"
 
 #: src/utils.c:94
 #, c-format
 msgid "%s: %s: Not enough memory.\n"
 msgstr "%s: %s: Ni dovolj pomnilnika.\n"
 
-#: src/utils.c:386
+#: src/utils.c:417
 msgid "Unknown/unsupported protocol"
 msgstr "Neznan/nepodprt protokol"
 
-#: src/utils.c:389
+#: src/utils.c:420
 msgid "Invalid port specification"
 msgstr "Neveljavna doloèitev vrat"
 
-#: src/utils.c:392
+#: src/utils.c:423
 msgid "Invalid host name"
 msgstr "Neveljavno gostiteljsko ime"
 
-#: src/utils.c:613
+#: src/utils.c:620
 #, c-format
 msgid "Failed to unlink symlink `%s': %s\n"
 msgstr "Ne morem odstraniti simbolne povezave `%s': %s\n"
-
-#, fuzzy
-#~ msgid "%s: Out of memory.\n"
-#~ msgstr "%s: %s: Ni dovolj pomnilnika.\n"
-
-#~ msgid ""
-#~ "Local file `%s' is more recent, not retrieving.\n"
-#~ "\n"
-#~ msgstr ""
-#~ "Lokalna datoteka `%s' je novej¹a, ne jemljem.\n"
-#~ "\n"
-
-#~ msgid "Error (%s): Link %s without a base provided.\n"
-#~ msgstr "Napaka (%s): Podana je povezava %s brez osnove.\n"
-
-#~ msgid "Error (%s): Base %s relative, without referer URL.\n"
-#~ msgstr "Napaka (%s): Osnova %s je relativna, brez sklicujoèega se URL-ja.\n"

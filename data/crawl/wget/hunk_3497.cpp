 "You may stop Wget by pressing CTRL+ALT+DELETE.\n"
 msgstr ""
 "\n"
-"CTRL+Break al�nd�, ��kt� `%s'e y�nlendiriliyor.\n"
-"��lem ardalanda s�recek.\n"
-"CTRL+ALT+DELETE tu�layarak Wget'i durdurabilirsiniz.\n"
+"CTRL+Break alındı, çıktı `%s'e yönlendiriliyor.\n"
+"İşlem ardalanda sürecek.\n"
+"CTRL+ALT+DELETE tuşlayarak Wget'i durdurabilirsiniz.\n"
 
 #. parent, no error
-#: src/mswindows.c:106 src/utils.c:458
+#: src/mswindows.c:123 src/utils.c:462
 msgid "Continuing in background.\n"
-msgstr "Ardalanda s�r�yor.\n"
+msgstr "Ardalanda sürüyor.\n"
 
-#: src/mswindows.c:108 src/utils.c:460
+#: src/mswindows.c:125 src/utils.c:464
 #, c-format
 msgid "Output will be written to `%s'.\n"
-msgstr "��kt� `%s'e yaz�lm�� olacak.\n"
+msgstr "Çıktı `%s'e yazılmış olacak.\n"
 
-#: src/mswindows.c:188
+#: src/mswindows.c:205
 #, c-format
 msgid "Starting WinHelp %s\n"
-msgstr "WinHelp %s Ba�lat�l�yor\n"
+msgstr "WinHelp %s Başlatılıyor\n"
 
-#: src/mswindows.c:215 src/mswindows.c:222
+#: src/mswindows.c:232 src/mswindows.c:239
 #, c-format
 msgid "%s: Couldn't find usable socket driver.\n"
-msgstr "%s: Kullan�labilir soket s�r�c� bulunamad�.\n"
+msgstr "%s: Kullanılabilir soket sürücü bulunamadı.\n"
 
-#: src/netrc.c:367
+#: src/netrc.c:365
 #, c-format
 msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
-msgstr "%s: %s:%d: uyar�: herhangi bir makina isminden �nce \"%s\" dizgeci�i g�r�n�yor\n"
+msgstr "%s: %s:%d: uyarı: herhangi bir makina isminden önce \"%s\" dizgeciği görünüyor\n"
 
-#: src/netrc.c:398
+#: src/netrc.c:396
 #, c-format
 msgid "%s: %s:%d: unknown token \"%s\"\n"
 msgstr "%s: %s:%d: bilinmeyen dizgecik \"%s\"\n"
 
-#: src/netrc.c:462
+#: src/netrc.c:460
 #, c-format
 msgid "Usage: %s NETRC [HOSTNAME]\n"
-msgstr "Kullan�m: %s NETRC [MAK�NA-ADI]\n"
+msgstr "Kullanım: %s NETRC [MAKİNA-ADI]\n"
 
-#: src/netrc.c:472
+#: src/netrc.c:470
 #, c-format
 msgid "%s: cannot stat %s: %s\n"
-msgstr "%s: %s durumlanamad�: %s\n"
+msgstr "%s: %s durumlanamadı: %s\n"
+
+#. Align the [ skipping ... ] line with the dots.  To do
+#. that, insert the number of spaces equal to the number of
+#. digits in the skipped amount in K.
+#: src/progress.c:203
+#, c-format
+msgid "\n%*s[ skipping %dK ]"
+msgstr "\n%*s[ %dK atlanıyor ]"
+
+#: src/progress.c:370
+#, c-format
+msgid "Invalid dot style specification `%s'; leaving unchanged.\n"
+msgstr "`%s' gösterge türü geçersiz; değiştirilmedi.\n"
 
-#: src/recur.c:484
+#: src/recur.c:337
 #, c-format
 msgid "Removing %s since it should be rejected.\n"
-msgstr "Reddedilece�inden %s kald�r�l�yor.\n"
+msgstr "Reddedileceğinden %s kaldırılıyor.\n"
 
-#: src/recur.c:679
+#: src/recur.c:747
+#, c-format
+msgid "Converted %d files in %.2f seconds.\n"
+msgstr "%d dosya %.2f saniyede dönüştürüldü.\n"
+
+#: src/res.c:541
 msgid "Loading robots.txt; please ignore errors.\n"
-msgstr "robots.txt y�kleniyor; l�tfen hatalar� yoksay�n.\n"
+msgstr "robots.txt yükleniyor; lütfen hataları yoksayın.\n"
+
+#: src/retr.c:363
+msgid "Could not find proxy host.\n"
+msgstr "Vekil makina bulunamadı.\n"
 
-#: src/retr.c:227
+#: src/retr.c:375
 #, c-format
-msgid "\n          [ skipping %dK ]"
-msgstr "\n          [ %dK atlan�yor ]"
+msgid "Error parsing proxy URL %s: %s.\n"
+msgstr "Vekil URLsi %s çözümlenirken hata: %s\n"
 
-#: src/retr.c:373
-msgid "Could not find proxy host.\n"
-msgstr "Vekil makina bulunamad�.\n"
+#: src/retr.c:384
+#, c-format
+msgid "Error in proxy URL %s: Must be HTTP.\n"
+msgstr "Vekil URLsi %s: HTTP olmalı.\n"
 
-#: src/retr.c:387
+#: src/retr.c:476
 #, c-format
-msgid "Proxy %s: Must be HTTP.\n"
-msgstr "Vekil makina %s: HTTP olmal�.\n"
+msgid "%d redirections exceeded.\n"
+msgstr "%d yönlendirme geçildi.\n"
 
-#: src/retr.c:481
+#: src/retr.c:491
 #, c-format
 msgid "%s: Redirection cycle detected.\n"
-msgstr "%s: Y�nlendirme �evrimi saptand�.\n"
+msgstr "%s: Yönlendirme çevrimi saptandı.\n"
 
-#: src/retr.c:587
+#: src/retr.c:608
 msgid "Giving up.\n\n"
-msgstr "Vazge�iliyor.\n\n"
+msgstr "Vazgeçiliyor.\n\n"
 
-#: src/retr.c:587
+#: src/retr.c:608
 msgid "Retrying.\n\n"
-msgstr "Tekrarlan�yor.\n\n"
+msgstr "Tekrarlanıyor.\n\n"
 
-#: src/url.c:1329
+#: src/url.c:1725
 #, c-format
 msgid "Converting %s... "
-msgstr "%s d�n��t�r�l�yor..."
+msgstr "%s dönüştürülüyor..."
 
-#: src/url.c:1342
+#: src/url.c:1738
 msgid "nothing to do.\n"
-msgstr "bir�ey yap�lmad�.\n"
+msgstr "birşey yapılmadı.\n"
 
-#: src/url.c:1350 src/url.c:1374
+#: src/url.c:1746 src/url.c:1770
 #, c-format
 msgid "Cannot convert links in %s: %s\n"
-msgstr "%s deki ba�lar d�n��t�r�lemiyor: %s\n"
+msgstr "%s deki bağlar dönüştürülemiyor: %s\n"
 
-#: src/url.c:1365
+#: src/url.c:1761
 #, c-format
 msgid "Unable to delete `%s': %s\n"
 msgstr "`%s' silinemiyor: %s\n"
 
-#: src/url.c:1555
+#: src/url.c:1967
 #, c-format
 msgid "Cannot back up %s as %s: %s\n"
 msgstr "%s, %s olarak yedeklenemiyor: %s\n"
 
-#: src/utils.c:94
+#: src/utils.c:97
 #, c-format
 msgid "%s: %s: Not enough memory.\n"
 msgstr "%s: %s: Bellek yetersiz.\n"
 
-#: src/utils.c:417
-msgid "Unknown/unsupported protocol"
-msgstr "Bilinmeyen/desteklenmeyen protokol"
-
-#: src/utils.c:420
-msgid "Invalid port specification"
-msgstr "Port �zellikleri ge�ersiz"
-
-#: src/utils.c:423
-msgid "Invalid host name"
-msgstr "Makina ismi ge�ersiz"
-
-#: src/utils.c:620
+#: src/utils.c:634
 #, c-format
 msgid "Failed to unlink symlink `%s': %s\n"
-msgstr "`%s' sembolik ba� as�l dosyaya d�n��t�r�l�rken ba�ar�s�z: %s\n"
+msgstr "`%s' sembolik bağ asıl dosyaya dönüştürülürken başarısız: %s\n"

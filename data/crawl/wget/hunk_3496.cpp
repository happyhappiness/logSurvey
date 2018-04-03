 #. No luck.
 #. #### This message SUCKS.  We should see what was the
 #. reason that nothing was retrieved.
-#: src/ftp.c:1606
+#: src/ftp.c:1621
 #, c-format
 msgid "No matches on pattern `%s'.\n"
-msgstr "`%s' kalıbına uygun sonuç gelmedi.\n"
+msgstr "`%s' kalÄ±bÄ±na uygun sonuÃ§ gelmedi.\n"
 
-#: src/ftp.c:1671
+#: src/ftp.c:1686
 #, c-format
 msgid "Wrote HTML-ized index to `%s' [%ld].\n"
-msgstr "HTMLeştirilmiş indeks `%s' e yazıldı [%ld].\n"
+msgstr "HTMLeÅŸtirilmiÅŸ indeks `%s' e yazÄ±ldÄ± [%ld].\n"
 
-#: src/ftp.c:1676
+#: src/ftp.c:1691
 #, c-format
 msgid "Wrote HTML-ized index to `%s'.\n"
-msgstr "HTMLeştirilmiş indeks `%s' e yazıldı.\n"
+msgstr "HTMLeÅŸtirilmiÅŸ indeks `%s' e yazÄ±ldÄ±.\n"
 
 #: src/getopt.c:454
 #, c-format
 msgid "%s: option `%s' is ambiguous\n"
-msgstr "%s: seçenek `%s' belirsiz\n"
+msgstr "%s: seÃ§enek `%s' belirsiz\n"
 
 #: src/getopt.c:478
 #, c-format
 msgid "%s: option `--%s' doesn't allow an argument\n"
-msgstr "%s: seçenek `--%s' argümansız kullanılır\n"
+msgstr "%s: seÃ§enek `--%s' argÃ¼mansÄ±z kullanÄ±lÄ±r\n"
 
 #: src/getopt.c:483
 #, c-format
 msgid "%s: option `%c%s' doesn't allow an argument\n"
-msgstr "%s: seçenek `%c%s' argümansız kullanılır\n"
+msgstr "%s: seÃ§enek `%c%s' argÃ¼mansÄ±z kullanÄ±lÄ±r\n"
 
 #: src/getopt.c:498
 #, c-format
 msgid "%s: option `%s' requires an argument\n"
-msgstr "%s: seçenek `%s' bir argümanla kullanılır\n"
+msgstr "%s: seÃ§enek `%s' bir argÃ¼manla kullanÄ±lÄ±r\n"
 
 #. --option
 #: src/getopt.c:528
 #, c-format
 msgid "%s: unrecognized option `--%s'\n"
-msgstr "%s: `--%s' seçeneği bilinmiyor\n"
+msgstr "%s: `--%s' seÃ§eneÄŸi bilinmiyor\n"
 
 #. +option or -option
 #: src/getopt.c:532
 #, c-format
 msgid "%s: unrecognized option `%c%s'\n"
-msgstr "%s: `%c%s' seçeneği bilinmiyor\n"
+msgstr "%s: `%c%s' seÃ§eneÄŸi bilinmiyor\n"
 
 #. 1003.2 specifies the format of this message.
 #: src/getopt.c:563
 #, c-format
 msgid "%s: illegal option -- %c\n"
-msgstr "%s: kuraldışı seçenek -- %c\n"
+msgstr "%s: kuraldÄ±ÅŸÄ± seÃ§enek -- %c\n"
 
 #. 1003.2 specifies the format of this message.
 #: src/getopt.c:602
 #, c-format
 msgid "%s: option requires an argument -- %c\n"
-msgstr "%s: seçenek bir argümanla kullanılır -- %c\n"
+msgstr "%s: seÃ§enek bir argÃ¼manla kullanÄ±lÄ±r -- %c\n"
 
-#: src/host.c:374
+#: src/host.c:251
+#, c-format
+msgid "Resolving %s... "
+msgstr "%s Ã§Ã¶zÃ¼mleniyor... "
+
+#: src/host.c:258
+#, c-format
+msgid "failed: %s.\n"
+msgstr "olmadÄ±: %s.\n"
+
+#: src/host.c:326
 msgid "Host not found"
-msgstr "Makina bulunamadı"
+msgstr "Makina bulunamadÄ±"
 
-#: src/host.c:376
+#: src/host.c:328
 msgid "Unknown error"
-msgstr "Hata anlaşılamadı"
+msgstr "Hata anlaÅŸÄ±lamadÄ±"
 
 #. this is fatal
-#: src/http.c:555
+#: src/http.c:584
 msgid "Failed to set up an SSL context\n"
-msgstr "Bir SSL bağlamı belirlenemedi\n"
+msgstr "Bir SSL baÄŸlamÄ± belirlenemedi\n"
 
-#: src/http.c:561
+#: src/http.c:590
 #, c-format
 msgid "Failed to load certificates from %s\n"
-msgstr "Sertifikalar %s'den yüklenemedi\n"
+msgstr "Sertifikalar %s'den yÃ¼klenemedi\n"
 
-#: src/http.c:565 src/http.c:573
+#: src/http.c:594 src/http.c:602
 msgid "Trying without the specified certificate\n"
-msgstr "Belirtilen sertifikasız deneniyor\n"
+msgstr "Belirtilen sertifikasÄ±z deneniyor\n"
 
-#: src/http.c:569
+#: src/http.c:598
 #, c-format
 msgid "Failed to get certificate key from %s\n"
-msgstr "Sertifika anahtarı %s'den alınamadı\n"
+msgstr "Sertifika anahtarÄ± %s'den alÄ±namadÄ±\n"
 
-#: src/http.c:663 src/http.c:1593
+#: src/http.c:668 src/http.c:1631
 msgid "Unable to establish SSL connection.\n"
-msgstr "SSL bağlantısı kurulamıyor.\n"
+msgstr "SSL baÄŸlantÄ±sÄ± kurulamÄ±yor.\n"
 
-#: src/http.c:671
+#: src/http.c:677
 #, c-format
 msgid "Reusing connection to %s:%hu.\n"
-msgstr "Bağlantı tekrar kullanılıyor: %s:%hu.\n"
+msgstr "BaÄŸlantÄ± tekrar kullanÄ±lÄ±yor: %s:%hu.\n"
 
-#: src/http.c:861
+#: src/http.c:879
 #, c-format
 msgid "Failed writing HTTP request: %s.\n"
-msgstr "HTTP isteğini yazma başarısız: %s.\n"
+msgstr "HTTP isteÄŸini yazma baÅŸarÄ±sÄ±z: %s.\n"
 
-#: src/http.c:866
+#: src/http.c:884
 #, c-format
 msgid "%s request sent, awaiting response... "
-msgstr "%s isteği gönderildi, cevap bekleniyor... "
+msgstr "%s isteÄŸi gÃ¶nderildi, cevap bekleniyor... "
 
-#: src/http.c:910
+#: src/http.c:928
 msgid "End of file while parsing headers.\n"
-msgstr "Başlıklar çözümlenirken dosya sonuyla karşılaşıldı.\n"
+msgstr "BaÅŸlÄ±klar Ã§Ã¶zÃ¼mlenirken dosya sonuyla karÅŸÄ±laÅŸÄ±ldÄ±.\n"
 
-#: src/http.c:920
+#: src/http.c:938
 #, c-format
 msgid "Read error (%s) in headers.\n"
-msgstr "Başlıklar okunurken hata (%s).\n"
+msgstr "BaÅŸlÄ±klar okunurken hata (%s).\n"
 
-#: src/http.c:959
+#: src/http.c:973
 msgid "No data received"
-msgstr "Alınan veri yok"
+msgstr "AlÄ±nan veri yok"
 
-#: src/http.c:961
+#: src/http.c:975
 msgid "Malformed status line"
-msgstr "Durum satırı bozuk"
+msgstr "Durum satÄ±rÄ± bozuk"
 
-#: src/http.c:966
+#: src/http.c:980
 msgid "(no description)"
-msgstr "(açıklama yok)"
+msgstr "(aÃ§Ä±klama yok)"
 
-#: src/http.c:1089
+#: src/http.c:1112
 msgid "Authorization failed.\n"
-msgstr "Yetkilendirme başarısız.\n"
+msgstr "Yetkilendirme baÅŸarÄ±sÄ±z.\n"
 
-#: src/http.c:1096
+#: src/http.c:1119
 msgid "Unknown authentication scheme.\n"
-msgstr "Kimlik tanımlama şeması bilinmiyor.\n"
+msgstr "Kimlik tanÄ±mlama ÅŸemasÄ± bilinmiyor.\n"
 
-#: src/http.c:1136
+#: src/http.c:1159
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Yer: %s%s\n"
 
-#: src/http.c:1137 src/http.c:1269
+#: src/http.c:1160 src/http.c:1293
 msgid "unspecified"
 msgstr "belirtilmeyen"
 
-#: src/http.c:1138
+#: src/http.c:1161
 msgid " [following]"
 msgstr " [izleyen]"
 
-#: src/http.c:1200
+#: src/http.c:1224
 msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
-msgstr "\n    Dosya zaten alınmıştı; birşey yapılmadı.\n\n"
+msgstr "\n    Dosya zaten alÄ±nmÄ±ÅŸtÄ±; birÅŸey yapÄ±lmadÄ±.\n\n"
 
-#: src/http.c:1216
+#: src/http.c:1240
 #, c-format
 msgid ""
 "\n"

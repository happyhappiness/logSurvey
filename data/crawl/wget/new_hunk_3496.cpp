#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1621
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "`%s' kalıbına uygun sonuç gelmedi.\n"

#: src/ftp.c:1686
#, c-format
msgid "Wrote HTML-ized index to `%s' [%ld].\n"
msgstr "HTMLeştirilmiş indeks `%s' e yazıldı [%ld].\n"

#: src/ftp.c:1691
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "HTMLeştirilmiş indeks `%s' e yazıldı.\n"

#: src/getopt.c:454
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: seçenek `%s' belirsiz\n"

#: src/getopt.c:478
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: seçenek `--%s' argümansız kullanılır\n"

#: src/getopt.c:483
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: seçenek `%c%s' argümansız kullanılır\n"

#: src/getopt.c:498
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: seçenek `%s' bir argümanla kullanılır\n"

#. --option
#: src/getopt.c:528
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: `--%s' seçeneği bilinmiyor\n"

#. +option or -option
#: src/getopt.c:532
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: `%c%s' seçeneği bilinmiyor\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:563
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: kuraldışı seçenek -- %c\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:602
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: seçenek bir argümanla kullanılır -- %c\n"

#: src/host.c:251
#, c-format
msgid "Resolving %s... "
msgstr "%s çözümleniyor... "

#: src/host.c:258
#, c-format
msgid "failed: %s.\n"
msgstr "olmadı: %s.\n"

#: src/host.c:326
msgid "Host not found"
msgstr "Makina bulunamadı"

#: src/host.c:328
msgid "Unknown error"
msgstr "Hata anlaşılamadı"

#. this is fatal
#: src/http.c:584
msgid "Failed to set up an SSL context\n"
msgstr "Bir SSL bağlamı belirlenemedi\n"

#: src/http.c:590
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "Sertifikalar %s'den yüklenemedi\n"

#: src/http.c:594 src/http.c:602
msgid "Trying without the specified certificate\n"
msgstr "Belirtilen sertifikasız deneniyor\n"

#: src/http.c:598
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "Sertifika anahtarı %s'den alınamadı\n"

#: src/http.c:668 src/http.c:1631
msgid "Unable to establish SSL connection.\n"
msgstr "SSL bağlantısı kurulamıyor.\n"

#: src/http.c:677
#, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Bağlantı tekrar kullanılıyor: %s:%hu.\n"

#: src/http.c:879
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "HTTP isteğini yazma başarısız: %s.\n"

#: src/http.c:884
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s isteği gönderildi, cevap bekleniyor... "

#: src/http.c:928
msgid "End of file while parsing headers.\n"
msgstr "Başlıklar çözümlenirken dosya sonuyla karşılaşıldı.\n"

#: src/http.c:938
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Başlıklar okunurken hata (%s).\n"

#: src/http.c:973
msgid "No data received"
msgstr "Alınan veri yok"

#: src/http.c:975
msgid "Malformed status line"
msgstr "Durum satırı bozuk"

#: src/http.c:980
msgid "(no description)"
msgstr "(açıklama yok)"

#: src/http.c:1112
msgid "Authorization failed.\n"
msgstr "Yetkilendirme başarısız.\n"

#: src/http.c:1119
msgid "Unknown authentication scheme.\n"
msgstr "Kimlik tanımlama şeması bilinmiyor.\n"

#: src/http.c:1159
#, c-format
msgid "Location: %s%s\n"
msgstr "Yer: %s%s\n"

#: src/http.c:1160 src/http.c:1293
msgid "unspecified"
msgstr "belirtilmeyen"

#: src/http.c:1161
msgid " [following]"
msgstr " [izleyen]"

#: src/http.c:1224
msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
msgstr "\n    Dosya zaten alınmıştı; birşey yapılmadı.\n\n"

#: src/http.c:1240
#, c-format
msgid ""
"\n"

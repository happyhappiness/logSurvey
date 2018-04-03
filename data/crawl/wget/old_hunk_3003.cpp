msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: seçenek `-W %s' argümansız kullanılır\n"

#: src/host.c:636
#, c-format
msgid "Resolving %s... "
msgstr "%s çözümleniyor... "

#: src/host.c:656 src/host.c:672
#, c-format
msgid "failed: %s.\n"
msgstr "olmadı: %s.\n"

#: src/host.c:674
msgid "failed: timed out.\n"
msgstr "olmadı: zamanaşımı.\n"

#: src/host.c:762
msgid "Host not found"
msgstr "Makina bulunamadı"

#: src/host.c:764
msgid "Unknown error"
msgstr "Hata anlaşılamadı"

#: src/html-url.c:293
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: İçi boş %s bağı çözümlenemez.\n"

#. this is fatal
#: src/http.c:674
msgid "Failed to set up an SSL context\n"
msgstr "Bir SSL bağlamı belirlenemedi\n"

#: src/http.c:680
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "Sertifikalar %s'den yüklenemedi\n"

#: src/http.c:684 src/http.c:692
msgid "Trying without the specified certificate\n"
msgstr "Belirtilen sertifikasız deneniyor\n"

#: src/http.c:688
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "Sertifika anahtarı %s'den alınamadı\n"

#: src/http.c:761 src/http.c:1809
msgid "Unable to establish SSL connection.\n"
msgstr "SSL bağlantısı kurulamıyor.\n"

#: src/http.c:770
#, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Bağlantı tekrar kullanılıyor: %s:%hu.\n"

#: src/http.c:1034
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "HTTP isteğini yazma başarısız: %s.\n"

#: src/http.c:1039
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s isteği gönderildi, cevap bekleniyor... "

#: src/http.c:1083
msgid "End of file while parsing headers.\n"
msgstr "Başlıklar çözümlenirken dosya sonuyla karşılaşıldı.\n"

#: src/http.c:1093
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Başlıklar okunurken hata (%s).\n"

#: src/http.c:1128
msgid "No data received"
msgstr "Alınan veri yok"

#: src/http.c:1130
msgid "Malformed status line"
msgstr "Durum satırı bozuk"

#: src/http.c:1135
msgid "(no description)"
msgstr "(açıklama yok)"

#: src/http.c:1267
msgid "Authorization failed.\n"
msgstr "Yetkilendirme başarısız.\n"

#: src/http.c:1274
msgid "Unknown authentication scheme.\n"
msgstr "Kimlik tanımlama şeması bilinmiyor.\n"

#: src/http.c:1314
#, c-format
msgid "Location: %s%s\n"
msgstr "Yer: %s%s\n"

#: src/http.c:1315 src/http.c:1454
msgid "unspecified"
msgstr "belirtilmeyen"

#: src/http.c:1316
msgid " [following]"
msgstr " [izleyen]"

#: src/http.c:1383
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"

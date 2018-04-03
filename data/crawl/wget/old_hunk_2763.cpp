msgid "No headers, assuming HTTP/0.9"
msgstr "Başlıklar eksik, HTTP/0.9 olduğu varsayılıyor"

#: src/http.c:1198
msgid "Disabling SSL due to encountered errors.\n"
msgstr "Ne olduğu belirsiz hatalardan dolayı SSL iptal ediliyor.\n"

#: src/http.c:1417
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Bağlantı tekrar kullanılıyor: %s:%d.\n"

#: src/http.c:1479
#, c-format
msgid "Failed writing to proxy: %s.\n"
msgstr "Vekile yazılamadı: %s.\n"

#: src/http.c:1488
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Vekilin yanıtı okunamadı: %s\n"

#: src/http.c:1508
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "Vekil tünellenemedi: %s"

#: src/http.c:1555
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s isteği gönderildi, yanıt bekleniyor... "

#: src/http.c:1566
msgid "No data received.\n"
msgstr "Hiçbir veri alınmadı.\n"

#: src/http.c:1573
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Başlıklar okunurken hata (%s).\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1658
msgid "Unknown authentication scheme.\n"
msgstr "Kimlik tanımlama şeması bilinmiyor.\n"

#: src/http.c:1682
msgid "Authorization failed.\n"
msgstr "Yetkilendirme başarısız.\n"

#: src/http.c:1696
msgid "Malformed status line"
msgstr "Durum satırı bozuk"

#: src/http.c:1698
msgid "(no description)"
msgstr "(açıklama yok)"

#: src/http.c:1769
#, c-format
msgid "Location: %s%s\n"
msgstr "Yer: %s%s\n"

#: src/http.c:1770 src/http.c:1867
msgid "unspecified"
msgstr "belirtilmeyen"

#: src/http.c:1771
msgid " [following]"
msgstr " [izleyen]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:1817
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"

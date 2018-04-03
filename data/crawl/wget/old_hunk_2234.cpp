msgid "Reusing existing connection to %s:%d.\n"
msgstr "Bağlantı tekrar kullanılıyor: %s:%d.\n"

#: src/http.c:1684
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Vekilin yanıtı okunamadı: %s\n"

#: src/http.c:1704
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "Vekil tünellenemedi: %s"

#: src/http.c:1749
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s isteği gönderildi, yanıt bekleniyor... "

#: src/http.c:1760
msgid "No data received.\n"
msgstr "Hiçbir veri alınmadı.\n"

#: src/http.c:1767
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Başlıklar okunurken hata (%s).\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1813
#, c-format
msgid ""
"File `%s' already there; not retrieving.\n"
"\n"
msgstr "`%s' dosyası zaten var; alınmayacak.\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1966
msgid "Unknown authentication scheme.\n"
msgstr "Kimlik tanımlama şeması bilinmiyor.\n"

#: src/http.c:1997
msgid "Authorization failed.\n"
msgstr "Yetkilendirme başarısız.\n"

#: src/http.c:2011
msgid "Malformed status line"
msgstr "Durum satırı bozuk"

#: src/http.c:2013
msgid "(no description)"
msgstr "(açıklama yok)"

#: src/http.c:2076
#, c-format
msgid "Location: %s%s\n"
msgstr "Yer: %s%s\n"

#: src/http.c:2077 src/http.c:2184
msgid "unspecified"
msgstr "belirtilmeyen"

#: src/http.c:2078
msgid " [following]"
msgstr " [izleyen]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:2134
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"

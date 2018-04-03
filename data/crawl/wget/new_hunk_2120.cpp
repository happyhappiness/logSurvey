"Zaten doğru sembolik bağ var: %s -> %s\n"
"\n"

#: src/ftp.c:1494
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Sembolik bağ oluşturuluyor: %s -> %s\n"

#: src/ftp.c:1504
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "Sembolik bağ desteklenmiyor. `%s' sembolik bağı atlanıyor.\n"

#: src/ftp.c:1516
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "`%s' dizini atlanıyor.\n"

#: src/ftp.c:1525
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: bilinmeyen/desteklenmeyen dosya türü.\n"

#: src/ftp.c:1552
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: zaman damgası bozuk.\n"

#: src/ftp.c:1580
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "%d derinliğindeki dizinler alınamayacak (en çok %d)\n"

#: src/ftp.c:1630
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "Dışlanan/izin-verilmeyen olarak `%s' e inilmiyor.\n"

#: src/ftp.c:1696 src/ftp.c:1710
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "`%s' reddediliyor.\n"

#: src/ftp.c:1733
#, fuzzy, c-format
msgid "Error matching %s against %s: %s\n"
msgstr "`%s' yazılırken hata: %s\n"

#: src/ftp.c:1774
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "`%s' kalıbına uygun sonuç gelmedi.\n"

#: src/ftp.c:1840
#, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr "HTMLeştirilmiş indeks `%s' e yazıldı [%s].\n"

#: src/ftp.c:1845
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "HTMLeştirilmiş indeks `%s' e yazıldı.\n"

#: src/host.c:348
msgid "Unknown host"
msgstr "Bilinmeyen makine"

#: src/host.c:352
msgid "Temporary failure in name resolution"
msgstr "İsim çözümlemesinde geçici bir hata oluştu"

#: src/host.c:354
msgid "Unknown error"
msgstr "Hata anlaşılamadı"

#: src/host.c:715
#, c-format
msgid "Resolving %s... "
msgstr "%s çözümleniyor... "

#: src/host.c:762
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "olmadı: Makinenin bir IPv4/IPv6 adresi yok.\n"

#: src/host.c:785
msgid "failed: timed out.\n"
msgstr "olmadı: zamanaşımı.\n"

#: src/html-url.c:289
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: İçi boş %s bağı çözümlenemez.\n"

#: src/html-url.c:696
#, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: URL `%s' geçersiz: %s\n"

#: src/http.c:368
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "HTTP isteğini yazma başarısız: %s.\n"

#: src/http.c:737
msgid "No headers, assuming HTTP/0.9"
msgstr "Başlıklar eksik, HTTP/0.9 olduğu varsayılıyor"

#: src/http.c:1417
msgid "Disabling SSL due to encountered errors.\n"
msgstr "Ne olduğu belirsiz hatalardan dolayı SSL iptal ediliyor.\n"

#: src/http.c:1570
#, c-format
msgid "POST data file `%s' missing: %s\n"
msgstr "POST veri dosyası `%s' kayıp: %s\n"

#: src/http.c:1619
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Bağlantı tekrar kullanılıyor: %s:%d.\n"

#: src/http.c:1687
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Vekilin yanıtı okunamadı: %s\n"

#: src/http.c:1707
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "Vekil tünellenemedi: %s"

#: src/http.c:1752
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s isteği gönderildi, yanıt bekleniyor... "

#: src/http.c:1763
msgid "No data received.\n"
msgstr "Hiçbir veri alınmadı.\n"

#: src/http.c:1770
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Başlıklar okunurken hata (%s).\n"

#: src/http.c:1816 src/http.c:2368
#, c-format
msgid ""
"File `%s' already there; not retrieving.\n"
"\n"
msgstr "`%s' dosyası zaten var; alınmayacak.\n"

#: src/http.c:1969
msgid "Unknown authentication scheme.\n"
msgstr "Kimlik tanımlama şeması bilinmiyor.\n"

#: src/http.c:2000
msgid "Authorization failed.\n"
msgstr "Yetkilendirme başarısız.\n"

#: src/http.c:2014
msgid "Malformed status line"
msgstr "Durum satırı bozuk"

#: src/http.c:2016
msgid "(no description)"
msgstr "(açıklama yok)"

#: src/http.c:2082
#, c-format
msgid "Location: %s%s\n"
msgstr "Yer: %s%s\n"

#: src/http.c:2083 src/http.c:2193
msgid "unspecified"
msgstr "belirtilmeyen"

#: src/http.c:2084
msgid " [following]"
msgstr " [izleyen]"

#: src/http.c:2140
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"

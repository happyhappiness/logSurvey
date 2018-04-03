 msgid "Failed writing HTTP request: %s.\n"
 msgstr "HTTP isteğini yazma başarısız: %s.\n"
 
-#: src/http.c:737
+#: src/http.c:745
 msgid "No headers, assuming HTTP/0.9"
 msgstr "Başlıklar eksik, HTTP/0.9 olduğu varsayılıyor"
 
-#: src/http.c:1417
+#: src/http.c:1430
 msgid "Disabling SSL due to encountered errors.\n"
 msgstr "Ne olduğu belirsiz hatalardan dolayı SSL iptal ediliyor.\n"
 
-#: src/http.c:1570
-#, c-format
-msgid "POST data file `%s' missing: %s\n"
+#: src/http.c:1548
+#, fuzzy, c-format
+msgid "POST data file %s missing: %s\n"
 msgstr "POST veri dosyası `%s' kayıp: %s\n"
 
-#: src/http.c:1619
+#: src/http.c:1632
 #, c-format
 msgid "Reusing existing connection to %s:%d.\n"
 msgstr "Bağlantı tekrar kullanılıyor: %s:%d.\n"
 
-#: src/http.c:1687
+#: src/http.c:1701
 #, c-format
 msgid "Failed reading proxy response: %s\n"
 msgstr "Vekilin yanıtı okunamadı: %s\n"
 
-#: src/http.c:1707
+#: src/http.c:1721
 #, c-format
 msgid "Proxy tunneling failed: %s"
 msgstr "Vekil tünellenemedi: %s"
 
-#: src/http.c:1752
+#: src/http.c:1766
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s isteği gönderildi, yanıt bekleniyor... "
 
-#: src/http.c:1763
+#: src/http.c:1777
 msgid "No data received.\n"
 msgstr "Hiçbir veri alınmadı.\n"
 
-#: src/http.c:1770
+#: src/http.c:1784
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Başlıklar okunurken hata (%s).\n"
 
-#: src/http.c:1816 src/http.c:2368
-#, c-format
+#: src/http.c:1831 src/http.c:2385
+#, fuzzy, c-format
 msgid ""
-"File `%s' already there; not retrieving.\n"
+"File %s already there; not retrieving.\n"
 "\n"
 msgstr "`%s' dosyası zaten var; alınmayacak.\n"
 
-#: src/http.c:1969
+#: src/http.c:1985
 msgid "Unknown authentication scheme.\n"
 msgstr "Kimlik tanımlama şeması bilinmiyor.\n"
 
-#: src/http.c:2000
+#: src/http.c:2016
 msgid "Authorization failed.\n"
 msgstr "Yetkilendirme başarısız.\n"
 
-#: src/http.c:2014
+#: src/http.c:2030
 msgid "Malformed status line"
 msgstr "Durum satırı bozuk"
 
-#: src/http.c:2016
+#: src/http.c:2032
 msgid "(no description)"
 msgstr "(açıklama yok)"
 
-#: src/http.c:2082
+#: src/http.c:2098
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Yer: %s%s\n"
 
-#: src/http.c:2083 src/http.c:2193
+#: src/http.c:2099 src/http.c:2209
 msgid "unspecified"
 msgstr "belirtilmeyen"
 
-#: src/http.c:2084
+#: src/http.c:2100
 msgid " [following]"
 msgstr " [izleyen]"
 
-#: src/http.c:2140
+#: src/http.c:2156
 msgid ""
 "\n"
 "    The file is already fully retrieved; nothing to do.\n"

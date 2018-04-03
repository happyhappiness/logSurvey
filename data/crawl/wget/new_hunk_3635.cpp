msgstr "Hata anlaþýlamadý"

#. this is fatal
#: src/http.c:555
msgid "Failed to set up an SSL context\n"
msgstr "Bir SSL baðlamý belirlenemedi\n"

#: src/http.c:561
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "Sertifikalar %s'den yüklenemedi\n"

#: src/http.c:565 src/http.c:573
msgid "Trying without the specified certificate\n"
msgstr "Belirtilen sertifikasýz deneniyor\n"

#: src/http.c:569
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "Sertifika anahtarý %s'den alýnamadý\n"

#: src/http.c:663 src/http.c:1593
msgid "Unable to establish SSL connection.\n"
msgstr "SSL baðlantýsý kurulamýyor.\n"

#: src/http.c:671
#, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Baðlantý tekrar kullanýlýyor: %s:%hu.\n"

#: src/http.c:861
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "HTTP isteðini yazma baþarýsýz: %s.\n"

#: src/http.c:866
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s isteði gönderildi, cevap bekleniyor... "

#: src/http.c:910
msgid "End of file while parsing headers.\n"
msgstr "Baþlýklar çözümlenirken dosya sonuyla karþýlaþýldý.\n"

#: src/http.c:920
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Baþlýklar okunurken hata (%s).\n"

#: src/http.c:959
msgid "No data received"
msgstr "Alýnan veri yok"

#: src/http.c:961
msgid "Malformed status line"
msgstr "Durum satýrý bozuk"

#: src/http.c:966
msgid "(no description)"
msgstr "(açýklama yok)"

#: src/http.c:1089
msgid "Authorization failed.\n"
msgstr "Yetkilendirme baþarýsýz.\n"

#: src/http.c:1096
msgid "Unknown authentication scheme.\n"
msgstr "Kimlik tanýmlama þemasý bilinmiyor.\n"

#: src/http.c:1136
#, c-format
msgid "Location: %s%s\n"
msgstr "Yer: %s%s\n"

#: src/http.c:1137 src/http.c:1269
msgid "unspecified"
msgstr "belirtilmeyen"

#: src/http.c:1138
msgid " [following]"
msgstr " [izleyen]"

#: src/http.c:1200
msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
msgstr "\n    Dosya zaten alýnmýþtý; birþey yapýlmadý.\n\n"

#: src/http.c:1216
#, c-format
msgid ""
"\n"
"Continued download failed on this file, which conflicts with `-c'.\n"
"Refusing to truncate existing file `%s'.\n"
"\n"
msgstr ""

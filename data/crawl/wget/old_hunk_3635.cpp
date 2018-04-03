msgstr "Hata anlaþýlamadý"

#. this is fatal
#: src/http.c:554
msgid "Failed to set up an SSL context\n"
msgstr "Bir SSL baðlamý belirlenemedi\n"

#: src/http.c:560
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "Sertifikalar %s'den yüklenemedi\n"

#: src/http.c:564 src/http.c:572
msgid "Trying without the specified certificate\n"
msgstr "Belirtilen setifikasýz deneniyor\n"

#: src/http.c:568
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "Sertifika anahtarý %s'den alýnamadý\n"

#: src/http.c:662 src/http.c:1592
msgid "Unable to establish SSL connection.\n"
msgstr "SSL baðlantýsý kurulamýyor.\n"

#: src/http.c:670
#, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Baðlantý tekrar kullanýlýyor: %s:%hu.\n"

#: src/http.c:860
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "HTTP isteðini yazma baþarýsýz: %s.\n"

#: src/http.c:865
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s isteði gönderildi, cevap bekleniyor... "

#: src/http.c:909
msgid "End of file while parsing headers.\n"
msgstr "Baþlýklar çözümlenirken dosya sonuyla karþýlaþýldý.\n"

#: src/http.c:919
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Baþlýklar okunurken hata (%s).\n"

#: src/http.c:958
msgid "No data received"
msgstr "Alýnan veri yok"

#: src/http.c:960
msgid "Malformed status line"
msgstr "Durum satýrý bozuk"

#: src/http.c:965
msgid "(no description)"
msgstr "(açýklama yok)"

#: src/http.c:1088
msgid "Authorization failed.\n"
msgstr "Yetkilendirme baþarýsýz.\n"

#: src/http.c:1095
msgid "Unknown authentication scheme.\n"
msgstr "Kimlik tanýmlama þemasý bilinmiyor.\n"

#: src/http.c:1135
#, c-format
msgid "Location: %s%s\n"
msgstr "Yer: %s%s\n"

#: src/http.c:1136 src/http.c:1268
msgid "unspecified"
msgstr "belirtilmeyen"

#: src/http.c:1137
msgid " [following]"
msgstr " [izleyen]"

#: src/http.c:1199
msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
msgstr "\n    Dosya zaten alýnmýþtý; birþey yapýlmadý.\n\n"

#: src/http.c:1215
#, c-format
msgid ""
"\n"
"The server does not support continued downloads, which conflicts with `-c'.\n"
"Refusing to truncate existing file `%s'.\n"
"\n"
msgstr ""

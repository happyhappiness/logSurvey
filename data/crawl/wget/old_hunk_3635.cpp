msgstr "Hata anla��lamad�"

#. this is fatal
#: src/http.c:554
msgid "Failed to set up an SSL context\n"
msgstr "Bir SSL ba�lam� belirlenemedi\n"

#: src/http.c:560
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "Sertifikalar %s'den y�klenemedi\n"

#: src/http.c:564 src/http.c:572
msgid "Trying without the specified certificate\n"
msgstr "Belirtilen setifikas�z deneniyor\n"

#: src/http.c:568
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "Sertifika anahtar� %s'den al�namad�\n"

#: src/http.c:662 src/http.c:1592
msgid "Unable to establish SSL connection.\n"
msgstr "SSL ba�lant�s� kurulam�yor.\n"

#: src/http.c:670
#, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Ba�lant� tekrar kullan�l�yor: %s:%hu.\n"

#: src/http.c:860
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "HTTP iste�ini yazma ba�ar�s�z: %s.\n"

#: src/http.c:865
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s iste�i g�nderildi, cevap bekleniyor... "

#: src/http.c:909
msgid "End of file while parsing headers.\n"
msgstr "Ba�l�klar ��z�mlenirken dosya sonuyla kar��la��ld�.\n"

#: src/http.c:919
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Ba�l�klar okunurken hata (%s).\n"

#: src/http.c:958
msgid "No data received"
msgstr "Al�nan veri yok"

#: src/http.c:960
msgid "Malformed status line"
msgstr "Durum sat�r� bozuk"

#: src/http.c:965
msgid "(no description)"
msgstr "(a��klama yok)"

#: src/http.c:1088
msgid "Authorization failed.\n"
msgstr "Yetkilendirme ba�ar�s�z.\n"

#: src/http.c:1095
msgid "Unknown authentication scheme.\n"
msgstr "Kimlik tan�mlama �emas� bilinmiyor.\n"

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
msgstr "\n    Dosya zaten al�nm��t�; bir�ey yap�lmad�.\n\n"

#: src/http.c:1215
#, c-format
msgid ""
"\n"
"The server does not support continued downloads, which conflicts with `-c'.\n"
"Refusing to truncate existing file `%s'.\n"
"\n"
msgstr ""

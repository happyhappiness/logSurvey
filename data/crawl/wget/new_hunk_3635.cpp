msgstr "Hata anla��lamad�"

#. this is fatal
#: src/http.c:555
msgid "Failed to set up an SSL context\n"
msgstr "Bir SSL ba�lam� belirlenemedi\n"

#: src/http.c:561
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "Sertifikalar %s'den y�klenemedi\n"

#: src/http.c:565 src/http.c:573
msgid "Trying without the specified certificate\n"
msgstr "Belirtilen sertifikas�z deneniyor\n"

#: src/http.c:569
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "Sertifika anahtar� %s'den al�namad�\n"

#: src/http.c:663 src/http.c:1593
msgid "Unable to establish SSL connection.\n"
msgstr "SSL ba�lant�s� kurulam�yor.\n"

#: src/http.c:671
#, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Ba�lant� tekrar kullan�l�yor: %s:%hu.\n"

#: src/http.c:861
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "HTTP iste�ini yazma ba�ar�s�z: %s.\n"

#: src/http.c:866
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s iste�i g�nderildi, cevap bekleniyor... "

#: src/http.c:910
msgid "End of file while parsing headers.\n"
msgstr "Ba�l�klar ��z�mlenirken dosya sonuyla kar��la��ld�.\n"

#: src/http.c:920
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Ba�l�klar okunurken hata (%s).\n"

#: src/http.c:959
msgid "No data received"
msgstr "Al�nan veri yok"

#: src/http.c:961
msgid "Malformed status line"
msgstr "Durum sat�r� bozuk"

#: src/http.c:966
msgid "(no description)"
msgstr "(a��klama yok)"

#: src/http.c:1089
msgid "Authorization failed.\n"
msgstr "Yetkilendirme ba�ar�s�z.\n"

#: src/http.c:1096
msgid "Unknown authentication scheme.\n"
msgstr "Kimlik tan�mlama �emas� bilinmiyor.\n"

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
msgstr "\n    Dosya zaten al�nm��t�; bir�ey yap�lmad�.\n\n"

#: src/http.c:1216
#, c-format
msgid ""
"\n"
"Continued download failed on this file, which conflicts with `-c'.\n"
"Refusing to truncate existing file `%s'.\n"
"\n"
msgstr ""

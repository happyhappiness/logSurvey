msgstr "Tundmatu viga"

#. this is fatal
#: src/http.c:554
msgid "Failed to set up an SSL context\n"
msgstr "SSL konteksti m��ramine eba�nnestus\n"

#: src/http.c:560
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "Sertifikaadi laadimine failist %s eba�nnestus\n"

#: src/http.c:564 src/http.c:572
msgid "Trying without the specified certificate\n"
msgstr "Proovin n�idatud sertifikaati mitte kasutada\n"

#: src/http.c:568
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "Sertifikaadi v�tme laadimine failist %s eba�nnestus\n"

#: src/http.c:662 src/http.c:1592
msgid "Unable to establish SSL connection.\n"
msgstr "SSL �henduse loomine ei �nnestu.\n"

#: src/http.c:670
#, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Kasutan �hendust serveriga %s:%hu.\n"

#: src/http.c:860
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "HTTP p�ringu kirjutamine eba�nnestus: %s.\n"

#: src/http.c:865
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s p�ring saadetud, ootan vastust... "

#: src/http.c:909
msgid "End of file while parsing headers.\n"
msgstr "P�iste anal��sil sain faili l�pu teate.\n"

#: src/http.c:919
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "P�iste lugemise viga (%s).\n"

#: src/http.c:958
msgid "No data received"
msgstr "Andmeid ei saanudki"

#: src/http.c:960
msgid "Malformed status line"
msgstr "Katkine staatuse rida"

#: src/http.c:965
msgid "(no description)"
msgstr "(kirjeldus puudub)"

#: src/http.c:1088
msgid "Authorization failed.\n"
msgstr "Autoriseerimine eba�nnestus.\n"

#: src/http.c:1095
msgid "Unknown authentication scheme.\n"
msgstr "Tundmatu autentimis skeem.\n"

#: src/http.c:1135
#, c-format
msgid "Location: %s%s\n"
msgstr "Asukoht: %s%s\n"

#: src/http.c:1136 src/http.c:1268
msgid "unspecified"
msgstr "m��ramata"

#: src/http.c:1137
msgid " [following]"
msgstr " [j�rgnev]"

#: src/http.c:1199
msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
msgstr "\n    Fail on juba t�ielikult kohal; rohkem ei saa midagi teha.\n\n"

#: src/http.c:1215
#, c-format
msgid ""
"\n"
"The server does not support continued downloads, which conflicts with `-c'.\n"
"Refusing to truncate existing file `%s'.\n"
"\n"
msgstr ""

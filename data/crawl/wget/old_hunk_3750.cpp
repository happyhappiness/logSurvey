msgid "Unknown error"
msgstr "Tundmatu viga"

#: src/http.c:621 src/http.c:1433
msgid "Unable to establish SSL connection.\n"
msgstr ""

#: src/http.c:629
#, fuzzy, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "�ritan �henduda serveriga %s:%hu.\n"

#: src/http.c:805
#, fuzzy, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "HTTP p�ringu kirjutamine eba�nnestus.\n"

#: src/http.c:810
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s p�ring saadetud, ootan vastust... "

#: src/http.c:854
msgid "End of file while parsing headers.\n"
msgstr "P�iste anal��sil sain faili l�pu teate.\n"

#: src/http.c:865
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "P�iste lugemise viga (%s).\n"

#: src/http.c:905
msgid "No data received"
msgstr "Andmeid ei saanudki"

#: src/http.c:907
msgid "Malformed status line"
msgstr "Katkine staatuse rida"

#: src/http.c:912
msgid "(no description)"
msgstr "(kirjeldus puudub)"

#: src/http.c:1030
msgid "Authorization failed.\n"
msgstr "Autoriseerimine eba�nnestus.\n"

#: src/http.c:1037
msgid "Unknown authentication scheme.\n"
msgstr "Tundmatu autentimis skeem.\n"

#: src/http.c:1127
#, c-format
msgid "Location: %s%s\n"
msgstr "Asukoht: %s%s\n"

#: src/http.c:1128 src/http.c:1153
msgid "unspecified"
msgstr "m��ramata"

#: src/http.c:1129
msgid " [following]"
msgstr " [j�rgnev]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1143
msgid "Length: "
msgstr "Pikkus: "

#: src/http.c:1148
#, c-format
msgid " (%s to go)"
msgstr " (%s veel)"

#: src/http.c:1153
msgid "ignored"
msgstr "ignoreerin"

#: src/http.c:1254
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Hoiatus: HTTP ei toeta jokkereid.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1275
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Fail `%s' on juba olemas, ei t�mba.\n"

#: src/http.c:1425
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Ei saa kirjutada faili `%s' (%s).\n"

#: src/http.c:1443
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "VIGA: �mbersuunamine (%d) ilma asukohata.\n"

#: src/http.c:1468
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s VIGA %d: %s.\n"

#: src/http.c:1481
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Last-modified p�ist pole -- ei kasuta aja-stampe.\n"

#: src/http.c:1489
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "Last-modified p�is on vigane -- ignoreerin aja-stampi.\n"

#: src/http.c:1524
msgid "Remote file is newer, retrieving.\n"
msgstr "Kauge fail on uuem, laen alla.\n"

#: src/http.c:1559
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"

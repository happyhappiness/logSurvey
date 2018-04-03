msgid "Unknown error"
msgstr "Tundmatu viga"

#: src/http.c:625 src/http.c:1437
msgid "Unable to establish SSL connection.\n"
msgstr ""

#: src/http.c:633
#, fuzzy, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Üritan ühenduda serveriga %s:%hu.\n"

#: src/http.c:809
#, fuzzy, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "HTTP päringu kirjutamine ebaõnnestus.\n"

#: src/http.c:814
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s päring saadetud, ootan vastust... "

#: src/http.c:858
msgid "End of file while parsing headers.\n"
msgstr "Päiste analüüsil sain faili lõpu teate.\n"

#: src/http.c:869
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Päiste lugemise viga (%s).\n"

#: src/http.c:909
msgid "No data received"
msgstr "Andmeid ei saanudki"

#: src/http.c:911
msgid "Malformed status line"
msgstr "Katkine staatuse rida"

#: src/http.c:916
msgid "(no description)"
msgstr "(kirjeldus puudub)"

#: src/http.c:1034
msgid "Authorization failed.\n"
msgstr "Autoriseerimine ebaõnnestus.\n"

#: src/http.c:1041
msgid "Unknown authentication scheme.\n"
msgstr "Tundmatu autentimis skeem.\n"

#: src/http.c:1131
#, c-format
msgid "Location: %s%s\n"
msgstr "Asukoht: %s%s\n"

#: src/http.c:1132 src/http.c:1157
msgid "unspecified"
msgstr "määramata"

#: src/http.c:1133
msgid " [following]"
msgstr " [järgnev]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1147
msgid "Length: "
msgstr "Pikkus: "

#: src/http.c:1152
#, c-format
msgid " (%s to go)"
msgstr " (%s veel)"

#: src/http.c:1157
msgid "ignored"
msgstr "ignoreerin"

#: src/http.c:1258
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Hoiatus: HTTP ei toeta jokkereid.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1279
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Fail `%s' on juba olemas, ei tõmba.\n"

#: src/http.c:1429
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Ei saa kirjutada faili `%s' (%s).\n"

#: src/http.c:1447
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "VIGA: Ümbersuunamine (%d) ilma asukohata.\n"

#: src/http.c:1472
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s VIGA %d: %s.\n"

#: src/http.c:1485
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Last-modified päist pole -- ei kasuta aja-stampe.\n"

#: src/http.c:1493
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "Last-modified päis on vigane -- ignoreerin aja-stampi.\n"

#: src/http.c:1528
msgid "Remote file is newer, retrieving.\n"
msgstr "Kauge fail on uuem, laen alla.\n"

#: src/http.c:1573
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"

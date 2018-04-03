msgstr "Tundmatu viga"

#. this is fatal
#: src/http.c:555
msgid "Failed to set up an SSL context\n"
msgstr "SSL konteksti määramine ebaõnnestus\n"

#: src/http.c:561
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "Sertifikaadi laadimine failist %s ebaõnnestus\n"

#: src/http.c:565 src/http.c:573
msgid "Trying without the specified certificate\n"
msgstr "Proovin näidatud sertifikaati mitte kasutada\n"

#: src/http.c:569
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "Sertifikaadi võtme laadimine failist %s ebaõnnestus\n"

#: src/http.c:663 src/http.c:1593
msgid "Unable to establish SSL connection.\n"
msgstr "SSL ühenduse loomine ei õnnestu.\n"

#: src/http.c:671
#, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Kasutan ühendust serveriga %s:%hu.\n"

#: src/http.c:861
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "HTTP päringu kirjutamine ebaõnnestus: %s.\n"

#: src/http.c:866
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s päring saadetud, ootan vastust... "

#: src/http.c:910
msgid "End of file while parsing headers.\n"
msgstr "Päiste analüüsil sain faili lõpu teate.\n"

#: src/http.c:920
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Päiste lugemise viga (%s).\n"

#: src/http.c:959
msgid "No data received"
msgstr "Andmeid ei saanudki"

#: src/http.c:961
msgid "Malformed status line"
msgstr "Katkine staatuse rida"

#: src/http.c:966
msgid "(no description)"
msgstr "(kirjeldus puudub)"

#: src/http.c:1089
msgid "Authorization failed.\n"
msgstr "Autoriseerimine ebaõnnestus.\n"

#: src/http.c:1096
msgid "Unknown authentication scheme.\n"
msgstr "Tundmatu autentimis skeem.\n"

#: src/http.c:1136
#, c-format
msgid "Location: %s%s\n"
msgstr "Asukoht: %s%s\n"

#: src/http.c:1137 src/http.c:1269
msgid "unspecified"
msgstr "määramata"

#: src/http.c:1138
msgid " [following]"
msgstr " [järgnev]"

#: src/http.c:1200
msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
msgstr "\n    Fail on juba täielikult kohal; rohkem ei saa midagi teha.\n\n"

#: src/http.c:1216
#, c-format
msgid ""
"\n"
"Continued download failed on this file, which conflicts with `-c'.\n"
"Refusing to truncate existing file `%s'.\n"
"\n"
msgstr ""

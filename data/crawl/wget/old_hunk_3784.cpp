msgid "Unknown error"
msgstr "Nezn�ma chyba"

#: src/http.c:621 src/http.c:1433
msgid "Unable to establish SSL connection.\n"
msgstr ""

# , c-format
#: src/http.c:629
#, fuzzy, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Pok�sim sa spoji� s %s:%hu.\n"

#: src/http.c:805
#, fuzzy, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Po�iadavku HTTP nebolo mo�n� odosla�.\n"

# , c-format
#: src/http.c:810
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s po�iadavka odoslan�, �ak�m na odpove� ... "

#: src/http.c:854
msgid "End of file while parsing headers.\n"
msgstr "Hlavi�ka nie je �pln�.\n"

# , c-format
#: src/http.c:865
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Chyba (%s) pri ��tan� hlavi�iek.\n"

#: src/http.c:905
msgid "No data received"
msgstr "Nepri�li �iadne d�ta"

#: src/http.c:907
msgid "Malformed status line"
msgstr "Odpove� serveru m� skomolen� stavov� riadok"

#: src/http.c:912
msgid "(no description)"
msgstr "(�iadny popis)"

#: src/http.c:1030
msgid "Authorization failed.\n"
msgstr "Autoriz�cia zlyhala.\n"

#: src/http.c:1037
msgid "Unknown authentication scheme.\n"
msgstr "Server po�aduje nezn�my sp�sob autentifik�cie.\n"

# , c-format
#: src/http.c:1127
#, c-format
msgid "Location: %s%s\n"
msgstr "Presmerovan� na: %s%s\n"

#: src/http.c:1128 src/http.c:1153
msgid "unspecified"
msgstr "neudan�"

#: src/http.c:1129
msgid " [following]"
msgstr " [nasledujem]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1143
msgid "Length: "
msgstr "D�ka:  "

# , c-format
#: src/http.c:1148
#, c-format
msgid " (%s to go)"
msgstr " (ost�va %s)"

#: src/http.c:1153
msgid "ignored"
msgstr "je ignorovan�"

#: src/http.c:1254
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Varovanie: HTTP nepodporuje �ol�kov� znaky.\n"

# , c-format
#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1275
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "S�bor `%s' sa nebude pren�a�, je u� tu.\n"

# , c-format
#: src/http.c:1425
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Nemo�no zap�sa� do `%s' (%s).\n"

# , c-format
#: src/http.c:1443
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "CHYBA: Presmerovanie (%d) bez udanej novej adresy.\n"

# , c-format
#: src/http.c:1468
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s CHYBA %d: %s.\n"

#: src/http.c:1481
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr ""
"Nebud� sa pou��va� �asov� raz�tka (`time-stamps'), preto�e hlavi�ka\n"
"\"Last-modified\" v odpovedi serveru ch�ba.\n"

#: src/http.c:1489
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr ""
"Ignorujem �asov� raz�tko s�boru (`time-stamp'), preto�e hlavi�ka \n"
"\"Last-modified\" obsahuje neplatn� �daje.\n"

#: src/http.c:1524
msgid "Remote file is newer, retrieving.\n"
msgstr "Vzdialen� s�bor m� nov�� d�tum, pren�am.\n"

# , c-format
#: src/http.c:1559
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"

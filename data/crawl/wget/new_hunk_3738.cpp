msgid "Unknown error"
msgstr "Nezn�m� chyba"

#: src/http.c:625 src/http.c:1437
msgid "Unable to establish SSL connection.\n"
msgstr ""

# , c-format
#: src/http.c:633
#, fuzzy, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Pokus�m se spojit s %s:%hu.\n"

#: src/http.c:809
#, fuzzy, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "HTTP po�adavek nebylo mo�n� odeslat.\n"

# , c-format
#: src/http.c:814
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s po�adavek odesl�n, �ek�m na odpov�� ... "

#: src/http.c:858
msgid "End of file while parsing headers.\n"
msgstr "Hlavi�ka nen� �pln�.\n"

# , c-format
#: src/http.c:869
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Chyba (%s) p�i �ten� hlavi�ek.\n"

#: src/http.c:909
msgid "No data received"
msgstr "Nep�i�la ��dn� data"

#: src/http.c:911
msgid "Malformed status line"
msgstr "Odpov�� serveru m� zkomolen� stavov� ��dek"

#: src/http.c:916
msgid "(no description)"
msgstr "(��dn� popis)"

#: src/http.c:1034
msgid "Authorization failed.\n"
msgstr "Autorizace selhala.\n"

#: src/http.c:1041
msgid "Unknown authentication scheme.\n"
msgstr "Server po�aduje nezn�m� zp�sob autentifikace.\n"

# , c-format
#: src/http.c:1131
#, c-format
msgid "Location: %s%s\n"
msgstr "P�esm�rov�no na: %s%s\n"

#: src/http.c:1132 src/http.c:1157
msgid "unspecified"
msgstr "neud�no"

#: src/http.c:1133
msgid " [following]"
msgstr " [n�sleduji]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1147
msgid "Length: "
msgstr "D�lka: "

# , c-format
#: src/http.c:1152
#, c-format
msgid " (%s to go)"
msgstr " (%s zb�v�)"

#: src/http.c:1157
msgid "ignored"
msgstr "je ignorov�na"

#: src/http.c:1258
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Varov�n�: HTTP nepodporuje �ol�kov� znaky.\n"

# , c-format
#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1279
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Soubor `%s' nebudu p�en�et, je ji� zde.\n"

# , c-format
#: src/http.c:1429
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Nemohu zapsat do `%s' (%s).\n"

# , c-format
#: src/http.c:1447
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "CHYBA: P�esm�rov�n� (%d) bez udan� nov� adresy.\n"

# , c-format
#: src/http.c:1472
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s CHYBA %d: %s.\n"

#: src/http.c:1485
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr ""
"Nebudu pou��vat �asov� raz�tka (`time-stamps'), proto�e hlavi�ka\n"
"\"Last-modified\" v odpov�di serveru sch�z�.\n"

#: src/http.c:1493
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr ""
"Ignoruji �asov� raz�tko souboru (`time-stamp'), proto�e hlavi�ka \n"
"\"Last-modified\" obsahuje neplatn� �daje.\n"

#: src/http.c:1528
msgid "Remote file is newer, retrieving.\n"
msgstr "Vzd�len� soubor je nov�j��ho data, p�en��m.\n"

# , c-format
#: src/http.c:1573
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"

msgid "ignored"
msgstr "je ignorov�na"

#: src/http.c:858
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Varov�n�: HTTP nepodporuje �ol�kov� znaky.\n"

# , c-format
#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:873
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Soubor `%s' nebudu p�en�et, je ji� zde.\n"

# , c-format
#: src/http.c:1015
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Nemohu zapsat do `%s' (%s).\n"

# , c-format
#: src/http.c:1025
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "CHYBA: P�esm�rov�n� (%d) bez udan� nov� adresy.\n"

# , c-format
#: src/http.c:1048
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s CHYBA %d: %s.\n"

#: src/http.c:1060
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr ""
"Nebudu pou��vat �asov� raz�tka (`time-stamps'), proto�e hlavi�ka\n"
"\"Last-modified\" v odpov�di serveru sch�z�.\n"

#: src/http.c:1068
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr ""
"Ignoruji �asov� raz�tko souboru (`time-stamp'), proto�e hlavi�ka \n"
"\"Last-modified\" obsahuje neplatn� �daje.\n"

#. We can't collapse this down into just one logprintf()
#. call with a variable set to u->local or the .orig
#. filename because we have to malloc() space for the
#. latter, and because there are multiple returns above (a
#. coding style no-no by many measures, for reasons such as
#. this) we'd have to remember to free() the string at each
#. one to avoid a memory leak.
#: src/http.c:1099
#, c-format
msgid ""
"Server file no newer than local file `%s.orig' -- not retrieving.\n"
"\n"
msgstr ""

#: src/http.c:1113
msgid "Remote file is newer, retrieving.\n"
msgstr "Vzd�len� soubor je nov�j��ho data, p�en��m.\n"

# , c-format
#: src/http.c:1147
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"

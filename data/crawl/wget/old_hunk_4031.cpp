msgid "ignored"
msgstr "je ignorována"

#: src/http.c:857
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Varování: HTTP nepodporuje ¾olíkové znaky.\n"

# , c-format
#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:872
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Soubor `%s' nebudu pøená¹et, je ji¾ zde.\n"

# , c-format
#: src/http.c:978
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Nemohu zapsat do `%s' (%s).\n"

# , c-format
#: src/http.c:988
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "CHYBA: Pøesmìrování (%d) bez udané nové adresy.\n"

# , c-format
#: src/http.c:1011
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s CHYBA %d: %s.\n"

#: src/http.c:1023
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr ""
"Nebudu pou¾ívat èasová razítka (`time-stamps'), proto¾e hlavièka\n"
"\"Last-modified\" v odpovìdi serveru schází.\n"

#: src/http.c:1031
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr ""
"Ignoruji èasové razítko souboru (`time-stamp'), proto¾e hlavièka \n"
"\"Last-modified\" obsahuje neplatné údaje.\n"

#: src/http.c:1064
msgid "Remote file is newer, retrieving.\n"
msgstr "Vzdálený soubor je novìj¹ího data, pøená¹ím.\n"

# , c-format
#: src/http.c:1098
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"

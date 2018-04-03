msgid " (%s bytes)"
msgstr " (%s bajtù)"

#: src/http.c:507
msgid "Failed writing HTTP request.\n"
msgstr "HTTP po¾adavek nebylo mo¾né odeslat.\n"

# , c-format
#: src/http.c:511
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s po¾adavek odeslán, èekám na odpovìï ... "

#: src/http.c:550
msgid "End of file while parsing headers.\n"
msgstr "Hlavièka není úplná.\n"

# , c-format
#: src/http.c:561
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Chyba (%s) pøi ètení hlavièek.\n"

#: src/http.c:601
msgid "No data received"
msgstr "Nepøi¹la ¾ádná data"

#: src/http.c:603
msgid "Malformed status line"
msgstr "Odpovìï serveru má zkomolený stavový øádek"

#: src/http.c:608
msgid "(no description)"
msgstr "(¾ádný popis)"

#. If we have tried it already, then there is not point
#. retrying it.
#: src/http.c:692
msgid "Authorization failed.\n"
msgstr "Autorizace selhala.\n"

#: src/http.c:699
msgid "Unknown authentication scheme.\n"
msgstr "Server po¾aduje neznámý zpùsob autentifikace.\n"

# , c-format
#: src/http.c:762
#, c-format
msgid "Location: %s%s\n"
msgstr "Pøesmìrováno na: %s%s\n"

#: src/http.c:763 src/http.c:788
msgid "unspecified"
msgstr "neudáno"

#: src/http.c:764
msgid " [following]"
msgstr " [následuji]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:778
msgid "Length: "
msgstr "Délka: "

# , c-format
#: src/http.c:783
#, c-format
msgid " (%s to go)"
msgstr " (%s zbývá)"

#: src/http.c:788
msgid "ignored"
msgstr "je ignorována"

#: src/http.c:880
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Varování: HTTP nepodporuje ¾olíkové znaky.\n"

# , c-format
#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:895
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Soubor `%s' nebudu pøená¹et, je ji¾ zde.\n"

# , c-format
#: src/http.c:1048
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Nemohu zapsat do `%s' (%s).\n"

# , c-format
#: src/http.c:1058
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "CHYBA: Pøesmìrování (%d) bez udané nové adresy.\n"

# , c-format
#: src/http.c:1081
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s CHYBA %d: %s.\n"

#: src/http.c:1093
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr ""
"Nebudu pou¾ívat èasová razítka (`time-stamps'), proto¾e hlavièka\n"
"\"Last-modified\" v odpovìdi serveru schází.\n"

#: src/http.c:1101
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr ""
"Ignoruji èasové razítko souboru (`time-stamp'), proto¾e hlavièka \n"
"\"Last-modified\" obsahuje neplatné údaje.\n"

#. We can't collapse this down into just one logprintf()
#. call with a variable set to u->local or the .orig
#. filename because we have to malloc() space for the
#. latter, and because there are multiple returns above (a
#. coding style no-no by many measures, for reasons such as
#. this) we'd have to remember to free() the string at each
#. one to avoid a memory leak.
#: src/http.c:1132
#, c-format
msgid ""
"Server file no newer than local file `%s.orig' -- not retrieving.\n"
"\n"
msgstr ""

#: src/http.c:1146
msgid "Remote file is newer, retrieving.\n"
msgstr "Vzdálený soubor je novìj¹ího data, pøená¹ím.\n"

# , c-format
#: src/http.c:1180
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"

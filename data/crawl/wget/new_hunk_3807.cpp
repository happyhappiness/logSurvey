#. that there can be valid reasons for the local host
#. name not to be an FQDN, so I've decided to remove the
#. annoying warning.
#: src/host.c:473
#, c-format
msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
msgstr ""
"%s: Varování: reverzní vyhledání lokální adresy nenavrátilo plnì\n"
"                kvalifikované jméno!\n"

#: src/host.c:501
msgid "Host not found"
msgstr "Poèítaè nebyl nalezen"

#: src/host.c:503
msgid "Unknown error"
msgstr "Neznámá chyba"

#: src/http.c:621 src/http.c:1433
msgid "Unable to establish SSL connection.\n"
msgstr ""

# , c-format
#: src/http.c:629
#, fuzzy, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Pokusím se spojit s %s:%hu.\n"

#: src/http.c:805
#, fuzzy, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "HTTP po¾adavek nebylo mo¾né odeslat.\n"

# , c-format
#: src/http.c:810
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s po¾adavek odeslán, èekám na odpovìï ... "

#: src/http.c:854
msgid "End of file while parsing headers.\n"
msgstr "Hlavièka není úplná.\n"

# , c-format
#: src/http.c:865
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Chyba (%s) pøi ètení hlavièek.\n"

#: src/http.c:905
msgid "No data received"
msgstr "Nepøi¹la ¾ádná data"

#: src/http.c:907
msgid "Malformed status line"
msgstr "Odpovìï serveru má zkomolený stavový øádek"

#: src/http.c:912
msgid "(no description)"
msgstr "(¾ádný popis)"

#: src/http.c:1030
msgid "Authorization failed.\n"
msgstr "Autorizace selhala.\n"

#: src/http.c:1037
msgid "Unknown authentication scheme.\n"
msgstr "Server po¾aduje neznámý zpùsob autentifikace.\n"

# , c-format
#: src/http.c:1127
#, c-format
msgid "Location: %s%s\n"
msgstr "Pøesmìrováno na: %s%s\n"

#: src/http.c:1128 src/http.c:1153
msgid "unspecified"
msgstr "neudáno"

#: src/http.c:1129
msgid " [following]"
msgstr " [následuji]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1143
msgid "Length: "
msgstr "Délka: "

# , c-format
#: src/http.c:1148
#, c-format
msgid " (%s to go)"
msgstr " (%s zbývá)"

#: src/http.c:1153
msgid "ignored"
msgstr "je ignorována"

#: src/http.c:1254
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Varování: HTTP nepodporuje ¾olíkové znaky.\n"

# , c-format
#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1275
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Soubor `%s' nebudu pøená¹et, je ji¾ zde.\n"

# , c-format
#: src/http.c:1425
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Nemohu zapsat do `%s' (%s).\n"

# , c-format
#: src/http.c:1443
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "CHYBA: Pøesmìrování (%d) bez udané nové adresy.\n"

# , c-format
#: src/http.c:1468
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s CHYBA %d: %s.\n"

#: src/http.c:1481
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr ""
"Nebudu pou¾ívat èasová razítka (`time-stamps'), proto¾e hlavièka\n"
"\"Last-modified\" v odpovìdi serveru schází.\n"

#: src/http.c:1489
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr ""
"Ignoruji èasové razítko souboru (`time-stamp'), proto¾e hlavièka \n"
"\"Last-modified\" obsahuje neplatné údaje.\n"

#: src/http.c:1524
msgid "Remote file is newer, retrieving.\n"
msgstr "Vzdálený soubor je novìj¹ího data, pøená¹ím.\n"

# , c-format
#: src/http.c:1559
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"

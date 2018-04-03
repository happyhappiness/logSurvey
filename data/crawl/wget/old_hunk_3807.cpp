#. that there can be valid reasons for the local host
#. name not to be an FQDN, so I've decided to remove the
#. annoying warning.
#: src/host.c:517
#, c-format
msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
msgstr ""
"%s: Varování: reverzní vyhledání lokální adresy nenavrátilo plnì\n"
"                kvalifikované jméno!\n"

#: src/host.c:545
msgid "Host not found"
msgstr "Poèítaè nebyl nalezen"

#: src/host.c:547
msgid "Unknown error"
msgstr "Neznámá chyba"

# , c-format
#: src/html.c:615 src/html.c:617
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "Obsah /%s na %s:%d"

#: src/html.c:639
msgid "time unknown       "
msgstr "èas neznámý        "

#: src/html.c:643
msgid "File        "
msgstr "Soubor      "

#: src/html.c:646
msgid "Directory   "
msgstr "Adresáø     "

#: src/html.c:649
msgid "Link        "
msgstr "Sym. odkaz  "

#: src/html.c:652
msgid "Not sure    "
msgstr "Neznámý typ "

# , c-format
#: src/html.c:670
#, c-format
msgid " (%s bytes)"
msgstr " (%s bajtù)"

#: src/http.c:508
msgid "Failed writing HTTP request.\n"
msgstr "HTTP po¾adavek nebylo mo¾né odeslat.\n"

# , c-format
#: src/http.c:512
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s po¾adavek odeslán, èekám na odpovìï ... "

#: src/http.c:551
msgid "End of file while parsing headers.\n"
msgstr "Hlavièka není úplná.\n"

# , c-format
#: src/http.c:562
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Chyba (%s) pøi ètení hlavièek.\n"

#: src/http.c:602
msgid "No data received"
msgstr "Nepøi¹la ¾ádná data"

#: src/http.c:604
msgid "Malformed status line"
msgstr "Odpovìï serveru má zkomolený stavový øádek"

#: src/http.c:609
msgid "(no description)"
msgstr "(¾ádný popis)"

#. If we have tried it already, then there is not point
#. retrying it.
#: src/http.c:693
msgid "Authorization failed.\n"
msgstr "Autorizace selhala.\n"

#: src/http.c:700
msgid "Unknown authentication scheme.\n"
msgstr "Server po¾aduje neznámý zpùsob autentifikace.\n"

# , c-format
#: src/http.c:783
#, c-format
msgid "Location: %s%s\n"
msgstr "Pøesmìrováno na: %s%s\n"

#: src/http.c:784 src/http.c:809
msgid "unspecified"
msgstr "neudáno"

#: src/http.c:785
msgid " [following]"
msgstr " [následuji]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:799
msgid "Length: "
msgstr "Délka: "

# , c-format
#: src/http.c:804
#, c-format
msgid " (%s to go)"
msgstr " (%s zbývá)"

#: src/http.c:809
msgid "ignored"
msgstr "je ignorována"

#: src/http.c:912
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Varování: HTTP nepodporuje ¾olíkové znaky.\n"

# , c-format
#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:933
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Soubor `%s' nebudu pøená¹et, je ji¾ zde.\n"

# , c-format
#: src/http.c:1099
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Nemohu zapsat do `%s' (%s).\n"

# , c-format
#: src/http.c:1110
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "CHYBA: Pøesmìrování (%d) bez udané nové adresy.\n"

# , c-format
#: src/http.c:1135
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s CHYBA %d: %s.\n"

#: src/http.c:1148
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr ""
"Nebudu pou¾ívat èasová razítka (`time-stamps'), proto¾e hlavièka\n"
"\"Last-modified\" v odpovìdi serveru schází.\n"

#: src/http.c:1156
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr ""
"Ignoruji èasové razítko souboru (`time-stamp'), proto¾e hlavièka \n"
"\"Last-modified\" obsahuje neplatné údaje.\n"

#: src/http.c:1191
msgid "Remote file is newer, retrieving.\n"
msgstr "Vzdálený soubor je novìj¹ího data, pøená¹ím.\n"

# , c-format
#: src/http.c:1226
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"

msgid "Unknown error"
msgstr "Neznáma chyba"

#: src/http.c:621 src/http.c:1433
msgid "Unable to establish SSL connection.\n"
msgstr ""

# , c-format
#: src/http.c:629
#, fuzzy, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Pokúsim sa spoji» s %s:%hu.\n"

#: src/http.c:805
#, fuzzy, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Po¾iadavku HTTP nebolo mo¾né odosla».\n"

# , c-format
#: src/http.c:810
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s po¾iadavka odoslaná, èakám na odpoveï ... "

#: src/http.c:854
msgid "End of file while parsing headers.\n"
msgstr "Hlavièka nie je úplná.\n"

# , c-format
#: src/http.c:865
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Chyba (%s) pri èítaní hlavièiek.\n"

#: src/http.c:905
msgid "No data received"
msgstr "Nepri¹li ¾iadne dáta"

#: src/http.c:907
msgid "Malformed status line"
msgstr "Odpoveï serveru má skomolený stavový riadok"

#: src/http.c:912
msgid "(no description)"
msgstr "(¾iadny popis)"

#: src/http.c:1030
msgid "Authorization failed.\n"
msgstr "Autorizácia zlyhala.\n"

#: src/http.c:1037
msgid "Unknown authentication scheme.\n"
msgstr "Server po¾aduje neznámy spôsob autentifikácie.\n"

# , c-format
#: src/http.c:1127
#, c-format
msgid "Location: %s%s\n"
msgstr "Presmerované na: %s%s\n"

#: src/http.c:1128 src/http.c:1153
msgid "unspecified"
msgstr "neudané"

#: src/http.c:1129
msgid " [following]"
msgstr " [nasledujem]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1143
msgid "Length: "
msgstr "Då¾ka:  "

# , c-format
#: src/http.c:1148
#, c-format
msgid " (%s to go)"
msgstr " (ostáva %s)"

#: src/http.c:1153
msgid "ignored"
msgstr "je ignorovaná"

#: src/http.c:1254
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Varovanie: HTTP nepodporuje ¾olíkové znaky.\n"

# , c-format
#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1275
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Súbor `%s' sa nebude prená¹a», je u¾ tu.\n"

# , c-format
#: src/http.c:1425
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Nemo¾no zapísa» do `%s' (%s).\n"

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
"Nebudú sa pou¾íva» èasové razítka (`time-stamps'), preto¾e hlavièka\n"
"\"Last-modified\" v odpovedi serveru chýba.\n"

#: src/http.c:1489
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr ""
"Ignorujem èasové razítko súboru (`time-stamp'), preto¾e hlavièka \n"
"\"Last-modified\" obsahuje neplatné údaje.\n"

#: src/http.c:1524
msgid "Remote file is newer, retrieving.\n"
msgstr "Vzdialený súbor má nov¹í dátum, prená¹am.\n"

# , c-format
#: src/http.c:1559
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"

msgid "%s: option requires an argument -- %c\n"
msgstr "%s: prepínaè vy¾aduje argument -- %c\n"

#: src/host.c:374
msgid "Host not found"
msgstr "Hostiteµ nebol nájdený"

#: src/host.c:376
msgid "Unknown error"
msgstr "Neznáma chyba"

#. this is fatal
#: src/http.c:555
msgid "Failed to set up an SSL context\n"
msgstr "Nepodarilo sa nastavi» SSL kontext.\n"

#: src/http.c:561
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "Nepodarilo sa naèíta» certifikáty z %s\n"

#: src/http.c:565 src/http.c:573
msgid "Trying without the specified certificate\n"
msgstr "Skú¹am bez zadaného certifikátu\n"

#: src/http.c:569
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "Nepodarilo sa naèíta» kµúè certifikátu z %s\n"

#: src/http.c:663 src/http.c:1593
msgid "Unable to establish SSL connection.\n"
msgstr "Nepodarilo sa nadviaza» SSL spojenie\n"

# , c-format
#: src/http.c:671
#, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Pou¾ívam existujúce spojenie s %s:%hu.\n"

#: src/http.c:861
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Po¾iadavku HTTP nebolo mo¾né odosla»: %s.\n"

# , c-format
#: src/http.c:866
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s po¾iadavka odoslaná, èakám na odpoveï ... "

#: src/http.c:910
msgid "End of file while parsing headers.\n"
msgstr "Hlavièka nie je úplná.\n"

# , c-format
#: src/http.c:920
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Chyba (%s) pri èítaní hlavièiek.\n"

#: src/http.c:959
msgid "No data received"
msgstr "Nepri¹li ¾iadne dáta"

#: src/http.c:961
msgid "Malformed status line"
msgstr "Odpoveï serveru má skomolený stavový riadok"

#: src/http.c:966
msgid "(no description)"
msgstr "(¾iadny popis)"

#: src/http.c:1089
msgid "Authorization failed.\n"
msgstr "Autorizácia zlyhala.\n"

#: src/http.c:1096
msgid "Unknown authentication scheme.\n"
msgstr "Server po¾aduje neznámy spôsob autentifikácie.\n"

# , c-format
#: src/http.c:1136
#, c-format
msgid "Location: %s%s\n"
msgstr "Presmerované na: %s%s\n"

#: src/http.c:1137 src/http.c:1269
msgid "unspecified"
msgstr "neudané"

#: src/http.c:1138
msgid " [following]"
msgstr " [nasledujem]"

#: src/http.c:1200
msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
msgstr "\n    Tento súbor je u¾ kompletne prenesený; netreba niè robi».\n\n"

#: src/http.c:1216
#, c-format
msgid ""
"\n"
"Continued download failed on this file, which conflicts with `-c'.\n"
"Refusing to truncate existing file `%s'.\n"
"\n"
msgstr ""
"\n"
"Pokraèovanie prenosu tohoto súboru zlyhalo, èo koliduje s `-c'.\n"
"Existujúci súbor `%s' nebude skrátený.\n"
"\n"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1259
msgid "Length: "
msgstr "Då¾ka:  "

# , c-format
#: src/http.c:1264
#, c-format
msgid " (%s to go)"
msgstr " (ostáva %s)"

#: src/http.c:1269
msgid "ignored"
msgstr "je ignorovaná"

#: src/http.c:1399
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Varovanie: HTTP nepodporuje ¾olíkové znaky.\n"

# , c-format
#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1417
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Súbor `%s' sa nebude prená¹a», je u¾ tu.\n"

# , c-format
#: src/http.c:1585
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Nemo¾no zapísa» do `%s' (%s).\n"

# , c-format
#: src/http.c:1602
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "CHYBA: Presmerovanie (%d) bez udanej novej adresy.\n"

# , c-format
#: src/http.c:1630
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s CHYBA %d: %s.\n"

#: src/http.c:1642
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr ""
"Nebudú sa pou¾íva» èasové razítka (`time-stamps'), preto¾e hlavièka\n"
"\"Last-modified\" v odpovedi serveru chýba.\n"

#: src/http.c:1650
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr ""
"Ignorujem èasové razítko súboru (`time-stamp'), preto¾e hlavièka \n"
"\"Last-modified\" obsahuje neplatné údaje.\n"

#: src/http.c:1673
#, c-format
msgid "Server file no newer than local file `%s' -- not retrieving.\n\n"
msgstr "Súbor na serveri nie je nov¹í ako lokálny súbor `%s' -- neprená¹am.\n\n"

# , c-format
#: src/http.c:1680
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n"
msgstr "Veµkosti se nezhodujú (lokálne %ld) -- prená¹am.\n"

#: src/http.c:1684
msgid "Remote file is newer, retrieving.\n"
msgstr "Vzdialený súbor má nov¹í dátum, prená¹am.\n"

# , c-format
#: src/http.c:1728
#, c-format
msgid "%s (%s) - `%s' saved [%ld/%ld]\n\n"
msgstr "%s (%s) - `%s' ulo¾ený [%ld/%ld]\n\n"

# , c-format
#: src/http.c:1774
#, c-format
msgid "%s (%s) - Connection closed at byte %ld. "
msgstr "%s (%s) - Spojenie uzatvorené na byte %ld. "

# , c-format
#: src/http.c:1782
#, c-format
msgid "%s (%s) - `%s' saved [%ld/%ld])\n\n"
msgstr "%s (%s) - `%s' ulo¾ené [%ld/%ld])\n\n"

# , c-format
#: src/http.c:1801
#, c-format
msgid "%s (%s) - Connection closed at byte %ld/%ld. "
msgstr "%s (%s) - Spojenie uzatvorené na byte %ld/%ld. "

# , c-format
#: src/http.c:1812
#, c-format
msgid "%s (%s) - Read error at byte %ld (%s)."
msgstr "%s (%s) - Chyba pri èítaní dát na byte %ld (%s)."

# , c-format
#: src/http.c:1820
#, c-format
msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
msgstr "%s (%s) - Chyba pri èítaní dát na byte %ld/%ld (%s). "

# , c-format
#: src/init.c:349 src/netrc.c:267
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: Nemo¾no preèíta» %s (%s).\n"

# , c-format
#: src/init.c:367 src/init.c:373
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: Chyba v %s na riadku %d.\n"

# , c-format
#: src/init.c:405
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr "%s: Varovanie: Globálne aj u¾ívateµské wgetrc sú zhodne ulo¾ené v `%s'.\n"

# , c-format
#: src/init.c:497
#, c-format
msgid "%s: BUG: unknown command `%s', value `%s'.\n"
msgstr "%s: Chyba: Neznámy príkaz `%s', hodnota `%s'.\n"

#: src/init.c:529
#, c-format
msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
msgstr "%s: %s: Nie je mo¾né konvertova» `%s' na IP adresu.\n"

# , c-format
#: src/init.c:559
#, c-format
msgid "%s: %s: Please specify on or off.\n"
msgstr "%s: %s: Zadajte prosím on alebo off.\n"

# , c-format
#: src/init.c:603
#, c-format
msgid "%s: %s: Please specify always, on, off, or never.\n"
msgstr "%s: %s: Zadajte prosím v¾dy on, off alebo never.\n"

# , c-format
#: src/init.c:622 src/init.c:919 src/init.c:941 src/init.c:1005
#, c-format
msgid "%s: %s: Invalid specification `%s'.\n"
msgstr "%s: %s: Neplatná ¹pecifikácia `%s'\n"

# , c-format
#: src/init.c:775 src/init.c:797 src/init.c:819 src/init.c:845
#, c-format
msgid "%s: Invalid specification `%s'\n"
msgstr "%s: Neplatná ¹pecifikácia `%s'\n"

msgid "%s: option requires an argument -- %c\n"
msgstr "%s: prep�na� vy�aduje argument -- %c\n"

#: src/host.c:394
#, c-format
msgid "%s: Cannot determine user-id.\n"
msgstr "%s: Nemo�no identifikova� u��vate�a.\n"

# , c-format
#: src/host.c:406
#, c-format
msgid "%s: Warning: uname failed: %s\n"
msgstr "%s: Varovanie: volanie \"uname\" skon�ilo s chybou %s\n"

#: src/host.c:418
#, c-format
msgid "%s: Warning: gethostname failed\n"
msgstr "%s: Varovanie: volanie \"gethostname\" skon�ilo s chybou\n"

#: src/host.c:446
#, c-format
msgid "%s: Warning: cannot determine local IP address.\n"
msgstr "%s: Varovanie: nemo�no ur�i� lok�lnu IP adresu.\n"

#: src/host.c:460
#, c-format
msgid "%s: Warning: cannot reverse-lookup local IP address.\n"
msgstr "%s: Varovanie: lok�lna IP adresa nem� reverzn� z�znam v DNS.\n"

#. This gets ticked pretty often.  Karl Berry reports
#. that there can be valid reasons for the local host
#. name not to be an FQDN, so I've decided to remove the
#. annoying warning.
#: src/host.c:473
#, c-format
msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
msgstr ""
"%s: Varovanie: reverzn� vyh�adanie lok�lnej adresy nevr�tilo pln�\n"
"                kvalifikovan� meno!\n"

#: src/host.c:501
msgid "Host not found"
msgstr "Hostite� nebol n�jden�"

#: src/host.c:503
msgid "Unknown error"
msgstr "Nezn�ma chyba"

#. this is fatal
#: src/http.c:549
msgid "Failed to set up an SSL context\n"
msgstr ""

#: src/http.c:555
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr ""

#: src/http.c:559 src/http.c:567
msgid "Trying without the specified certificate\n"
msgstr ""

#: src/http.c:563
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr ""

#: src/http.c:657 src/http.c:1470
msgid "Unable to establish SSL connection.\n"
msgstr ""

# , c-format
#: src/http.c:665
#, fuzzy, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Pok�sim sa spoji� s %s:%hu.\n"

#: src/http.c:841
#, fuzzy, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Po�iadavku HTTP nebolo mo�n� odosla�.\n"

# , c-format
#: src/http.c:846
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s po�iadavka odoslan�, �ak�m na odpove� ... "

#: src/http.c:890
msgid "End of file while parsing headers.\n"
msgstr "Hlavi�ka nie je �pln�.\n"

# , c-format
#: src/http.c:901
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Chyba (%s) pri ��tan� hlavi�iek.\n"

#: src/http.c:941
msgid "No data received"
msgstr "Nepri�li �iadne d�ta"

#: src/http.c:943
msgid "Malformed status line"
msgstr "Odpove� serveru m� skomolen� stavov� riadok"

#: src/http.c:948
msgid "(no description)"
msgstr "(�iadny popis)"

#: src/http.c:1066
msgid "Authorization failed.\n"
msgstr "Autoriz�cia zlyhala.\n"

#: src/http.c:1073
msgid "Unknown authentication scheme.\n"
msgstr "Server po�aduje nezn�my sp�sob autentifik�cie.\n"

# , c-format
#: src/http.c:1163
#, c-format
msgid "Location: %s%s\n"
msgstr "Presmerovan� na: %s%s\n"

#: src/http.c:1164 src/http.c:1189
msgid "unspecified"
msgstr "neudan�"

#: src/http.c:1165
msgid " [following]"
msgstr " [nasledujem]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1179
msgid "Length: "
msgstr "D�ka:  "

# , c-format
#: src/http.c:1184
#, c-format
msgid " (%s to go)"
msgstr " (ost�va %s)"

#: src/http.c:1189
msgid "ignored"
msgstr "je ignorovan�"

#: src/http.c:1290
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Varovanie: HTTP nepodporuje �ol�kov� znaky.\n"

# , c-format
#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1311
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "S�bor `%s' sa nebude pren�a�, je u� tu.\n"

# , c-format
#: src/http.c:1462
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Nemo�no zap�sa� do `%s' (%s).\n"

# , c-format
#: src/http.c:1480
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "CHYBA: Presmerovanie (%d) bez udanej novej adresy.\n"

# , c-format
#: src/http.c:1505
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s CHYBA %d: %s.\n"

#: src/http.c:1518
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr ""
"Nebud� sa pou��va� �asov� raz�tka (`time-stamps'), preto�e hlavi�ka\n"
"\"Last-modified\" v odpovedi serveru ch�ba.\n"

#: src/http.c:1526
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr ""
"Ignorujem �asov� raz�tko s�boru (`time-stamp'), preto�e hlavi�ka \n"
"\"Last-modified\" obsahuje neplatn� �daje.\n"

#: src/http.c:1549
#, c-format
msgid ""
"Server file no newer than local file `%s' -- not retrieving.\n"
"\n"
msgstr ""

# , c-format
#: src/http.c:1557
#, fuzzy, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n"
msgstr "Ve�kosti se nezhoduj� (lok�lne %ld), pren�am.\n"

#: src/http.c:1561
msgid "Remote file is newer, retrieving.\n"
msgstr "Vzdialen� s�bor m� nov�� d�tum, pren�am.\n"

# , c-format
#: src/http.c:1606
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
"\n"
msgstr ""
"%s (%s) - `%s' ulo�en� [%ld/%ld]\n"
"\n"

# , c-format
#: src/http.c:1654
#, c-format
msgid "%s (%s) - Connection closed at byte %ld. "
msgstr "%s (%s) - Spojenie uzatvoren� na byte %ld. "

# , c-format
#: src/http.c:1662
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld])\n"
"\n"
msgstr ""
"%s (%s) - `%s' ulo�en� [%ld/%ld])\n"
"\n"

# , c-format
#: src/http.c:1682
#, c-format
msgid "%s (%s) - Connection closed at byte %ld/%ld. "
msgstr "%s (%s) - Spojenie uzatvoren� na byte %ld/%ld. "

# , c-format
#: src/http.c:1693
#, c-format
msgid "%s (%s) - Read error at byte %ld (%s)."
msgstr "%s (%s) - Chyba pri ��tan� d�t na byte %ld (%s)."

# , c-format
#: src/http.c:1701
#, c-format
msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
msgstr "%s (%s) - Chyba pri ��tan� d�t na byte %ld/%ld (%s). "

# , c-format
#: src/init.c:336 src/netrc.c:261
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: Nemo�no pre��ta� %s (%s).\n"

# , c-format
#: src/init.c:354 src/init.c:360
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: Chyba v %s na riadku %d.\n"

# , c-format
#: src/init.c:391
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr ""
"%s: Varovanie: Glob�lne aj u��vate�sk� wgetrc s� zhodne ulo�en� v `%s'.\n"

# , c-format
#: src/init.c:483
#, c-format
msgid "%s: BUG: unknown command `%s', value `%s'.\n"
msgstr "%s: Chyba: Nezn�my pr�kaz `%s', hodnota `%s'.\n"

#: src/init.c:504
#, fuzzy, c-format
msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
msgstr "%s: Varovanie: lok�lna IP adresa nem� reverzn� z�znam v DNS.\n"

# , c-format
#: src/init.c:532
#, c-format
msgid "%s: %s: Please specify on or off.\n"
msgstr "%s: %s: Zadajte pros�m `on' alebo `off'.\n"

# , c-format
#: src/init.c:576
#, fuzzy, c-format
msgid "%s: %s: Please specify always, on, off, or never.\n"
msgstr "%s: %s: Zadajte pros�m `on' alebo `off'.\n"

# , c-format
#: src/init.c:595 src/init.c:852 src/init.c:874 src/init.c:938
#, c-format
msgid "%s: %s: Invalid specification `%s'.\n"
msgstr "%s: %s: Neplatn� �pecifik�cia `%s'\n"

# , c-format
#: src/init.c:708 src/init.c:730 src/init.c:752 src/init.c:778
#, c-format
msgid "%s: Invalid specification `%s'\n"
msgstr "%s: Neplatn� �pecifik�cia `%s'\n"

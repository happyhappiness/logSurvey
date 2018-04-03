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
"\n"
msgstr ""
"%s (%s) - `%s' ulo�en� [%ld/%ld]\n"
"\n"

# , c-format
#: src/http.c:1607
#, c-format
msgid "%s (%s) - Connection closed at byte %ld. "
msgstr "%s (%s) - Spojenie uzatvoren� na byte %ld. "

# , c-format
#: src/http.c:1615
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld])\n"
"\n"
msgstr ""
"%s (%s) - `%s' ulo�en� [%ld/%ld])\n"
"\n"

# , c-format
#: src/http.c:1635
#, c-format
msgid "%s (%s) - Connection closed at byte %ld/%ld. "
msgstr "%s (%s) - Spojenie uzatvoren� na byte %ld/%ld. "

# , c-format
#: src/http.c:1646
#, c-format
msgid "%s (%s) - Read error at byte %ld (%s)."
msgstr "%s (%s) - Chyba pri ��tan� d�t na byte %ld (%s)."

# , c-format
#: src/http.c:1654
#, c-format
msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
msgstr "%s (%s) - Chyba pri ��tan� d�t na byte %ld/%ld (%s). "

# , c-format
#: src/init.c:332 src/netrc.c:261
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: Nemo�no pre��ta� %s (%s).\n"

# , c-format
#: src/init.c:350 src/init.c:356
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: Chyba v %s na riadku %d.\n"

# , c-format
#: src/init.c:387
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr ""
"%s: Varovanie: Glob�lne aj u��vate�sk� wgetrc s� zhodne ulo�en� v `%s'.\n"

# , c-format
#: src/init.c:479
#, c-format
msgid "%s: BUG: unknown command `%s', value `%s'.\n"
msgstr "%s: Chyba: Nezn�my pr�kaz `%s', hodnota `%s'.\n"

# , c-format
#: src/init.c:501
#, fuzzy, c-format
msgid "%s: Out of memory.\n"
msgstr "%s: %s: Nie je dos� pam�te.\n"

#: src/init.c:507
#, fuzzy, c-format
msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
msgstr "%s: Varovanie: lok�lna IP adresa nem� reverzn� z�znam v DNS.\n"

# , c-format
#: src/init.c:535
#, c-format
msgid "%s: %s: Please specify on or off.\n"
msgstr "%s: %s: Zadajte pros�m `on' alebo `off'.\n"

# , c-format
#: src/init.c:579
#, fuzzy, c-format
msgid "%s: %s: Please specify always, on, off, or never.\n"
msgstr "%s: %s: Zadajte pros�m `on' alebo `off'.\n"

# , c-format
#: src/init.c:598 src/init.c:855 src/init.c:877 src/init.c:941
#, c-format
msgid "%s: %s: Invalid specification `%s'.\n"
msgstr "%s: %s: Neplatn� �pecifik�cia `%s'\n"

# , c-format
#: src/init.c:711 src/init.c:733 src/init.c:755 src/init.c:781
#, c-format
msgid "%s: Invalid specification `%s'\n"
msgstr "%s: Neplatn� �pecifik�cia `%s'\n"

# , c-format
#: src/main.c:119
#, c-format
msgid "Usage: %s [OPTION]... [URL]...\n"
msgstr "Pou�itie: %s [PREP�NA�]... [URL]...\n"

# , c-format
#: src/main.c:127
#, c-format
msgid "GNU Wget %s, a non-interactive network retriever.\n"
msgstr "GNU Wget %s, program pre neinterakt�vne s�ahovanie s�borov.\n"

#. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
#. don't bitch.  Also, it makes translation much easier.
#: src/main.c:132
msgid ""
"\n"
"Mandatory arguments to long options are mandatory for short options too.\n"
"\n"
msgstr ""
"\n"
"Argumenty, povinn� pri dlh�ch prep�na�och, s� povinn� aj pre kr�tke verzie\n"
"prep�na�ov.\n"
"\n"

#: src/main.c:135
#, fuzzy
msgid ""
"Startup:\n"
"  -V,  --version           display the version of Wget and exit.\n"
"  -h,  --help              print this help.\n"
"  -b,  --background        go to background after startup.\n"
"  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
"\n"
msgstr ""
"Za��tek:\n"
"  -V,  --version           vyp�e inform�ciu o verzii programu Wget a "
"skon��\n"
"  -h,  --help              vyp�e t�to n�povedu a skon��\n"
"  -b,  --background        po spusten� pokra�uje v behu na pozad�\n"
"  -e,  --execute=PR�KAZ    vykonaj pr�kaz `.wgetrc'\n"
"\n"

# , fuzzy
#: src/main.c:141
#, fuzzy
msgid ""
"Logging and input file:\n"
"  -o,  --output-file=FILE     log messages to FILE.\n"

msgid "%s: option requires an argument -- %c\n"
msgstr "%s: flaggan beh�ver ett argument -- %c\n"

#: src/host.c:394
#, c-format
msgid "%s: Cannot determine user-id.\n"
msgstr "%s: Kan inte avg�ra anv�ndar-id.\n"

#: src/host.c:406
#, c-format
msgid "%s: Warning: uname failed: %s\n"
msgstr "%s: Varning: uname misslyckades: %s\n"

#: src/host.c:418
#, c-format
msgid "%s: Warning: gethostname failed\n"
msgstr "%s: Varning: gethostname misslyckades\n"

#: src/host.c:446
#, c-format
msgid "%s: Warning: cannot determine local IP address.\n"
msgstr "%s: Varning: kan inte avg�ra lokal IP-adress.\n"

#: src/host.c:460
#, c-format
msgid "%s: Warning: cannot reverse-lookup local IP address.\n"
msgstr "%s: Varning: kan inte utf�ra omv�nd uppslagning av lokal IP-adress.\n"

#. This gets ticked pretty often.  Karl Berry reports
#. that there can be valid reasons for the local host
#. name not to be an FQDN, so I've decided to remove the
#. annoying warning.
#: src/host.c:473
#, c-format
msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
msgstr ""
"%s: Varning: omv�nd uppslagning av den lokala adressen gav inget\n"
"fullst�ndigt dom�nnamn!\n"

#: src/host.c:501
msgid "Host not found"
msgstr "Servern kunde inte hittas"

#: src/host.c:503
msgid "Unknown error"
msgstr "Ok�nt fel"

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

#: src/http.c:665
#, fuzzy, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "F�rs�ker ansluta till %s:%hu.\n"

#: src/http.c:841
#, fuzzy, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Misslyckades med att skriva HTTP-beg�ran.\n"

#: src/http.c:846
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s beg�ran skickad, v�ntar p� svar... "

#: src/http.c:890
msgid "End of file while parsing headers.\n"
msgstr "Filslut vid genoms�kning av huvuden.\n"

#: src/http.c:901
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "L�sfel (%s) i huvuden.\n"

#: src/http.c:941
msgid "No data received"
msgstr "Ingen data mottagen"

#: src/http.c:943
msgid "Malformed status line"
msgstr "Missbildad statusrad"

#: src/http.c:948
msgid "(no description)"
msgstr "(ingen beskrivning)"

#: src/http.c:1066
msgid "Authorization failed.\n"
msgstr "Auktorisering misslyckades.\n"

#: src/http.c:1073
msgid "Unknown authentication scheme.\n"
msgstr "Ok�nd auktoriseringsmetod.\n"

#: src/http.c:1163
#, c-format
msgid "Location: %s%s\n"
msgstr "Adress: %s%s\n"

#: src/http.c:1164 src/http.c:1189
msgid "unspecified"
msgstr "ospecificerat"

#: src/http.c:1165
msgid " [following]"
msgstr " [f�ljande]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1179
msgid "Length: "
msgstr "L�ngd: "

#: src/http.c:1184
#, c-format
msgid " (%s to go)"
msgstr " (%s kvar)"

#: src/http.c:1189
msgid "ignored"
msgstr "ignorerad"

#: src/http.c:1290
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Varning: jokertecken underst�ds inte i HTTP.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1311
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Filen \"%s\" finns redan d�r, h�mtar inte.\n"

#: src/http.c:1462
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Kan inte skriva till \"%s\" (%s).\n"

#: src/http.c:1480
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "FEL: Omdirigering (%d) utan adress.\n"

#: src/http.c:1505
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s FEL %d: %s.\n"

#: src/http.c:1518
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "\"Last-modified\"-huvud saknas -- tidsst�mplar avst�ngda.\n"

#: src/http.c:1526
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "\"Last-modified\"-huvudet ogiltigt -- tidsst�mpel ignorerad.\n"

#: src/http.c:1549
#, c-format
msgid ""
"Server file no newer than local file `%s' -- not retrieving.\n"
"\n"
msgstr ""

#: src/http.c:1557
#, fuzzy, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n"
msgstr "Storlekarna st�mmer inte �verens (lokal %ld), h�mtar.\n"

#: src/http.c:1561
msgid "Remote file is newer, retrieving.\n"
msgstr "Filen p� fj�rrsystemet �r nyare, h�mtar.\n"

#: src/http.c:1606
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
"\n"
msgstr ""
"%s (%s) - \"%s\" sparad [%ld/%ld]\n"
"\n"

#: src/http.c:1654
#, c-format
msgid "%s (%s) - Connection closed at byte %ld. "
msgstr "%s (%s) - F�rbindelse st�ngd vid byte %ld. "

#: src/http.c:1662
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld])\n"
"\n"
msgstr ""
"%s (%s) - \"%s\" sparad [%ld/%ld])\n"
"\n"

#: src/http.c:1682
#, c-format
msgid "%s (%s) - Connection closed at byte %ld/%ld. "
msgstr "%s (%s) - F�rbindelse st�ngd vid byte %ld/%ld. "

#: src/http.c:1693
#, c-format
msgid "%s (%s) - Read error at byte %ld (%s)."
msgstr "%s (%s) - L�sfel vid byte %ld (%s)."

#: src/http.c:1701
#, c-format
msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
msgstr "%s (%s) - L�sfel vid byte %ld/%ld (%s). "

#: src/init.c:336 src/netrc.c:261
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: Kan inte l�sa %s (%s).\n"

#: src/init.c:354 src/init.c:360
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: Fel i %s vid rad %d.\n"

#: src/init.c:391
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr ""
"%s: Varning: B�de systemets och anv�ndarens wgetrc pekar till \"%s\".\n"

#: src/init.c:483
#, c-format
msgid "%s: BUG: unknown command `%s', value `%s'.\n"
msgstr "%s: BUGG: ok�nt kommando \"%s\", v�rde \"%s\".\n"

#: src/init.c:504
#, fuzzy, c-format
msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
msgstr "%s: Varning: kan inte utf�ra omv�nd uppslagning av lokal IP-adress.\n"

#: src/init.c:532
#, c-format
msgid "%s: %s: Please specify on or off.\n"
msgstr "%s: %s: V�nligen ange \"on\" eller \"off\".\n"

#: src/init.c:576
#, fuzzy, c-format
msgid "%s: %s: Please specify always, on, off, or never.\n"
msgstr "%s: %s: V�nligen ange \"on\" eller \"off\".\n"

#: src/init.c:595 src/init.c:852 src/init.c:874 src/init.c:938
#, c-format
msgid "%s: %s: Invalid specification `%s'.\n"
msgstr "%s: %s: Ogiltig specifikation \"%s\".\n"

#: src/init.c:708 src/init.c:730 src/init.c:752 src/init.c:778
#, c-format
msgid "%s: Invalid specification `%s'\n"
msgstr "%s: Ogiltig specifikation \"%s\"\n"

#: src/main.c:120
#, c-format
msgid "Usage: %s [OPTION]... [URL]...\n"
msgstr "Anv�ndning: %s [FLAGGA]... [URL]...\n"

#: src/main.c:128
#, c-format
msgid "GNU Wget %s, a non-interactive network retriever.\n"
msgstr "GNU Wget %s, en icke-interaktiv n�tverksh�mtare.\n"

#. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
#. don't bitch.  Also, it makes translation much easier.
#: src/main.c:133
msgid ""
"\n"
"Mandatory arguments to long options are mandatory for short options too.\n"
"\n"
msgstr ""
"\n"
"Obligatoriska argument till l�nga flaggor �r obligatoriska �ven f�r de "
"korta.\n"
"\n"

#: src/main.c:136
#, fuzzy
msgid ""
"Startup:\n"
"  -V,  --version           display the version of Wget and exit.\n"

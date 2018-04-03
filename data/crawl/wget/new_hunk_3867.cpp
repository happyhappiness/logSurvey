#. that there can be valid reasons for the local host
#. name not to be an FQDN, so I've decided to remove the
#. annoying warning.
#: src/host.c:473
#, c-format
msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
msgstr ""
"%s: Varning: omvänd uppslagning av den lokala adressen gav inget\n"
"fullständigt domännamn!\n"

#: src/host.c:501
msgid "Host not found"
msgstr "Servern kunde inte hittas"

#: src/host.c:503
msgid "Unknown error"
msgstr "Okänt fel"

#: src/http.c:621 src/http.c:1433
msgid "Unable to establish SSL connection.\n"
msgstr ""

#: src/http.c:629
#, fuzzy, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Försöker ansluta till %s:%hu.\n"

#: src/http.c:805
#, fuzzy, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Misslyckades med att skriva HTTP-begäran.\n"

#: src/http.c:810
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s begäran skickad, väntar på svar... "

#: src/http.c:854
msgid "End of file while parsing headers.\n"
msgstr "Filslut vid genomsökning av huvuden.\n"

#: src/http.c:865
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Läsfel (%s) i huvuden.\n"

#: src/http.c:905
msgid "No data received"
msgstr "Ingen data mottagen"

#: src/http.c:907
msgid "Malformed status line"
msgstr "Missbildad statusrad"

#: src/http.c:912
msgid "(no description)"
msgstr "(ingen beskrivning)"

#: src/http.c:1030
msgid "Authorization failed.\n"
msgstr "Auktorisering misslyckades.\n"

#: src/http.c:1037
msgid "Unknown authentication scheme.\n"
msgstr "Okänd auktoriseringsmetod.\n"

#: src/http.c:1127
#, c-format
msgid "Location: %s%s\n"
msgstr "Adress: %s%s\n"

#: src/http.c:1128 src/http.c:1153
msgid "unspecified"
msgstr "ospecificerat"

#: src/http.c:1129
msgid " [following]"
msgstr " [följande]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1143
msgid "Length: "
msgstr "Längd: "

#: src/http.c:1148
#, c-format
msgid " (%s to go)"
msgstr " (%s kvar)"

#: src/http.c:1153
msgid "ignored"
msgstr "ignorerad"

#: src/http.c:1254
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Varning: jokertecken understöds inte i HTTP.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1275
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Filen \"%s\" finns redan där, hämtar inte.\n"

#: src/http.c:1425
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Kan inte skriva till \"%s\" (%s).\n"

#: src/http.c:1443
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "FEL: Omdirigering (%d) utan adress.\n"

#: src/http.c:1468
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s FEL %d: %s.\n"

#: src/http.c:1481
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "\"Last-modified\"-huvud saknas -- tidsstämplar avstängda.\n"

#: src/http.c:1489
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "\"Last-modified\"-huvudet ogiltigt -- tidsstämpel ignorerad.\n"

#: src/http.c:1524
msgid "Remote file is newer, retrieving.\n"
msgstr "Filen på fjärrsystemet är nyare, hämtar.\n"

#: src/http.c:1559
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
"\n"
msgstr ""
"%s (%s) - \"%s\" sparad [%ld/%ld]\n"
"\n"

#: src/http.c:1607
#, c-format
msgid "%s (%s) - Connection closed at byte %ld. "
msgstr "%s (%s) - Förbindelse stängd vid byte %ld. "

#: src/http.c:1615
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld])\n"
"\n"
msgstr ""
"%s (%s) - \"%s\" sparad [%ld/%ld])\n"
"\n"

#: src/http.c:1635
#, c-format
msgid "%s (%s) - Connection closed at byte %ld/%ld. "
msgstr "%s (%s) - Förbindelse stängd vid byte %ld/%ld. "

#: src/http.c:1646
#, c-format
msgid "%s (%s) - Read error at byte %ld (%s)."
msgstr "%s (%s) - Läsfel vid byte %ld (%s)."

#: src/http.c:1654
#, c-format
msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
msgstr "%s (%s) - Läsfel vid byte %ld/%ld (%s). "

#: src/init.c:332 src/netrc.c:261
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: Kan inte läsa %s (%s).\n"

#: src/init.c:350 src/init.c:356
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: Fel i %s vid rad %d.\n"

#: src/init.c:387
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr ""
"%s: Varning: Både systemets och användarens wgetrc pekar till \"%s\".\n"

#: src/init.c:479
#, c-format
msgid "%s: BUG: unknown command `%s', value `%s'.\n"
msgstr "%s: BUGG: okänt kommando \"%s\", värde \"%s\".\n"

#: src/init.c:501
#, fuzzy, c-format
msgid "%s: Out of memory.\n"
msgstr "%s: %s: Ej tillräckligt med minne.\n"

#: src/init.c:507
#, fuzzy, c-format
msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
msgstr "%s: Varning: kan inte utföra omvänd uppslagning av lokal IP-adress.\n"

#: src/init.c:535
#, c-format
msgid "%s: %s: Please specify on or off.\n"
msgstr "%s: %s: Vänligen ange \"on\" eller \"off\".\n"

#: src/init.c:579
#, fuzzy, c-format
msgid "%s: %s: Please specify always, on, off, or never.\n"
msgstr "%s: %s: Vänligen ange \"on\" eller \"off\".\n"

#: src/init.c:598 src/init.c:855 src/init.c:877 src/init.c:941
#, c-format
msgid "%s: %s: Invalid specification `%s'.\n"
msgstr "%s: %s: Ogiltig specifikation \"%s\".\n"

#: src/init.c:711 src/init.c:733 src/init.c:755 src/init.c:781
#, c-format
msgid "%s: Invalid specification `%s'\n"
msgstr "%s: Ogiltig specifikation \"%s\"\n"

#: src/main.c:119
#, c-format
msgid "Usage: %s [OPTION]... [URL]...\n"
msgstr "Användning: %s [FLAGGA]... [URL]...\n"

#: src/main.c:127
#, c-format
msgid "GNU Wget %s, a non-interactive network retriever.\n"
msgstr "GNU Wget %s, en icke-interaktiv nätverkshämtare.\n"

#. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
#. don't bitch.  Also, it makes translation much easier.
#: src/main.c:132
msgid ""
"\n"
"Mandatory arguments to long options are mandatory for short options too.\n"
"\n"
msgstr ""
"\n"
"Obligatoriska argument till långa flaggor är obligatoriska även för de "
"korta.\n"
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
"Uppstart:\n"

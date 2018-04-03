#. that there can be valid reasons for the local host
#. name not to be an FQDN, so I've decided to remove the
#. annoying warning.
#: src/host.c:511
#, c-format
msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
msgstr ""
"%s: Varning: omvänd uppslagning av den lokala adressen gav inget\n"
"fullständigt domännamn!\n"

#: src/host.c:539
msgid "Host not found"
msgstr "Servern kunde inte hittas"

#: src/host.c:541
msgid "Unknown error"
msgstr "Okänt fel"

#: src/html.c:439 src/html.c:441
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "Innehåll i /%s på %s:%d"

#: src/html.c:463
msgid "time unknown       "
msgstr "okänd tid          "

#: src/html.c:467
msgid "File        "
msgstr "Fil         "

#: src/html.c:470
msgid "Directory   "
msgstr "Katalog     "

#: src/html.c:473
msgid "Link        "
msgstr "Länk        "

#: src/html.c:476
msgid "Not sure    "
msgstr "Osäker      "

#: src/html.c:494
#, c-format
msgid " (%s bytes)"
msgstr " (%s byte)"

#: src/http.c:492
msgid "Failed writing HTTP request.\n"
msgstr "Misslyckades med att skriva HTTP-begäran.\n"

#: src/http.c:497
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s begäran skickad, väntar på svar... "

#: src/http.c:536
msgid "End of file while parsing headers.\n"
msgstr "Filslut vid genomsökning av huvuden.\n"

#: src/http.c:547
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Läsfel (%s) i huvuden.\n"

#: src/http.c:587
msgid "No data received"
msgstr "Ingen data mottagen"

#: src/http.c:589
msgid "Malformed status line"
msgstr "Missbildad statusrad"

#: src/http.c:594
msgid "(no description)"
msgstr "(ingen beskrivning)"

#. If we have tried it already, then there is not point
#. retrying it.
#: src/http.c:678
msgid "Authorization failed.\n"
msgstr "Auktorisering misslyckades.\n"

#: src/http.c:685
msgid "Unknown authentication scheme.\n"
msgstr "Okänd auktoriseringsmetod.\n"

#: src/http.c:748
#, c-format
msgid "Location: %s%s\n"
msgstr "Adress: %s%s\n"

#: src/http.c:749 src/http.c:774
msgid "unspecified"
msgstr "ospecificerat"

#: src/http.c:750
msgid " [following]"
msgstr " [följande]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:764
msgid "Length: "
msgstr "Längd: "

#: src/http.c:769
#, c-format
msgid " (%s to go)"
msgstr " (%s kvar)"

#: src/http.c:774
msgid "ignored"
msgstr "ignorerad"

#: src/http.c:857
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Varning: jokertecken understöds inte i HTTP.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:872
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Filen \"%s\" finns redan där, hämtar inte.\n"

#: src/http.c:978
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Kan inte skriva till \"%s\" (%s).\n"

#: src/http.c:988
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "FEL: Omdirigering (%d) utan adress.\n"

#: src/http.c:1011
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s FEL %d: %s.\n"

#: src/http.c:1023
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "\"Last-modified\"-huvud saknas -- tidsstämplar avstängda.\n"

#: src/http.c:1031
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "\"Last-modified\"-huvudet ogiltigt -- tidsstämpel ignorerad.\n"

#: src/http.c:1064
msgid "Remote file is newer, retrieving.\n"
msgstr "Filen på fjärrsystemet är nyare, hämtar.\n"

#: src/http.c:1098
#, c-format
msgid "%s (%s) - `%s' saved [%ld/%ld]\n\n"
msgstr "%s (%s) - \"%s\" sparad [%ld/%ld]\n\n"

#: src/http.c:1130
#, c-format
msgid "%s (%s) - Connection closed at byte %ld. "
msgstr "%s (%s) - Förbindelse stängd vid byte %ld. "

#: src/http.c:1138
#, c-format
msgid "%s (%s) - `%s' saved [%ld/%ld])\n\n"
msgstr "%s (%s) - \"%s\" sparad [%ld/%ld])\n\n"

#: src/http.c:1150
#, c-format
msgid "%s (%s) - Connection closed at byte %ld/%ld. "
msgstr "%s (%s) - Förbindelse stängd vid byte %ld/%ld. "

#: src/http.c:1161
#, c-format
msgid "%s (%s) - Read error at byte %ld (%s)."
msgstr "%s (%s) - Läsfel vid byte %ld (%s)."

#: src/http.c:1169
#, c-format
msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
msgstr "%s (%s) - Läsfel vid byte %ld/%ld (%s). "

#: src/init.c:312 src/netrc.c:250
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: Kan inte läsa %s (%s).\n"

#: src/init.c:333 src/init.c:339
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: Fel i %s vid rad %d.\n"

#: src/init.c:370
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr "%s: Varning: Både systemets och användarens wgetrc pekar till \"%s\".\n"

#: src/init.c:458
#, c-format
msgid "%s: BUG: unknown command `%s', value `%s'.\n"
msgstr "%s: BUGG: okänt kommando \"%s\", värde \"%s\".\n"

#: src/init.c:485
#, c-format
msgid "%s: %s: Please specify on or off.\n"
msgstr "%s: %s: Vänligen ange \"on\" eller \"off\".\n"

#: src/init.c:503 src/init.c:760 src/init.c:782 src/init.c:855
#, c-format
msgid "%s: %s: Invalid specification `%s'.\n"
msgstr "%s: %s: Ogiltig specifikation \"%s\".\n"

#: src/init.c:616 src/init.c:638 src/init.c:660 src/init.c:686
#, c-format
msgid "%s: Invalid specification `%s'\n"
msgstr "%s: Ogiltig specifikation \"%s\"\n"

#: src/main.c:101
#, c-format
msgid "Usage: %s [OPTION]... [URL]...\n"
msgstr "Användning: %s [FLAGGA]... [URL]...\n"

#: src/main.c:109
#, c-format
msgid "GNU Wget %s, a non-interactive network retriever.\n"
msgstr "GNU Wget %s, en icke-interaktiv nätverkshämtare.\n"

#. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
#. don't bitch.  Also, it makes translation much easier.
#: src/main.c:114
msgid "\nMandatory arguments to long options are mandatory for short options too.\n\n"
msgstr "\nObligatoriska argument till långa flaggor är obligatoriska även för de korta.\n\n"

#: src/main.c:117
msgid ""
"Startup:\n"
"  -V,  --version           display the version of Wget and exit.\n"
"  -h,  --help              print this help.\n"
"  -b,  --background        go to background after startup.\n"
"  -e,  --execute=COMMAND   execute a `.wgetrc' command.\n"
"\n"
msgstr ""
"Uppstart:\n"

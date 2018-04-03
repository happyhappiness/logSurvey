"KLAAR --%s--\n"
"Opgehaald: %s bytes in %d bestanden\n"

#: src/main.c:842
#, c-format
msgid "Download quota (%s bytes) EXCEEDED!\n"
msgstr "Download quota (%s Bytes) OVERSCHREDEN!\n"

#. Please note that the double `%' in `%%s' is intentional, because
#. redirect_output passes tmp through printf.
#: src/main.c:876
#, c-format
msgid "%s received, redirecting output to `%%s'.\n"
msgstr "%s ontvangen, leid uitvoer om naar `%%s'.\n"

#: src/mswindows.c:89
#, c-format
msgid ""
"\n"
"CTRL+Break received, redirecting output to `%s'.\n"
"Execution continued in background.\n"
"You may stop Wget by pressing CTRL+ALT+DELETE.\n"
msgstr ""
"\n"
"CTRL+Break ontvangen, leid uitvoer om naar `%s'.\n"
"Uitvoering voortgezet in de achtergrond.\n"
"Wget kan worden gestopt door op CTRL+ALT+DELETE te drukken.\n"

#. parent, no error
#: src/mswindows.c:106 src/utils.c:458
msgid "Continuing in background.\n"
msgstr "Voortzetting in de achtergrond.\n"

#: src/mswindows.c:108 src/utils.c:460
#, c-format
msgid "Output will be written to `%s'.\n"
msgstr "Uitvoer wordt naar `%s' geschreven.\n"

#: src/mswindows.c:188
#, c-format
msgid "Starting WinHelp %s\n"
msgstr "WinHelp %s wordt gestart\n"

#: src/mswindows.c:215 src/mswindows.c:222
#, c-format
msgid "%s: Couldn't find usable socket driver.\n"
msgstr "%s: Kan geen bruikbare \"socket driver\" vinden.\n"

#: src/netrc.c:367
#, c-format
msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
msgstr "%s: %s:%d: Waarschuwing: `%s'-teken verschijnt voor een machinenaam\n"

#: src/netrc.c:398
#, c-format
msgid "%s: %s:%d: unknown token \"%s\"\n"
msgstr "%s: %s:%d: onbekend teken `%s'\n"

#: src/netrc.c:462
#, c-format
msgid "Usage: %s NETRC [HOSTNAME]\n"
msgstr "Aanroep: %s NETRC [HOSTNAME]\n"

# stat
#: src/netrc.c:472
#, c-format
msgid "%s: cannot stat %s: %s\n"
msgstr "%s: kan de status van bestand %s niet opvragen: %s\n"

#: src/recur.c:484
#, c-format
msgid "Removing %s since it should be rejected.\n"
msgstr "Verwijder `%s' omdat het verworpen zal worden.\n"

#: src/recur.c:679
msgid "Loading robots.txt; please ignore errors.\n"
msgstr "Laad `robots.txt'; gelieve fouten te negeren.\n"

#: src/retr.c:227
#, c-format
msgid "\n          [ skipping %dK ]"
msgstr "\n          [ overslaan %dK ]"

#: src/retr.c:373
msgid "Could not find proxy host.\n"
msgstr "Kan proxy-host niet vinden.\n"

#: src/retr.c:387
#, c-format
msgid "Proxy %s: Must be HTTP.\n"
msgstr "Proxy %s: Moet HTTP zijn.\n"

#: src/retr.c:481
#, c-format
msgid "%s: Redirection cycle detected.\n"
msgstr "%s: Cyclische omleiding gedetecteerd.\n"

#: src/retr.c:587
msgid "Giving up.\n\n"
msgstr "Geef op.\n\n"

#: src/retr.c:587
msgid "Retrying.\n\n"
msgstr "Opnieuw proberen.\n\n"

#: src/url.c:1329
#, c-format
msgid "Converting %s... "
msgstr "Omzetten %s... "

#: src/url.c:1342
msgid "nothing to do.\n"
msgstr "niets te doen.\n"

#: src/url.c:1350 src/url.c:1374
#, c-format
msgid "Cannot convert links in %s: %s\n"
msgstr "Kan verwijzingen niet omzetten naar %s: %s\n"

#: src/url.c:1365
#, c-format
msgid "Unable to delete `%s': %s\n"
msgstr "Niet in staat `%s': %s te verwijderen\n"

#: src/url.c:1555
#, c-format
msgid "Cannot back up %s as %s: %s\n"
msgstr "Kan %s niet backuppen als %s: %s\n"

#: src/utils.c:94
#, c-format
msgid "%s: %s: Not enough memory.\n"
msgstr "%s: %s: Onvoldoende geheugen.\n"

#: src/utils.c:417
msgid "Unknown/unsupported protocol"
msgstr "Onbekend/niet-ondersteund protocol"

#: src/utils.c:420
msgid "Invalid port specification"
msgstr "Ongeldige poort-specificatie"

#: src/utils.c:423
msgid "Invalid host name"
msgstr "Ongeldige computernaam"

#: src/utils.c:620
#, c-format
msgid "Failed to unlink symlink `%s': %s\n"
msgstr "Verwijderen symbolische koppeling `%s' gefaald: %s\n"

#~ msgid "%s: Cannot determine user-id.\n"
#~ msgstr "%s: Kan gebruikers-id niet bepalen.\n"

#~ msgid "%s: Warning: uname failed: %s\n"
#~ msgstr "%s: Waarschuwing: uname gefaald: %s\n"

#~ msgid "%s: Warning: gethostname failed\n"
#~ msgstr "%s: Waarschuwing: gethostname gefaald\n"

#~ msgid "%s: Warning: cannot determine local IP address.\n"
#~ msgstr "%s: Waarschuwing: kan lokaal IP-adres niet bepalen.\n"

#~ msgid "%s: Warning: cannot reverse-lookup local IP address.\n"
#~ msgstr "%s: Waarschuwing: omgekeerd opzoeken van lokaal IP-adres onmogelijk.\n"

#~ msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
#~ msgstr ""
#~ "%s: Waarschuwing: omgekeerd opzoeken van lokaal adres levert geen\n"
#~ "volledige domein naam.\n"

#~ msgid "%s: Out of memory.\n"
#~ msgstr "%s: Onvoldoende geheugen.\n"

#~ msgid "%s: Redirection to itself.\n"
#~ msgstr "%s: Omleiding naar zichzelf.\n"

#~ # ???
#~ msgid "Error (%s): Link %s without a base provided.\n"
#~ msgstr "Fout (%s): Verwijzing `%s' zonder basis aangeboden.\n"

#~ msgid "Error (%s): Base %s relative, without referer URL.\n"
#~ msgstr "Fout (%s): Basis %s relatief, zonder verwijzings-URL.\n"

#~ msgid "Local file `%s' is more recent, not retrieving.\n\n"
#~ msgstr "Lokaal bestand `%s' is nieuwer, niet ophalen.\n\n"

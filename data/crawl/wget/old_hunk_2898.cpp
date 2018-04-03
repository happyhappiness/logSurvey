# Translation of `wget' messages to Esperanto.
# Copyright (C) 2003 Free Software Foundation, Inc.
# This file is distributed under the same license as the `wget' package.
# Luiz Portella <lfpor@luiz.org>, 2005.
#
msgid ""
msgstr ""
"Project-Id-Version: GNU wget 1.9.1\n"
"Report-Msgid-Bugs-To: \n"
"POT-Creation-Date: 2005-04-28 12:13+0200\n"
"PO-Revision-Date: 2005-04-13 24:00-0300\n"
"Last-Translator: Luiz Portella <lfpor@luiz.org>\n"
"Language-Team: Esperanto <translation-team-eo@lists.sourceforge.net>\n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=UTF-8\n"
"Content-Transfer-Encoding: 8bit\n"

#: src/connect.c:200
#, c-format
msgid "%s: unable to resolve bind address `%s'; disabling bind.\n"
msgstr ""

#: src/connect.c:272
#, fuzzy, c-format
msgid "Connecting to %s|%s|:%d... "
msgstr "Konektante al %s[%s]:%hu... "

#: src/connect.c:275
#, fuzzy, c-format
msgid "Connecting to %s:%d... "
msgstr "Konektante al %s:%hu... "

#: src/connect.c:336
msgid "connected.\n"
msgstr "konektita.\n"

#: src/convert.c:176
#, fuzzy, c-format
msgid "Converted %d files in %.*f seconds.\n"
msgstr "Konvertitaj %d dosieroj dum %.2f sekundoj.\n"

#: src/convert.c:202
#, c-format
msgid "Converting %s... "
msgstr "Konvertante %s... "

#: src/convert.c:215
msgid "nothing to do.\n"
msgstr "nenio farenda.\n"

#: src/convert.c:223 src/convert.c:247
#, c-format
msgid "Cannot convert links in %s: %s\n"
msgstr "Ne eblis konverti ligilojn al %s: %s\n"

#: src/convert.c:238
#, c-format
msgid "Unable to delete `%s': %s\n"
msgstr "Ne eblis forviŝi `%s': %s\n"

#: src/convert.c:447
#, c-format
msgid "Cannot back up %s as %s: %s\n"
msgstr "Ne eblis kopii %s kiel %s: %s\n"

#: src/cookies.c:619
#, c-format
msgid "Error in Set-Cookie, field `%s'"
msgstr "Eraro en Set-Cookie, kampo `%s'"

#: src/cookies.c:643
#, c-format
msgid "Syntax error in Set-Cookie: %s at position %d.\n"
msgstr "Sintaksa eraro en Set-Cookie: %s ĉe pozicio %d.\n"

#: src/cookies.c:1469
#, c-format
msgid "Cannot open cookies file `%s': %s\n"
msgstr "Ne eblis malfermi kuketan dosieron `%s': %s\n"

#: src/cookies.c:1481
#, c-format
msgid "Error writing to `%s': %s\n"
msgstr "Eraro dum registrado al `%s': %s\n"

#: src/cookies.c:1484
#, c-format
msgid "Error closing `%s': %s\n"
msgstr "Eraro fermante `%s': %s\n"

#: src/ftp-ls.c:841
msgid "Unsupported listing type, trying Unix listing parser.\n"
msgstr "Lista tipo ne eltenebla, provante Uniksan liston.\n"

#: src/ftp-ls.c:887 src/ftp-ls.c:889
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "Indekso de /%s en %s:%d"

#: src/ftp-ls.c:912
#, c-format
msgid "time unknown       "
msgstr "horaro nekonata   "

#: src/ftp-ls.c:916
#, c-format
msgid "File        "
msgstr "Dosiero        "

#: src/ftp-ls.c:919
#, c-format
msgid "Directory   "
msgstr "Dosierujo   "

#: src/ftp-ls.c:922
#, c-format
msgid "Link        "
msgstr "Ligilo        "

#: src/ftp-ls.c:925
#, c-format
msgid "Not sure    "
msgstr "Sen certeco    "

#: src/ftp-ls.c:943
#, c-format
msgid " (%s bytes)"
msgstr ""

#: src/ftp.c:226
#, c-format
msgid "Length: %s"
msgstr ""

#: src/ftp.c:232 src/http.c:1853
#, c-format
msgid ", %s (%s) remaining"
msgstr ""

#: src/ftp.c:236 src/http.c:1857
#, c-format
msgid ", %s remaining"
msgstr ""

#: src/ftp.c:240
msgid " (unauthoritative)\n"
msgstr ""

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:315
#, c-format
msgid "Logging in as %s ... "
msgstr ""

#: src/ftp.c:328 src/ftp.c:381 src/ftp.c:412 src/ftp.c:466 src/ftp.c:581
#: src/ftp.c:632 src/ftp.c:662 src/ftp.c:724 src/ftp.c:792 src/ftp.c:856
#: src/ftp.c:908
msgid "Error in server response, closing control connection.\n"
msgstr ""

#: src/ftp.c:336
msgid "Error in server greeting.\n"
msgstr ""

#: src/ftp.c:344 src/ftp.c:475 src/ftp.c:590 src/ftp.c:671 src/ftp.c:735
#: src/ftp.c:803 src/ftp.c:867 src/ftp.c:919
msgid "Write failed, closing control connection.\n"
msgstr ""

#: src/ftp.c:351
msgid "The server refuses login.\n"
msgstr ""

#: src/ftp.c:358
msgid "Login incorrect.\n"
msgstr ""

#: src/ftp.c:365
msgid "Logged in!\n"
msgstr ""

#: src/ftp.c:390
msgid "Server error, can't determine system type.\n"
msgstr ""

#: src/ftp.c:400 src/ftp.c:711 src/ftp.c:775 src/ftp.c:822
msgid "done.    "
msgstr ""

#: src/ftp.c:454 src/ftp.c:611 src/ftp.c:646 src/ftp.c:891 src/ftp.c:942
msgid "done.\n"
msgstr ""

#: src/ftp.c:483
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr ""

#: src/ftp.c:496
msgid "done.  "
msgstr ""

#: src/ftp.c:502
msgid "==> CWD not needed.\n"
msgstr ""

#: src/ftp.c:597
#, c-format
msgid ""
"No such directory `%s'.\n"
"\n"
msgstr ""

#. do not CWD
#: src/ftp.c:615
msgid "==> CWD not required.\n"
msgstr ""

#: src/ftp.c:678
msgid "Cannot initiate PASV transfer.\n"
msgstr ""

#: src/ftp.c:682
msgid "Cannot parse PASV response.\n"
msgstr ""

#: src/ftp.c:702
#, c-format
msgid "couldn't connect to %s port %d: %s\n"
msgstr ""

#: src/ftp.c:753
#, c-format
msgid "Bind error (%s).\n"
msgstr ""

#: src/ftp.c:760
msgid "Invalid PORT.\n"
msgstr ""

#: src/ftp.c:811
msgid ""
"\n"
"REST failed, starting from scratch.\n"
msgstr ""

#: src/ftp.c:876
#, c-format
msgid ""
"No such file `%s'.\n"
"\n"
msgstr ""

#: src/ftp.c:928
#, c-format
msgid ""
"No such file or directory `%s'.\n"
"\n"
msgstr ""

#. We cannot just invent a new name and use it (which is
#. what functions like unique_create typically do)
#. because we told the user we'd use this name.
#. Instead, return and retry the download.
#: src/ftp.c:993 src/http.c:1909
#, c-format
msgid "%s has sprung into existence.\n"
msgstr ""

#: src/ftp.c:1055
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr ""

#: src/ftp.c:1063
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr ""

#: src/ftp.c:1078
msgid "Control connection closed.\n"
msgstr ""

#: src/ftp.c:1096
msgid "Data transfer aborted.\n"
msgstr ""

#: src/ftp.c:1161
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr ""

#: src/ftp.c:1225 src/http.c:2128
#, c-format
msgid "(try:%2d)"
msgstr ""

#: src/ftp.c:1297 src/http.c:2409
#, c-format
msgid ""
"%s (%s) - `%s' saved [%s]\n"
"\n"
msgstr ""

#: src/ftp.c:1339 src/main.c:946 src/recur.c:376 src/retr.c:835
#, c-format
msgid "Removing %s.\n"
msgstr ""

#: src/ftp.c:1381
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr ""

#: src/ftp.c:1396
#, c-format
msgid "Removed `%s'.\n"
msgstr ""

#: src/ftp.c:1431
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr ""

#. Remote file is older, file sizes can be compared and
#. are both equal.
#: src/ftp.c:1501
#, c-format
msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
msgstr ""

#. Remote file is newer or sizes cannot be matched
#: src/ftp.c:1508
#, c-format
msgid ""
"Remote file is newer than local file `%s' -- retrieving.\n"
"\n"
msgstr ""

#. Sizes do not match
#: src/ftp.c:1515
#, c-format
msgid ""
"The sizes do not match (local %s) -- retrieving.\n"
"\n"
msgstr ""

#: src/ftp.c:1533
msgid "Invalid name of the symlink, skipping.\n"
msgstr ""

#: src/ftp.c:1550
#, c-format
msgid ""
"Already have correct symlink %s -> %s\n"
"\n"
msgstr ""

#: src/ftp.c:1558
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr ""

#: src/ftp.c:1568
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr ""

#: src/ftp.c:1580
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr ""

#: src/ftp.c:1589
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr ""

#: src/ftp.c:1616
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr ""

#: src/ftp.c:1644
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr ""

#: src/ftp.c:1694
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr ""

#: src/ftp.c:1760 src/ftp.c:1774
#, c-format
msgid "Rejecting `%s'.\n"
msgstr ""

#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1820
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr ""

#: src/ftp.c:1886
#, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr ""

#: src/ftp.c:1891
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr ""

#: src/getopt.c:675
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr ""

#: src/getopt.c:700
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr ""

#: src/getopt.c:705
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr ""

#: src/getopt.c:723 src/getopt.c:896
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr ""

#. --option
#: src/getopt.c:752
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr ""

#. +option or -option
#: src/getopt.c:756
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr ""

#. 1003.2 specifies the format of this message.
#: src/getopt.c:782
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr ""

#: src/getopt.c:785
#, c-format
msgid "%s: invalid option -- %c\n"
msgstr ""

#. 1003.2 specifies the format of this message.
#: src/getopt.c:815 src/getopt.c:945
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr ""

#: src/getopt.c:862
#, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr ""

#: src/getopt.c:880
#, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr ""

#: src/host.c:371
msgid "Unknown host"
msgstr ""

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:375
msgid "Temporary failure in name resolution"
msgstr ""

#: src/host.c:377
msgid "Unknown error"
msgstr ""

#: src/host.c:757
#, c-format
msgid "Resolving %s... "
msgstr ""

#: src/host.c:801 src/host.c:830
#, c-format
msgid "failed: %s.\n"
msgstr ""

#: src/host.c:810
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr ""

#: src/host.c:833
msgid "failed: timed out.\n"
msgstr ""

#: src/html-url.c:297
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr ""

#: src/http.c:373 src/http.c:1534
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr ""

#: src/http.c:687
msgid "No headers, assuming HTTP/0.9"
msgstr ""

#: src/http.c:1194
msgid "Disabling SSL due to encountered errors.\n"
msgstr ""

#: src/http.c:1402
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr ""

#: src/http.c:1464
#, fuzzy, c-format
msgid "Failed writing to proxy: %s.\n"
msgstr "Eraro dum registrado al `%s': %s\n"

#: src/http.c:1473
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr ""

#: src/http.c:1493
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr ""

#: src/http.c:1540
#, c-format
msgid "%s request sent, awaiting response... "
msgstr ""

#: src/http.c:1551
msgid "No data received.\n"
msgstr ""

#: src/http.c:1558
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr ""

#. If we have tried it already, then there is not point
#. retrying it.
#: src/http.c:1629
msgid "Authorization failed.\n"
msgstr ""

#: src/http.c:1656
msgid "Unknown authentication scheme.\n"
msgstr ""

#: src/http.c:1689
msgid "Malformed status line"
msgstr ""

#: src/http.c:1691
msgid "(no description)"
msgstr ""

#: src/http.c:1762
#, c-format
msgid "Location: %s%s\n"
msgstr ""

#: src/http.c:1763 src/http.c:1863
msgid "unspecified"
msgstr ""

#: src/http.c:1764
msgid " [following]"
msgstr ""

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:1813
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
"\n"
msgstr ""

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1843
msgid "Length: "
msgstr ""

#: src/http.c:1863
msgid "ignored"
msgstr ""

#: src/http.c:2005
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr ""

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:2040
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr ""

#: src/http.c:2227
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr ""

#: src/http.c:2236
msgid "Unable to establish SSL connection.\n"
msgstr ""

#: src/http.c:2246
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr ""

#: src/http.c:2278
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr ""

#: src/http.c:2291
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr ""

#: src/http.c:2299
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr ""

#: src/http.c:2322
#, c-format
msgid ""
"Server file no newer than local file `%s' -- not retrieving.\n"
"\n"
msgstr ""

#: src/http.c:2330
#, c-format
msgid "The sizes do not match (local %s) -- retrieving.\n"
msgstr ""

#: src/http.c:2335
msgid "Remote file is newer, retrieving.\n"
msgstr ""

#: src/http.c:2377
#, c-format
msgid ""
"%s (%s) - `%s' saved [%s/%s]\n"
"\n"
msgstr ""

#: src/http.c:2434
#, c-format
msgid "%s (%s) - Connection closed at byte %s. "
msgstr ""

#: src/http.c:2443
#, c-format
msgid ""
"%s (%s) - `%s' saved [%s/%s])\n"
"\n"
msgstr ""

#: src/http.c:2469
#, c-format
msgid "%s (%s) - Connection closed at byte %s/%s. "
msgstr ""

#: src/http.c:2483
#, c-format
msgid "%s (%s) - Read error at byte %s (%s)."
msgstr ""

#: src/http.c:2493
#, c-format
msgid "%s (%s) - Read error at byte %s/%s (%s). "
msgstr ""

#: src/init.c:369
#, c-format
msgid "%s: WGETRC points to %s, which doesn't exist.\n"
msgstr ""

#: src/init.c:422 src/netrc.c:277
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr ""

#: src/init.c:440 src/init.c:446
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr ""

#: src/init.c:478
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr ""

#: src/init.c:622
#, c-format
msgid "%s: Invalid --execute command `%s'\n"
msgstr ""

#: src/init.c:668
#, c-format
msgid "%s: %s: Invalid boolean `%s', use `on' or `off'.\n"
msgstr ""

#: src/init.c:711
#, c-format
msgid "%s: %s: Invalid boolean `%s', use always, on, off, or never.\n"
msgstr ""

#: src/init.c:728
#, c-format
msgid "%s: %s: Invalid number `%s'.\n"
msgstr ""

#: src/init.c:959 src/init.c:978
#, c-format
msgid "%s: %s: Invalid byte value `%s'\n"
msgstr ""

#: src/init.c:1003
#, c-format
msgid "%s: %s: Invalid time period `%s'\n"
msgstr ""

#: src/init.c:1057 src/init.c:1138 src/init.c:1233 src/init.c:1259
#, c-format
msgid "%s: %s: Invalid value `%s'.\n"
msgstr ""

#: src/init.c:1086
#, c-format
msgid "%s: %s: Invalid header `%s'.\n"
msgstr ""

#: src/init.c:1150
#, c-format
msgid "%s: %s: Invalid progress type `%s'.\n"
msgstr ""

#: src/init.c:1201
#, c-format
msgid "%s: %s: Invalid restriction `%s', use `unix' or `windows'.\n"
msgstr ""

#: src/log.c:777
#, c-format
msgid ""
"\n"

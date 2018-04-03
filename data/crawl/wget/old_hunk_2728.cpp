"Content-Type: text/plain; charset=ISO-8859-8\n"
"Content-Transfer-Encoding: 8-bit\n"

#: src/connect.c:199
#, c-format
msgid "%s: unable to resolve bind address `%s'; disabling bind.\n"
msgstr ""

# FIXME: this is lame!  The method of printing "Frobbing...done" etc.
# does not lend itself to good translations into languages where
# such sentences have a different structure, and should be rethought.
#: src/connect.c:271
#, fuzzy, c-format
msgid "Connecting to %s|%s|:%d... "
msgstr "%s:%hu-� ������� �����"

# FIXME: this is lame!  The method of printing "Frobbing...done" etc.
# does not lend itself to good translations into languages where
# such sentences have a different structure, and should be rethought.
#: src/connect.c:274
#, fuzzy, c-format
msgid "Connecting to %s:%d... "
msgstr "%s:%hu-� ������� �����"

# Pay attention: this is written to the RIGHT of "Connecting.." !!
#: src/connect.c:335
#, fuzzy
msgid "connected.\n"
msgstr "� �����\n"

#: src/convert.c:176
#, c-format
msgid "Converted %d files in %.*f seconds.\n"
msgstr ""

# Note: the following 5 messages are all written on the same line!
#: src/convert.c:202
#, c-format
msgid "Converting %s... "
msgstr "%s ����"

#: src/convert.c:215
msgid "nothing to do.\n"
msgstr "� ���� ���\n"

#: src/convert.c:223 src/convert.c:247
#, c-format
msgid "Cannot convert links in %s: %s\n"
msgstr "� (%s: %s) ������� ���� ����\n"

#: src/convert.c:238
#, c-format
msgid "Unable to delete `%s': %s\n"
msgstr "`%s' ����� ������ (%s) ����\n"

#: src/convert.c:447
#, c-format
msgid "Cannot back up %s as %s: %s\n"
msgstr "%s-� ������ %s ������ (%s) ����\n"

#: src/cookies.c:619
#, c-format
msgid "Error in Set-Cookie, field `%s'"
msgstr "���� Set-Cookie ����� �� `%s' ���"

#: src/cookies.c:643
#, fuzzy, c-format
msgid "Syntax error in Set-Cookie: %s at position %d.\n"
msgstr ".��� ����� ������� ������� :Set-Cookie ����� �� ���� �����\n"

#: src/cookies.c:1469
#, c-format
msgid "Cannot open cookies file `%s': %s\n"
msgstr "`%s' ������ ���� ����� ��� (%s) ���� �����\n"

#: src/cookies.c:1481
#, c-format
msgid "Error writing to `%s': %s\n"
msgstr "`%s'-� ������ (%s) ����\n"

#: src/cookies.c:1484
#, c-format
msgid "Error closing `%s': %s\n"
msgstr "`%s' ������ (%s) ����\n"

#: src/ftp-ls.c:841
msgid "Unsupported listing type, trying Unix listing parser.\n"
msgstr ".Unix ����� ��� ���� ���� ,����-���� ���� ����� �����\n"

#: src/ftp-ls.c:887 src/ftp-ls.c:889
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "/%s ������ %s:%d-� ����� �����"

#: src/ftp-ls.c:912
#, c-format
msgid "time unknown       "
msgstr "  ���� �� ����� ���"

#: src/ftp-ls.c:916
#, c-format
msgid "File        "
msgstr "        ����"

#: src/ftp-ls.c:919
#, c-format
msgid "Directory   "
msgstr "       �����"

#: src/ftp-ls.c:922
#, c-format
msgid "Link        "
msgstr "       �����"

#: src/ftp-ls.c:925
#, c-format
msgid "Not sure    "
msgstr " ���� �� ���"

#: src/ftp-ls.c:943
#, c-format
msgid " (%s bytes)"
msgstr "  (���� %s)"

# FIXME: This 3-part message will look totally messed up in a
# right-to-left language such as Hebrew!  The maintainers
# should _really_ fix the code!
#: src/ftp.c:226
#, c-format
msgid "Length: %s"
msgstr "%s :����"

#: src/ftp.c:232 src/http.c:1857
#, c-format
msgid ", %s (%s) remaining"
msgstr ""

#: src/ftp.c:236 src/http.c:1861
#, c-format
msgid ", %s remaining"
msgstr ""

#: src/ftp.c:239
msgid " (unauthoritative)\n"
msgstr " (�����)\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:314
#, c-format
msgid "Logging in as %s ... "
msgstr "%s-� ����� �����"

#: src/ftp.c:327 src/ftp.c:373 src/ftp.c:402 src/ftp.c:454 src/ftp.c:566
#: src/ftp.c:612 src/ftp.c:640 src/ftp.c:698 src/ftp.c:759 src/ftp.c:819
#: src/ftp.c:866
msgid "Error in server response, closing control connection.\n"
msgstr ".���� ����� ���� ,��� �� ���� ����\n"

#: src/ftp.c:334
msgid "Error in server greeting.\n"
msgstr ".���� ���� �� ����� ���\n"

#: src/ftp.c:341 src/ftp.c:462 src/ftp.c:574 src/ftp.c:648 src/ftp.c:708
#: src/ftp.c:769 src/ftp.c:829 src/ftp.c:876
msgid "Write failed, closing control connection.\n"
msgstr ".���� ����� ���� ,������ ����\n"

#: src/ftp.c:347
msgid "The server refuses login.\n"
msgstr ".����� ���� ���� ����\n"

#: src/ftp.c:353
msgid "Login incorrect.\n"
msgstr ".����� �����\n"

# Note: this is written to the right of "Logging in as", with no newline!
#: src/ftp.c:359
msgid "Logged in!\n"
msgstr "� �����\n"

#: src/ftp.c:381
msgid "Server error, can't determine system type.\n"
msgstr ".����� ��� ����� ������ ��� ,��� �� ���� ����\n"

#: src/ftp.c:390 src/ftp.c:685 src/ftp.c:742 src/ftp.c:785
msgid "done.    "
msgstr " <== ������ ����"

#: src/ftp.c:442 src/ftp.c:591 src/ftp.c:624 src/ftp.c:849 src/ftp.c:895
msgid "done.\n"
msgstr " <== ������ ����\n"

#: src/ftp.c:469
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr ".���� ����� ���� ,���� ���� `%c' ����� ���\n"

#: src/ftp.c:481
msgid "done.  "
msgstr " <== ������ ����"

#: src/ftp.c:487
msgid "==> CWD not needed.\n"
msgstr "==> .����� ���� CWD �����\n"

#: src/ftp.c:580
#, c-format
msgid ""
"No such directory `%s'.\n"
"\n"
msgstr ""
".����� ���� `%s' �����\n"
"\n"

#. do not CWD
#: src/ftp.c:595
msgid "==> CWD not required.\n"
msgstr "==> .CWD ������ ���� ���\n"

#: src/ftp.c:654
msgid "Cannot initiate PASV transfer.\n"
msgstr ".PASV ����� ����� ������ ���� ��\n"

#: src/ftp.c:658
msgid "Cannot parse PASV response.\n"
msgstr ".PASV ������ ���� ���� ���� ��\n"

#: src/ftp.c:676
#, c-format
msgid "couldn't connect to %s port %d: %s\n"
msgstr ""

#: src/ftp.c:724
#, c-format
msgid "Bind error (%s).\n"
msgstr ".(%s) ������� ����\n"

#: src/ftp.c:730
msgid "Invalid PORT.\n"
msgstr ".PORT ����\n"

#: src/ftp.c:776
msgid ""
"\n"
"REST failed, starting from scratch.\n"
msgstr ""
"\n"
".������ ����� ;����� REST �����\n"

#: src/ftp.c:837
#, c-format
msgid ""
"No such file `%s'.\n"
"\n"
msgstr ""
".���� ���� `%s' ����\n"
"\n"

#: src/ftp.c:884
#, c-format
msgid ""
"No such file or directory `%s'.\n"
"\n"
msgstr ""
".������ ����� �� ���� ���� `%s'\n"
"\n"

#. We cannot just invent a new name and use it (which is
#. what functions like unique_create typically do)
#. because we told the user we'd use this name.
#. Instead, return and retry the download.
#: src/ftp.c:946 src/http.c:1913
#, c-format
msgid "%s has sprung into existence.\n"
msgstr ""

#: src/ftp.c:1008
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr ".���� ����� ���� ,%s-� (%s) ����\n"

# Note: the rightmost colon is for the message that will be printed
# later.
#: src/ftp.c:1016
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "(%s :���  %s :���) ������� ����� (%s) ���� :"

# Note: this and the next one don't have the period because they get
# printed to the right of the previous message.
#: src/ftp.c:1031
msgid "Control connection closed.\n"
msgstr "���� ����� ����\n"

#: src/ftp.c:1049
msgid "Data transfer aborted.\n"
msgstr "������ ������ �����\n"

#: src/ftp.c:1114
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr ".���� ����� ���� ��� ,��� ��� `%s' ����\n"

#: src/ftp.c:1182 src/http.c:2130
#, c-format
msgid "(try:%2d)"
msgstr "(%2d '�� �����)"

# I give up!
#: src/ftp.c:1252 src/http.c:2409
#, fuzzy, c-format
msgid ""
"%s (%s) - `%s' saved [%s]\n"
"\n"
msgstr ""
"%s (%s) - `%s' saved [%ld]\n"
"\n"

#: src/ftp.c:1294 src/main.c:948 src/recur.c:376 src/retr.c:842
#, c-format
msgid "Removing %s.\n"
msgstr ".%s ����\n"

#: src/ftp.c:1336
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr ".����� ����� ����� ���� ����� `%s'-� �����\n"

#: src/ftp.c:1351
#, c-format
msgid "Removed `%s'.\n"
msgstr ".���� `%s' ����\n"

#: src/ftp.c:1386
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr ".���� ���� %d ����� ���� �� ,%d ��� ����� ������� ����\n"

#. Remote file is older, file sizes can be compared and
#. are both equal.
#: src/ftp.c:1456
#, c-format
msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
msgstr ".����� �� ����� -- `%s' ����� ����� ���� ����� ���� ����� ����\n"

#. Remote file is newer or sizes cannot be matched
#: src/ftp.c:1463
#, c-format
msgid ""
"Remote file is newer than local file `%s' -- retrieving.\n"
"\n"
msgstr ".����� ����� -- `%s' ����� ����� ���� ����� ����� ����\n"

#. Sizes do not match
#: src/ftp.c:1470
#, fuzzy, c-format
msgid ""
"The sizes do not match (local %s) -- retrieving.\n"
"\n"
msgstr ".����� ����� -- (%ld :����� ����) ��� ���� ����\n"

#: src/ftp.c:1488
msgid "Invalid name of the symlink, skipping.\n"
msgstr ".����� ����� ,���� ���� ������� ����� ���� �� ���\n"

#: src/ftp.c:1505
#, c-format
msgid ""
"Already have correct symlink %s -> %s\n"
"\n"
msgstr ".���� ��� %s -> %s ������� �����\n"

#: src/ftp.c:1513
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr ".%s -> %s ������� ����� ����\n"

#: src/ftp.c:1523
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr ".`%s' ���� ����� ,������ ���� ������� ����� ����\n"

#: src/ftp.c:1535
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr ".`%s' ����� �����\n"

#: src/ftp.c:1544
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr ".���� ���� �� ����-���� ���� ���� `%s' ����\n"

#: src/ftp.c:1571
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr ".����� ��� ����� ��� ��� `%s' ����\n"

#: src/ftp.c:1599
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr ".���� �� %d ����� ��� ������ �� ������ ;%d ����� ����\n"

#: src/ftp.c:1649
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr ".������� ����� �� ����� ��� ���� `%s'-� ������� ����\n"

#: src/ftp.c:1715 src/ftp.c:1729
#, c-format
msgid "Rejecting `%s'.\n"
msgstr ".���� `%s'\n"

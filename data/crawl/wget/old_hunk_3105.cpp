msgstr ""
"\n"
"��������� --%s--\n"
"�������: %s ���� � %d ����ax\n"

#: src/main.c:854
#, c-format
msgid "Download quota (%s bytes) EXCEEDED!\n"
msgstr "��������� ����������� ������ (%s ����)!\n"

#. Please note that the double `%' in `%%s' is intentional, because
#. redirect_output passes tmp through printf.
#: src/main.c:896
#, c-format
msgid "%s received, redirecting output to `%%s'.\n"
msgstr "������� ������ %s, ����� ������������� � `%%s'.\n"

#: src/mswindows.c:106
#, c-format
msgid ""
"\n"
"CTRL+Break received, redirecting output to `%s'.\n"
"Execution continued in background.\n"
"You may stop Wget by pressing CTRL+ALT+DELETE.\n"
msgstr ""
"\n"
"������ CTRL+Break, ����� ���������������� � `%s'.\n"
"���������� ��������� ����� ���������� � ������� ������.\n"
"�� ������ ���������� ������ Wget �������� CTRL+ALT+DELETE.\n"

#. parent, no error
#: src/mswindows.c:123 src/utils.c:467
msgid "Continuing in background.\n"
msgstr "����������� ������ � ������� ������.\n"

#: src/mswindows.c:125 src/utils.c:469
#, c-format
msgid "Output will be written to `%s'.\n"
msgstr "�������� ���������� ����� �������� � ���� `%s'.\n"

#: src/mswindows.c:205
#, c-format
msgid "Starting WinHelp %s\n"
msgstr "������ WinHelp %s\n"

#: src/mswindows.c:232 src/mswindows.c:239
#, c-format
msgid "%s: Couldn't find usable socket driver.\n"
msgstr "%s: �� ������ ���������� ������� TCP/IP.\n"

#: src/netrc.c:365
#, c-format
msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
msgstr "%s: %s:%d: ��������������: ������� \"%s\" ��������� ����� ����� ������\n"

#: src/netrc.c:396
#, c-format
msgid "%s: %s:%d: unknown token \"%s\"\n"
msgstr "%s: %s:%d: ����������� ������� \"%s\"\n"

#: src/netrc.c:460
#, c-format
msgid "Usage: %s NETRC [HOSTNAME]\n"
msgstr "�������������: %s NETRC [HOSTNAME]\n"

#: src/netrc.c:470
#, c-format
msgid "%s: cannot stat %s: %s\n"
msgstr "%s: �� ������� ��������� stat ��� %s: %s\n"

#. Align the [ skipping ... ] line with the dots.  To do
#. that, insert the number of spaces equal to the number of
#. digits in the skipped amount in K.
#: src/progress.c:224
#, c-format
msgid "\n%*s[ skipping %dK ]"
msgstr "\n%*s[ ������� %dK ]"

#: src/progress.c:391
#, c-format
msgid "Invalid dot style specification `%s'; leaving unchanged.\n"
msgstr "������������ �������� `%s'; ����� �������� ��� ���������.\n"

#: src/recur.c:350
#, c-format
msgid "Removing %s since it should be rejected.\n"
msgstr "�������� %s, ��� ��� ���� ���� ������ ���� ��������.\n"

#: src/recur.c:916
#, c-format
msgid "Converted %d files in %.2f seconds.\n"
msgstr "������������� %d ������ �� %.2f ������.\n"

#: src/res.c:541
msgid "Loading robots.txt; please ignore errors.\n"
msgstr "�������� robots.txt; �� ��������� �������� �� ������.\n"

#: src/retr.c:363
msgid "Could not find proxy host.\n"
msgstr "�� ������ ������-������.\n"

#: src/retr.c:375
#, c-format
msgid "Error parsing proxy URL %s: %s.\n"
msgstr "������ ������� URL ������-������� %s: %s\n"

#: src/retr.c:384
#, c-format
msgid "Error in proxy URL %s: Must be HTTP.\n"
msgstr "������ � URL ������-������� %s: ����������� ������ HTTP.\n"

#: src/retr.c:476
#, c-format
msgid "%d redirections exceeded.\n"
msgstr "����� %d ���������������.\n"

#: src/retr.c:491
#, c-format
msgid "%s: Redirection cycle detected.\n"
msgstr "%s: ��������� ���� ���������������.\n"

#: src/retr.c:608
msgid "Giving up.\n\n"
msgstr "����������.\n\n"

#: src/retr.c:608
msgid "Retrying.\n\n"
msgstr "����������� �������.\n\n"

#: src/url.c:1748
#, c-format
msgid "Converting %s... "
msgstr "�������������� %s... "

#: src/url.c:1761
msgid "nothing to do.\n"
msgstr "�������� �� ������.\n"

#: src/url.c:1769 src/url.c:1793
#, c-format
msgid "Cannot convert links in %s: %s\n"
msgstr "�� ������� ������������� ������ � %s: %s\n"

#: src/url.c:1784
#, c-format
msgid "Unable to delete `%s': %s\n"
msgstr "������ �������� `%s': %s\n"

#: src/url.c:1990
#, c-format
msgid "Cannot back up %s as %s: %s\n"
msgstr "�� ������� ��������� %s ��� ������ %s: %s\n"

#: src/utils.c:102
#, c-format
msgid "%s: %s: Not enough memory.\n"
msgstr "%s: %s: ������������ ������.\n"

#: src/utils.c:667
#, c-format
msgid "Failed to unlink symlink `%s': %s\n"
msgstr "������ �������� ���������� ������ `%s': %s\n"

#~ msgid "Connection to %s:%hu refused.\n"
#~ msgstr "������ %s:%hu �������� ����������.\n"

#~ msgid "Will try connecting to %s:%hu.\n"
#~ msgstr "������� ���������� � %s:%hu ����� ����������.\n"

#~ msgid "Unknown/unsupported protocol"
#~ msgstr "�������� ���������� ��� �� ��������������."

#~ msgid "Invalid port specification"
#~ msgstr "������������ ����������� �����"

#~ msgid "Invalid host name"
#~ msgstr "������������ ��� ������"

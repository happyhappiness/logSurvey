
#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:150 src/http.c:624
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "��������� ���������� � %s:%hu... "

#: src/ftp.c:172 src/ftp.c:539 src/http.c:641
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "������ %s:%hu �������� ����������.\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:193 src/http.c:652
msgid "connected!\n"
msgstr "�����������!\n"

#: src/ftp.c:194
#, c-format
msgid "Logging in as %s ... "
msgstr "����������� ��� ������ %s ... "

#: src/ftp.c:203 src/ftp.c:256 src/ftp.c:288 src/ftp.c:336 src/ftp.c:429
#: src/ftp.c:481 src/ftp.c:575 src/ftp.c:648 src/ftp.c:709 src/ftp.c:757
msgid "Error in server response, closing control connection.\n"
msgstr "������ � ������� �������, �������� ������������ ����������.\n"

#: src/ftp.c:211
msgid "Error in server greeting.\n"
msgstr "������ � ����������� �������.\n"

#: src/ftp.c:219 src/ftp.c:345 src/ftp.c:438 src/ftp.c:490 src/ftp.c:585
#: src/ftp.c:658 src/ftp.c:719 src/ftp.c:767
msgid "Write failed, closing control connection.\n"
msgstr "������ ������, �������� ������������ ����������.\n"

#: src/ftp.c:226
msgid "The server refuses login.\n"
msgstr "������ �������� �����������.\n"

#: src/ftp.c:233
msgid "Login incorrect.\n"
msgstr "������������ ��� ��� ������.\n"

#: src/ftp.c:240
msgid "Logged in!\n"
msgstr "����������� ������ �������!\n"

#: src/ftp.c:265
msgid "Server error, can't determine system type.\n"
msgstr "������ �� �������, �� ������� ���������� ��� �������.\n"

#: src/ftp.c:275 src/ftp.c:560 src/ftp.c:632 src/ftp.c:689
msgid "done.    "
msgstr "�������.    "

#: src/ftp.c:325 src/ftp.c:459 src/ftp.c:740 src/ftp.c:788 src/url.c:1429
msgid "done.\n"
msgstr "�������.\n"

#: src/ftp.c:353
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "����������� ��� `%c', �������� ������������ ����������.\n"

#: src/ftp.c:366
msgid "done.  "
msgstr "�������.  "

#: src/ftp.c:372
msgid "==> CWD not needed.\n"
msgstr "==> CWD �� �����.\n"

#: src/ftp.c:445
#, c-format
msgid "No such directory `%s'.\n\n"
msgstr "����������� ������� `%s'.\n\n"

#. do not CWD
#: src/ftp.c:463
msgid "==> CWD not required.\n"
msgstr "==> CWD �� ���������.\n"

#: src/ftp.c:497
msgid "Cannot initiate PASV transfer.\n"
msgstr "�� ������� ������ PASV-��������.\n"

#: src/ftp.c:501
msgid "Cannot parse PASV response.\n"
msgstr "������ ��������������� ������� ������ PASV.\n"

#: src/ftp.c:515
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "������� ���������� � %s:%hu ����� ����������.\n"

#: src/ftp.c:602
#, c-format
msgid "Bind error (%s).\n"
msgstr "������ bind (%s).\n"

#: src/ftp.c:618
msgid "Invalid PORT.\n"
msgstr "������������ PORT.\n"

#: src/ftp.c:671
#, c-format
msgid "\nREST failed; will not truncate `%s'.\n"
msgstr "\n������� REST �� ���������; �������� `%s' �� ������������.\n"

#: src/ftp.c:678
msgid "\nREST failed, starting from scratch.\n"
msgstr "\n������� REST �� ���������, ������ � ������� �������.\n"

#: src/ftp.c:727
#, c-format
msgid "No such file `%s'.\n\n"
msgstr "����������� ���� `%s'.\n\n"

#: src/ftp.c:775
#, c-format
msgid "No such file or directory `%s'.\n\n"
msgstr "����������� ���� ��� ������� `%s'.\n\n"

#: src/ftp.c:859 src/ftp.c:867
#, c-format
msgid "Length: %s"
msgstr "�����: %s"

#: src/ftp.c:861 src/ftp.c:869
#, c-format
msgid " [%s to go]"
msgstr " [�������� %s]"

#: src/ftp.c:871
msgid " (unauthoritative)\n"
msgstr " (�� ����������)\n"

#: src/ftp.c:898
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, �������� ������������ ����������.\n"

#: src/ftp.c:906
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - ����������: %s; "

#: src/ftp.c:923
msgid "Control connection closed.\n"
msgstr "����������� ���������� �������.\n"

#: src/ftp.c:941
msgid "Data transfer aborted.\n"
msgstr "�������� ������ ��������.\n"

#: src/ftp.c:1005
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "���� `%s' ��� ����������, �������� �� ���������.\n"

#: src/ftp.c:1075 src/http.c:1502
#, c-format
msgid "(try:%2d)"
msgstr "(�������:%2d)"

#: src/ftp.c:1139 src/http.c:1753
#, c-format
msgid "%s (%s) - `%s' saved [%ld]\n\n"
msgstr "%s (%s) - `%s' �������� [%ld]\n\n"

#: src/ftp.c:1181 src/main.c:810 src/recur.c:483 src/retr.c:566
#, c-format
msgid "Removing %s.\n"
msgstr "�������� %s.\n"

#: src/ftp.c:1221
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "������� ����� �������� �� ��������� ����� `%s'.\n"

#: src/ftp.c:1233
#, c-format
msgid "Removed `%s'.\n"
msgstr "������ `%s'.\n"

#: src/ftp.c:1269
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "������� �������� %d ��������� ������������ ������� %d.\n"

#. Remote file is older, file sizes can be compared and
#. are both equal.
#: src/ftp.c:1330
#, c-format
msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
msgstr "���� �� ������� �� ����� ���������� ����� `%s' -- �������.\n"

#. Remote file is newer or sizes cannot be matched
#: src/ftp.c:1337
#, c-format
msgid "Remote file is newer than local file `%s' -- retrieving.\n\n"
msgstr "���� �� ������� ����� ���������� ����� `%s' -- ���������.\n"

#. Sizes do not match
#: src/ftp.c:1344
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n\n"
msgstr "������� �� ��������� (��������� ������ %ld) -- ���������.\n"

#: src/ftp.c:1361
msgid "Invalid name of the symlink, skipping.\n"
msgstr "������������ ��� ���������� ������, ���������.\n"

#: src/ftp.c:1378
#, c-format
msgid "Already have correct symlink %s -> %s\n\n"
msgstr "���������� ������ %s -> %s ��� ����������.\n\n"

#: src/ftp.c:1386
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "�������� ���������� ������ %s -> %s\n"

#: src/ftp.c:1397
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "���������� ������ �� ��������������, ������� `%s'.\n"

#: src/ftp.c:1409
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "������� �������� `%s'.\n"

#: src/ftp.c:1418
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: ��� ����� ���������� ��� �� ��������������.\n"

#: src/ftp.c:1445
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: �������� ����� ��������� �����.\n"

#: src/ftp.c:1466
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "�������� �� ����� ��������, ������� ���������� %d (�������� %d).\n"

#: src/ftp.c:1512
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "������� `%s' ��������, ��� ��� ��������� � ������ �����������.\n"

#: src/ftp.c:1559
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "������� `%s'.\n"

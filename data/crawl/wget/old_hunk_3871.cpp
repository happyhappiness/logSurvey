msgid "%s: option requires an argument -- %c\n"
msgstr "%s: �ﶵ�ݭn�@�Ӥ޼� -- %c\n"

#: src/host.c:432
#, c-format
msgid "%s: Cannot determine user-id.\n"
msgstr "%s: �L�k�����ϥΪ��ѧO�X.\n"

#: src/host.c:444
#, c-format
msgid "%s: Warning: uname failed: %s\n"
msgstr "%s: ĵ�i: uname ����: %s\n"

#: src/host.c:456
#, c-format
msgid "%s: Warning: gethostname failed\n"
msgstr "%s: ĵ�i: gethostname ����\n"

#: src/host.c:484
#, c-format
msgid "%s: Warning: cannot determine local IP address.\n"
msgstr "%s: ĵ�i: �L�k�������a IP ��}.\n"

#: src/host.c:498
#, c-format
msgid "%s: Warning: cannot reverse-lookup local IP address.\n"
msgstr "%s: ĵ�i: �L�k�Ϭd���a IP ��}.\n"

#: src/host.c:506
#, c-format
msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
msgstr "%s: ĵ�i: ���a��}���Ϭd���ŦX FQDN �W��!\n"

#: src/host.c:533
msgid "Host not found"
msgstr "�䤣��D��"

#: src/host.c:535
msgid "Unknown error"
msgstr "���������~"

#: src/html.c:433 src/html.c:435
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "/%s �����ަb %s:%d"

#: src/html.c:457
msgid "time unknown       "
msgstr "�ɶ�����           "

#: src/html.c:461
msgid "File        "
msgstr "�ɮ�        "

#: src/html.c:464
msgid "Directory   "
msgstr "�ؿ�        "

#: src/html.c:467
msgid "Link        "
msgstr "�s��        "

#: src/html.c:470
msgid "Not sure    "
msgstr "�S���T�w    "

#: src/html.c:488
#, c-format
msgid " (%s bytes)"
msgstr " (%s �줸��)"

#: src/http.c:483
msgid "Failed writing HTTP request.\n"
msgstr "���ѩ�g�J HTTP �ШD��.\n"

#: src/http.c:488
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "�w�g�e�X %s �ШD�ʥ]�A���b���ݦ^����... "

#: src/http.c:527
msgid "End of file while parsing headers.\n"
msgstr "���b���R���Y���e�ɡA�ɮפw�g����.\n"

#: src/http.c:538
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Ū�������Y�����~ (%s).\n"

#: src/http.c:578
msgid "No data received"
msgstr "�S�������������"

#: src/http.c:580
msgid "Malformed status line"
msgstr "��Ϊ����A��"

#: src/http.c:585
msgid "(no description)"
msgstr "(�S����������)"

#. If we have tried it already, then there is not point
#. retrying it.
#: src/http.c:669
msgid "Authorization failed.\n"
msgstr "�{�ҥ���.\n"

#: src/http.c:676
msgid "Unknown authentication scheme.\n"
msgstr "�������{�Ҥ��.\n"

#: src/http.c:739
#, c-format
msgid "Location: %s%s\n"
msgstr "��m: %s%s\n"

#: src/http.c:740 src/http.c:765
msgid "unspecified"
msgstr "�S�����w"

#: src/http.c:741
msgid " [following]"
msgstr " [�U�C�U��]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:755
msgid "Length: "
msgstr "����: "

#: src/http.c:760
#, c-format
msgid " (%s to go)"
msgstr " (%s �n�}�l)"

#: src/http.c:765
msgid "ignored"
msgstr "����"

#: src/http.c:848
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "ĵ�i: �b HTTP �̭��ä䴩�U�Φr���Ÿ� (wildcards).\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:863
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "�ɮ� `%s' �w�g�s�b�A�N�����^.\n"

#: src/http.c:969
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "�L�k�g�� `%s' (%s).\n"

#: src/http.c:979
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "���~: �n�D���s�w�V (%d) �o�S����m.\n"

#: src/http.c:995
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s ���~ %d: %s.\n"

#: src/http.c:1007
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "�� \"Last-modified\" �����Y -- �ɶ��W�O�Q����.\n"

#: src/http.c:1015
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "�L�Ī� \"Last-modified\" ���Y -- �ɶ��W�O�Q����.\n"

#: src/http.c:1047
msgid "Remote file is newer, retrieving.\n"
msgstr "���ݪ��ɮפ���s�A���^��.\n"

#: src/http.c:1081
#, c-format
msgid "%s (%s) - `%s' saved [%ld/%ld]\n\n"
msgstr "%s (%s) - `%s' �Q�s�� [%ld/%ld]\n\n"

#: src/http.c:1113
#, c-format
msgid "%s (%s) - Connection closed at byte %ld. "
msgstr "%s (%s) - �s�u�Q�����b %ld �줸��. "

#: src/http.c:1121
#, c-format
msgid "%s (%s) - `%s' saved [%ld/%ld])\n\n"
msgstr "%s (%s) - `%s' �Q�s�� [%ld/%ld])\n\n"

#: src/http.c:1133
#, c-format
msgid "%s (%s) - Connection closed at byte %ld/%ld. "
msgstr "%s (%s) - �s�u������ %ld/%ld byte."

#: src/http.c:1144
#, c-format
msgid "%s (%s) - Read error at byte %ld (%s)."
msgstr "%s (%s) - �� %ld (%s) �줸�ճB�o��Ū�����~."

#: src/http.c:1152
#, c-format
msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
msgstr "%s (%s) - �� %ld/%ld (%s) �줸�ճB�o��Ū�����~."

#: src/init.c:311 src/netrc.c:249
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: �L�kŪ�� %s (%s).\n"

#: src/init.c:332 src/init.c:338
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: ���ѩ� %s �b�� %d ��.\n"

#: src/init.c:369
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr "%s: ĵ�i: �t�λP�ϥΪ̪� wgetrc �����V `%s'.\n"

#: src/init.c:460
#, c-format
msgid "%s: BUG: unknown command `%s', value `%s'.\n"
msgstr "%s: BUG: �������R�O `%s', �ƭ� `%s'.\n"

#: src/init.c:487
#, c-format
msgid "%s: %s: Please specify on or off.\n"
msgstr "%s: %s: �ЯS�O���w�}�ҩ�����.\n"

#: src/init.c:505 src/init.c:762 src/init.c:784 src/init.c:857
#, c-format
msgid "%s: %s: Invalid specification `%s'.\n"
msgstr "%s: %s: �L�Ī����w���� `%s'.\n"

#: src/init.c:618 src/init.c:640 src/init.c:662 src/init.c:688
#, c-format
msgid "%s: Invalid specification `%s'\n"
msgstr "%s: �L�Ī����w���� `%s'\n"

#: src/main.c:101
#, c-format
msgid "Usage: %s [OPTION]... [URL]...\n"
msgstr "�Ϊk: %s [�ﶵ]... [URL]...\n"

#: src/main.c:109
#, c-format
msgid "GNU Wget %s, a non-interactive network retriever.\n"
msgstr "GNY Wget %s, �@�ӫD��ͦ����������ɤu��.\n"

#. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
#. don't bitch.  Also, it makes translation much easier.
#: src/main.c:114
msgid "\nMandatory arguments to long options are mandatory for short options too.\n\n"
msgstr "\n�R�O���޼ƨϥΪ����ػP�u���جۦP.\n"

#: src/main.c:117
msgid ""
"Startup:\n"
"  -V,  --version           display the version of Wget and exit.\n"
"  -h,  --help              print this help.\n"
"  -b,  --background        go to background after startup.\n"
"  -e,  --execute=COMMAND   execute a `.wgetrc' command.\n"
"\n"
msgstr ""
"�Ұ�:\n"

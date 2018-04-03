          logprintf (LOG_NOTQUIET, "%s", _("\
WARNING: timestamping does nothing in combination with -O. See the manual\n\
for details.\n\n"));
          opt.timestamping = false;
        }
    }

ChangeLog | 4 ++++
NEWS      | 6 ++++++
2 files changed, 10 insertions(+)

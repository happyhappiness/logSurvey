      [multimailhook]
              refFilterExclusionRegex = ^refs/tags/|^refs/heads/master$

    ``refFilterInclusionRegex`` and ``refFilterExclusionRegex`` are
    strictly stronger than ``refFilterDoSendRegex`` and
    ``refFilterDontSendRegex``. In other words, adding a ref to a
    DoSend/DontSend regex has no effect if it is already excluded by a
    Exclusion/Inclusion regex.

multimailhook.logFile, multimailhook.errorLogFile, multimailhook.debugLogFile

    When set, these variable designate path to files where
    git-multimail will log some messages. Normal messages and error
    messages are sent to ``logFile``, and error messages are also sent
    to ``errorLogFile``. Debug messages and all other messages are
    sent to ``debugLogFile``. The recommended way is to set only one
    of these variables, but it is also possible to set several of them
    (part of the information is then duplicated in several log files,
    for example errors are duplicated to all log files).

    Relative path are relative to the Git repository where the push is
    done.

multimailhook.verbose

    Verbosity level of git-multimail on its standard output. By
    default, show only error and info messages. If set to true, show
    also debug messages.

Email filtering aids
--------------------


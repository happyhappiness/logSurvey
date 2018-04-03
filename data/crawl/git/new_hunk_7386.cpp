        if len(p4CmdList("opened ...")) > 0:
            die("You have files opened with perforce! Close them before starting the sync.")

    # replaces everything between 'Description:' and the next P4 submit template field with the
    # commit message
    def prepareLogMessage(self, template, message):

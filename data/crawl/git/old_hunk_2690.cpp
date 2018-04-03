        self.p4HasMoveCommand = p4_has_move_command()
        self.branch = None

    def check(self):
        if len(p4CmdList("opened ...")) > 0:
            die("You have files opened with perforce! Close them before starting the sync.")

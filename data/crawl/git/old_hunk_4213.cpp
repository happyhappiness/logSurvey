
        return True

class P4Sync(Command, P4UserMap):
    delete_actions = ( "delete", "move/delete", "purge" )


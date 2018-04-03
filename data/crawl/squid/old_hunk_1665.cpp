
            if (!FtpSupportedCommand(cmd))
                filteredHeader.delAt(pos, deletedCount);
        }
    }

    if (deletedCount) {
        filteredHeader.refreshMask();
        debugs(33, 5, "deleted " << deletedCount);
    }

    FtpWriteForwardedReply(context, filteredReply);
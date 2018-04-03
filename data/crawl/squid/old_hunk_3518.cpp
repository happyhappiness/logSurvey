                point = service->cfg().point;
            } else {
                if (method != service->cfg().method)
                    finalizeMsg("Inconsistent service method for", sid, true);
                if (point != service->cfg().point)
                    finalizeMsg("Inconsistent vectoring point for", sid, true);
            }

            checkUniqueness(pos);

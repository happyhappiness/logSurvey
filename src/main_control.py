#-*-coding: utf-8 -*-
from gumtree_api import Gumtree
import gumtree_api
import fetch_hunk
import fetch_log
import cluster_log
import my_util

if __name__ == "__main__":
    my_util.set_user_repos('tar')
    fetch_hunk.fetch_patch()
    gumtree=Gumtree()
    fetch_log.fetch_hunk(gumtree)
    cluster_log.cluster_edition()
    gumtree_api.close_jvm()
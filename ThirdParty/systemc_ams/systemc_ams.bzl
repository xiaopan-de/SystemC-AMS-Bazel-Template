"""
This module contains rule to pull SystemC-AMS
"""

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:utils.bzl", "maybe")

_VERSION = "2.3.4"

def systemc_ams():
    maybe(
        http_archive,
        name = "systemc_ams",
        sha256 = "27aa93e087dbe432db460c9da9752ad092edc61dcd09d0dd64a4e8ce332b1ba3",
        strip_prefix = "",
        build_file = "//ThirdParty/systemc_ams:systemc_ams.BUILD",
        url = "https://github.com/xiaopan-de/systemc-ams/releases/download/v{version}/systemc-ams-{version}.zip".format(version = _VERSION),
    )

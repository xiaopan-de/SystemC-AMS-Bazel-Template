"""
This module contains rule to pull SystemC-AMS
"""

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:utils.bzl", "maybe")

_VERSION = "2.3.4"

def systemc():
    maybe(
        http_archive,
        name = "systemc",
        sha256 = "302e32b1d5175b59e59e40488d026f0624a7bdbc5f3cf50e04e950668c5c4c5d",
        strip_prefix = "",
        build_file = "//ThirdParty/systemc:systemc.BUILD",
        url = "https://github.com/xiaopan-de/systemc-ams/releases/download/v{version}/systemc-{version}.zip".format(version = _VERSION),
    )

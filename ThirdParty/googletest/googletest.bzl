"""
This module contains rule to pull googletest
"""

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:utils.bzl", "maybe")

# TYPE: upstream
# LICENSE: BSD-3-Clause
def googletest():
    maybe(
        http_archive,
        name = "googletest",
        url = "https://github.com/google/googletest/archive/refs/tags/release-1.10.0.tar.gz",
        sha256 = "9dc9157a9a1551ec7a7e43daea9a694a0bb5fb8bec81235d8a1e6ef64c716dcb",
        strip_prefix = "googletest-release-1.10.0",
    )

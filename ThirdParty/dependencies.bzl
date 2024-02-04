load("@//ThirdParty/googletest:googletest.bzl", "googletest")
load("@//ThirdParty/systemc:systemc.bzl", "systemc")
load("@//ThirdParty/systemc_ams:systemc_ams.bzl", "systemc_ams")

def third_party_deps():
    """
    Load thrid party libiraries
    """
    googletest()
    systemc()
    systemc_ams()

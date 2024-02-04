cc_library(
    name = "basic_adc",
    srcs = ["basic_adc.cpp"],
    hdrs = ["basic_adc.h"],
    visibility = ["//visibility:public"],
    deps = [
        "@systemc",
        "@systemc_ams",
    ],
)

cc_test(
    name = "basic_adc_test",
    srcs = ["basic_adc_test.cpp"],
    deps = [
        ":basic_adc",
        "@googletest//:gtest_main",
    ],
)

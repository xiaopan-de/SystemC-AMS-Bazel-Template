# SystemC-AMS-Bazel-Template
SystemC-AMS-Bazel-Template is designed to jumpstart SystemC/.-TLM and SystemC-AMS projects using the Bazel build system. This template is an essential resource for developers and researchers working in system-level modeling and simulation, providing a streamlined and efficient setup for both analog and mixed-signal modeling endeavors.

# Key Features:

- **Bazel** Workspace: Instant setup with Bazel, integrating SystemC and SystemC-AMS.
- **Containerized Environments**: Streamlined setup with DevContainer and Docker.
- **GTest Framework**: Integrated with Google Test for unit testing.
- **CI Pipeline**: Automated builds and test with GitHub Actions.
- Prebuilt Libraries: Ready-to-use SystemC/AMS libraries.
- Example Modules: Demonstrative SystemC and SystemC-AMS samples.

# Dev Environment Setup 

## Develop with GitHub Codespaces (Recommended)
1. Open the Repository in Codespaces
2. Use the `.devcontainer` configuration which GitHub Codespaces
3. Develop Directly in Your Browser


## Dev Containerized Setup
1. Clone the Repository
2. Set Up the Development Environment: install `docker`
3. DevContainer: Open the project in VSCode with the `Remote - Containers` extension.


##  Local dev use system configs   
1. System Requirements: Ubuntu 22.04, C++ Standard 14
2. Clone the Repository
3. Install Bazel 
    - Install Bazel: https://bazel.build/install
    - Install Bazel Command-Line Completion : https://bazel.build/install/completion
    - Bazel formatter: https://github.com/bazelbuild/buildtools/blob/master/buildifier/README.md 



# Build and Test  
```bash 
cd SystemC-AMS-Bazel-Template

# Build the basic adc module 
bazel build sca/basic_adc:basic_adc

# Run the unit test 
bazel  test sca/basic_adc:basic_adc_test  --test_output=all
```

test out put 
```shell
INFO: Analyzed target //sca/basic_adc:basic_adc_test (0 packages loaded, 85 targets configured).
INFO: Found 1 test target...
INFO: From Testing //sca/basic_adc:basic_adc_test:
==================== Test output for //sca/basic_adc:basic_adc_test:

        SystemC 2.3.4-Accellera --- Jan 29 2024 22:16:39
        Copyright (c) 1996-2022 by all Contributors,
        ALL RIGHTS RESERVED
[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from BasicAdcTest
[ RUN      ] BasicAdcTest.GivenValidAnalogInput_WhenAdcConversion_ThenCorrectConvertedinput


        SystemC AMS extensions 2.4.0-COSEDA Release date: 20220406 2361 
        Copyright (c) 2010-2014  by Fraunhofer-Gesellschaft IIS/EAS
        Copyright (c) 2015-2022  by COSEDA Technologies GmbH
        Licensed under the Apache License, Version 2.0



Info: SystemC-AMS: 
	2 SystemC-AMS modules instantiated
	1 SystemC-AMS views created
	2 SystemC-AMS synchronization objects/solvers instantiated


Info: SystemC-AMS: 
	1 dataflow clusters instantiated
	  cluster 0:
		2 dataflow modules/solver, contains e.g. module: basic_adc
		2 elements in schedule list,  
		1 ns cluster period, 
		ratio to lowest:  1              e.g. module: basic_adc
		ratio to highest: 1 sample time  e.g. module: basic_adc
		1 connections to SystemC de, 1 connections from SystemC de

[       OK ] BasicAdcTest.GivenValidAnalogInput_WhenAdcConversion_ThenCorrectConvertedinput (1 ms)
[----------] 1 test from BasicAdcTest (1 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test suite ran. (1 ms total)
[  PASSED  ] 1 test.
================================================================================
Target //sca/basic_adc:basic_adc_test up-to-date:
  bazel-bin/sca/basic_adc/basic_adc_test
INFO: Elapsed time: 0.343s, Critical Path: 0.05s
INFO: 2 processes: 1 internal, 1 linux-sandbox.
INFO: Build completed successfully, 2 total actions
//sca/basic_adc:basic_adc_test                                           PASSED in 0.0s

Executed 1 out of 1 test: 1 test passes.

```


# Continuous Integration
This project uses GitHub Actions for continuous integration. Upon each push or pull request, the CI pipeline automatically builds the project and runs tests, ensuring that changes do not break existing functionality.

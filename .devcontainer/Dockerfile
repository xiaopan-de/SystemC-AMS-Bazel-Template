FROM ubuntu:22.04 AS build-base

RUN apt-get --quiet update && \
    DEBIAN_FRONTEND=noninteractive apt-get --quiet install -y --no-install-recommends \
    build-essential \
    git \
    git-lfs \
    curl \
    ca-certificates \
    clang-format \
    clang-tidy \
    gnupg \
    apt-transport-https \
    # required for code coverage :
    lcov \
    default-jre default-jdk \
    # reuqired by doxygen:
    doxygen \
    graphviz \
    aha \
    # required by test output generation :
    xsltproc

RUN curl -fsSL https://bazel.build/bazel-release.pub.gpg | gpg --dearmor >bazel-archive-keyring.gpg \
    && mv bazel-archive-keyring.gpg /usr/share/keyrings \
    && echo "deb [arch=amd64 signed-by=/usr/share/keyrings/bazel-archive-keyring.gpg] https://storage.googleapis.com/bazel-apt stable jdk1.8" |  tee /etc/apt/sources.list.d/bazel.list
RUN apt update && apt install bazel -y && apt full-upgrade -y && apt install bazel-5.1.1 -y

ARG BUILDIFIER_VERSION=6.0.0
ARG BUILDIFIER_SHA=7ff82176879c0c13bc682b6b0e482d670fbe13bbb20e07915edb0ad11be50502
RUN curl -fSsL -L -o /usr/local/bin/buildifier \
    "https://github.com/bazelbuild/buildtools/releases/download/${BUILDIFIER_VERSION}/buildifier-linux-amd64" \
    && echo "${BUILDIFIER_SHA} */usr/local/bin/buildifier" | sha256sum --check - \
    && chmod 0755 /usr/local/bin/buildifier

ARG SHFMT_VERSION=v3.6.0
ARG SHFMT_SHA=5741a02a641de7e56b8da170e71a97e58050d66a3cf485fb268d6a5a8bb74afb
RUN curl -fSsL -L -o /usr/local/bin/shfmt \
    "https://github.com/mvdan/sh/releases/download/${SHFMT_VERSION}/shfmt_${SHFMT_VERSION}_linux_amd64" \
    && echo "${SHFMT_SHA} */usr/local/bin/shfmt" | sha256sum --check - \
    && chmod 0755 /usr/local/bin/shfmt

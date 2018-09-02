from conans import ConanFile, tools
import os


class KainjowmustacheConan(ConanFile):
    name = "lmdbxx"
    version = "0.9.18"
    license = "The Unlicense (Public Domain)"
    # No settings/options are necessary, this is header only
    build_policy="missing" # header only no need to build it
    requires = ("lmdb/[~=0.9]@inexorgame/testing")

    def source(self):
        self.run("git clone --branch master --depth 1 https://github.com/bendiken/lmdbxx")

    def package(self):
        self.copy("lmdb++.h", dst="include", src="lmdbxx")

    def package_info(self):
        self.cpp_info.includedirs = ['include']  # Ordered list of include paths


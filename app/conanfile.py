from conans import ConanFile, CMake
class Pkg(ConanFile):
    settings = "os", "compiler", "arch", "build_type"
    requires = ("openalsound/0.1@user/testing",
                "spdlogger/0.1@user/testing",
                "nulllogger/0.1@user/testing",
                "fruit/[~=3.2]@inexorgame/stable")
    generators = "cmake"
    exports_sources = "src/*"

    def build(self):
        cmake = CMake(self)
        cmake.configure(source_folder="src")
        cmake.build()


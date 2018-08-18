from conans import ConanFile, CMake
import os


class modularConan(ConanFile):
    license = "ZLIB"
    description = "Inexor's private root Conan recipe"
    url = "https://github.com/inexorgame/inexor-core.git"
    settings = "os", "compiler", "build_type", "arch"

    requires = ("fruit/3.2.0@inexorgame/stable")
    generators = "cmake"

    def build(self):
        args = []

        cmake = CMake(self)
        self.run('cmake "{}" {} {}'.format(self.source_folder, cmake.command_line, ' '.join(args)))
        self.run('cmake --build .'.format(cmake.build_config))

    def imports(self):
        self.copy("*.dll", dst="bin", src="bin")  # From bin to bin
        self.copy("*.so*", dst="bin", src="lib")  # From lib to bin
        self.copy("*.dylib*", dst="bin", src="lib")  # From lib to bin
        self.copy("*.bin", dst="bin", src="bin")  # From bin to bin
        self.copy("*.dat", dst="bin", src="bin")  # From bin to bin
        self.copy("*.pak", dst="bin", src="bin")  # From bin to bin


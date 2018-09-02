from conans import ConanFile, CMake, tools, AutoToolsBuildEnvironment
import os

class LightningDBCppConan(ConanFile):
    name = "lmdb"
    version = "0.9.18"
    settings = "os", "compiler", "build_type", "arch"
    url = "https://github.com/sunsided/lmdb"
    license = "OpenLDAP Public License"
    options = {"shared": [True, False]}
    default_options = "shared=True"
    exports = "CMakeLists.txt", "conanfile.py", "mdb.def"#, "win32/*"

    def source(self):
        extension = "zip" if self.settings.os == "Windows" else "tar.gz"
        base_name = "LMDB_%s" % (self.version)
        zip_name = "%s.%s" % (base_name, extension)
        url = "https://github.com/LMDB/lmdb/archive/%s" % (zip_name)
        self.output.info("Downloading %s..." % url)
        tools.download(url, zip_name)
        tools.unzip(zip_name, ".")
        os.unlink(zip_name)
        os.rename("lmdb-%s" % base_name, "lmdb")

    def build_with_cmake(self):
        cmake = CMake(self)
        if self.options.shared:
            cmake.definitions["BUILD_SHARED_LIBS"] = "YES"
        else:
            cmake.definitions["BUILD_SHARED_LIBS"] = "NO"
        cmake.configure() #source_folder="lmdb")
        cmake.build()

    def build_with_make(self):
        makedir = "lmdb/libraries/liblmdb"
        with tools.chdir(makedir):
            env_build = AutoToolsBuildEnvironment(self)
            # env_build.configure() # use it to run "./configure" if using autotools
            env_build.make()

    def build(self):
        if self.settings.os == "Windows":
            return self.build_with_cmake()
        else:
            return self.build_with_make()

    def package(self):
        self.copy("lmdb.h", dst="include", src="lmdb/libraries/liblmdb")
        self.copy("*.lib", dst="lib", src="", keep_path=False)
        self.copy("*.a", dst="lib", src="", keep_path=False)
        self.copy("*.pdb", dst="lib", src="", keep_path=False)
        self.copy("*.dll", dst="bin", src="", keep_path=False)
        self.copy("*.so", dst="bin", src="", keep_path=False)
        self.copy("*.exe", dst="bin", src="", keep_path=False)

    def package_info(self):
        if  self.settings.os == "Windows":
            self.cpp_info.libs.append("ntdll")
            if self.settings.build_type == "Debug":
                self.cpp_info.libs = ["lmdbd"]
            else:
                self.cpp_info.libs = ["lmdb"]
        else:
            self.cpp_info.libs.append("pthread")
            self.cpp_info.libs = ["lmdb"]

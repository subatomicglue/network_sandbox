import os
from conan import ConanFile
from conan.tools.cmake import cmake_layout, CMake
from conan.tools.files import get
from conan.tools.files import patch


class Pkg(ConanFile):
    name = "boringssl"
    version = "0.0.1"
    #exports_sources = "patches*"
    generators = "CMakeToolchain"

    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}

    def layout(self):
        cmake_layout(self, src_folder="src")
        # if you are declaring your own layout, just declare:
        # self.folders.source = "src"

    def source(self):
        # we are inside a "src" subfolder, as defined by layout
        # the downloaded soures will be inside the "src" subfolder
        get(self, "https://boringssl.googlesource.com/boringssl/+archive/e28988ecaa5e72523a982915084c9422e495116d.tar.gz",
            strip_root=False)
        # Please, be aware that using the head of the branch instead of an immutable tag
        # or commit is not a good practice in general as the branch may change the contents

        # patching, replacing, happens here
        #patch(self, patch_file=os.path.join(self.export_sources_folder, "patches/mypatch"))

    def build(self):
        # If necessary, the build() method also has access to the export_sources_folder
        # for example if patching happens in build() instead of source()
        #patch(self, patch_file=os.path.join(self.export_sources_folder, "patches/mypatch"))
        cmake = CMake(self)
        cmake.configure()
        cmake.build()


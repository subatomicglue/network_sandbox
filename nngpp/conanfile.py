import os
from conan import ConanFile
from conan.tools.cmake import cmake_layout, CMake
from conan.tools.files import get
from conan.tools.files import patch


class Pkg(ConanFile):
    name = "nngpp"
    version = "1.3.0"
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
        #git = Git(self)
        #git.clone(url="https://github.com/conan-io/libhello.git", target=".")
        get(self, "https://github.com/cwzx/nngpp/archive/refs/tags/nng-v1.3.0.zip",
            strip_root=True)
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


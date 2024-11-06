add_rules("mode.debug", "mode.release")
set_languages("c99","c++20")
add_requires("spdlog")

set_toolset("cc", "clang")
set_toolset("cxx", "clang++")

if is_plat("windows") then
    -- 设置编码
    add_defines("UNICODE", "_UNICODE")
    -- 添加必要的系统库
    add_links("kernel32", "user32", "gdi32", "winspool", "shell32", "ole32", "oleaut32", "uuid", "comdlg32", "advapi32", "oldnames")
    -- 添加 C 运行时库
    add_links("libcmt", "libvcruntime", "libucrt")
end


target("tutorial")
    set_kind("binary")
    add_packages(("spdlog"))
    add_files("src/*.cpp")
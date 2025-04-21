import qbs

Product
{
    name: "MediaController"
    targetName: "mediacontroller"
    type: "staticlibrary"
    condition: true

    Depends { name: "Qt"; submodules: ["core", "multimedia", "widgets"] }

    cpp.defines: project.cppDefines
    cpp.cxxFlags: project.cxxFlags
    cpp.cxxLanguageVersion: project.cxxLanguageVersion

    property var includePaths:
    [
        "../",
    ]

    Group
    {
        name:"Widgets"
        prefix: "widgets/"
        files:[
           "media_player.cpp",
           "media_player.h",
           "media_player.ui",
        ]
    }

    files:
    [
    ]
    Export
    {
        Depends { name: "cpp" }
        cpp.includePaths: exportingProduct.includePaths
    }
}

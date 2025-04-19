import qbs

Product
{
    name: "StreamBot"
    targetName: "streambot"
    type: "application"
    condition: true

    Depends { name: "MediaController" }
    Depends { name: "Qt"; submodules: ["core", "multimedia", "network", "widgets"] }

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
           "mainwindow.cpp",
           "mainwindow.h",
           "mainwindow.ui",
        ]
    }

    files:
    [
        "main.cpp"
    ]
    Export
    {
        Depends { name: "cpp" }
        cpp.includePaths: exportingProduct.includePaths
    }
}

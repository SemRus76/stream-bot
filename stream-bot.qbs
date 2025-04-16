import qbs.FileInfo

QtApplication {
    Depends { name: "Qt"; submodules: ["core", "multimedia", "network", "widgets"] }

    cpp.defines: [
        // You can make your code fail to compile if it uses deprecated APIs.
        // In order to do so, uncomment the following line.
    ]

    Group
    {
        name:"Widgets"
        prefix:"src/stream-bot/widgets/"
        files: [
            "mainwindow.cpp",
            "mainwindow.h",
            "mainwindow.ui",
        ]
    }

    Group
    {
        name:"Media Controller"
        prefix:"src/media-controller/"
        files:[
            "widgets/media_player.cpp",
            "widgets/media_player.h",
            "widgets/media_player.ui",
        ]
    }

    Group
    {
        name:"StreamBot"
        prefix:"src/stream-bot/"
        files: [
            "main.cpp",
        ]
    }

    install: true
    installDir: qbs.targetOS.contains("qnx") ? FileInfo.joinPaths("/tmp", name, "bin") : base
}

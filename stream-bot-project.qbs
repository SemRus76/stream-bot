import qbs

Project {
    name: "stream-bot (Project)"
    minimumQbsVersion: "1.22.0"
    qbsSearchPaths: ["qbs"]

    property string cxxLanguageVersion: "c++17"
    property var cxxFlags: [
        "-ggdb3",
        "-Wall",
        "-Wextra",
        "-Wswitch-enum",
        "-Wdangling-else",
        "-Wno-unused-parameter",
        "-Wno-variadic-macros",
        "-Wno-vla",
    ]

    // TODO: Добавить свойства версирования git и проекта

    property var cppDefines: {
        var def = [

        ];

        return def;
    }

    references: [
        "src/stream-bot/stream-bot.qbs",
        "src/media-controller/media-controller.qbs"
    ]
}

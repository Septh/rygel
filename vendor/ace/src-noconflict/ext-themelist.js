ace.define("ace/ext/themelist",["require","exports","module"], function(require, exports, module){/**
 * ## Theme enumeration utility
 *
 * Provides theme management for the Ace Editor by generating and organizing available themes into
 * categorized collections. Automatically maps theme data into structured objects containing theme metadata including
 * display captions, theme paths, brightness classification (dark/light), and normalized names. Exports both an
 * indexed theme collection and a complete themes array for easy integration with theme selection components
 * and configuration systems.
 *
 * @author <a href="mailto:matthewkastor@gmail.com">
 *  Matthew Christopher Kastor-Inare III </a><br />
 * @module
 */
"use strict";
var themeData = [
    ["Chrome"],
    ["Clouds"],
    ["Crimson Editor"],
    ["Dawn"],
    ["Dreamweaver"],
    ["Eclipse"],
    ["GitHub Light Default"],
    ["GitHub (Legacy)", "github", "light"],
    ["IPlastic"],
    ["Solarized Light"],
    ["TextMate"],
    ["Tomorrow"],
    ["XCode"],
    ["Kuroir"],
    ["KatzenMilch"],
    ["SQL Server", "sqlserver", "light"],
    ["CloudEditor", "cloud_editor", "light"],
    ["Ambiance", "ambiance", "dark"],
    ["Chaos", "chaos", "dark"],
    ["Clouds Midnight", "clouds_midnight", "dark"],
    ["Dracula", "", "dark"],
    ["Cobalt", "cobalt", "dark"],
    ["Gruvbox", "gruvbox", "dark"],
    ["Green on Black", "gob", "dark"],
    ["idle Fingers", "idle_fingers", "dark"],
    ["krTheme", "kr_theme", "dark"],
    ["Merbivore", "merbivore", "dark"],
    ["Merbivore Soft", "merbivore_soft", "dark"],
    ["Mono Industrial", "mono_industrial", "dark"],
    ["Monokai", "monokai", "dark"],
    ["Nord Dark", "nord_dark", "dark"],
    ["One Dark", "one_dark", "dark"],
    ["Pastel on dark", "pastel_on_dark", "dark"],
    ["Solarized Dark", "solarized_dark", "dark"],
    ["Terminal", "terminal", "dark"],
    ["Tomorrow Night", "tomorrow_night", "dark"],
    ["Tomorrow Night Blue", "tomorrow_night_blue", "dark"],
    ["Tomorrow Night Bright", "tomorrow_night_bright", "dark"],
    ["Tomorrow Night 80s", "tomorrow_night_eighties", "dark"],
    ["Twilight", "twilight", "dark"],
    ["Vibrant Ink", "vibrant_ink", "dark"],
    ["GitHub Dark", "github_dark", "dark"],
    ["CloudEditor Dark", "cloud_editor_dark", "dark"]
];
exports.themesByName = {};
exports.themes = themeData.map(function (data) {
    var name = data[1] || data[0].replace(/ /g, "_").toLowerCase();
    var theme = {
        caption: data[0],
        theme: "ace/theme/" + name,
        isDark: data[2] == "dark",
        name: name
    };
    exports.themesByName[name] = theme;
    return theme;
});

});                (function() {
                    ace.require(["ace/ext/themelist"], function(m) {
                        if (typeof module == "object" && typeof exports == "object" && module) {
                            module.exports = m;
                        }
                    });
                })();
            
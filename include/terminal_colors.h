/*
 * TERMINAL_COLORS.H
 * =================
 * Cross-platform terminal color codes for C++
 *
 * USAGE:
 * ------
 * #include "terminal_colors.h"
 *
 * std::cout << BOLD_RED << "Error message" << RESET << std::endl;
 * std::cout << SKY_BLUE << "Info message" << RESET << std::endl;
 *
 * ANSI COLORS (Basic 16 colors):
 * -------------------------------
 * These work on virtually all terminals (Linux, Mac, Windows 10+)
 * Format: \033[{style};{color}m
 * - Style: 0 = normal, 1 = bold
 * - Color: 30-37 (foreground), 40-47 (background)
 *
 * Examples:
 *   std::cout << RED << "Red text" << RESET << std::endl;
 *   std::cout << BOLD_GREEN << "Bold green" << RESET << std::endl;
 *   std::cout << BG_BLUE << WHITE << "White on blue" << RESET << std::endl;
 *
 * 256-COLOR MODE (Extended palette):
 * -----------------------------------
 * Provides 256 colors (works on most modern terminals)
 * Format: \033[38;5;{code}m (foreground) or \033[48;5;{code}m (background)
 * - Code: 0-255 (color index)
 *
 * Common color ranges:
 *   0-15:   Standard colors
 *   16-231: 216 color cube (6x6x6)
 *   232-255: Grayscale
 *
 * Examples:
 *   std::cout << ORANGE << "Orange text" << RESET << std::endl;
 *   std::cout << SKY_BLUE << "Sky blue" << RESET << std::endl;
 *   std::cout << "\033[48;5;208m" << "Orange background" << RESET << std::endl;
 *
 * RGB TRUE COLOR (24-bit):
 * ------------------------
 * Format: \033[38;2;{r};{g};{b}m
 * Allows any RGB color (0-255 for each channel)
 *
 * Example:
 *   std::cout << "\033[38;2;255;165;0m" << "Custom orange" << RESET << std::endl;
 *
 * COMBINING STYLES:
 * -----------------
 *   std::cout << BOLD << UNDERLINE << RED << "Bold underlined red" << RESET << std::endl;
 *   std::cout << BG_BLACK << BOLD_YELLOW << "Yellow on black" << RESET << std::endl;
 *
 * IMPORTANT:
 * ----------
 * - Always end with RESET to return to default colors
 * - Some terminals may not support 256-color or RGB modes
 */

#ifndef TERMINAL_COLORS_H
#define TERMINAL_COLORS_H

// ============================================================================
// RESET
// ============================================================================
#define RESET "\033[0m"

// ============================================================================
// BASIC ANSI COLORS (Foreground)
// ============================================================================
#define BLACK   "\033[0;30m"
#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define BLUE    "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN    "\033[0;36m"
#define WHITE   "\033[0;37m"

// ============================================================================
// BOLD ANSI COLORS (Bright/Bold Foreground)
// ============================================================================
#define BOLD_BLACK   "\033[1;30m"
#define BOLD_RED     "\033[1;31m"
#define BOLD_GREEN   "\033[1;32m"
#define BOLD_YELLOW  "\033[1;33m"
#define BOLD_BLUE    "\033[1;34m"
#define BOLD_MAGENTA "\033[1;35m"
#define BOLD_CYAN    "\033[1;36m"
#define BOLD_WHITE   "\033[1;37m"

// ============================================================================
// BACKGROUND COLORS
// ============================================================================
#define BG_BLACK   "\033[40m"
#define BG_RED     "\033[41m"
#define BG_GREEN   "\033[42m"
#define BG_YELLOW  "\033[43m"
#define BG_BLUE    "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN    "\033[46m"
#define BG_WHITE   "\033[47m"

// ============================================================================
// TEXT STYLES
// ============================================================================
#define BOLD      "\033[1m"
#define DIM       "\033[2m"
#define ITALIC    "\033[3m"
#define UNDERLINE "\033[4m"
#define BLINK     "\033[5m"
#define REVERSE   "\033[7m"
#define HIDDEN    "\033[8m"
#define STRIKE    "\033[9m"

// ============================================================================
// 256-COLOR EXTENDED PALETTE (Common Colors)
// ============================================================================

// Oranges
#define ORANGE          "\033[38;5;208m"
#define DARK_ORANGE     "\033[38;5;166m"
#define LIGHT_ORANGE    "\033[38;5;214m"
#define BRIGHT_ORANGE   "\033[38;5;202m"

// Pinks
#define PINK            "\033[38;5;205m"
#define HOT_PINK        "\033[38;5;198m"
#define LIGHT_PINK      "\033[38;5;217m"
#define DEEP_PINK       "\033[38;5;161m"

// Blues
#define SKY_BLUE        "\033[38;5;117m"
#define LIGHT_BLUE      "\033[38;5;81m"
#define DEEP_BLUE       "\033[38;5;18m"
#define NAVY_BLUE       "\033[38;5;17m"
#define DODGER_BLUE     "\033[38;5;33m"

// Purples
#define PURPLE          "\033[38;5;141m"
#define VIOLET          "\033[38;5;92m"
#define DARK_PURPLE     "\033[38;5;54m"
#define LIGHT_PURPLE    "\033[38;5;183m"

// Greens
#define LIME            "\033[38;5;154m"
#define FOREST_GREEN    "\033[38;5;28m"
#define MINT_GREEN      "\033[38;5;121m"
#define DARK_GREEN      "\033[38;5;22m"

// Reds
#define CRIMSON         "\033[38;5;160m"
#define DARK_RED        "\033[38;5;88m"
#define LIGHT_RED       "\033[38;5;203m"

// Yellows
#define GOLD            "\033[38;5;220m"
#define LIGHT_YELLOW    "\033[38;5;228m"
#define DARK_YELLOW     "\033[38;5;136m"

// Others
#define CORAL           "\033[38;5;209m"
#define SALMON          "\033[38;5;210m"
#define PEACH           "\033[38;5;216m"
#define LAVENDER        "\033[38;5;183m"
#define TEAL            "\033[38;5;51m"
#define TURQUOISE       "\033[38;5;80m"
#define AQUA            "\033[38;5;87m"
#define BROWN           "\033[38;5;130m"
#define TAN             "\033[38;5;180m"
#define BEIGE           "\033[38;5;223m"

// Grays
#define GRAY            "\033[38;5;244m"
#define LIGHT_GRAY      "\033[38;5;250m"
#define DARK_GRAY       "\033[38;5;238m"
#define SLATE_GRAY      "\033[38;5;102m"

// ============================================================================
// SEMANTIC COLORS (For common use cases)
// ============================================================================
#define ERROR_COLOR     BOLD_RED
#define WARNING_COLOR   ORANGE
#define SUCCESS_COLOR   BOLD_GREEN
#define INFO_COLOR      SKY_BLUE
#define DEBUG_COLOR     GRAY

#endif // TERMINAL_COLORS_H

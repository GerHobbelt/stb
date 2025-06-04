#! /bin/bash
set -euo pipefail

if [[ $@ == "-v" || $@ == "--verbose" ]]; then set -x; fi;

if which valgrind >/dev/null 2>&1; then
	function run() {
		# Just some standard flags I normally use with valgrind
		valgrind \
			--leak-check=full --show-leak-kinds=all \
			--track-origins=yes --track-fds=yes \
			--quiet "$@"
	}
else
	function run() {
		"$@"
	}
fi

function test_lexer() {
	if which "$1" >/dev/null 2>&1; then
		echo "Compiling with \"$@\"..."
		# -O3 because clang may find undefined behaviour when optimizing (O2 for clang-cl)
        # Allow deprecations (fopen on Windows. only used in the main() of STB_C_LEXER_SELF_TEST)
		"$@" -Wall -Wextra -Werror -O2 -O3 -Wno-unused-command-line-argument \
			-Wno-deprecated-declarations -Wno-unused-macros \
            -Wno-unsafe-buffer-usage -Wno-declaration-after-statement -Wno-unreachable-code \
			-DSTB_C_LEXER_SELF_TEST -DSTB_C_LEXER_IMPLEMENTATION \
			-x c stb_c_lexer.h -o ./out
		echo "Successful compilation with $@"
		run ./out >/dev/null
		echo "Successful execution with $@"
	else
		echo "Command $1 not found. Ignoring..."
	fi
	echo
}
test_lexer gcc
test_lexer g++
test_lexer clang
test_lexer clang++
test_lexer clang-cl -TC
test_lexer clang-cl -TP

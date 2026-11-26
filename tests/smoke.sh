#!/usr/bin/env sh
set -eu

output=$(printf 'hello\nexit\n' | ./msh)
printf '%s\n' "$output" | grep -q 'command processing not implemented yet'

output=$(printf '\nexit\n' | ./msh)
if printf '%s\n' "$output" | grep -q 'command processing not implemented yet'; then
    echo "empty input should not be treated as a command" >&2
    exit 1
fi

long_input=$(awk 'BEGIN { for (i = 0; i < 4097; i++) printf "x"; printf "\nexit\n" }')
output=$(printf '%s\n' "$long_input" | ./msh 2>&1)
printf '%s\n' "$output" | grep -q 'input exceeds maximum length'

echo "smoke tests passed"

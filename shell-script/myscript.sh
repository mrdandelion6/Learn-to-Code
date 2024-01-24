functionA() {
    local name="$1"
    echo "Hello" $name
}

val1=$(functionA "bob")

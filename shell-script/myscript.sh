function_test() {
    echo "first"
    echo "second"
    echo "third"
}


result=$(function_test)

echo "$(echo "$result" | sed -n '3p')"

multiple_return_values() {
    echo "orange1"
    echo "apple2"
    echo "carrot3"
    echo "mango4"
    echo "banana5"
    echo "peach6"
}

# for efficieny, let us first collect all of the echos in one variable
result=$(multiple_return_values)
# now we can access each individal return like so
val1=$(echo "$result" | sed -n '1p')
val2=$(echo "$result" | sed -n '2p')
val3=$(echo "$result" | sed -n '3p')
val4=$(echo "$result" | sed -n '4p')

echo $val1 # print values to check
echo $val2
echo $val3
echo $val4
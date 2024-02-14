#!/bin/bash
# first lets iter through some bash array

# x=("whats up" "amigo yo" "im bored")
# for el in "${x[@]}"; do
#     echo $el
# done

# now here is some loop practice

# x=699
# y=699
# if [[ $y -gt $x && 0 < 1 ]]; then
#     echo $y
# elif [[ $x -eq $y ]]; then
#     echo "they are equal"
# else
#     echo $x
# fi


# now lets iterate through the directories
isWantedDirectory() {
    case $1 in
        "a1" | "a2" | "a3" | "t1" | "t2" | "t3" | "t4" | "t5")
            echo 0
            ;;
        *)
            echo 1
    esac
}

for d in iterate_dirs; do
    echo $d
    if [[ $(isWantedDirectory $d) -eq 0 ]]; then
        cat $(d)/feedback.txt
    fi
done

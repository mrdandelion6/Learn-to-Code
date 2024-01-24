fruitsArray=("apple" "mango" "pineapple" "guava" "lichi")
echo ${fruitsArray[0]}
echo ${fruitsArray[4]} # prints lichi 
echo ${fruitsArray[5]} # prints nothing
fruitsArray+=("banana" "orange")
echo ${fruitsArray[5]} # prints banana

echo ${fruitsArray[@]}
fruitsArray[2]="grape"
echo ${fruitsArray[@]} # now third element is grapes
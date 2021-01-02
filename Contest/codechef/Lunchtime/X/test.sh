declare -a arr=("a" "b" "c" "d" "e")
for i in "${arr[@]}"
do
   mkdir "$i"
   cd $i
   cf gen
   geany $i.cpp
   cd ..
done

declare -a arr=("a" "b" "c" "d" "e" "f")
for i in "${arr[@]}"
do
   mkdir "$i"
   cd $i
   cf gen
   subl $i.cpp
   cd ..
done

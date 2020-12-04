for((i = 0; ; i++)) do
  echo $i
  ./array $i > in$i
 # ./brute < in > out2
  ./c < in$i > out1
#  diff -w out1 out2 || break
done

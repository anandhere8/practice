for((i = 0; ; i++)) do
  echo $i
  ./gen $i > in
  ./brute < in > out2
  ./c < in > out1
  diff -w out1 out2 || break
done

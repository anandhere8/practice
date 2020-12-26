for((i = 0; ; i++)) do
  echo $i
  ./array $i > in
  ./brute < in > out2
  ./b < in > out1
  diff -w out1 out2 || break
done

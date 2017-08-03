CFILES="$(ls cs1713-day0-prog*.c)"
i=1
for cFile in $CFILES
do
   echo "compiling ${i}:  ${cFile}..."
   objFile=cs1713-day0-prog${i}.o
   gcc ${cFile} -o ${objFile}
   i=$(( i+1 ))
done
    

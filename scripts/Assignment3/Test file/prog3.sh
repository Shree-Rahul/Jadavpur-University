total=0
for file in * ;do
    if [ -f "$file" ] then
        size=$(ls -l | awk '{print $5}')
        $total=$(($total + $size))
    fi
done

echo "Total bytes used: $total"
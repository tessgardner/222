for file in *.txt
do
	if [ -f "$file" ]
	then
		cp ./$file ./$file.bak
		echo "$file has been backed up"
	fi
done


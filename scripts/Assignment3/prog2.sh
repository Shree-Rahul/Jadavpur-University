# Count the number of files and directories and list their names separately
echo "Number of files: $(ls -l | grep ^- | wc -l)"
echo "Number of directories: $(ls -l | grep ^d | wc -l)"
echo "List of files:"
ls -l | grep ^- | awk '{print $9}'
echo "List of directories:"
ls -l | grep ^d | awk '{print $9}'
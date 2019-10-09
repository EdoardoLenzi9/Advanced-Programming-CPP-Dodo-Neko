#!/bin/bash

echo "############################################"
echo "### A dirty shortcut for gprof profiling ###"
echo "############################################"

# Compile the source
g++ -pg $1

# Execute the source
./a.out

# Profile
gprof a.out gmon.out > profile-data.txt

# Display profile data
cat profile-data.txt

# Clean
rm a.out 
rm gmon.out
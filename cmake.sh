#! /bin/bash

if [[ $1 == 0 ]]; then
    nice -n 20 ./build/prjcreator
else
  nice -n 20 cmake -B build -S .
  nice -n 20 cmake --build build --config debug --clean-first
  nice -n 20 echo ""
  nice -n 20 echo ""
  #nice -n 20 echo "PRESS ANY KEY TO EXECUTE PROGRAM ..."
  #read
  nice -n 20 ls -lthra ./build/prjcreator
  nice -n 20 echo ""
  nice -n 20 echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
  nice -n 20 echo ""
  nice -n 20 ./build/prjcreator --path:Mariam --project-normal --git-init --author:ramin --email:StubbornStruggle@gmail.com
  nice -n 20 echo ""
  nice -n 20 echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
fi
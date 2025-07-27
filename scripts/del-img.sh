rm /usr/archpass/img/$1.qcow2

if [$1 -eq "archpass-base-img"]; then 
  echo "archpass: cant delete archpass-base-img, terminating process"
  exit 4 

if [ $? -eq 0 ]; then
  echo "archpass: Image deleted successfully"
fi

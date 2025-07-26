rm img/$1.qcow2

if [ $? -eq 0 ]; then
  echo "archpass: Image deleted successfully"
fi

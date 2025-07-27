
ls -l img/archpass-base-img.qcow2
if [ $? -eq 0 ]; then
  echo "archpass: base image found, attempting to install" 
else
  echo "archpass: base image not found"
  echo "Please get the image from archpass-base-img from https://gofile.io/d/mwp9Ts and move it under img directory"
  exit 1
fi

sudo mv $(pwd) /usr
chmod +x /usr/archpass/scripts/*.sh
chmod +x src/archpass
rm /usr/archpass/img/IMG.md
sudo ln -s /usr/archpass/src/archpass /usr/local/bin/archpass

